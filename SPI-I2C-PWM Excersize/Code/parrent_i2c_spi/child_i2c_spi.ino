//child
#include <bitbang_shift_register.h>
bitbang_shift_register child;

//chip select pin
//unused                  //PB0
//unused                  //PB1
#define CS_PIN_MASK 0x04  //PB2
#define POCI_MASK 0x08    //PB3
#define PICO_MASK 0x10    //PB4
#define SCK_MASK 0x20     //PB5
//unused                  //PB6
//unused                  //PB7


//led pins
//unused                   //PD0-PD4 (shift register bit bang)
#define SPI_LED_MASK 0x20  //PD5 
#define i2c_LED_MASK 0x40  //PD6
#define PWM_LED_MASK 0x80  //PD7

void setup() {

  //pinMode(CS_PIN, INPUT);
  DDRB |= (CS_PIN_MASK) | (PICO_MASK);
  DDRD |= (PWM_LED_MASK) | (i2c_LED_MASK)|(SPI_LED_MASK);
  child.shiftbyte(42);
  delay(1000);
  /* Enable SPI */
  SPCR = (1 << SPE);

}
void loop() {
  
child_receive();
}


void child_receive(){
  
  /* Wait for reception complete */
  while (!(SPSR & (1 << SPIF)))
    ;
  /* Return Data Register */
  child.shiftbyte( int( SPDR ) );
}
