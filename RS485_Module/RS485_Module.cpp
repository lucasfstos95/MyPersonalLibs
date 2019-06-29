#include "RS485_Module.h"
#include <Arduino.h>

//========== DIRECTIVES ===============//
#define SIZE_OF_BUFFER 256

//========== MACROS =============//


char buffer[SIZE_OF_BUFFER];                //buffer master to receive and send the messages through serial




RS485_Module::RS485_Module(const char *serial){
    
}