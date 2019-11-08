#include "stc15.h"
#include <stdbool.h>

#define BAUDRATE 9600
#define  FOSC 6000000

void uart1_init()
{
    //P_SW1 |= (1<<6); // swap UART1 pins -> P3_6:rxd, P3_7:txd
    
    // UART1 use Timer2
    T2L = (65536 - (FOSC/4/BAUDRATE)) & 0xFF;
    T2H = (65536 - (FOSC/4/BAUDRATE)) >> 8;

    SM1 = 1;        // serial mode 1: 8-bit async
    AUXR |= 0x14;   // T2R: run T2, T2x12: T2 clk src sysclk/1
    AUXR |= 0x01;   // S1ST2: T2 is baudrate generator

    ES = 1;         // enable uart1 interrupt
    //EA = 1;         // enable interrupts
    REN = 1;        // rx enable
}

void uart1_isr() __interrupt 4
{

    if (RI)
    {
        // do something with rx bytes?
        RI = 0; //clear rx int      
    }

}

int putchar(int c)
{
    SBUF = c;       // put byte in buf
    while (! TI);
    TI = 0;
    return 0;    
}

int getchar() {
    char c;
    while (!RI)
      ;
    RI=0;
    c=SBUF;
    return c;
  }
  