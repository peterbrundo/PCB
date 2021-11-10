#include <ShiftregC1.h>
ShiftregC1 dorito;

void setup(){
  pinMode(A3,INPUT);
  }
void loop(){
  dorito.clearBoard();
  dorito.forwards(map(analogRead(A3), 0, 1023, 0, 255));
  delay(500);
 }

 




