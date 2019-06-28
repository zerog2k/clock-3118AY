#include "fonts.h"

const uint8_t dot_font[] = {
	0x00,0x00,0x00,0x00,	//""
	0x00,0x08,0x08,0x00,	//"-"
	0x00,0x1C,0x1C,0x00,	//""
	0x00,0x36,0x36,0x00,	//"::"
	0x00,0x24,0x36,0x00,	//""
	0x00,0x24,0x24,0x00,	//""
	0x00,0x24,0x00,0x00,	//""
	0x00,0x30,0x30,0x00,	//""
	0x00,0x06,0x06,0x00,	//""
};

const uint8_t temperature_font[] = {
	0x7F,0x7F,0x41,0x7F,0x7F,	//"0"
	0x00,0x00,0x7F,0x7F,0x00,	//"1"
	0x0F,0x4F,0x49,0x79,0x79,	//"2"
	0x41,0x49,0x49,0x7F,0x7F,	//"3"
	0x78,0x78,0x08,0x7F,0x7F,	//"4"
	0x79,0x79,0x49,0x4F,0x0F,	//"5"
	0x7F,0x7F,0x49,0x4F,0x0F,	//"6"
	0x40,0x40,0x40,0x7F,0x7F,	//"7"
	0x7F,0x7F,0x49,0x7F,0x7F,	//"8"
	0x78,0x79,0x49,0x7F,0x7F,	//"9"
	0x30,0x40,0x45,0x48,0x30,	//"?"
	0x70,0x50,0x70,0x00,0x3E,0x7F,0x63,0x41,0x41, // "° C"
};

const uint8_t num_font1[] = {
	0x7F,0x41,0x41,0x7F,	//"0"
	0x00,0x00,0x7F,0x00,	//"1"
	0x4F,0x49,0x49,0x79,	//"2"
	0x49,0x49,0x49,0x7F,	//"3"
	0x78,0x08,0x08,0x7F,	//"4"
	0x79,0x49,0x49,0x4F,	//"5"
	0x7F,0x49,0x49,0x4F,	//"6"
	0x40,0x40,0x40,0x7F,	//"7"
	0x7F,0x49,0x49,0x7F,	//"8"
	0x79,0x49,0x49,0x7F,	//"9"
};

const uint8_t num_font2[] = {
	0x3E,0x45,0x41,0x3E,	//"0"
	0x00,0x21,0x7F,0x01,	//"1"
	0x23,0x45,0x49,0x31,	//"2"
	0x42,0x51,0x69,0x46,	//"3"
	0x0C,0x14,0x24,0x5F,	//"4"
	0x72,0x51,0x51,0x4E,	//"5"
	0x1E,0x29,0x49,0x06,	//"6"
	0x40,0x4F,0x50,0x60,	//"7"
	0x36,0x7F,0x49,0x36,	//"8"
	0x30,0x49,0x4A,0x3C,	//"9"
};

/*code uint8_t num_font1[] = {
	0x3E,0x51,0x45,0x3E,	//"0"
	0x00,0x21,0x7F,0x01,	//"1"
	0x23,0x45,0x49,0x31,	//"2"
	0x22,0x49,0x59,0x2E,	//"3"
	0x0C,0x14,0x24,0x7F,	//"4"
	0x72,0x51,0x51,0x4E,	//"5"
	0x0E,0x19,0x29,0x46,	//"6"
	0x40,0x4F,0x50,0x60,	//"7"
	0x36,0x49,0x49,0x36,	//"8"
	0x32,0x49,0x49,0x3E,	//"9"
	0x00,0x36,0x36,0x00,	//"::"
	0x00,0x08,0x08,0x00,	//"--"
	0x70,0x50,0x70,0x00,0x1C,0x3E,0x63,0x63,0x63,0x22,0x00,	//"??C"
}
;*/

const uint8_t num_font3[] = {
	0x7E,0x41,0x41,0x3F,	//"0"
	0x00,0x40,0x7F,0x00,	//"1"
	0x0F,0x49,0x49,0x39,	//"2"
	0x49,0x49,0x49,0x3E,	//"3"
	0x7C,0x04,0x04,0x1F,	//"4"
	0x78,0x49,0x49,0x0F,	//"5"
	0x7F,0x49,0x49,0x07,	//"6"
	0x60,0x40,0x40,0x3F,	//"7"
	0x7E,0x49,0x49,0x3F,	//"8"
	0x78,0x49,0x49,0x3F,	//"9"
};

const uint8_t num_font4[] = {
	0x7F,0x63,0x63,0x7F,	//"0"
	0x00,0x60,0x7F,0x00,	//"1"
	0x6F,0x6B,0x6B,0x7B,	//"2"
	0x6B,0x6B,0x6B,0x7F,	//"3"
	0x78,0x78,0x08,0x7F,	//"4"
	0x7B,0x7B,0x4B,0x4F,	//"5"
	0x7F,0x7F,0x49,0x4F,	//"6"
	0x40,0x40,0x7F,0x7F,	//"7"
	0x7F,0x6B,0x6B,0x7F,	//"8"
	0x79,0x69,0x49,0x7F,	//"9"
};

const uint8_t num_font5[] = {
	0x00,0x7F,0x41,0x7F,	//"0"
	0x00,0x00,0x7F,0x00,	//"1"
	0x00,0x4F,0x49,0x79,	//"2"
	0x00,0x49,0x49,0x7F,	//"3"
	0x00,0x78,0x08,0x7F,	//"4"
	0x00,0x79,0x49,0x4F,	//"5"
	0x00,0x7F,0x49,0x4F,	//"6"
	0x00,0x40,0x40,0x7F,	//"7"
	0x00,0x7F,0x49,0x7F,	//"8"
	0x00,0x79,0x49,0x7F,	//"9"
};


const uint8_t font_cp1251_07[] = {
	0x00, 0x00, 0x00, 0x00, VOID,		// 0x20 =>
	0x7D, VOID, VOID, VOID, VOID,		// 0x21 => !
	0x70, 0x00, 0x70, VOID, VOID,		// 0x22 => "
	0x14, 0x7F, 0x14, 0x7F, 0x14,		// 0x23 => #
	0x12, 0x2A, 0x7F, 0x2A, 0x24,		// 0x24 => $
	0x62, 0x64, 0x08, 0x13, 0x23,		// 0x25 => %
	0x36, 0x49, 0x55, 0x22, 0x05,		// 0x26 => &
	0x50, 0x60, VOID, VOID, VOID,		// 0x27 => '
	0x1C, 0x22, 0x41, VOID, VOID,		// 0x28 => (
	0x41, 0x22, 0x1C, VOID, VOID,		// 0x29 => )
	0x14, 0x08, 0x3E, 0x08, 0x14,		// 0x2A => *
	0x08, 0x08, 0x3E, 0x08, 0x08,		// 0x2B => +
	0x05, 0x06, VOID, VOID, VOID,		// 0x2C => ,
	0x04, 0x04, 0x04, 0x04, VOID,		// 0x2D => -
	/* 0x08, 0x08, 0x08, 0x08, VOID,		// 0x2D => - */
	0x01, VOID, VOID, VOID, VOID,		// 0x2E => .
	/* 0x03, 0x03, VOID, VOID, VOID,		// 0x2E => . */
	0x02, 0x04, 0x08, 0x10, 0x20,		// 0x2F => /

	0x3E, 0x41, 0x41, 0x3E, VOID,		// 0x30 => 0
	0x00, 0x21, 0x7F, 0x01, VOID,		// 0x31 => 1
	0x21, 0x43, 0x45, 0x39, VOID,		// 0x32 => 2
	0x22, 0x41, 0x49, 0x36, VOID,		// 0x33 => 3
	0x0C, 0x14, 0x24, 0x7F, VOID,		// 0x34 => 4
	0x72, 0x51, 0x51, 0x4E, VOID,		// 0x35 => 5
	0x3E, 0x49, 0x49, 0x26, VOID,		// 0x36 => 6
	0x40, 0x47, 0x48, 0x70, VOID,		// 0x37 => 7
	0x36, 0x49, 0x49, 0x36, VOID,		// 0x38 => 8
	0x32, 0x49, 0x49, 0x3E, VOID,		// 0x39 => 9
	0x12, VOID, VOID, VOID, VOID,		// 0x3A => :
	0x01, 0x12, VOID, VOID, VOID,		// 0x3B => ;
	0x08, 0x14, 0x22, 0x41, VOID,		// 0x3C => <
	0x14, 0x14, 0x14, 0x14, 0x14,		// 0x3D => =
	0x41, 0x22, 0x14, 0x08, VOID,		// 0x3E => >
	0x20, 0x40, 0x45, 0x48, 0x30,		// 0x3F => ?

	0x3E, 0x41, 0x5D, 0x55, 0x3C,		// 0x40 => @
	0x1F, 0x24, 0x44, 0x24, 0x1F,		// 0x41 => A
	0x7F, 0x49, 0x49, 0x49, 0x36,		// 0x42 => B
	0x3E, 0x41, 0x41, 0x41, 0x22,		// 0x43 => C
	0x7F, 0x41, 0x41, 0x22, 0x1C,		// 0x44 => D
	0x7F, 0x49, 0x49, 0x49, 0x41,		// 0x45 => E
	0x7F, 0x48, 0x48, 0x48, 0x40,		// 0x46 => F	
	0x3E, 0x41, 0x49, 0x49, 0x2F,		// 0x47 => G
	0x7F, 0x08, 0x08, 0x08, 0x7F,		// 0x48 => H
	0x41, 0x7F, 0x41, VOID, VOID,		// 0x49 => I
	0x02, 0x01, 0x41, 0x7E, 0x40,		// 0x4A => J
	0x7F, 0x08, 0x14, 0x22, 0x41,		// 0x4B => K
	0x7F, 0x01, 0x01, 0x01, VOID,		// 0x4C => L
	0x7F, 0x20, 0x18, 0x20, 0x7F,		// 0x4D => M
	0x7F, 0x10, 0x08, 0x04, 0x7F,		// 0x4E => N
	0x3E, 0x41, 0x41, 0x41, 0x3E,		// 0x4F => O

	0x7F, 0x48, 0x48, 0x48, 0x30,		// 0x50 => P
	0x3E, 0x41, 0x45, 0x42, 0x3D,		// 0x51 => Q
	0x7F, 0x48, 0x4C, 0x4A, 0x31,		// 0x52 => R
	0x32, 0x49, 0x49, 0x49, 0x26,		// 0x53 => S
	0x40, 0x40, 0x7F, 0x40, 0x40,		// 0x54 => T
	0x7E, 0x01, 0x01, 0x01, 0x7E,		// 0x55 => U
	0x70, 0x0C, 0x03, 0x0C, 0x70,		// 0x56 => V
	0x7E, 0x01, 0x0E, 0x01, 0x7E,		// 0x57 => W
	0x63, 0x14, 0x08, 0x14, 0x63,		// 0x58 => X
	0x70, 0x08, 0x07, 0x08, 0x70,		// 0x59 => Y
	0x43, 0x45, 0x49, 0x51, 0x61,		// 0x00 => Z
	0x7F, 0x41, 0x41, VOID, VOID,		// 0x5B => [
	0x0C, 0x12, 0x3F, 0x12, 0x04,		// 0x5C => �
	0x41, 0x41, 0x7F, VOID, VOID,		// 0x5D => ]
	0x10, 0x20, 0x40, 0x20, 0x10,		// 0x5E => ^
	0x01, 0x01, 0x01, 0x01, 0x01,		// 0x5F => -

	0x40, 0x20, VOID, VOID, VOID,		// 0x60 => `
	0x02, 0x15, 0x15, 0x15, 0x0F,		// 0x61 => a
	0x7F, 0x09, 0x11, 0x11, 0x0E,		// 0x62 => b
	0x0E, 0x11, 0x11, 0x11, 0x02,		// 0x63 => c
	0x0E, 0x11, 0x11, 0x09, 0x7F,		// 0x64 => d
	0x0E, 0x15, 0x15, 0x15, 0x0C,		// 0x65 => e
	0x08, 0x3F, 0x48, 0x40, 0x20,		// 0x66 => f
	0x18, 0x25, 0x25, 0x25, 0x3E,		// 0x67 => g
	0x7F, 0x08, 0x10, 0x10, 0x0F,		// 0x68 => h
	0x11, 0x5F, 0x01, VOID, VOID,		// 0x69 => i
	0x02, 0x01, 0x11, 0x5E, VOID,		// 0x6A => j
	0x7F, 0x04, 0x0A, 0x11, VOID,		// 0x6B => k
	0x41, 0x7F, 0x01, VOID, VOID,		// 0x6C => l
	0x1F, 0x10, 0x0C, 0x10, 0x0F,		// 0x6D => m
	0x1F, 0x08, 0x10, 0x0F, VOID,		// 0x6E => n
	0x0E, 0x11, 0x11, 0x11, 0x0E,		// 0x6F => o

	0x3F, 0x24, 0x22, 0x22, 0x1C,		// 0x70 => p
	0x1C, 0x22, 0x22, 0x24, 0x3F,		// 0x71 => q
	0x1F, 0x08, 0x10, 0x08, VOID,		// 0x72 => r
	0x08, 0x15, 0x15, 0x15, 0x02,		// 0x73 => s
	0x10, 0x7E, 0x11, 0x01, 0x02,		// 0x74 => t
	0x1E, 0x01, 0x01, 0x02, 0x1F,		// 0x75 => u
	0x18, 0x06, 0x01, 0x06, 0x18,		// 0x76 => v
	0x1E, 0x01, 0x06, 0x01, 0x1E,		// 0x77 => w
	0x11, 0x0A, 0x04, 0x0A, 0x11,		// 0x78 => x
	0x18, 0x05, 0x05, 0x05, 0x1E,		// 0x79 => y
	0x11, 0x13, 0x15, 0x19, 0x11,		// 0x7A => z
	0x08, 0x36, 0x41, VOID, VOID,		// 0x7B => {
	0x7F, VOID, VOID, VOID, VOID,		// 0x7C => |
	0x41, 0x36, 0x08, VOID, VOID,		// 0x7D => }
	0x08, 0x10, 0x08, 0x10, VOID,		// 0x7E => ~
	VOID, VOID, VOID, VOID, VOID,		// 0x7F =>

//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x80 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x81 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x82 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x83 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x84 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x85 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x86 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x87 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x88 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x89 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x8A =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x8B =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x8C =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x8D =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x8E =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x8F =>

//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x90 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x91 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x92 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x93 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x94 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x95 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x96 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x97 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x98 =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// IDLE =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x9A =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x9B =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x9C =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x9D =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x9E =>
//	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0x9F =>

	0x02, 0x1E, 0x3F, 0x1E, 0x02,		// 0xA0 => BELL
	0x30, 0x49, 0x29, 0x49, 0x36,		// 0xA1 => ?
	0x18, 0x45, 0x25, 0x45, 0x1E,		// 0xA2 => ?
	0x02, 0x01, 0x41, 0x7E, 0x40,		// 0xA3 => ?
	0x2A, 0x1C, 0x77, 0x1C, 0x2A,		// 0xA4 => �
	0x3F, 0x20, 0x20, 0x20, 0x60,		// 0xA5 => ?
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xA6 =>
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xA7 =>
	0x3F, 0x69, 0x29, 0x69, 0x21,		// 0xA8 => ?
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xA9 =>
	0x3E, 0x49, 0x49, 0x41, 0x22,		// 0xAA => ?
	0x08, 0x14, 0x2A, 0x14, 0x22,		// 0xAB => �
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xAC =>
	0x1E, 0x29, 0x27, 0x21, 0x1E,		// 0xAD => CLOCK
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xAE =>
	0x41, 0x3F, 0x41, VOID, VOID,		// 0xAF => ?

	0x00, 0x30, 0x48, 0x48, 0x30,		// 0xB0 => �
	0x09, 0x09, 0x7D, 0x09, 0x09,		// 0xB1 => �
	0x41, 0x7F, 0x41, VOID, VOID,		// 0xB2 => ?
	0x11, 0x5F, 0x01, VOID, VOID,		// 0xB3 => ?
	0x1F, 0x10, 0x10, 0x58, VOID,		// 0xB4 => ?
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xB5 =>
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xB6 =>
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xB7 =>
	0x0E, 0x55, 0x15, 0x55, 0x0C,		// 0xB8 => ?
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xB9 =>
	0x0E, 0x15, 0x15, 0x11, 0x0A,		// 0xBA => ?
	0x22, 0x14, 0x2A, 0x14, 0x08,		// 0xBB => �
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xBC =>
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xBD =>
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F,		// 0xBE =>
	0x51, 0x1F, 0x51, VOID, VOID,		// 0xBF => ?

	0x3F, 0x44, 0x44, 0x44, 0x3F,		// 0xC0 => �
	0x7F, 0x49, 0x49, 0x49, 0x46,		// 0xC1 => �
	0x7F, 0x49, 0x49, 0x49, 0x36,		// 0xC2 => �
	0x7F, 0x40, 0x40, 0x40, 0x60,		// 0xC3 => �
	0x03, 0x3E, 0x42, 0x7E, 0x03,		// 0xC4 => �
	0x7F, 0x49, 0x49, 0x49, 0x41,		// 0xC5 => �
	0x77, 0x08, 0x7F, 0x08, 0x77,		// 0xC6 => �
	0x41, 0x49, 0x49, 0x49, 0x36,		// 0xC7 => �
	0x7F, 0x04, 0x08, 0x10, 0x7F,		// 0xC8 => �
	0x3F, 0x02, 0x64, 0x08, 0x3F,		// 0xC9 => �
	0x7F, 0x08, 0x14, 0x22, 0x41,		// 0xCA => �
	0x01, 0x1E, 0x20, 0x40, 0x7F,		// 0xCB => �
	0x7F, 0x20, 0x18, 0x20, 0x7F,		// 0xCC => �
	0x7F, 0x08, 0x08, 0x08, 0x7F,		// 0xCD => �
	0x3E, 0x41, 0x41, 0x41, 0x3E,		// 0xCE => �
	0x7F, 0x40, 0x40, 0x40, 0x7F,		// 0xCF => �
										            
	0x7F, 0x48, 0x48, 0x48, 0x30,		// 0xD0 => �
	0x3E, 0x41, 0x41, 0x41, 0x22,		// 0xD1 => �
	0x40, 0x40, 0x7F, 0x40, 0x40,		// 0xD2 => �
	0x70, 0x09, 0x09, 0x09, 0x7E,		// 0xD3 => �
	0x3C, 0x42, 0xFF, 0x42, 0x3C,		// 0xD4 => �
	0x63, 0x14, 0x08, 0x14, 0x63,		// 0xD5 => �
	0x7F, 0x01, 0x01, 0x7F, 0x01,		// 0xD6 => �
	0x70, 0x08, 0x08, 0x08, 0x7F,		// 0xD7 => �
	0x7F, 0x01, 0x7F, 0x01, 0x7F,		// 0xD8 => �
	0x7E, 0x02, 0x7E, 0x02, 0x7F,		// 0xD9 => �
	0x40, 0x7F, 0x09, 0x09, 0x06,		// 0xDA => �
	0x7F, 0x09, 0x06, 0x00, 0x7F,		// 0xDB => �
	0x7F, 0x09, 0x11, 0x11, 0x0E,		// 0xDC => �
	0x22, 0x41, 0x49, 0x49, 0x3E,		// 0xDD => �
	0x7F, 0x08, 0x3E, 0x41, 0x3E,		// 0xDE => �
	0x31, 0x4A, 0x4C, 0x48, 0x7F,		// 0xDF => �
										            
	0x02, 0x15, 0x15, 0x15, 0x0F,		// 0xE0 => �
	0x1E, 0x29, 0x29, 0x49, 0x06,		// 0xE1 => �
	0x1F, 0x15, 0x15, 0x0A, VOID,		// 0xE2 => �
	0x1F, 0x10, 0x10, 0x18, VOID,		// 0xE3 => �
	0x03, 0x0E, 0x12, 0x1E, 0x03,		// 0xE4 => �
	0x0E, 0x15, 0x15, 0x15, 0x0C,		// 0xE5 => �
	0x1B, 0x04, 0x1F, 0x04, 0x1B,		// 0xE6 => �
	0x11, 0x15, 0x15, 0x0A, VOID,		// 0xE7 => �
	0x1F, 0x02, 0x04, 0x08, 0x1F,		// 0xE8 => �
	0x1F, 0x42, 0x24, 0x48, 0x1F,		// 0xE9 => �
	0x1F, 0x04, 0x0A, 0x11, VOID,		// 0xEA => �
	0x07, 0x08, 0x10, 0x1F, VOID,		// 0xEB => �
	0x1F, 0x08, 0x04, 0x08, 0x1F,		// 0xEC => �
	0x1F, 0x04, 0x04, 0x1F, VOID,		// 0xED => �
	0x0E, 0x11, 0x11, 0x11, 0x0E,		// 0xEE => �
	0x1F, 0x10, 0x10, 0x1F, VOID,		// 0xEF => �
										            
	0x1F, 0x14, 0x12, 0x12, 0x0C,		// 0xF0 => �
	0x0E, 0x11, 0x11, 0x11, 0x02,		// 0xF1 => �
	0x10, 0x10, 0x1F, 0x10, 0x10,		// 0xF2 => �
	0x18, 0x05, 0x05, 0x05, 0x1E,		// 0xF3 => �
	0x0C, 0x12, 0x9F, 0x12, 0x0C,		// 0xF4 => �
	0x11, 0x0A, 0x04, 0x0A, 0x11,		// 0xF5 => �
	0x1F, 0x01, 0x01, 0x1F, 0x01,		// 0xF6 => �
	0x18, 0x04, 0x04, 0x1F, VOID,		// 0xF7 => �
	0x1F, 0x01, 0x1F, 0x01, 0x1F,		// 0xF8 => �
	0x1E, 0x02, 0x1E, 0x02, 0x1F,		// 0xF9 => �
	0x10, 0x1F, 0x05, 0x05, 0x02,		// 0xFA => �
	0x1F, 0x05, 0x02, 0x00, 0x1F,		// 0xFB => �
	0x1F, 0x05, 0x05, 0x02, VOID,		// 0xFC => �
	0x0A, 0x11, 0x15, 0x15, 0x0E,		// 0xFD => �
	0x1F, 0x04, 0x0E, 0x11, 0x0E,		// 0xFE => �
	0x08, 0x15, 0x16, 0x14, 0x1F,		// 0xFF => �
};
