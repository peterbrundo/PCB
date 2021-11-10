/*

1. needs to set DDRB 0-5
2. needs to put data on SER
3. needs to clock

strat
take a byte
disect the byte
shift it into a register
*/


#ifndef ShiftregP1_h
#define ShiftregP1_h

#include "Arduino.h"

/*
definitions from first shift register board I made
#define SER_u8_b0 8
#define NOE_u9_b1 9
#define RCLK_u10_b2 10
#define SRCLK_u11_b3 11
#define SRCLR_u12_b4 12
#define QH_u13_b5 13
*/

#define SER 0
#define NOE 1
#define RCLK 2
#define SRCLK 4
#define SRCLR 7

class ShiftregP1{
	public:
	ShiftregP1();
	void hello();
	void clearboardpin();
	void clearBoard();
	void backwards(byte input);
	void forwards(byte input);
	private:
	void clockOnce();
	void registerShiftThenenable(byte input, int wamjam);
};

#endif

