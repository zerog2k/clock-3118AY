#ifndef _ADC_H_
#define _ADC_H_

#include "sys.h"

#define ADC_POWER   0x80         //��� ���������� �������� ADC
#define ADC_FLAG    0x10         //��� ���������� �������������� ADC
#define ADC_START   0x08         //��� ���������� �������� ADC
#define ADC_SPEEDLL 0x00         //540 ������
#define ADC_SPEEDL  0x20         //360 ������
#define ADC_SPEEDH  0x40         //180 ������
#define ADC_SPEEDHH 0x60         //90 ������

typedef struct {
	int16_t	RawT;
	int16_t	RawB;
	int8_t	temp;
	int8_t	bright;
} Adc_type;

__pdata extern Adc_type adc;

#define ALARM_NOEDIT			0xFF

void adcInit(void);
uint16_t getADCResult(uint8_t chanel);
uint8_t getADCResult8(uint8_t chanel);
void adcConvert(void);

#endif /* _ADC_H_ */
