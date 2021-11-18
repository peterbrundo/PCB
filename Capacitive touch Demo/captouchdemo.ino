#include <Wire.h>
#define ADDRESS           0x44
#define REGISTER_CONFIG   0x00
#define REGISTER_CONTROL  0x01
#define REGISTER_STATE1   0x02
#define REGISTER_STATE2   0x03
#define REGISTER_INT      0x04


#define KEYAMASK 0x01
#define KEYBMASK 0x02
#define KEYCMASK 0x04
#define KEYDMASK 0x08
#define KEYEMASK 0x10
#define KEYFMASK 0x20
#define KEYGMASK 0x40
#define KEYHMASK 0x80

int state = 1;
byte report[2] = {};
void setup()
{
  Wire.begin();
  //Serial.begin(115200);//  if using python script
  Serial.begin(9600);
  pinMode(A7, INPUT_PULLUP);
  //scanner();
  //writeregister(REGISTER_CONTROL, 0xf0);
  Serial.println(String("REGISTER_STATE1") + String("\t\t") + String("REGISTER_STATE2") + String("\t\t")  + String("STATUS"));
}

void loop() {
  if (digitalRead(A7) == LOW && state == 1) {
    state = 0;
    report[0] = readregister(REGISTER_STATE1);
    report[1] = readregister(REGISTER_STATE2);
    }
    else if (digitalRead(A7) == HIGH && state == 0){
      state = 1;
      String result = "";
      if (report[1]){
        switch (report[1]){
          case (KEYAMASK):
          if (report[0] & (KEYAMASK)){
            result = "KEYA Pressed";
          }
          else{
            result = "KEYA UnPressed";
          }
          break;
          case (KEYBMASK):
          if (report[0] & (KEYBMASK)){
            result = "KEYB Pressed";
          }
          else{
            result = "KEYB UnPressed";
          }
          break;
          case (KEYCMASK):
          if (report[0] & (KEYCMASK)){
            result = "KEYC Pressed";
          }
          else{
            result = "KEYC UnPressed";
          }
          break;
          case (KEYDMASK):
          if (report[0] & (KEYDMASK) ){
            result = "KEYD Pressed";
          }
          else{
            result = "KEYD UnPressed";
          }
          break;
          case (KEYEMASK):
          if (report[0] & (KEYEMASK)){
            result = "KEYE Pressed";
          }
          else{
            
            result = "KEYE UnPressed";
          }
          break;
          case (KEYFMASK):
          if (report[0] & (KEYFMASK)){
            result = "KEYF Pressed";
          }
          else{
            
            result = "KEYF UnPressed";
          }
          break;
          
          case (KEYGMASK):
          if (report[0] & (KEYGMASK)){
            result = "KEYG Pressed";
          }
          else{
            
            result = "KEYG UnPressed";
          }
          break;
          case (KEYHMASK):
          if (report[0] & (KEYHMASK)){
            result = "KEYH Pressed";
          }
          else{
            
            result = "KEYH UnPressed";
          }
          break;

          
          default:
          result = "error?" + String(report[1]);
          break;
        }
      }
      Serial.println(String(report[0],HEX) + String("\t\t\t") + String(report[1],HEX) + String("\t\t\t") +result);
      //Serial.print(int(report[0])); //use this ugly line if using the python script, figure out how to make this better later!
  }


}
void writeregister(byte Cregister, byte regvalue) {
  Wire.beginTransmission(ADDRESS);
  Wire.write(Cregister);
  Wire.write(regvalue);
  Wire.endTransmission();
}
byte readregister(byte Aregister) {
  Wire.beginTransmission(ADDRESS);
  Wire.write(Aregister);
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS, 1);
  return Wire.read();
}






void scanner() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  delay(1000);           // wait 5 seconds for next scan
}
