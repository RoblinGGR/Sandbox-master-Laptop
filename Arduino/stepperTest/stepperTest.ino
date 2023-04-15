int stepperPin1= 9;
int stepperPin2= 10;
int stepperPin3= 11;
int stepperPin4= 12;
int stepNumber=0;

void setup() {
pinMode(stepperPin1,OUTPUT);
pinMode(stepperPin2,OUTPUT);
pinMode(stepperPin3,OUTPUT);
pinMode(stepperPin4,OUTPUT);

}

void loop() {
OneStep(0); 
delay(2);
}

void OneStep(bool dir){
if(dir)
  switch(stepNumber){
    case 0:
  digitalWrite(stepperPin1,HIGH);
  digitalWrite(stepperPin2,LOW);
  digitalWrite(stepperPin3,LOW);
  digitalWrite(stepperPin4,LOW);
  break;
      case 1:
  digitalWrite(stepperPin2,HIGH);
  digitalWrite(stepperPin1,LOW);
  digitalWrite(stepperPin3,LOW);
  digitalWrite(stepperPin4,LOW);
  break;
      case 2:
  digitalWrite(stepperPin3,HIGH);
  digitalWrite(stepperPin2,LOW);
  digitalWrite(stepperPin1,LOW);
  digitalWrite(stepperPin4,LOW);
  break;
      case 3:
  digitalWrite(stepperPin4,HIGH);
  digitalWrite(stepperPin2,LOW);
  digitalWrite(stepperPin3,LOW);
  digitalWrite(stepperPin1,LOW);
  break;
  }
  else{
  switch(stepNumber){
    case 0:
  digitalWrite(stepperPin4,HIGH);
  digitalWrite(stepperPin2,LOW);
  digitalWrite(stepperPin3,LOW);
  digitalWrite(stepperPin1,LOW);
  break;
      case 1:
  digitalWrite(stepperPin3,HIGH);
  digitalWrite(stepperPin1,LOW);
  digitalWrite(stepperPin2,LOW);
  digitalWrite(stepperPin4,LOW);
  break;
      case 2:
  digitalWrite(stepperPin2,HIGH);
  digitalWrite(stepperPin3,LOW);
  digitalWrite(stepperPin1,LOW);
  digitalWrite(stepperPin4,LOW);
  break;
      case 3:
  digitalWrite(stepperPin1,HIGH);
  digitalWrite(stepperPin2,LOW);
  digitalWrite(stepperPin3,LOW);
  digitalWrite(stepperPin4,LOW);
  break;
  }
    }
    stepNumber++;
    if(stepNumber>3){
      stepNumber=0;
    }
}
