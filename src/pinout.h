#ifndef _PINOUT_H_
#define _PINOUT_H_

#include "stc15.h"

#define row0 P0_0
#define row1 P0_1
#define row2 P0_2
#define row3 P0_3
#define row4 P0_4
#define row5 P0_5
#define row6 P0_6
#define row7 P0_7

#define col00  P2_0
#define col01  P2_1
#define col02  P2_2
#define col03  P2_3
#define col04  P2_4
#define col05  P2_5
#define col06  P2_6
#define col07  P2_7
#define col08  P3_4
#define col09  P3_5
#define col10  P3_6
#define col11  P3_7
#define col12  P4_1
#define col13  P4_2
#define col14  P4_3
#define col15  P4_4
#define col16  P1_0
#define col17  P1_1
#define col18  P4_7
#define col19  P1_2
#define col20  P1_3
#define col21  P3_2
#define col22  P4_5
#define col23  P4_6

#define DS1302_CE  P4_0	// RTC CE
#define DS1302_IO  P1_5	// RTC I/O
#define DS1302_SCLK  P5_5	// RTC SCLK

#define key_s1  P3_1	//  +  key
#define key_s2  P3_3	//  -  key

#define beep  P5_4	// beeper

__sbit __at 0xE0 ACC0;
__sbit __at 0xE7 ACC7;

#endif /* _PINOUT_H_ */
