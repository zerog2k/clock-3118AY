#pragma std_sdcc99

#include "sys.h"
#include "pinout.h"
#include "timer.h"
#include "display.h"
#include "adc.h"
#include "ds1302.h"
#include "key.h"
#include "alarm.h"
#include "delay.h"
#include "settings.h"
//#include "holidays.h"
#include "adc.h"

#include <stdio.h>
#define printf printf_tiny     // see sdcc user guide
#include "serial.h"

void hwInit(void)
{
	settingsInit();
	displayInit();
	timerInit();
	adcInit();
	rtcInit();
	alarmInit();
	uart1_init();
	EA = 1; // enable interrupts
	rtc.etm = RTC_NOEDIT;
}

void cancelEdit(void)
{
	while(refstart == 0) {}
	displayClear();
	EA = 0;
	settingsInit();
	EA = 1;
	dispMode = MODE_MAIN;

}

void saveEdit(void)
{
	while(refstart == 0) {}
	displayClear();
	EA = 0;
	settingsSave();
	EA = 1;
	dispMode = MODE_MAIN;

}

void main(void)
{
	uint8_t cmd;
	int8_t direction = PARAM_UP;
	uint8_t z = 0;
	beep = 0; delay_ms(1); beep = 1;
	delay_ms(1);

	hwInit();
	printf("start1\n");
	delay_ms(250);

	startBeeper(BEEP_SHORT);

	sensTimer = TEMP_MEASURE_TIME;

	while(1) {
		while (refstart == 0); // wait for refresh
		refstart = 0;

		if (((refcount % 10) == 0) && (dispMode == MODE_MAIN || !(dispMode == MODE_EDIT_TIME || dispMode == MODE_EDIT_DATE))) {
			if (sensTimer == 0) {
				sensTimer = TEMP_MEASURE_TIME;
				adcConvert();
			}
			checkAlarm();
			//checkHolidays();
		//printf("adc.bright: %d\n", adc.bright);
		}

		cmd = getBtnCmd();
		if (cmd != BTN_STATE_0) {
			if (cmd < BTN_0_LONG)
				startBeeper(BEEP_SHORT);
			else
				startBeeper(BEEP_LONG);
		}

		/*
		BTN_0 - '+' 'ok'
		BTN_1 - '-' 'cansel'
		*/
		switch (cmd) {
			case BTN_0: {
				direction = PARAM_UP;
			}
			case BTN_1: {
				if (cmd == BTN_1)
					direction = PARAM_DOWN;
				switch (dispMode) {
					case MODE_MAIN: { changeBright(direction); break; }
					case MODE_MENU: { changeMenu(direction); break; }
					case MODE_EDIT_TIME:
					case MODE_EDIT_DATE: { rtcChangeTime(direction); break; }
					case MODE_EDIT_ALARM: { alarmChange(direction); break; }
					case MODE_EDIT_HOURSIGNAL: { changeHourSignal(direction); break; }
					case MODE_EDIT_FONT: { changeFont(direction); break; }
					case MODE_EDIT_DISP: { changeDisp(direction); break; }
					case MODE_EDIT_DOT: { changeDot(direction); break; }
					case MODE_EDIT_BRIGHT: { changeBright(direction); break; }
					case MODE_EDIT_TEMP_COEF: { changeTempCoef(direction); break; }
				}
				break;
			}
			case BTN_0_LONG: {
				switch (dispMode) {
					case MODE_MAIN: { dispMode = MODE_MENU; /*menuNumber = MODE_EDIT_TIME;*/ break; }
					case MODE_MENU: {
						switch(menuNumber) {
							case MODE_EDIT_TIME: {rtc.etm = RTC_HOUR; dispMode = menuNumber; break;}
							case MODE_EDIT_DATE: {rtc.etm = RTC_YEAR; dispMode = menuNumber; break;}
							case MODE_EDIT_ALARM: {alarm.etm = ALARM_ON; dispMode = menuNumber; break;}
							case MODE_EDIT_HOURSIGNAL:
							case MODE_EDIT_FONT:
							case MODE_EDIT_DISP:
							case MODE_EDIT_DOT:
							case MODE_EDIT_BRIGHT:
							case MODE_EDIT_TEMP_COEF: {
								dispMode = menuNumber;
								break;
							}
							default:
								break;
						}
						break;
					}
					case MODE_EDIT_TIME: {
						if(rtc.etm == RTC_SEC) {
							rtcSaveTime();
							resetDispLoop();
						}
						else {
							rtcNextEditParam();
						}
						break;
					}
					case MODE_EDIT_DATE: {
						if(rtc.etm == RTC_DATE) {
							rtcSaveDate();
							resetDispLoop();
						}
						else {
							rtcNextEditParam();
						}
						break;
					}
					case MODE_EDIT_ALARM: {
						if((alarm.etm == ALARM_ON && !alarm.on)||(alarm.etm == ALARM_SUN)) {
							alarmSave();
							saveEdit();
							resetDispLoop();
						}
						else {
							alarmNextEditParam();
						}
						break;
					}
					case MODE_EDIT_HOURSIGNAL:
					case MODE_EDIT_FONT:
					case MODE_EDIT_DISP:
					case MODE_EDIT_DOT:
					case MODE_EDIT_BRIGHT:
					case MODE_EDIT_TEMP_COEF: {
						saveEdit();
						resetDispLoop();
						break;
					}
				}
				break;
			}
			case BTN_1_LONG: {
				switch (dispMode) {
					case MODE_MAIN: { dispMode = MODE_MENU; /*menuNumber = MODE_EDIT_TIME;*/ break; }
					case MODE_MENU: { dispMode = MODE_MAIN; break; }
					case MODE_EDIT_ALARM: {
						alarmInit();
					}
					case MODE_EDIT_HOURSIGNAL:
					case MODE_EDIT_FONT:
					case MODE_EDIT_DISP:
					case MODE_EDIT_DOT:
					case MODE_EDIT_BRIGHT:
					case MODE_EDIT_TEMP_COEF: {
						cancelEdit();
					}
					case MODE_EDIT_TIME:
					case MODE_EDIT_DATE: {
						resetDispLoop();
						break;
					}
				}
				break;
			}
			case BTN_0_LONG | BTN_1_LONG: {
				break;
			}
		}

		switch(dispMode) {
			case MODE_MAIN: { showMainScreen(); break; }
			case MODE_MENU: { showMenu(); break; }
			case MODE_EDIT_TIME: { showTimeEdit(); break; } 
			case MODE_EDIT_DATE: { showDateEdit(); break; }
			case MODE_EDIT_ALARM: { showAlarmEdit(); break; }
			case MODE_EDIT_HOURSIGNAL: { showHourSignalEdit(); break; }
			case MODE_EDIT_FONT: { showFontEdit(); break; }
			case MODE_EDIT_DISP: { showDispEdit(); break; }
			case MODE_EDIT_DOT: { showDotEdit(); break; }
			case MODE_EDIT_BRIGHT: { showBrightEdit(); break; }
			case MODE_EDIT_TEMP_COEF: { showTempCoefEdit(); break; }
		}

		dotcount++;
		refcount++;
		/*
		if( holiday&&(widgetNumber == WI_HOLY) && (refcount % 5) == 0 ) {
			if(scroll_index >=0) scroll_index++;
		}
		*/
		if( dotcount > 59 ) dotcount = 0;
		if( refcount > 59 ) {
			refcount = 0;
			screenTime++;
			((__ptr_wi_func)widgets[widgetNumber].func)();
		}
		
		// power save, idle mode ?
		PCON |= 0x01;
		_nop_();
	}

}

