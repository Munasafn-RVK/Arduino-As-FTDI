#include <Arduino.h>
#include <SoftwareSerial.h>
// put function declarations here:
int myFunction(int, int);
int rxPin = 2;
int txPin = 3;
int serialBaudRate = 9600;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {
    // Define pin modes for TX and RX
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    
    Serial.begin(serialBaudRate);
    mySerial.begin(serialBaudRate); 


}

void loop() {
  // wait for serial data to be received from software serial port and sent to hardware serial port and vice versa
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

