#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "sys.h"

#define PARAM_UP				1
#define PARAM_DOWN				-1

enum {
	MODE_MAIN = 0,
	MODE_MENU,
	MODE_EDIT_TIME,
	MODE_EDIT_DATE,
	MODE_EDIT_ALARM,
	MODE_EDIT_HOURSIGNAL,
	MODE_EDIT_FONT,
	MODE_EDIT_DISP,
	MODE_EDIT_DOT,
	MODE_EDIT_BRIGHT,
	MODE_EDIT_TEMP_COEF,
	MODE_TEST,

	MODE_END
};

enum {
	WI_TIME = 0,
	WI_DATE,
	WI_WEEK,
	WI_TEMP,
//	WI_PRES,
//	WI_HUMI,
	WI_HOLY
};

enum {
	TS_DS = 0,
	TS_SI,
	TS_BMP
};

typedef void __wi_func(void); 
typedef __wi_func *__ptr_wi_func;

typedef struct {
	uint8_t sec;
	__code __wi_func *func;
} Widget;

#define DISPLAYSIZE 24
#define RENDSERBUFFERSIZE 254
#define hbd(a,b) a | (b << 4)
#define EMPTYLINE 	*pdisp = 0x00; pdisp++;


extern uint8_t dispMode;
__data extern uint8_t disp[DISPLAYSIZE];
__xdata extern uint8_t render_buffer[RENDSERBUFFERSIZE];
extern uint8_t displayBright;
extern uint8_t render_buffer_size;
extern int16_t scroll_index;
extern uint8_t menuNumber;
extern uint8_t screenTime;
extern uint8_t widgetNumber;
extern __bit refstart;
extern uint8_t refcount;
extern uint8_t dotcount;
extern __bit reversed;
__code extern Widget widgets[7];

void displayInit(void);
void displayClear(void);
void displayRefresh(void);
void checkAlarm(void);
void checkParam(int8_t *param, int8_t diff, int8_t paramMin, int8_t paramMax);
void updateFont(void);
void showMainScreen(void);
void showTime(void);
void resetDispLoop(void);
void updateFont(void);
void showTime(void);
void changeBright(int8_t diff);
void changeMenu(uint8_t diff);
void showMenu(void);
void showTimeEdit(void);
void showDateEdit(void);
void showAlarmEdit(void);
void changeFont(int8_t diff);
void showFontEdit(void);
void changeDisp(int8_t diff);
void showDispEdit(void);
void changeDot(int8_t diff);
void showDotEdit(void);
void showBrightEdit(void);
void changeHourSignal(int8_t diff);
void showHourSignalEdit(void);
void changeTempCoef(int8_t diff);
void showTempCoefEdit(void);
void showRenderBuffer(void);
void renderHoliday(uint8_t length, char *str);

#endif /* _DISPLAY_H_ */