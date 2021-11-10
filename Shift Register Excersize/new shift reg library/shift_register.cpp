#include "shift_register.h"
#include "Arduino.h"


//improvements / thoughts
//RCLK doesn't need to be constatntly toggled, only at the last (***implemented 11/9)
//there must be a clever way to do this without repeated if statements here (switch case or looped conidtional
//include a feature to toggle which bit gets sent first (bit0 vs bit7) *overkill



shift_register::shift_register(){
	  DDRD |= (1 << SRCLR) | (1 << SRCLK) | (1 << RCLK) | (1 << NOE) | (1<<SER);
	  PORTD |= (1 << SRCLR);
	  
	  PORTD &=  ~(1 << SRCLK);
	  
	  PORTD &=  ~(1 << RCLK);
	  
	  PORTD &=  ~(1 << NOE);

	}
	
void shift_register::shiftbite(byte setBit){
//Setup
PORTD &= ~(1<<SRCLK | 1<<RCLK | 1 << SER | 1<<SRCLR);//
//PORTD &= ~(1<<SRCLR);
PORTD |= (1<<SRCLR | 1 << NOE);
//PORTD |= (1 << NOE);
//PORTD &=  ~(1 << SER);

//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_7)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);


if ( setBit & mask_bit_6)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_5)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_4)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_3)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_2)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_1)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_0)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
//PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
//PORTD &= ~(1<<RCLK);
//end

PORTD |=(1<<RCLK);
PORTD &= ~(1<<RCLK);
PORTD |=(1<<RCLK);
PORTD &= ~(1<<RCLK);

  PORTD &=  ~(1 << NOE | 1 << SER);
  
  //PORTD &=  ~(1 << SER);
}

void shift_register::clearboard(){
PORTD &= ~(1<<SRCLR); //proof that srclr 
PORTD |= (1<<SRCLR);
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<RCLK);

}
	
	
void shift_register::clockOnce(){
PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

//should probably put an RCLK here b/c it's behind by one, but I don't use this anymore anyways so w/e
}
void shift_register::clockninsertx(int n, int x){
PORTD |= (1 << NOE);
  PORTD &=  ~(1 << SER);
  for (int i = 0;i<n;i++){
  if (i == x){PORTD |= (1 << SER);}
  else{PORTD &= ~(1 << SER);  }
    PORTD |= (1 << SRCLK) | (1 << RCLK);
    PORTD &= ~((1 << SRCLK) | (1 << RCLK));
    delay(1000);
    
  }
  
  PORTD |= ~(1 << RCLK);
  PORTD &= ~(1 << RCLK);
  
  
  PORTD &=  ~(1 << NOE);
  
  PORTD &=  ~(1 << SER);
}
void shift_register::clockntimes(int n){
  PORTD |= (1 << NOE);
  for (int i = 0; i < n; i++) {    
    PORTD |= (1 << SRCLK) | (1 << RCLK);
    PORTD &= ~((1 << SRCLK) | (1 << RCLK));
  }
  PORTD &=  ~(1 << NOE);
}
