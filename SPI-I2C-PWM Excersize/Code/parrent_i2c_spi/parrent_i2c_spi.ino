//parent
#include <parent_bitbang_shift_register.h>
parent_bitbang_shift_register parent;

#define CS1 10
#define CS2 9
#define CS3 8



int r2r_select = 0;
int currentbuttonstate = 0;
int prevbuttonstate = 1;
void setup() {

      
  pinMode(3, INPUT_PULLUP);

  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);

  pinMode(CS1, OUTPUT);
  pinMode(CS2, OUTPUT);
  pinMode(CS3, OUTPUT);
  
  digitalWrite(CS1, HIGH);
  digitalWrite(CS2, HIGH);
  digitalWrite(CS3, HIGH);

  
/* Set MOSI and SCK output, all others input */
pinMode(11,OUTPUT);
pinMode(13,OUTPUT);

/* Enable SPI, Master, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);


      parent.parent_clearboard();
      parent.parent_shiftbyte(1);
      delay(1000);
      parent.parent_shiftbyte(2);
      delay(1000);
      parent.parent_shiftbyte(3);
      delay(1000);
      parent.parent_shiftbyte(4);
      delay(1000);
      parent.parent_clearboard();




}
void loop() {
  /*
  currentbuttonstate = digitalRead(3);
  if ( prevbuttonstate == 1 && currentbuttonstate == LOW  ) {
    r2r_select = r2r_select + 1;
    if (r2r_select > 2) {
      r2r_select = 0;
    }
  }
  prevbuttonstate = currentbuttonstate;
  delay(10);


  */
  /*
    switch (r2r_select) {
      case 0:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A0), 0, 1023, 0, 255));
        break;
      case 1:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A1), 0, 1023, 0, 255));
        break;
      case 2:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A2), 0, 1023, 0, 255));
        break;
      case 3:
        parent.parent_clearboard();
        parent.parent_shiftbyte(map(analogRead(A3), 0, 1023, 0, 255));
        break;
      default:
          break;
    }
  */
  switch (r2r_select) {
    case 0:
      digitalWrite(CS1, LOW);
      parent_send_spi(0xAA);
      digitalWrite(CS1, HIGH);
      
      parent.parent_shiftbyte(1);
      delay(1000);
      
      digitalWrite(CS1, LOW);
      parent_send_spi(0);
      digitalWrite(CS1, HIGH);
      parent.parent_clearboard();
      delay(1000);
      break;
    case 1:
      digitalWrite(CS2, LOW);
      parent_send_spi(0xAA);
      digitalWrite(CS2, HIGH);
      
      parent.parent_shiftbyte(2);
      delay(1000);
      
      digitalWrite(CS2, LOW);
      parent_send_spi(0);
      digitalWrite(CS2, HIGH);
      parent.parent_clearboard();
      delay(1000);
      break;
    case 2:
      digitalWrite(CS3, LOW);
      parent_send_spi(0xAA);
      digitalWrite(CS3, HIGH);
      
      parent.parent_shiftbyte(3);
      delay(1000);
      
      digitalWrite(CS3, LOW);
      parent_send_spi(0);
      digitalWrite(CS3, HIGH);
      parent.parent_clearboard();
      delay(1000);
      break;
    default:
      break;
  }
  r2r_select = r2r_select+1;
  if (r2r_select > 2){
    r2r_select = 0;
  }
}

void parent_send_spi(byte info) {

/* Start transmission */
SPDR = char(info);
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
}






