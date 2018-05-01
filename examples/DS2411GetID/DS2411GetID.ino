#include "DS2411.h"
DS2411 ds(9); // DS2411 data pin
void setup() {
  Serial.begin(9600);
}
void loop() {
  byte data[8];
  ds.Init();
  ds.GetID(data);   //get data
 
  for(byte a=0;a<8;a++)  //print data
  {
  Serial.print(data[a]);
  Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}