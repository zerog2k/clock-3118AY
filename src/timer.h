#ifndef _TIMER_H_
#define _TIMER_H_

#include "sys.h"

void timerInit(void);
void timer0_isr(void) __interrupt 1;

#endif /* _TIMER_H_ */
