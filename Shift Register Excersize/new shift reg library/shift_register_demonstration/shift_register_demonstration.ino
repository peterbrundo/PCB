#include <shift_register.h>
shift_register dorito;
void setup() {
  dorito.shiftbite(0x00);
  
  delay(1000);
dorito.shiftbite(0xAA);

  delay(1000);
dorito.shiftbite(0x00);

  delay(1000);
dorito.shiftbite(0x55);

  delay(1000);
  
dorito.shiftbite(0x00);
pinMode(A0,INPUT);
}

void loop() {
  for (int i = 0 ; i < 256; i++) {
    dorito.shiftbite(i);
    delay(10);
  }
  delay(1000);
    for (int i = 256 ; i > -1; i--) {
    dorito.shiftbite(i);
    delay(10);
  }
  delay(1000);
    dorito.shiftbite(0x83);
  delay(1000);
  
  
  for (int i = 0 ; i < 256; i++) {
    dorito.shiftbite_lsb(i);
    delay(10);
  }
  delay(1000);
    for (int i = 256 ; i > -1; i--) {
    dorito.shiftbite_lsb(i);
    delay(10);
  }
  delay(1000);
  
    dorito.shiftbite_lsb(0x83);
    
  delay(1000);

}