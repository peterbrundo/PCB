#include "bitbang_shift_register.h"
#include "Arduino.h"


bitbang_shift_register::bitbang_shift_register(){
	//set outputs
	//SER 0
	//NOE 1
	//RCLK 2
	//SRCLK 3
	//SRCLR 4
	DDRD |= (1 << SRCLR) | (1 << SRCLK) | (1 << RCLK) | (1 << NOE) | (1 << SER);
	  
	//clear shift register clock and storage register clock
	PORTD &=  ~(1 << SRCLK);
	PORTD &=  ~(1 << RCLK);
	//disable output
	PORTD &=  ~(1 << NOE);
}
//shifts 8 bits onto the shift register, most significant byte first	
void bitbang_shift_register::shiftbyte(byte setByte){
	//clear the shift register, clear clocks, clear serial input
	PORTD &= ~(1 << SRCLK | 1 << RCLK | 1 << SER);
	//disable output
	PORTD |=  (1 << NOE | 1 << SRCLR);

	//7
	if ( setByte & mask_bit_7)  {PORTD |= (1 << SER);} //turn Serial input ON
	else{PORTD &= ~(1 << SER);} //turn Serial input OFF
	PORTD |= (1<<SRCLK); 
	PORTD &= ~(1<<SRCLK);
	//6
	if ( setByte & mask_bit_6)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);} 

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//5
	if ( setByte & mask_bit_5)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);} 

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//4
	if ( setByte & mask_bit_4)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);} 

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//3
	if ( setByte & mask_bit_3)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK); 
	PORTD &= ~(1<<SRCLK);
	//2
	if ( setByte & mask_bit_2)  {PORTD |= (1 << SER);}
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//1
	if ( setByte & mask_bit_1)  {PORTD |= (1 << SER);}
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK); 
	PORTD &= ~(1<<SRCLK);
	//0
	if ( setByte & mask_bit_0)  {PORTD |= (1 << SER);}
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);

	//the shift register always is one clock pulse ahead of the storage register
	PORTD |=(1<<RCLK);
	PORTD &= ~(1<<RCLK);

	PORTD &=  ~(1 << NOE); //enable output
  
}

//shifts 8 bits onto the shift register, least significant byte first
void bitbang_shift_register::shiftbyte_lsb(byte setByte){
	//clear the shift register, clear clocks, clear serial input
	PORTD &= ~(1 << SRCLK | 1 << RCLK | 1 << SER);
	//disable output
	PORTD |=  (1 << NOE | 1 << SRCLR);

	//0
	if ( setByte & mask_bit_0)  {PORTD |= (1 << SER);} //turn Serial input ON
	else{PORTD &= ~(1 << SER);} //turn Serial input OFF
	PORTD |= (1<<SRCLK); 
	PORTD &= ~(1<<SRCLK);
	//1
	if ( setByte & mask_bit_1)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);} 

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//2
	if ( setByte & mask_bit_2)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);} 

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//3
	if ( setByte & mask_bit_3)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);} 

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//4
	if ( setByte & mask_bit_4)  {PORTD |= (1 << SER);} 
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK); 
	PORTD &= ~(1<<SRCLK);
	//5
	if ( setByte & mask_bit_5)  {PORTD |= (1 << SER);}
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);
	//6
	if ( setByte & mask_bit_6)  {PORTD |= (1 << SER);}
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK); 
	PORTD &= ~(1<<SRCLK);
	//7
	if ( setByte & mask_bit_7)  {PORTD |= (1 << SER);}
	else{PORTD &= ~(1 << SER);}

	PORTD |= (1<<SRCLK);
	PORTD &= ~(1<<SRCLK);

	//the shift register always is one clock pulse ahead of the storage register
	PORTD |=(1<<RCLK);
	PORTD &= ~(1<<RCLK);

	PORTD &=  ~(1 << NOE); //enable output
}

//clears the board
void bitbang_shift_register::clearboard(){
	PORTD &= ~(1<<SRCLR);
}
	
	