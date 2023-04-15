/*
  Arduino Wireless Communication Tutorial
        Example 1 - Receiver Code

  by Dejan Nedelkovski, www.HowToMechatronics.com

  Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

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
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
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
delay(500);
}
