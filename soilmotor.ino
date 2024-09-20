 //soil&motor
 #include <Servo.h>
 
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(9);
}
void loop() {
  // put your main code here, to run repeatedly:
int sensor_data = analogRead(A2);
Serial.println(sensor_data);
delay(500);
if(sensor_data>700)
{
  myservo.write(180);
}
else{
  myservo.write(0);
}


}
