#include <shift_register.h>
shift_register dorito;
int index = 0;
int prev = 0;
byte key = 0x00;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  //trasnimt button
  DDRD &= ~(1 << DDD3);
  PORTD |= (1 << PORTD3);
}
void loop() {
  switch (index) {
    case 0:
      break;
    case 1:
      dorito.shiftbite(map(analogRead(A0), 0, 1024, 0, 255));
      delay(500);
      break;
    case 2:
      dorito.shiftbite(map(analogRead(A1), 0, 1024, 0, 255));
      delay(500);
      break;
    case 3:
      dorito.shiftbite(map(analogRead(A2), 0, 1024, 0, 255));
      delay(500);
      break;
    case 4:
      dorito.shiftbite(map(analogRead(A3), 0, 1024, 0, 255));
      delay(500);
      break;
  }
  if (PIND & mask_bit_3) {
    prev = 1;
  }
  else if (!(PIND & mask_bit_3) && prev == 1) {
    prev = 0;
    index++;
    if (index > 4) {
      index = 0;
    }
  }
  else {
  }
}
