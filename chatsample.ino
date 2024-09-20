#include<SoftwareSerial.h>
SoftwareSerial bluetooth_connec(10,11); //10-RX and 11-TX
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth_connec.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
 bluetooth_connec.println(Serial.readString());
  }
  if(bluetooth_connec.available()>0)
  {
    Serial.println(bluetooth_connec.readString());
  }
}
