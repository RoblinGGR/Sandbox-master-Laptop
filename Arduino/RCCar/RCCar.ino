//Radio Libs

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(10, 6); // CE, CSN



// Motor A connections
int enA = 9;
int in1 = 7;
int in2 = 8;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

#define left A4
#define center A3
#define right A5
////////////////////////////////////////

//RC Data Struct
const byte address[6] = "00001";

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {

  
  // read analog X and Y analog values
int  xValue_L = 0;
int  yValue_L = 0;

int  xValue_R = 0;
int  yValue_R = 0;

};

Data_Package data; //Create a variable with the above structure

void setup() {
  Serial.begin(9600);
//Radio Setup
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

//Car Setup
  pinMode(left,INPUT);
  pinMode(center,INPUT);
  pinMode(right,INPUT);
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
analogWrite(9,0);
analogWrite(3,0);
}

void loop() {
  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
  }
  Serial.print("XL: ");
  Serial.print(data.xValue_L);
  Serial.print(" YL: ");
  Serial.print(data.yValue_L);
  Serial.println(" ");
  Serial.print(" XR: ");
  Serial.print(data.xValue_R);
  Serial.print(" YR: ");
  Serial.print(data.yValue_R);
  Serial.println("  ");
delay(10);

int maxSpeed;
if(abs(data.yValue_L)>abs(data.xValue_L)){
  maxSpeed=abs(data.yValue_L);
if(data.yValue_L<0){
  analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
if(data.yValue_L>0){
  analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
}
if(abs(data.yValue_L)<abs(data.xValue_L)){
  maxSpeed=abs(data.xValue_L);
if(data.xValue_L<0){
  analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
if(data.xValue_L>0){
  analogWrite(enA, maxSpeed);
  analogWrite(enB, maxSpeed);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
}
}
