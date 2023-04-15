//////////define pins////////////

int red=2;
int green=3;      /////the pins connected to the rgb led
int blue=4;

int reflexive1=A0;
int reflexive2=A1;   //the analog pins for the readings of the reflexive proximity sensor
int reflexive3=A2;

void setup() {
  Serial.begin(9600);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
                               //////boilerplate (define what each pin does)
pinMode(reflexive1,INPUT);
pinMode(reflexive2,INPUT);
pinMode(reflexive3,INPUT);
}


void loop() {
 int redRead =analogRead(reflexive2);   //// Check the reading of the proximity sensor 1
 int redVal=map(redRead,45,1000,0,255); //// Map the values of the sensor to 255 so the rgb can use it
  analogWrite(red,redVal);              ////  Change the intensity of the colored LED depending on proximity to the sensor  
 int blueRead =analogRead(reflexive1);  //// REPEAT FOR OTHER COLORS 
 int blueVal=map(blueRead,45,1000,0,255);
  analogWrite(blue,blueVal);
 int greenRead =analogRead(reflexive3);
 int greenVal=map(greenRead,45,1000,0,255);
  analogWrite(green,greenVal);
Serial.println(blueVal);
}
