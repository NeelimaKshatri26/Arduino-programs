//servro motor
#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
myservo.attach(3);
}
void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(7)==HIGH){
   myservo.write(90); 
  }
  else
  {
   myservo.write(180); 
  }
delay(1000);
}
