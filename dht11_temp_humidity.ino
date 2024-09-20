#include <DHT11.h>
DHT11 dht11(2);
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(dht11.readHumidity());  
Serial.println(dht11.readTemperature());
delay(1000);
}
