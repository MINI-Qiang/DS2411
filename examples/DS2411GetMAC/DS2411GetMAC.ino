#include "DS2411.h"
DS2411 ds(9); // DS2411 data pin
void setup() {
  Serial.begin(9600);
}
void loop() {
  byte MAC[6];
  ds.Init();
  ds.GetMAC(MAC);   //get data
 
  for(byte a=0;a<6;a++)  //print data
  {
  Serial.print(MAC[a],HEX);
  Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}