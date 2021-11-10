#include <shift_register.h>
shift_register dorito;
int index = 0;
int prev = 0;
byte key = 0x00;
void setup() {
  pinMode(A0, INPUT);
  //trasnimt button
  DDRD &= ~(1 << DDD3);
  PORTD |= (1 << PORTD3);
}

void loop() {
  switch (index) {
    case 0:
      key = 0x00;
      break;
    case 1:
      key = 0x03;
      break;
    case 2:
      key = 0x0C;
      break;
    case 3:
      key = 0x30;
      break;
    case 4:
      key = 0xC0;
      break;
  }
  dorito.shiftbite(key);
  if (PIND & mask_bit_3) {
    prev = 1;

  }
  else if (!(PIND & mask_bit_3) && prev == 1) {

    PORTB &= ~(1 << PORTB5);

    prev = 0;
    index++;
    if (index > 4) {
      index = 0;
    }
  }
  else {

  }

  delay(100);

  //dorito.shiftbite(map(analogRead(A0),0,1024,0,255));
  //delay(40);
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
