#include <Arduino.h>
#include "RS485Module.h"

//#define SERIAL_1
RS485Module RS485(1);

void setup() {
  RS485.begin(9600);
  RS485.print("Olá Mundo!");
}

void loop() {
  // put your main code here, to run repeatedly:
}

serialEvent(){
  RS485.read();
  RS485.print("oi");
}
