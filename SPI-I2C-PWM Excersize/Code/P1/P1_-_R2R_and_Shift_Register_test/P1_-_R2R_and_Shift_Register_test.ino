#include <ShiftregP1.h>
ShiftregP1 dorito;

void setup() {
  dorito.clearBoard();
  pinMode(A3, INPUT);
   pinMode(A2,INPUT);
   pinMode(A1,INPUT);
     pinMode(A0,INPUT);
  dorito.forwards(240);
  delay(1000);
  dorito.clearBoard();


  dorito.forwards(15);
  delay(1000);
  dorito.clearBoard();
}
void loop() {

   dorito.forwards(map(analogRead(A0), 0, 1023, 0, 255));
    delay(1000);
    dorito.clearBoard();
  /*
   


  dorito.forwards(map(analogRead(A3), 0, 1023, 0, 255));
  delay(500);
  dorito.clearBoard();
    dorito.forwards(map(analogRead(A1), 0, 1023, 0, 255));
    delay(1000);
    dorito.clearBoard();
  */

}







