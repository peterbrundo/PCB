#ifndef bitbang_shift_register_h
#define bitbang_shift_register_h

#include "Arduino.h"

#define SER 0
#define  NOE 1
#define  RCLK 2
#define  SRCLK 3
#define  SRCLR 4

#define mask_bit_0 0x01
#define mask_bit_1 0x02
#define mask_bit_2 0x04
#define mask_bit_3 0x08
#define mask_bit_4 0x10
#define mask_bit_5 0x20
#define mask_bit_6 0x40
#define mask_bit_7 0x80


class bitbang_shift_register{
	public:
	bitbang_shift_register();
	void shiftbyte(byte setByte);
	void clearboard();
	void shiftbyte_lsb(byte setByte);
	
	private:
};

#endif