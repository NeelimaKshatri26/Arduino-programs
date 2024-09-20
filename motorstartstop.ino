#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
String data1=Serial.readString();
Serial.println(data1);
data1.trim();
 if(data1=="start")
 {
   myservo.write(90); 
 }
 if(data1=="stop")
 {
   myservo.write(180);
 }
}
}
