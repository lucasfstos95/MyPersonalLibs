#include <Arduino.h>
#include <SoftwareSerial.h>
#include "RS485Module.h"

SoftwareSerial minhaSerial(2,3);
#define WRITE_PIN 10

//#define SERIAL_1
RS485Module rs485(Serial3, WRITE_PIN);

void setup() {
  rs485.begin(9600);
  
}

void loop() {
  rs485.println("Olá Mundo!");
  delay(1000);
}
/*
serialEvent(){
  RS485.read();
  RS485.print("oi");
  
}
*/