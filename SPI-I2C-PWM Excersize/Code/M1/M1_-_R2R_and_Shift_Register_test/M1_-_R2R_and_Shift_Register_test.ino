#include <ShiftregM1.h>
ShiftregM1 dorito;

void setup(){
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  pinMode(A1,INPUT);
  dorito.clearBoard();
   dorito.forwards(0xAA);
  delay(1000);
  dorito.clearBoard();
  delay(1000);
   dorito.forwards(0xF0);
  dorito.clearBoard();
delay(1000);
  
   dorito.forwards(0xF0);
  dorito.clearBoard();
  delay(1000);
  }
void loop(){
  dorito.forwards(map(analogRead(A3), 0, 1023, 0, 255));
  delay(1000);
  dorito.clearBoard();
  
  dorito.forwards(map(analogRead(A2), 0, 1023, 0, 255));
  delay(1000);
  dorito.clearBoard();
 
  
  dorito.forwards(map(analogRead(A1), 0, 1023, 0, 255));
  delay(1000);
  dorito.clearBoard();

  
 }

 





