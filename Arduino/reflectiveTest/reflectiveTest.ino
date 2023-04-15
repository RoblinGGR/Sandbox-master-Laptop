void setup() {
Serial.begin(9600);
pinMode(A0,INPUT);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);

}

void loop() {
int reading=analogRead(A0);
Serial.println(reading);
for (int i=13;i>8;i--){
  digitalWrite(i,LOW);
}
if(reading>0&&reading<200){
  digitalWrite(13,HIGH);
  }else if(reading>201&&reading<400){
  digitalWrite(12,HIGH);
  }else if(reading>401&&reading<600){
  digitalWrite(11,HIGH);
  }else if(reading>601&&reading<800){
  digitalWrite(10,HIGH);
  }else if(reading>800){
  digitalWrite(9,HIGH);
  }

}
