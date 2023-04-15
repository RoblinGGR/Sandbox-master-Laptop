

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <ezButton.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";



//JOYSTICK CONFIG

#define VRX_PIN_L  A1 // Arduino pin connected to VRX pin
#define VRY_PIN_L  A0 // Arduino pin connected to VRY pin

#define VRX_PIN_R  A3 // Arduino pin connected to VRX pin
#define VRY_PIN_R  A2 // Arduino pin connected to VRY pin

int xValue_L = 0; // To store value of the X axis
int yValue_L = 0; // To store value of the Y axis

int xValue_R = 0; // To store value of the X axis
int yValue_R = 0; // To store value of the Y axis


void setup() {
  Serial.begin(9600) ;
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {


// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {

  
  // read analog X and Y analog values
int  xValue_L = map(analogRead(VRX_PIN_L),0,1023,-255,255);
int  yValue_L = map(analogRead(VRY_PIN_L),0,1023,-255,255);

int  xValue_R = map(analogRead(VRX_PIN_R),0,1023,-255,255);
int  yValue_R = map(analogRead(VRY_PIN_R),0,1023,-255,255);

};

  xValue_L = map(analogRead(VRX_PIN_L),0,1023,-255,255);
  yValue_L = map(analogRead(VRY_PIN_L),0,1023,-255,255);

  xValue_R = map(analogRead(VRX_PIN_R),0,1023,-255,255);
  yValue_R = map(analogRead(VRY_PIN_R),0,1023,-255,255);

Data_Package data; // Create a variable with the above structure

  // print data to Serial Monitor on Arduino IDE
  Serial.print("xLeft = ");
  Serial.print(xValue_L);
  Serial.print(", yLeft = ");
  Serial.println(yValue_L);

  Serial.println("-----------------");

  Serial.print("xRight = ");
  Serial.print(xValue_R);
  Serial.print(", yRight = ");
  Serial.println(yValue_R);
  
  Serial.println("-----------------");
  
  radio.write(&data, sizeof(Data_Package));
  delay(500);
}
