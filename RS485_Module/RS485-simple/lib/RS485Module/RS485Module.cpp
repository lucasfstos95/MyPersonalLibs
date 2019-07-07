#include <Arduino.h>
#include "RS485Module.h"


#define serial Serial
//========== DIRECTIVES ===============//
//#define SIZE_OF_BUFFER 256

//========== MACROS =============//

char buffer[SERIAL_RX_BUFFER_SIZE];                //buffer master to receive and send the messages through serial

//constructor
RS485Module::RS485Module(int serial){

    if(serial == 0){
         #define serialPrint(text) Serial.print(text)
         #define serialPrintln(text) Serial.println(text)
         #define serialReadString(text) Serial.readStringUntil(text)
         #define serialWrite(text) Serial.write(text)
         #define serialBegin(baud_rate) Serial.begin(baud_rate)
    }
    /*
    #if (serial == 1)
         #define serial Serial2
    #endif
    #if (serial == 2)
         #define serial Serial
    #endif
    #if (serial == 3)
         #define serial Serial3
    #endif
    */

}

void RS485Module::read(){
    int i = 0;
    //size_t buffer_size;
    String msg = serialReadString('\n');
    int tam = msg.length();
    for(i=0; i<tam; i++){
        buffer[i] = (char)msg.charAt(i);
    }
}

void RS485Module::print(const char *msg){
    for(int i=0; i<SERIAL_TX_BUFFER_SIZE; i++){
        serialWrite(buffer[i]);
    }
    serialWrite('\n');
}

void RS485Module::begin(int baud){
    serialBegin(baud);
}
