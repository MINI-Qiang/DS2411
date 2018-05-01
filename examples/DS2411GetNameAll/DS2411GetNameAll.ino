#include "DS2411.h"
DS2411 ds(9); // DS2411 data pin
void setup() {
  Serial.begin(9600);
}
void loop() {
  char Name[16];
  ds.Init();
  ds.GetCharAll(Name);   //get name
  String StrName = Name;  // char[] to String
  Serial.println(StrName);
  delay(1000);
}