#include <DHT11.h>
#include <Servo.h>
DHT11 dht11(2);
Servo myservo;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(dht11.readTemperature());
float temperature=dht11.readTemperature();
if(temperature<50){
   myservo.write(180); 
}
else if(temperature==28){
  myservo.write(120);
}
delay(1000);
}
