//parent
#include <parent_bitbang_shift_register.h>
parent_bitbang_shift_register parent;

#define C3_LOW PORTB &= ~(CS3_PIN_MASK)
#define C3_HIGH PORTB |= (CS3_PIN_MASK)
#define C2_LOW PORTB &= ~(CS2_PIN_MASK)
#define C2_HIGH PORTB |= (CS2_PIN_MASK)
#define C1_LOW PORTB &= ~(CS1_PIN_MASK)
#define C1_HIGH PORTB |= (CS1_PIN_MASK)

//PORTB
       
#define CS3_PIN_MASK    0x01//PB0
#define CS2_PIN_MASK    0x02//PB1
#define CS1_PIN_MASK    0x04//PB2
#define POCI_MASK       0x08//PB3 
#define PICO_MASK       0x10//PB4 
#define SCK_MASK        0x20//PB5 
//xtal1                 0x40//PB6 
//xtal2                 0x80//PB7 
           
//PORTC

#define P1_POT1_MASK  0x01//PC0
#define CS_lDR_MASK   0x02//PC1
#define COM_lDR_MASK  0x04//PC2
#define BIT_LDR_MASK   0x08//PC3
#define SDA_MASK      0x10//PC4
#define SCL_MASK      0x20//PC5
//RESET               0x40//PC6
//N/A                 0x80//PC7

//PORTD

//P1 - SER           0x01//PD0
//P1 - OE            0x02//PD1
//P1 - RCLK          0x04//PD2
#define TX_BTN_MASK  0x08//PD3
//P1 - SRCLK         0x10//PD4
#define C2_OC0B_MASK 0x20//PD5
#define C3_OC0A_MASK 0x40//PD6
//P1 - SRCLR         0x80//PD7



int r2r_select = 0;
int currentbuttonstate = 0;
int prevbuttonstate = 1;
void setup() {


//CS pins as outputs, high by default
  DDRB |= (CS3_PIN_MASK | CS2_PIN_MASK | CS1_PIN_MASK);
  PORTB |= (CS3_PIN_MASK | CS2_PIN_MASK | CS1_PIN_MASK);  
/* Set POCI and SCK output*/

DDRB |= (POCI_MASK | SCK_MASK);
PORTB |= (POCI_MASK | SCK_MASK);

/* Enable SPI, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

//potentiometers and r2r ladders as inputs
  //DDRC &= ~(P1_POT1_MASK | CS_lDR_MASK | COM_lDR_MASK | BIT_LDR_MASK);

  //transmit butotn as input pullup
  DDRD &= ~(TX_BTN_MASK);
  PORTD |= (TX_BTN_MASK); 

 

  


      parent.parent_clearboard();
      parent.parent_shiftbyte(1);
      delay(1000);
      parent.parent_shiftbyte(2);
      delay(1000);
      parent.parent_shiftbyte(3);
      delay(1000);
      parent.parent_shiftbyte(4);
      delay(1000);
      parent.parent_clearboard();




}
void loop() {

  /*
  currentbuttonstate = digitalRead(3);
  if ( prevbuttonstate == 1 && currentbuttonstate == LOW  ) {
    r2r_select = r2r_select + 1;
    if (r2r_select > 2) {
      r2r_select = 0;
    }
  }
  prevbuttonstate = currentbuttonstate;
  delay(10);


  */
  /*
    switch (r2r_select) {
      case 0:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A0), 0, 1023, 0, 255));
        break;
      case 1:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A1), 0, 1023, 0, 255));
        break;
      case 2:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A2), 0, 1023, 0, 255));
        break;
      case 3:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A3), 0, 1023, 0, 255));
        break;
      default:
          break;
    }
  */
  
  parent_spi_cycle();
}


void parent_spi_cycle(){
  switch (r2r_select) {
    case 0:
      C1_LOW;
      parent_send_spi(0xAA);
      C1_HIGH;
      
      parent.parent_shiftbyte(1);
      delay(1000);
      
      C1_LOW;
      parent_send_spi(0);
      C1_HIGH;
      parent.parent_clearboard();
      delay(1000);
      break;
    case 1:
      C2_LOW;
      parent_send_spi(0xAA);
      C2_HIGH;
      
      parent.parent_shiftbyte(2);
      delay(1000);
      
      C2_LOW;
      parent_send_spi(0);
      C2_HIGH;
      parent.parent_clearboard();
      delay(1000);
      break;
    case 2:
      C3_LOW;
      parent_send_spi(0xAA);
      C3_HIGH;
      
      parent.parent_shiftbyte(3);
      delay(1000);
      
      C3_LOW;
      parent_send_spi(0);
      C3_HIGH;
      parent.parent_clearboard();
      delay(1000);
      break;
    default:
      break;
  }
  r2r_select = r2r_select+1;
  if (r2r_select > 2){
    r2r_select = 0;
  }
}
void parent_send_spi(byte info) {

/* Start transmission */
SPDR = char(info);
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
}






