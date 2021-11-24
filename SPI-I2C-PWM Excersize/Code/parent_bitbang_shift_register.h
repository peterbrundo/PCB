#ifndef parent_bitbang_shift_register_h
#define parent_bitbang_shift_register_h

#include "Arduino.h"

#define SER 0
#define  NOE 1
#define  RCLK 2
#define  SRCLK 4
#define  SRCLR 7

#define mask_bit_0 0x01
#define mask_bit_1 0x02
#define mask_bit_2 0x04
#define mask_bit_3 0x08
#define mask_bit_4 0x10
#define mask_bit_5 0x20
#define mask_bit_6 0x40
#define mask_bit_7 0x80


class parent_bitbang_shift_register{
	public:
	parent_bitbang_shift_register();
	void parent_shiftbyte(byte setByte);
	void parent_clearboard();
	void parent_shiftbyte_lsb(byte setByte);
	
	private:
};

#endif