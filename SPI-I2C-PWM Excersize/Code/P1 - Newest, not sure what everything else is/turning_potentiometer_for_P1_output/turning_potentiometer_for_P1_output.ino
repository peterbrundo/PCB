#include <shift_register.h>
shift_register dorito;
void setup() {
pinMode(A0,INPUT);
}

void loop() {

dorito.shiftbite(map(analogRead(A0),0,1024,0,255));
delay(40);
//below is a 0-255 255-0 light show
  /*
  for (int i = 0 ; i < 256; i++) {
    dorito.shiftbite(i);
    delay(20);
  }
  delay(1000);
    for (int i = 256 ; i >-1; i--) {
    dorito.shiftbite(i);
    delay(20);
  }
  delay(1000);

  */
}
