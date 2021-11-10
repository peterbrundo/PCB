#include <ShiftregC1.h>
ShiftregC1 dorito;

void setup(){
  
  }
void loop(){
 for(int i = 0;i<255;i++){
  dorito.forwards(i);
  delay(10); 
 }

 for(int i = 255;i>0;i--){
  dorito.forwards(i);
  delay(10); 
 }

delay(200);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
delay(200);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
delay(200);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
dorito.clearBoard();
delay(2000);

  for(int i = 0;i<255;i++){
  dorito.backwards(i);
  delay(10); 
 }

 for(int i = 255;i>0;i--){
  dorito.backwards(i);
  delay(10); 
 }
 
delay(200);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
delay(200);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
delay(200);
dorito.clearBoard();
delay(200);
dorito.forwards(0xAA);
dorito.clearBoard();
delay(2000);
}












