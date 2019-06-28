#include "sys.h"
#include "display.h"
#include "pinout.h"
#include "ds1302.h"
#include "adc.h"
#include "key.h"
#include "alarm.h"
#include "fonts.h"
#include "weekpicture.h"
#include "menupicture.h"
//#include "holidays.h"
#include "settings.h"
#include <string.h>

__pdata uint8_t disp[DISPLAYSIZE];
uint8_t render_buffer_size = 0;
int16_t scroll_index = -1;
__xdata uint8_t render_buffer[RENDSERBUFFERSIZE];
uint8_t *pdisp;
const uint8_t *fptr;
uint8_t displayBright = 6;
uint8_t dispMode = MODE_MAIN;
const uint8_t hourbright[12] = { 0x00, 0x00, 0x12, 0x34, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x32, 0x10 };

uint8_t menuNumber = MODE_EDIT_TIME;
uint8_t screenTime = 0;
uint8_t widgetNumber = 0;
volatile __bit reversed;
volatile __bit refstart;
volatile uint8_t refcount;
uint8_t dotcount;

void wiNext(void);
void wiTime(void);
void wiHoly(void);

const Widget widgets[7] = {
	{5, wiTime}, /* WI_TIME */
	{2, wiNext}, /* WI_DATE */ 
	{2, wiNext}, /* WI_WEEK */ 
	{2, wiNext}, /* WI_TEMP */ 
//	{2, wiNext}, /* WI_PRES */ 
//	{2, wiNext}, /* WI_HUMI */ 
	{0, wiHoly}, /* WI_HOLY */ 
};

void displayInit(void)
{
	/* 
	P0M1 = 0x00;
	P0M0 = 0xFF;
	P1M1 = 0x00;
	P1M0 = 0x0F;
	P2M1 = 0x00;
	P2M0 = 0xFF;
	P3M1 = 0x00;
	P3M0 = 0xF7;
	P4M1 = 0x00;
	P4M0 = 0xFE;
	*/
	
	// MODE_CONFIG_ALL_PORTS(); //temp disable, makes very bright?

	displayBright = eep.bright;
	//displayBright = 2;
	refstart = 0;
	updateFont();

	//pdisp = &render_buffer[0];
	// �������� '��������'
	/*
	pdisp = &disp[0];
	sptr = &pic_heart[0];
	for(i=0; i<DISPLAYSIZE; i++, sptr++, pdisp++) {
		*pdisp = *sptr;
	}
	*/
	pdisp = disp;
	memcpy(pdisp, pic_heart, DISPLAYSIZE);
}

void displayClear(void)
{
	/* 
	P0 |= 0x00;
	P1 &= 0xF0;
	P2 &= 0x00;
	P3 &= 0x0B;
	P4 &= 0x01;
	*/
	ALL_ROWS_LOW();
	ALL_COLS_HIGH();
}

void displayRefresh(void) __critical
{
	static uint8_t columnrefnum = 0;
	static uint8_t columnrefwidth = 0;
	uint8_t k;
	//refstart = 1;
	if ( columnrefwidth < 5 ) {
		if ( columnrefwidth == displayBright )
			displayClear();
		columnrefwidth++;

		return;
	} else {
		columnrefwidth = 0;
		displayClear();
		if(reversed) {
			k = columnrefnum;
		}
		else {
			k = 23-columnrefnum;
		}
		switch(k) {
			case 0:		col00 = 0;	break;
			case 1:		col01 = 0;	break;
			case 2:		col02 = 0;	break;	
			case 3:		col03 = 0;	break;
			case 4:		col04 = 0;	break;
			case 5:		col05 = 0;	break;	
			case 6:		col06 = 0;	break;
			case 7:		col07 = 0;	break;
			case 8:		col08 = 0;	break;
			case 9:		col09 = 0;	break;
			case 10:	col10 = 0;	break;
			case 11:	col11 = 0;	break;
			case 12:	col12 = 0;	break;
			case 13:	col13 = 0;	break;	
			case 14:	col14 = 0;	break;
			case 15:	col15 = 0;	break;
			case 16:	col16 = 0;	break;	
			case 17:	col17 = 0;	break;
			case 18:	col18 = 0;	break;
			case 19:	col19 = 0;	break;
			case 20:	col20 = 0;	break;
			case 21:	col21 = 0;	break;
			case 22:	col22 = 0;	break;
			case 23:	col23 = 0;	break;
			default:break;
		}

		if(reversed) {	
			P0 = 0x00^disp[23-k];
		}
		else {
			P0 = 0x00^(((disp[k]>>7)&0x01)|((disp[k]>>5)&0x02)|((disp[k]>>3)&0x04)| (disp[k]>>1&0x08)|((disp[k]<<1)&0x10)|((disp[k]<<3)&0x20)|((disp[k]<<5)&0x40)|((disp[k]<<7)&0x80));
		}
		columnrefnum++;
		if( columnrefnum > 23 ) {
			columnrefnum = 0;
			//reversed = key_mer;
			if(!refstart) {
				refstart = 1;
			}
		}
	}
}

void checkAlarm(void)
{
	static __bit firstCheck = 1;

	rtcReadTime();

	// Once check if it's a new second
	if (rtc.sec == 0) {
		if (firstCheck) {
			firstCheck = 0;
			// Check alarm
			if (alarm.on && rtc.hour == alarm.hour && rtc.min == alarm.min) {
				if (*((int8_t*)&alarm.mon + rtc.wday - 1))
					alarmTimer = 60 * (uint16_t)eep.alarmTimeout;
			}
			else {
				// Check new hour
				if (rtc.hour > alarm.hour && rtc.min == 0 && eep.hourSignal)
					startBeeper(BEEP_LONG);
			}
		}
	}
	else {
		firstCheck = 1;
	}

}

void updateFont(void)
{
	switch(eep.fontMode) {
		default:
		case 0: {fptr = num_font1; break; }
		case 1: {fptr = num_font2; break; }
		case 2: {fptr = num_font3; break; }
		case 3: {fptr = num_font4; break; }
		case 4: {fptr = num_font5; break; }
	}

}

void resetDispLoop(void)
{
	dispMode = MODE_MAIN;
	screenTime = 0;
	widgetNumber = 0;

}

void showDot(void)
{
	uint8_t i, dot;

	switch(eep.dotMode) {
		case 0: {
			if (dotcount < 15) { dot = 0; }
			else if (dotcount < 45) { dot = 3; }
			else { dot = 0; }
			break;
		}
		default:
		case 1: {
			if (dotcount < 5) { dot = 0; }
			else if (dotcount < 13) { dot = 1; }
			else if (dotcount < 22) { dot = 2; }
			else if (dotcount < 39) { dot = 3; }
			else if (dotcount < 48) { dot = 2; }
			else if (dotcount < 56) { dot = 1; }
			else { dot = 0; }
			break;
		}
		case 2: {
			if (dotcount < 6) { dot = 0; }
			else if (dotcount < 18) { dot = 3; }
			else if (dotcount < 30) { dot = 4; }
			else if (dotcount < 42) { dot = 5; }
			else if (dotcount < 54) { dot = 6; }
			else { dot = 0; }
			break;
		}
		case 3: {
			if (dotcount < 7) { dot = 0; }
			else if (dotcount < 22) { dot = 7; }
			else if (dotcount < 37) { dot = 3; }
			else if (dotcount < 52) { dot = 8; }
			else { dot = 0; }
			break;
		}
		case 4: {
			if (dotcount < 7) { dot = 0; }
			else if (dotcount < 22) { dot = 1; }
			else if (dotcount < 37) { dot = 2; }
			else if (dotcount < 52) { dot = 1; }
			else { dot = 0; }
			break;
		}
	}
	for(i=0; i<4; i++, pdisp++) {
		*pdisp = dot_font[4*dot+i];
	}

}

void showNumber(uint8_t num, uint8_t clean, uint8_t dig )
{
	uint8_t i;
	const uint8_t *sptr;

	for(i=0; i<4; i++, pdisp++) {
			if(!clean&&(!dig ||((num/10) > 0 ))) {
			sptr = fptr + (4*(num/10)+i);
			*pdisp = *sptr;
		}
		else
			*pdisp = 0x00;
	}
	*pdisp = 0x00;
	pdisp++;
	for(i=0; i<4; i++, pdisp++) {
		if(!clean) {
			sptr = fptr + (4*(num%10)+i);
			*pdisp = *sptr;
		}
		else
			*pdisp = 0x00;
	}
}

void showTime(void)
{
	showNumber(rtc.hour, 0, 0);
	showDot();
	showNumber(rtc.min, 0, 0);
	EMPTYLINE;
	EMPTYLINE;

}

void showDate(void)
{
	uint8_t i;

	showNumber(rtc.date, 0, 1);
	for(i=0; i<4; i++, pdisp++) {
		*pdisp = dot_font[4+i];
	}
	showNumber(rtc.month, 0, 0);
	EMPTYLINE;
	EMPTYLINE;

}

void showDayWeek(void)
{
	const uint8_t *sptr;
	switch(rtc.wday) {
		case 1: sptr = pic_mon; break;
		case 2: sptr = pic_tue; break;
		case 3: sptr = pic_wed; break;
		case 4: sptr = pic_thu; break;
		case 5: sptr = pic_fri; break;
		case 6: sptr = pic_sat; break;
		case 7: sptr = pic_sun; break;
		default: sptr = pic_heart; break; // should never see this ;)
	}
	memcpy(pdisp, sptr, DISPLAYSIZE);
}

void showTemperature(void)
{
	uint8_t i;
	int8_t temp = eep.tempcoef;
	temp += adc.temp;

	if (temp > 99) {
		for(i=0; i<4; i++, pdisp++) {
			*pdisp = 0x00;
		}
		for(i=0; i<5; i++, pdisp++) {
			*pdisp = temperature_font[50+i];
		}
		EMPTYLINE;
		EMPTYLINE;
	}
	else {
		// tens place
		if (temp > 9) {
			for(i=0; i<5; i++, pdisp++) {
				*pdisp = temperature_font[5*(temp/10)+i];
			}
		}
		// blank tens place
		else {
			for(i=0; i<5; i++, pdisp++) {
				*pdisp = 0x00;
			}
		}
		EMPTYLINE;
		// ones place
		for(i=0; i<5; i++, pdisp++) {
			*pdisp = temperature_font[5*(temp%10)+i];
		}
	}
	EMPTYLINE;
	EMPTYLINE;
	// degrees C
	for(i=0; i<9; i++, pdisp++) {
		*pdisp = temperature_font[55+i];
	}
	EMPTYLINE;
	EMPTYLINE;
}

void autoBright(void)
{
	if( rtc.hour < 24 && eep.bright == 6 ) {
		displayBright = (rtc.hour&0x01)?(hourbright[rtc.hour>>1] & 0x0F):((hourbright[rtc.hour>>1]>>4 )& 0x0F);
	}

}

void showMainScreen(void)
{
	pdisp = disp;
	updateFont();
	autoBright();

	switch(widgetNumber) {
		case WI_TIME: { showTime(); break;}
		case WI_DATE: { showDate(); break;}
		case WI_WEEK: { showDayWeek(); break;}
		case WI_TEMP: { showTemperature(); break;}
//		case WI_PRES: { showPressure(); break;}
//		case WI_HUMI: { showHumidity(); break;}
//		case WI_HOLY: { showRenderBuffer(); break;}
		default: { showTime(); break;}
	}

}

void checkParam(int8_t *param, int8_t diff, int8_t paramMin, int8_t paramMax)
{
	*param += diff;

	if (*param > paramMax)
		*param = paramMin;
	if (*param < paramMin)
		*param = paramMax;

}

void changeMenu(uint8_t diff)
{
	checkParam(&menuNumber, diff, MODE_EDIT_TIME, MODE_EDIT_TEMP_COEF);

}

void showMenu(void)
{
	const uint8_t *sptr;
	switch(menuNumber) {
		case MODE_EDIT_TIME: sptr = pic_Time; break;
		case MODE_EDIT_DATE: sptr = pic_Date; break;
		case MODE_EDIT_ALARM: sptr = pic_Alarm; break;
		case MODE_EDIT_HOURSIGNAL: sptr = pic_HourSignal; break;
		case MODE_EDIT_FONT: sptr = pic_Font; break;
		case MODE_EDIT_DISP: sptr = pic_Disp; break;
		case MODE_EDIT_DOT: sptr = pic_Dot; break;
		case MODE_EDIT_BRIGHT: sptr = pic_Bright; break;
		case MODE_EDIT_TEMP_COEF: sptr = pic_TempCoef; break;
		default: break;
	}
	memcpy(disp, sptr, DISPLAYSIZE);
}

void showTimeEdit(void)
{
	uint8_t i;
	__bit flash;

	pdisp = &disp[0];
	updateFont();

	if (refcount < 15) { flash = 0; }
	else if (refcount < 45) { flash = 1; }
	else { flash = 0; }

	if(rtc.etm == RTC_SEC) {
		for(i=0; i<9; i++, pdisp++) {
			*pdisp = 0x00;
		}
		for(i=0; i<4; i++, pdisp++) {
			*pdisp = dot_font[4*3+i];
		}
		showNumber(rtc.sec, !((rtc.etm != RTC_SEC)||(flash && (rtc.etm == RTC_SEC))), 0);
	}
	else {
		showNumber(rtc.hour, !((rtc.etm != RTC_HOUR)||(flash && (rtc.etm == RTC_HOUR))), 0);
		for(i=0; i<4; i++, pdisp++) {
			*pdisp = dot_font[4*3+i];
		}
		showNumber(rtc.min, !((rtc.etm != RTC_MIN)||(flash && (rtc.etm == RTC_MIN))), 0);
	}

}

void showDateEdit(void)
{
	uint8_t i;
	__bit flash;

	pdisp = disp;
	updateFont();

	if (refcount < 15) { flash = 0; }
	else if (refcount < 45) { flash = 1; }
	else { flash = 0; }

	if(rtc.etm == RTC_YEAR) {
		EMPTYLINE;
		EMPTYLINE;
		showNumber(20, 0, 0);
		EMPTYLINE;
		showNumber(rtc.year, !((rtc.etm != RTC_YEAR)||(flash && (rtc.etm == RTC_YEAR))), 0);
		EMPTYLINE;
	}
	else {
		showNumber(rtc.date, !((rtc.etm != RTC_DATE)||(flash && (rtc.etm == RTC_DATE))), 1);
		for(i=0; i<4; i++, pdisp++) {
			*pdisp = dot_font[4+i];
		}
		showNumber(rtc.month, !((rtc.etm != RTC_MONTH)||(flash && (rtc.etm == RTC_MONTH))), 0);
	}

}

void showAlarmEdit(void)
{
	uint8_t i, j;
	const uint8_t *sptr;
	__bit flash;

	pdisp = &disp[0];
	updateFont();

	if( alarm.etm == ALARM_ON) {
		if(alarm.on) {
			sptr = &pic_On[0];
		}
		else {
			sptr = &pic_Off[0];
		}
		for(i=0; i<DISPLAYSIZE; i++, sptr++) {
			disp[i] = *sptr;
		}
	}
	else if((alarm.etm == ALARM_HOUR)||(alarm.etm == ALARM_MIN)) {
		if (refcount < 15) { flash = 0; }
		else if (refcount < 45) { flash = 1; }
		else { flash = 0; }

		showNumber(alarm.hour, !((alarm.etm != ALARM_HOUR)||(flash && (alarm.etm == ALARM_HOUR))), 0);
		for(i=0; i<4; i++, pdisp++) {
			*pdisp = dot_font[4*3+i];
		}
		showNumber(alarm.min, !((alarm.etm != ALARM_MIN)||(flash && (alarm.etm == ALARM_MIN))), 0);
	}
	else {
		if (refcount < 27) { flash = 0; }
		else if (refcount < 33) { flash = 1; }
		else { flash = 0; }

		switch(alarm.etm) {
			case ALARM_MON: {sptr = &pic_alarm_mon[0]; break; }
			case ALARM_TUE: {sptr = &pic_alarm_tue[0]; break; }
			case ALARM_WED: {sptr = &pic_alarm_wed[0]; break; }
			case ALARM_THU: {sptr = &pic_alarm_thu[0]; break; }
			case ALARM_FRI: {sptr = &pic_alarm_fri[0]; break; }
			case ALARM_SAT: {sptr = &pic_alarm_sat[0]; break; }
			case ALARM_SUN: {sptr = &pic_alarm_sun[0]; break; }
			default: break;
		}

		for(i=0; i<DISPLAYSIZE; i++, sptr++) {
			j = 0;
			switch(i) {
				case 1:
				case 2: {
					if(((alarm.etm != ALARM_MON)&&alarm.mon)||((alarm.etm == ALARM_MON)&&((alarm.mon && !flash)||(!alarm.mon && flash)))) j = 1;
					break;
				}
				case 4:
				case 5: {
					if(((alarm.etm != ALARM_TUE)&&alarm.tue)||((alarm.etm == ALARM_TUE)&&((alarm.tue && !flash)||(!alarm.tue && flash)))) j = 1;
					break;
				}
				case 7:
				case 8: {
					if(((alarm.etm != ALARM_WED)&&alarm.wed)||((alarm.etm == ALARM_WED)&&((alarm.wed && !flash)||(!alarm.wed && flash)))) j = 1;
					break;
				}
				case 10:
				case 11: {
					if(((alarm.etm != ALARM_THU)&&alarm.thu)||((alarm.etm == ALARM_THU)&&((alarm.thu && !flash)||(!alarm.thu && flash)))) j = 1;
					break;
				}
				case 13:
				case 14: {
					if(((alarm.etm != ALARM_FRI)&&alarm.fri)||((alarm.etm == ALARM_FRI)&&((alarm.fri && !flash)||(!alarm.fri && flash)))) j = 1;
					break;
				}
				case 16:
				case 17: {
					if(((alarm.etm != ALARM_SAT)&&alarm.sat)||((alarm.etm == ALARM_SAT)&&((alarm.sat && !flash)||(!alarm.sat && flash)))) j = 1;
					break;
				}
				case 19:
				case 20: {
					if(((alarm.etm != ALARM_SUN)&&alarm.sun)||((alarm.etm == ALARM_SUN)&&((alarm.sun && !flash)||(!alarm.sun && flash)))) j = 1;
					break;
				}
			}
			disp[i] = *sptr | j;
		}
	}

}

void changeFont(int8_t diff)
{
	checkParam(&eep.fontMode, diff, eepMin.fontMode, eepMax.fontMode); // 0, 4

}

void showFontEdit(void)
{
	pdisp = &disp[0];
	updateFont();
	showTime();

}

void changeDisp(int8_t diff)
{
	checkParam(&eep.dispMode, diff, eepMin.dispMode, eepMax.dispMode); // 1, 5

}

void showDispEdit(void)
{
	uint8_t i;

	pdisp = &disp[0];

	for(i=0; i<16; i++, pdisp++) {
		*pdisp = pic_Type[i];
	}
	EMPTYLINE;

	for(i=0; i<5; i++, pdisp++) {
		*pdisp = temperature_font[5*eep.dispMode+i];
	}

}

void changeDot(int8_t diff)
{
	checkParam(&eep.dotMode, diff, eepMin.dotMode, eepMax.dotMode); // 0, 4

}

void showDotEdit(void)
{
	pdisp = &disp[0];
	updateFont();

	showTime();

}

void changeBright(int8_t diff)
{
	checkParam(&eep.bright, diff, eepMin.bright, eepMax.bright); // 0, 6
	displayBright = eep.bright;
	autoBright();

}

void showBrightEdit(void)
{
	uint8_t i;

	pdisp = &disp[0];

	for(i=0; i<16; i++, pdisp++) {
		*pdisp = pic_BrEdit[i];
	}
	EMPTYLINE;

	for(i=0; i<5; i++, pdisp++) {
		*pdisp = temperature_font[5*eep.bright+i];
	}

}

void changeHourSignal(int8_t diff)
{
	checkParam(&eep.hourSignal, diff, eepMin.hourSignal, eepMax.hourSignal); // 0, 1

}

void showHourSignalEdit(void)
{
	uint8_t i;
	const uint8_t *sptr;

	if(eep.hourSignal) {
		sptr = &pic_On[0];
	}
	else {
		sptr = &pic_Off[0];
	}
	for(i=0; i<DISPLAYSIZE; i++, sptr++) {
		disp[i] = *sptr;
	}

}

void changeTempCoef(int8_t diff)
{
	checkParam(&eep.tempcoef, diff, eepMin.tempcoef, eepMax.tempcoef); // -9, 9

}

void showTempCoefEdit(void)
{
	pdisp = &disp[0];

	showTemperature();

}

void wiNext(void)
{
	if( screenTime > widgets[widgetNumber].sec ) {
		widgetNumber++;
		screenTime = 0;
		if( widgetNumber > ELEMENTS(widgets) ) {
			widgetNumber = WI_TIME;
		}
/*		if(widgetNumber == WI_PRES && !bmxx80HaveSensor()) {
			widgetNumber = WI_HUMI;
		}
		if(widgetNumber == WI_HUMI && ( !(bmxx80HaveSensor()==BME280_CHIP_ID||si7021SensorExists()) )) {
			widgetNumber = WI_HOLY;
		}*/
		if(widgetNumber == WI_HOLY) {
			//if(holiday) {
			if(0) {
				scroll_index = 0;
			}
			else {
				widgetNumber = WI_TIME;
				scroll_index = -1;
			}
		}
	}

}

void wiTime(void)
{
	if(eep.dispMode == 1) {
		screenTime = 0;
	}
	wiNext();

}

void wiHoly(void)
{
	if(scroll_index < 0){
		wiNext();
	}

}

void showRenderBuffer(void)
{
	uint8_t i;

	int16_t ind = scroll_index - DISPLAYSIZE;
	if( scroll_index > (render_buffer_size + DISPLAYSIZE )) {
		scroll_index = -1;
		widgetNumber = 0; screenTime = 0;
	}

	for(i=0; i<DISPLAYSIZE; i++) {
		if(( ind + i >= 0 )&&(ind + i < render_buffer_size )) {
			disp[i] = render_buffer[(uint8_t)(ind + i)];
		}
		else {
			disp[i] = 0x00;
		}
	}

}

void writeRenderBuffer(uint8_t value)
{
	if ( render_buffer_size < RENDSERBUFFERSIZE) {
		render_buffer[render_buffer_size++] = value;
	}

}

void renderHoliday(uint8_t length, char *str)
{
	uint8_t i, j, t, c;

	render_buffer_size = 0;

	for(i=0; i < (length - 1); i++, str++) {
		c = *str;
		if( c >= 0xA0 ) {
			c -= 0x40;
		}
		else if( c >= 0x20 ) {
			c -= 0x20;
		}
		else {
			c = 0x1F;
		}
		for(j=0; j<5; j++) {
			t = font_cp1251_07[5*c+j];
			if( t != VOID ) {
				writeRenderBuffer(t);
			}
		}
		writeRenderBuffer(0x00);
	}

}

