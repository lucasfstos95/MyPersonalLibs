#include <Arduino.h>
#include "RS485Module.h"
#include <SoftwareSerial.h>




//========== DIRECTIVES ===============//
//#define SIZE_OF_BUFFER 256

//========== MACROS =============//

char buffer[SERIAL_RX_BUFFER_SIZE];                //buffer master to receive and send the messages through serial

//constructor
RS485Module::RS485Module(HardwareSerial &_serial){
    MySerial = &_serial;  
    MySerial->println("RS485 Inicializado");
}

void RS485Module::read(){
    int i = 0;
    //size_t buffer_size;
    String msg = MySerial->readStringUntil('\n');
    int tam = msg.length();
    for(i=0; i<tam; i++){
        buffer[i] = (char)msg.charAt(i);
    }
}

void RS485Module::print(const char *msg){
    for(int i=0; i<SERIAL_TX_BUFFER_SIZE; i++){
        MySerial->write(buffer[i]);
    }
    MySerial->write('\n');
}

void RS485Module::begin(int baud){
    MySerial->begin(baud);
}
