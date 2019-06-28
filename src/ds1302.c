#include "pinout.h"
#include "sys.h"
#include "ds1302.h"
#include "delay.h"

__pdata RTC_type rtc;

const static RTC_type rtcMin = {0, 0, 0, 1, 1, 1, 0, RTC_NOEDIT};
const static RTC_type rtcMax = {59, 59, 23, 31, 12, 7, 99, RTC_NOEDIT};

const static uint16_t rtcMonthNumberDay[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

static void rtcWeekDay(void)
{
	uint8_t a, y, m;

	a = (rtc.month > 2 ? 0 : 1);
	y = 12 + rtc.year - a;
	m = rtc.month + 12 * a - 2;

	rtc.wday = (rtc.date + y + (y / 4) + ((31 * m) / 12) - 1) % 7;

	if (rtc.wday == 0)
		rtc.wday = 7;

	return;
}

uint8_t rtcDaysInMonth(void)
{
	uint8_t ret = rtc.month;

	if (ret == 2) {
		ret = rtc.year & 0x03;
		ret = (ret ? 29 : 28);
	}
	else {
		if (ret > 7)
			ret++;
		ret |= 30;
	}

	return ret;
}

void writebyte(uint8_t b)
{ 
    b;
  __asm
    push	ar7
    mov     a,dpl
    mov	r7,#8
00001$:
    nop
    nop
    rrc     a
    mov     _DS_IO,c
    setb	_DS_SCLK
    nop
    nop
    clr	_DS_SCLK
    djnz	r7,00001$
    pop	ar7
  __endasm;
}

uint8_t readbyte(void)
{ 
  __asm
	push	ar7
	mov 	a,#0
	mov 	r7,#8
00002$:
	nop
	nop
	mov	c,_DS_IO
	rrc	a	
	setb	_DS_SCLK
	nop
	nop
	clr	_DS_SCLK
	djnz	r7,00002$
	mov	dpl,a
	pop	ar7
  __endasm;
}

void ds1302WriteReg(uint8_t reg, uint8_t value)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
	DS1302_CE = 1;
	writebyte(reg);
	writebyte(value);
	//DS1302_SCLK = 1;
	DS1302_CE = 0;

	return;
} 

uint8_t ds1302ReadReg(uint8_t reg)
{
    uint8_t result;

    DS1302_CE = 0;
    DS1302_SCLK = 0;
    DS1302_CE = 1;
    writebyte(reg|0x01);
    result = readbyte();
    //DS1302_SCLK = 1;
    DS1302_CE = 0;

    return result;
}

void ds1302SetProtect(__bit flag)
{
	if(flag)
		ds1302WriteReg(0x8E,0x10);
	else
		ds1302WriteReg(0x8E,0x00);

	return;
}

void ds1302SetTime(uint8_t address, uint8_t value)
{
	ds1302SetProtect(0);
	ds1302WriteReg(address, rtcDecToBinDec(value));

	return;
}

void rtcInit(void)
{
	uint8_t temp = ds1302ReadReg(DS1302_SECOND);
	if (temp&0x80)
	{
		rtc.date = 1;
		rtc.month = 1;
		rtc.year = 17;

		rtcSaveDate();

		rtc.sec = 0;
		rtc.min = 0;
		rtc.hour = 0;

		rtcSaveTime();
	}
	
	rtcReadTime();
	temp = rtc.wday;
	rtcWeekDay();
	if(temp != rtc.wday) {
		rtcSaveDate();
	}

	return;
}

void rtcSaveTime(void)
{
	uint8_t i;

	for (i = RTC_SEC; i <= RTC_HOUR; i++)
	{
		ds1302SetTime(0x80|(i<<1), *((uint8_t*)&rtc + i));
	}

	return;	
}

void rtcSaveDate(void)
{
	uint8_t i;

	rtcWeekDay();
	for (i = RTC_DATE; i <= RTC_YEAR; i++)
	{
		ds1302SetTime(0x80|(i<<1), *((uint8_t*)&rtc + i));
	}

	return;
}

void rtcReadTime(void)
{
	uint8_t i;

	DS1302_CE = 0;
	DS1302_SCLK = 0;
	DS1302_CE = 1;
	writebyte(DS1302_BURSTCLOCK|0x01);

	for (i = RTC_SEC; i <= RTC_YEAR; i++) {
		*((uint8_t*)&rtc + i) = rtcBinDecToDec(readbyte());
	}
	DS1302_SCLK = 1;
	DS1302_CE = 0;

	return;
}

void rtcChangeTime(uint8_t diff)
{
	int8_t *time = (int8_t*)&rtc + rtc.etm;
	int8_t timeMax = *((int8_t*)&rtcMax + rtc.etm);
	int8_t timeMin = *((int8_t*)&rtcMin + rtc.etm);

	if (rtc.etm == RTC_DATE)
		timeMax = rtcDaysInMonth();

	*time += diff;

	if (*time > timeMax)
		*time = timeMin;
	if (*time < timeMin)
		*time = timeMax;

	return;
}

void rtcNextEditParam(void)
{
	switch (rtc.etm) {
		case RTC_HOUR:
		case RTC_MIN:
			rtc.etm--;
			break;
		case RTC_SEC:
			rtc.etm = RTC_DATE;
			break;
		case RTC_DATE:
		case RTC_MONTH:
			rtc.etm--;
			break;
		case RTC_YEAR:
			rtc.etm--;
			rtc.etm--;
			break;
		default:
			rtc.etm = RTC_HOUR;
			break;
	}

	return;
}

uint16_t rtcYearDay(void)
{
	return rtcMonthNumberDay[rtc.month-1] + rtc.date + (((rtc.year % 4 == 0) && (rtc.month>2))? 1 : 0);
}

uint8_t rtcBinDecToDec(uint8_t num)
{
	return (num >> 4) * 10 + (num & 0x0F);
}

uint8_t rtcDecToBinDec(uint8_t num)
{
	return ((num / 10) << 4) + (num % 10);
}
