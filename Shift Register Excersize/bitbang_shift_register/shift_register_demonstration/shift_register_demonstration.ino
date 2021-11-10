#include <bitbang_shift_register.h>
bitbang_shift_register bitbang;

void setup() {
  //flash a visually recognizible pattern
  //0xAA -> 10101010
  //0x88 -> 01010100
  bitbang.shiftbyte(0x00);
  delay(1000);
  bitbang.shiftbyte(0xAA);
  delay(1000);
  bitbang.shiftbyte(0x00);
  delay(1000);
  bitbang.shiftbyte(0x55);
  delay(1000);
  bitbang.shiftbyte(0x00);
}

void loop() {
  //msb shift in numbers 0 to 256 with a 10ms
  for (int i = 0 ; i < 256; i++) {
    bitbang.shiftbyte(i);
    delay(10);
  }
  delay(1000);
  //msb shift in numbers 256 to 0
  for (int i = 255 ; i > -1; i--) {
    bitbang.shiftbyte(i);
    delay(10);
  }
  delay(500);
  //display a visually recognizable pattern
  bitbang.shiftbyte(0x8F);
  delay(1000);
  
  //lsb shift in numbers 0 to 256 with a 10ms
  for (int i = 0 ; i < 256; i++) {
    bitbang.shiftbyte_lsb(i);
    delay(10);
  }
  delay(500);

  //lsb shift in numbers 0 to 255 with a 10ms
  for (int i = 255 ; i > -1; i--) {
    bitbang.shiftbyte_lsb(i);
    delay(10);
  }
  delay(1000);

  //display a visually recognizable pattern
  bitbang.shiftbyte_lsb(0x8F);
  delay(1000);
}
