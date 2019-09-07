#include <Arduino.h>
#include "RS485Module.h"
#include <SoftwareSerial.h>




//========== DIRECTIVES ===============//
//#define SIZE_OF_BUFFER 256


//#define SOFTWARE_SERIAL_ENABLED
//========== MACROS =============//

char buffer[SERIAL_RX_BUFFER_SIZE];                //buffer master to receive and send the messages through serial

//constructor
#ifndef SOFTWARE_SERIAL_ENABLED 
    RS485Module::RS485Module(HardwareSerial &serial, int WritePin){
    _MySerial = &serial;
    _WritePin = WritePin;  
    _MySerial->println("Started RS485 communication");
}
#else
    RS485Module::RS485Module(SoftwareSerial &serial, int WritePin){
    _MySerial = &serial;  
    _WritePin = WritePin;  
    //_MySerial->println("Started RS485 communication");
}
#endif


void RS485Module::read(){
    writeDisable();
    int i = 0;
    //size_t buffer_size;
    String msg = _MySerial->readStringUntil('\n');
    int tam = msg.length();
    for(i=0; i<tam; i++){
        buffer[i] = (char)msg.charAt(i);
    }
}

void RS485Module::print(const char *msg){
    writeEnable();
    for(int i=0; i<SERIAL_TX_BUFFER_SIZE; i++){
        _MySerial->write(msg[i]);
    }
    writeDisable();
}

void RS485Module::println(const char *msg){
    writeEnable();
    for(int i=0; i<SERIAL_TX_BUFFER_SIZE; i++){
        _MySerial->write(msg[i]);
        //delay(1);
    }
    _MySerial->write('\n');
    writeDisable();
}

void RS485Module::begin(int baud){
    _MySerial->begin(baud);
}

//======================================================================

void RS485Module::writeEnable(){
    digitalWrite(_WritePin, HIGH);
}

void RS485Module::writeDisable(){
    digitalWrite(_WritePin, LOW);
}


