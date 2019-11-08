#include "sys.h"
#include "timer.h"
#include "key.h"
#include "display.h"

volatile uint8_t keytest;

// void timer1Init(void)
// {

// 	return;
// }

void timer0Init(void)
{

	AUXR |= 0x80;		// T0: /1T

#if (SYSCLK == SYSCLK_11)
	// @11.059MHz
	TL0 = 0x34;
	TH0 = 0xFB;
#elif (SYSCLK == SYSCLK_18)
	// @18.432MHz
	TL0 = 0x02;
 	TH0 = 0xF8;
#else
	// @6.000MHz
	/*
		For 1T:
		(65536 - trv) = t * Fcpu
		65536 - (Fcpu * t) = timer_reload_value
 	*/
 	// t = 0.000126
	// TL0 = 0x66;
	// TH0 = 0xFD;

	// t = 0.000111
	TL0 = 0x66;
	TH0 = 0xFD;

	/*  experimenting with other timer ticks
	// t= 0.0002
	TL0 = 0x50;
	TH0 = 0xFB;

	// t = 0.001
	TL0 = 0x90;
	TH0 = 0xE8;
	*/

#endif
	//TMOD = 0x000;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
}

void timerInit(void)
{
	timer0Init();
	//timer1Init();
	EA = 1;
}

void timer0_isr(void) __interrupt 1
{
	displayRefresh();
	keytest++;
	if( keytest > 36 ) {
	 	keytest = 0;
		CheckBtn();
	 }
}

// void timer1_isr(void) __interrupt 3
// {

// 	return;
// }