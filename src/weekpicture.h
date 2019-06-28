#ifndef _WEEKPICTURE_H_
#define _WEEKPICTURE_H_

#include "sys.h"

#define LOCALE_US

// bytes are vertical columns, left to right
// https://xantorohara.github.io/led-matrix-editor is useful to visualize chars, although it provides c code with horizontal rows
// use transform_led_matrix.py to convert

// fonts for weekday
// TODO: combine all of this into single fonts

#ifdef LOCALE_US
#define _WD_A	0b00000000, 0b00111111, 0b01111111, 0b01001000, 0b01001000, 0b01111111, 0b00111111, 0b00000000
#define _WD_D	0b00000000, 0b01111111, 0b01111111, 0b01000001, 0b01000001, 0b01111111, 0b00111110, 0b00000000
#define _WD_E	0b00000000, 0b01111111, 0b01111111, 0b01001001, 0b01001001, 0b01001001, 0b01000001, 0b00000000
#define _WD_F	0b00000000, 0b01111111, 0b01111111, 0b01001000, 0b01001000, 0b01001000, 0b01000000, 0b00000000
#define _WD_H	0b00000000, 0b01111111, 0b01111111, 0b00001000, 0b00001000, 0b01111111, 0b01111111, 0b00000000
#define _WD_I	0b00000000, 0b00000000, 0b01000001, 0b01111111, 0b01111111, 0b01000001, 0b00000000, 0b00000000
#define _WD_M	0b00000000, 0b01111111, 0b01111111, 0b00110000, 0b00011000, 0b00110000, 0b01111111, 0b01111111
#define _WD_N	0b00000000, 0b01111111, 0b01111111, 0b00110000, 0b00011000, 0b00001100, 0b01111111, 0b01111111
#define _WD_O	0b00000000, 0b00111110, 0b01111111, 0b01000001, 0b01000001, 0b01111111, 0b00111110, 0b00000000
#define _WD_R	0b00000000, 0b01111111, 0b01111111, 0b01001100, 0b01001110, 0b01111011, 0b00110001, 0b00000000
#define _WD_S	0b00000000, 0b00110010, 0b01111011, 0b01001001, 0b01001001, 0b01101111, 0b00100110, 0b00000000
#define _WD_T	0b00000000, 0b01100000, 0b01000000, 0b01111111, 0b01111111, 0b01000000, 0b01100000, 0b00000000
#define _WD_U	0b00000000, 0b01111110, 0b01111111, 0b00000001, 0b00000001, 0b01111111, 0b01111111, 0b00000000
#define _WD_W	0b00000000, 0b01111111, 0b01111111, 0b00000110, 0b00001100, 0b00000110, 0b01111111, 0b01111111

const uint8_t   pic_mon[DISPLAYSIZE] = {_WD_M, _WD_O, _WD_N},
				pic_tue[DISPLAYSIZE] = {_WD_T, _WD_U, _WD_E},
				pic_wed[DISPLAYSIZE] = {_WD_W, _WD_E, _WD_D},
				pic_thu[DISPLAYSIZE] = {_WD_T, _WD_H, _WD_U},
				pic_fri[DISPLAYSIZE] = {_WD_F, _WD_R, _WD_I},
				pic_sat[DISPLAYSIZE] = {_WD_S, _WD_A, _WD_T},
				pic_sun[DISPLAYSIZE] = {_WD_S, _WD_U, _WD_N};

const uint8_t   *pic_alarm_mon = pic_mon,
				*pic_alarm_tue = pic_tue,
				*pic_alarm_wed = pic_wed,
				*pic_alarm_thu = pic_thu,
				*pic_alarm_fri = pic_fri,
				*pic_alarm_sat = pic_sat,
				*pic_alarm_sun = pic_sun;

#elif defined LOCALE_RU

#define _WD_P_ 0x7F,0x7F,0x40,0x40,0x7F,0x7F
#define _WD_N_ 0x7F,0x7F,0x08,0x08,0x7F,0x7F
#define _WD_D_ 0x03,0x1F,0x22,0x7E,0x7F,0x03
#define _WD_V_ 0x7F,0x7F,0x49,0x49,0x7F,0x36
#define _WD_T_ 0x40,0x40,0x7F,0x7F,0x40,0x40
#define _WD_R_ 0x7F,0x7F,0x48,0x48,0x78,0x30
#define _WD_S1_ 0x3E,0x7F,0x41,0x41,0x77,0x36
#define _WD_S_ 0x3E,0x7F,0x41,0x41,0x63,0x22
#define _WD_CH_ 0x70,0x78,0x08,0x08,0x7F,0x7F
#define _WD_U_ 0x60,0x73,0x1B,0x0F,0x7C,0x70
#define _WD_B_ 0x7F,0x7F,0x49,0x49,0x4F,0x46
#define _WD_K_ 0x7F,0x7F,0x08,0x14,0x63,0x63


const uint8_t pic_mon[24]={0x00,0x00,_WD_P_,0x00,_WD_N_,0x00,_WD_D_,0x00,0x00},
				pic_tue[24]={0x00,0x00,_WD_V_,0x00,_WD_T_,0x00,_WD_R_,0x00,0x00},
				pic_wed[24]={0x00,0x00,_WD_S_,0x00,_WD_R_,0x00,_WD_D_,0x00,0x00},
				pic_thu[24]={0x00,0x00,_WD_CH_,0x00,_WD_T_,0x00,_WD_V_,0x00,0x00},
				pic_fri[24]={0x00,0x00,_WD_P_,0x00,_WD_T_,0x00,_WD_N_,0x00,0x00},
				pic_sat[24]={0x00,0x00,_WD_S_,0x00,_WD_U_,0x00,_WD_B_,0x00,0x00},
				pic_sun[24]={0x00,0x00,_WD_V_,0x00,_WD_S_,0x00,_WD_K_,0x00,0x00}
		;

#define _AWD_P_ 0x7C,0x7C,0x40,0x40,0x7C,0x7C
#define _AWD_N_ 0x7C,0x7C,0x10,0x10,0x7C,0x7C
#define _AWD_D_ 0x0C,0x3C,0x48,0x78,0x7C,0x0C
#define _AWD_V_ 0x7C,0x7C,0x54,0x54,0x7C,0x28
#define _AWD_T_ 0x40,0x40,0x7C,0x7C,0x40,0x40
#define _AWD_R_ 0x7C,0x7C,0x50,0x50,0x70,0x20
#define _AWD_S_ 0x38,0x7C,0x44,0x44,0x6C,0x28
#define _AWD_CH_ 0x60,0x70,0x10,0x10,0x7C,0x7C
#define _AWD_U_ 0x64,0x74,0x1C,0x18,0x70,0x60
#define _AWD_B_ 0x7C,0x7C,0x54,0x54,0x5C,0x48
#define _AWD_K_ 0x7C,0x7C,0x10,0x38,0x6C,0x44

const uint8_t pic_alarm_mon[24]={0x00,_AWD_P_,0x00,_AWD_N_,0x00,_AWD_D_,0x00},
				pic_alarm_tue[24]={0x00,_AWD_V_,0x00,_AWD_T_,0x00,_AWD_R_,0x00},
				pic_alarm_wed[24]={0x00,_AWD_S_,0x00,_AWD_R_,0x00,_AWD_D_,0x00},
				pic_alarm_thu[24]={0x00,_AWD_CH_,0x00,_AWD_T_,0x00,_AWD_V_,0x00},
				pic_alarm_fri[24]={0x00,_AWD_P_,0x00,_AWD_T_,0x00,_AWD_N_,0x00},
				pic_alarm_sat[24]={0x00,_AWD_S_,0x00,_AWD_U_,0x00,_AWD_B_,0x00},
				pic_alarm_sun[24]={0x00,_AWD_V_,0x00,_AWD_S_,0x00,_AWD_K_,0x00}
		;
#endif // LOCALE_RU

#endif /* _WEEKPICTURE_H_ */
