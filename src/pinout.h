#ifndef _PINOUT_H_
#define _PINOUT_H_

#include "stc15.h"
#include <stdint.h>

#define row0 P0_0
#define row1 P0_1
#define row2 P0_2
#define row3 P0_3
#define row4 P0_4
#define row5 P0_5
#define row6 P0_6
#define row7 P0_7

#define ROW_PORT P0
#define ROW_LENGTH 8

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

#define COL_LENGTH 24

#define ROW_MASK_P0 0b11111111
#define ALL_ROWS_HIGH() P0 = ROW_MASK_P0;
#define ALL_ROWS_LOW()  P0 = ~ROW_MASK_P0;

#define COL_MASK_P1 0b00001111
#define COL_MASK_P2 0b11111111
#define COL_MASK_P3 0b11110100
#define COL_MASK_P4 0b11111110

#define MODE_CONFIG_P0()  P0M0 = 0b11111111; P0M1 = 0;  // push/pull
#define MODE_CONFIG_P1()  P1M0 &= ~COL_MASK_P1; P1M1 &= ~COL_MASK_P1;  // quasi-bidirectional, weak high, strong low
#define MODE_CONFIG_P2()  P2M0 &= ~COL_MASK_P2; P2M1 &= ~COL_MASK_P2;  // 
#define MODE_CONFIG_P3()  P3M0 &= ~COL_MASK_P3; P3M1 &= ~COL_MASK_P3;  // 
#define MODE_CONFIG_P4()  P4M0 &= ~COL_MASK_P4; P4M1 &= ~COL_MASK_P4;  // 

#define MODE_CONFIG_ALL_PORTS() MODE_CONFIG_P0(); MODE_CONFIG_P1(); MODE_CONFIG_P2(); MODE_CONFIG_P3(); MODE_CONFIG_P4();

#define ALL_COLS_HIGH() P1 |= COL_MASK_P1; P2 |= COL_MASK_P2; P3 |= COL_MASK_P3; P4 |= COL_MASK_P4;
#define ALL_COLS_LOW()  P1 &= ~COL_MASK_P1; P2 &= ~COL_MASK_P2; P3 &= ~COL_MASK_P3; P4 &= ~COL_MASK_P4;

#define DS1302_CE  P4_0	// RTC CE
#define DS1302_IO  P1_5	// RTC I/O
#define DS1302_SCLK  P5_5	// RTC SCLK
#define _DS_IO  _P1_5
#define _DS_SCLK _P5_5

#define key_s1  P3_1	//  +  key
#define key_s2  P3_3	//  -  key

#define beep  P5_4	// beeper

__sbit __at 0xE0 ACC0;
__sbit __at 0xE7 ACC7;

#endif /* _PINOUT_H_ */
