
void setup(){
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(12,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
int sensor_data = analogRead(A2);
Serial.println(sensor_data);
if(sensor_data>950)
{
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(12,LOW);

}
else if(sensor_data>500)
{
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
}
else
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
}
delay(500);
}
