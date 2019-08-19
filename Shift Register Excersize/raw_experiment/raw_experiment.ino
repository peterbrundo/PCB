#define SER 0
#define  NOE 1
#define  RCLK 2
#define  SRCLK 3
#define  SRCLR 4

#define mask_bit_0 0x01
#define mask_bit_1 0x02
#define mask_bit_2 0x04
#define mask_bit_3 0x08
#define mask_bit_4 0x10
#define mask_bit_5 0x20
#define mask_bit_6 0x40
#define mask_bit_7 0x80

void setup() {
  // put your setup code here, to run once:
  DDRD |= (1 << SRCLR) | (1 << SRCLK) | (1 << RCLK) | (1 << NOE) | (1<<SER);
  PORTD |= (1 << SRCLR);
  
  PORTD &=  ~(1 << SRCLK);
  
  PORTD &=  ~(1 << RCLK);
  
  PORTD &=  ~(1 << NOE);

pinMode(13,OUTPUT);

clockntimes(10);
}

void loop() {
for (int i = 0;i<256;i++){
      itworksbutrealycond(i);
      delay(10);
      } 
      delay(2000);
      
PORTD &= ~(1 << NOE);
      
      delay(500);
      delay(500);
      digitalWrite(13,HIGH);
      PORTD &= ~(1<<SRCLR); //proof that srclr 
      PORTD |= (1<<SRCLR);
      delay(2000);
      digitalWrite(13,HIGH);
      delay(2000);

      digitalWrite(13,LOW);
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<RCLK);

      delay(2000);
      digitalWrite(13,HIGH);
      delay(2000);

      digitalWrite(13,LOW);
PORTD &= ~(1<<SRCLR); //proof that srclr 
PORTD |= (1<<SRCLR);

      delay(2000);
      digitalWrite(13,LOW);
      delay(2000);
      
      digitalWrite(13,HIGH);
PORTD |= (1<<SRCLK);//2
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

      delay(2000);
      digitalWrite(13,LOW);
      delay(2000);

      digitalWrite(13,HIGH);
PORTD |=(1<<RCLK);
PORTD &= ~(1<<RCLK);

      delay(2000);
      digitalWrite(13,LOW);
/*
  for (int i = 0;i<256;i+=2){
      itworksbutrealy(i);
      delay(50);
      } 
      delay(5000);
      
      PORTD &= ~(1 << NOE);
      PORTD |= (1<<SER);
      
      PORTD &= ~(1<<SRCLR);
      delay(1000);
      
      
      PORTD |= (1<<SRCLR);
      
      PORTD |= (1<<SRCLK); //*one clock pulse
      PORTD |= (1<<RCLK);  //*
      PORTD &= ~(1<<SRCLK);//
      PORTD &= ~(1<<RCLK);
      
      PORTD |= (1<<SRCLK); //*one clock pulse
      PORTD |= (1<<RCLK);  //*
      PORTD &= ~(1<<SRCLK);//
      PORTD &= ~(1<<RCLK);
      
      
      PORTD |= (1<<SRCLK); //*one clock pulse
      PORTD |= (1<<RCLK);  //*
      PORTD &= ~(1<<SRCLK);//
      PORTD &= ~(1<<RCLK);
      
      PORTD |= (1<<RCLK);  //*
      PORTD &= ~(1<<RCLK);
      
      delay(1000);
      
      delay(1000);
      
      delay(1000);

      */
}
void itworksbutrealycond(byte setBit){


  //Setup
PORTD &= ~(1<<SRCLK | 1<<RCLK | 1 << SER | 1<<SRCLR);//
//PORTD &= ~(1<<SRCLR);
PORTD |= (1<<SRCLR | 1 << NOE);
//PORTD |= (1 << NOE);
//PORTD &=  ~(1 << SER);

//PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_7)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);


if ( setBit & mask_bit_6)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_5)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_4)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_3)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_2)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF


PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_1)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_0)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);
//end

PORTD |=(1<<RCLK);
PORTD &= ~(1<<RCLK);

  PORTD &=  ~(1 << NOE | 1 << SER);
  
  //PORTD &=  ~(1 << SER);
}
void itworksbutrealy(byte setBit){

  //Setup
  
PORTD &= ~(1<<SRCLR);
PORTD |= (1<<SRCLR);
PORTD |= (1 << NOE);
PORTD &=  ~(1 << SER);
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_7)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*
PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);


if ( setBit & mask_bit_6)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//2
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_5)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//3
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_4)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//4
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_3)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//5
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_2)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//6
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_1)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//7
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);

if ( setBit & mask_bit_0)  {PORTD |= (1<<SER);} //turn output ON
else{PORTD &= ~(1<<SER);} //turn output OFF

PORTD |= (1<<SRCLK);//8
PORTD |= (1<<RCLK); 
PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);
//end

PORTD |=(1<<RCLK);
PORTD &= ~(1<<RCLK);

  PORTD &=  ~(1 << NOE);
  
  PORTD &=  ~(1 << SER);
}
void itworks(){
PORTD |= (1<<SER); //turn output ON
PORTD |= (1<<SRCLK); //*one clock pulse
PORTD |= (1<<RCLK);  //*

PORTD &= ~(1<<SRCLK);//
PORTD &= ~(1<<RCLK);

PORTD |= (1<<SRCLK);//2
PORTD |= (1<<RCLK); 

PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);


PORTD &= ~(1<<SER);//turn output OFF before next clock pulse high
PORTD |= (1<<SRCLK);
PORTD |= (1<<RCLK); 

PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);
PORTD |= (1<<SRCLK);
PORTD |= (1<<RCLK); 

PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);
PORTD |= (1<<SRCLK);
PORTD |= (1<<RCLK); 

PORTD &= ~(1<<SRCLK);
PORTD &= ~(1<<RCLK);
//end

PORTD |=(1<<RCLK);
PORTD &= ~(1<<RCLK);
delay(10000);
/* this also puts led 1 on
PORTD |= (1<<SER);
PORTD |= (1<<SRCLK) | (1<<RCLK); 
PORTD &= ~(1<<RCLK);
PORTD |=(1<<RCLK);
while(true);
  */
/* this puts led 1 on
PORTD |= (1<<SER);

PORTD |= (1<<SRCLK); 
PORTD &= ~(1<<RCLK);

delay(1000);

  PORTD &= ~(1<<SER);
  

PORTD |= (1<<RCLK);
PORTD &= ~(1<<SRCLK);


PORTD |= (1<<SRCLK); 
PORTD &= ~(1<<RCLK);



PORTD &= ~(1<<SER);
while(true);
delay(1000);
*/
/* this is usefull, cascades
  PORTD |= (1<<SER);
PORTD |= (1<<SRCLK) |(1<<RCLK);

PORTD &= ~((1<<SRCLK) |(1<<RCLK));
delay(1000);

  PORTD &= ~(1<<SER);
  
PORTD |= (1<<SRCLK) |(1<<RCLK);

PORTD &= ~((1<<SRCLK) |(1<<RCLK));

delay(1000);
*/
  /*
clockntimes(10);
delay(3000);
digitalWrite(13,HIGH);
PORTD |= (1<<SER);
PORTD |= (1<<SRCLK) |(1<<RCLK);
PORTD &= ~(1<<SER);
clockntimes(7);
digitalWrite(13,LOW);
delay(3000);
*/
  /*
clockntimes(10);
  
  delay(3000);
  digitalWrite(13,HIGH);
  clockninsertx(8,0);
  
  delay(500);
  
  clockninsertx(8,1);
  delay(500);
  
  clockninsertx(8,2);
  delay(500);
  
  clockninsertx(8,3);
  delay(500);
    clockninsertx(8,4);
  delay(500);
    clockninsertx(8,5);
  delay(500);
    clockninsertx(8,6);
  delay(500);
    clockninsertx(8,7);
  delay(500);
  
  digitalWrite(13,LOW);

*/
  
  /*
  // put your main code here, to run repeatedly:
  check(mask_bit_3);
  delay(3000);

  check(mask_bit_7);
  delay(3000);
  digitalWrite(13,HIGH);
  checkmask(0xAA);

  delay(3000);

  checkmask(0x55);
  
  delay(3000);

  digitalWrite(13,LOW);

  delay(3000);
  
  digitalWrite(13,HIGH);
  clockninsertx(8,0);
  
  delay(500);
  
  clockninsertx(8,1);
  delay(500);
  
  clockninsertx(8,2);
  delay(500);
  
  clockninsertx(8,3);
  delay(500);
  
  digitalWrite(13,LOW);
  */
}
void checkmask(byte input) {
  clockntimes(9);
  //disable output
  //shoudl prevent instantaneous flickering between shifts
  PORTD |= (1 << NOE);
  PORTD &=  ~(1 << SER);
  //bit 0
  if (input & mask_bit_0) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 1
  if (input & mask_bit_1) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 2
  if (input & mask_bit_2) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 3
  if (input & mask_bit_3) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 4
  if (input & mask_bit_4) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 5
  if (input & mask_bit_5) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 6
  if (input & mask_bit_6) {PORTD |= (1 << SER);}
  else {PORTD &= ~(1 << SER);}
  clockonce();
  //bit 7
  if (input & mask_bit_7) {PORTD |= (1 << SER);}
  else{PORTD &= ~(1 << SER);}
  clockonce();
  //enable output
  PORTD &=  ~(1 << NOE);
}
void check(byte input) {

  //disable output
  //shoudl prevent instantaneous flickering between shifts
  PORTD |= (1 << NOE);
  if (input & mask_bit_0) {

  }
  else if (input & mask_bit_1) {

  }
  else if (input & mask_bit_2) {

  }
  else if (input & mask_bit_3) {

    PORTD &= ~(1 << SER);

    clockntimes(4);
    PORTD |= (1 << SER);
    clockonce();
    PORTD &= ~(1 << SER);
    clockonce();
    clockonce();
    clockonce();
    clockonce();
  }
  else if (input & mask_bit_4) {

  }
  else if (input & mask_bit_5) {

  }
  else if (input & mask_bit_6) {

  }
  else if (input & mask_bit_7) {

    digitalWrite(0, LOW);

    clockeight();
  }
  //enable output
  PORTD &=  ~(1 << NOE);
}
void clockntimes(int n) {
  PORTD |= (1 << NOE);
  for (int i = 0; i < n; i++) {    
    PORTD |= (1 << SRCLK) | (1 << RCLK);
    PORTD &= ~((1 << SRCLK) | (1 << RCLK));
  }
  PORTD &=  ~(1 << NOE);
}
void clockninsertx(int n, int x){
  PORTD |= (1 << NOE);
  PORTD &=  ~(1 << SER);
  for (int i = 0;i<n;i++){
  if (i == x){PORTD |= (1 << SER);}
  else{PORTD &= ~(1 << SER);  }
    PORTD |= (1 << SRCLK) | (1 << RCLK);
    PORTD &= ~((1 << SRCLK) | (1 << RCLK));
    delay(1000);
    
  }
  
  PORTD |= ~(1 << RCLK);
  PORTD &= ~(1 << RCLK);
  
  
  PORTD &=  ~(1 << NOE);
  
  PORTD &=  ~(1 << SER);
}
void clockonce() {
  //1
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
}
void clockeight() {
  //1
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //2

  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //3
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //4
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //5
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //6
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //7
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //8
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);

  //9
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
  PORTD ^= (1 << SRCLK) | (1 << RCLK);
}

