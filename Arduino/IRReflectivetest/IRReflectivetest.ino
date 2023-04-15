int led = 10;
int IRReciever=2;

void setup() {
pinMode(10,OUTPUT);
pinMode(2,INPUT);

}

void loop() {
  bool reciever= digitalRead(IRReciever);
if(reciever){
  digitalWrite(led,HIGH);
}else{
  digitalWrite(led,LOW);
}
}
