void setup() {
  // put your setup code here, to run once:
pinMode(3,INPUT);
pinMode(13,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  int x;
  x=digitalRead(3);
  if(x==HIGH){
digitalWrite(7,HIGH);
digitalWrite(8,HIGH); 
  }
  else{
digitalWrite(8,LOW);
digitalWrite(7,LOW);
}
}
