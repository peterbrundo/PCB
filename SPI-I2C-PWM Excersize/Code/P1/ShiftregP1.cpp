#include "ShiftregP1.h"
#include "Arduino.h"

//todo: 
//replace PORTDx with defintion (DONE)
//replace bitRead with mask -going to put this off for a bit (pun intended looool)

ShiftregP1::ShiftregP1(){
	DDRD |= (1 << SRCLR) | (1 << SRCLK) | (1 << RCLK) | (1 << NOE) | (1 << SER);
	PORTD |= (1 << SRCLR) | (0 << SRCLK) | (0 << RCLK) | (0 << NOE);
	}
	
void ShiftregP1::registerShiftThenenable(byte input, int wamjam){
clearBoard();
//disable output
PORTD |= (1<NOE);
//throw input byte onto the register
for (int i = 0;i<8;i++){
  if (bitRead(input,i) == 0){
    PORTD |= (1<<SER);
  }
  else{
    PORTD &= ~(1<<SER);
  }
}
//delay
delay(wamjam);
//enable output
PORTD &= ~(1<NOE);
} 
void ShiftregP1::backwards(byte input){
clearBoard();
 
  int index = 3;
  for (int i = 7;i>-1;i--){
    if (index == 3){
      if (bitRead(input, i)==1){
        PORTD |= (1<<SER);
      }
      else if (bitRead(input, i)==0){
        //PORTD |=(0<<SER);
      }
      
    }
    else if (index != 3 && bitRead(input,i) == 1 && bitRead(input, i+1) != 1){
      PORTD ^= (1<<SER);
	  //1
	  //10000000
	  //previous value of PORTD in bit 7 is 1
	  //result is 
	  
	  //0x00
	 //
	 
	 //previous of PORTD in bit 7 is 0x00
	 
	 //result is 1
      index =0;
    }
    else if (index != 3 && bitRead(input,i) == 1 && bitRead(input, i+1) == 1){
     index =0;
    }
    else if (index != 3 && bitRead(input,i) == 0 && bitRead(input,i+1) != 0){
      PORTD ^=(1<<SER);
      
      index =0;
      }
      else if (index != 3 && bitRead(input,i) == 0 && bitRead(input, i+1) == 0){
      index =0;
    }
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    index = 0;
  }
  PORTD ^= (1<<SRCLK) | (1<<RCLK);
  PORTD ^= (1<<SRCLK) | (1<<RCLK);
  //while (true);

}

void ShiftregP1::forwards(byte input){
	clearBoard();
  int index = 3;byte previousVal = 0x00;
  for (int i = 0;i<8;i++){
	  
	previousVal = PORTD;
    if (index == 3){
      if (bitRead(input, i)==1){
        PORTD |= (1<<SER);
      }
      else if (bitRead(input, i)==0){
        //PORTD |=(0<<SER);
      }
      index =0;
    }
    else if (bitRead(input,i) == 1 && bitRead(input, i-1) == 0){
      PORTD ^= (1<<SER);
    }
    else if (bitRead(input,i) == 0 && bitRead(input, i-1) == 1){
     PORTD ^=(1<<SER);
    }
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
  }
  PORTD ^= (1<<SRCLK) | (1<<RCLK);
  PORTD ^= (1<<SRCLK) | (1<<RCLK);
  //while (true);
}

void ShiftregP1::clockOnce(){
	
  PORTD ^= (1<<SRCLK) | (1<<RCLK);
  PORTD ^= (1<<SRCLK) | (1<<RCLK);
}
void ShiftregP1::clearBoard(){
byte previousValue = PORTD;


//for loop purpose:  we are going to look at each value of the previous PORTD value
//for each bit, we need to see if the value needs to be toggled,
//if the bit value equals the previous, then we do NOT toggle AND we send a clock pulse
//however, if the bit value != the previous, then we toggle AND we send a clock pulse

		bitClear(previousValue,0);
		PORTD = previousValue;
	for (int i = 0;i<8;i++){
		
		
		
		
		PORTD ^= (1<<SRCLK) | (1<<RCLK);
		PORTD ^= (1<<SRCLK) | (1<<RCLK);
		
	}//END FORLOOP
	
	//send a last clock pulse
		PORTD ^= (1<<SRCLK) | (1<<RCLK);
		PORTD ^= (1<<SRCLK) | (1<<RCLK);
		
}


void ShiftregP1::hello(){
	DDRB |= (1 << DDB5) | (1 << DDB4) | (1 << DDB3) | (1 << DDB2) | (1 << DDB1) | (1 << DDB0);

	delay(100);
    //digitalWrite(SER_u8_b0, HIGH);
    PORTD ^= (1<<SER);
      //clockit();
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
	PORTD ^= (0<<SER);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
	PORTD ^= (1<<SER);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //digitalWrite(SER_u8_b0, LOW);
    PORTD ^= (0<<SER);
    //clockit();
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
	PORTD ^= (1<<SER);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    //clockit();
    PORTD ^= (1<<SRCLK) | (1<<RCLK);
    PORTD ^= (1<<SRCLK) | (1<<RCLK);

  
  delay(1000);
}
