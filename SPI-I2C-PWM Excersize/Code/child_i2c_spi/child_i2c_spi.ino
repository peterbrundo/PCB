//child
#include <bitbang_shift_register.h>
bitbang_shift_register child;

#define CS_PIN 10

void setup() {

  child.shiftbyte(42);
  delay(1000);
  pinMode(CS_PIN, INPUT);

  /* Set MISO output, all others input */
  pinMode(12, OUTPUT);
  /* Enable SPI */
  SPCR = (1 << SPE);

}
void loop() {
  /* Wait for reception complete */
  while (!(SPSR & (1 << SPIF)))
    ;
  /* Return Data Register */
  child.shiftbyte( int( SPDR ) );

}
