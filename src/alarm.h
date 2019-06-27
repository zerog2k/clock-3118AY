#ifndef _ALARM_H_
#define _ALARM_H_

#include "sys.h"

enum {
	ALARM_ON = 0,
	ALARM_HOUR,
	ALARM_MIN,
	ALARM_MON,
	ALARM_TUE,
	ALARM_WED,
	ALARM_THU,
	ALARM_FRI,
	ALARM_SAT,
	ALARM_SUN,
	ALARM_ETM
};

typedef struct {
	uint8_t on;
	uint8_t hour;
	uint8_t min;
	uint8_t mon;
	uint8_t tue;
	uint8_t wed;
	uint8_t thu;
	uint8_t fri;
	uint8_t sat;
	uint8_t sun;
	uint8_t etm;
} Alarm_type;

__pdata extern Alarm_type alarm;

#define ALARM_NOEDIT			0xFF

void alarmInit(void);
void alarmSave(void);
void alarmNextEditParam(void);
void alarmChange(int8_t diff);
uint8_t alarmRawWeekday(void);

#endif /* _ALARM_H_ */
