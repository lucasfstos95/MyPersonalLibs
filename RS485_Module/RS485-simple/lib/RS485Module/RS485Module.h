#ifndef RS485Module_h
#define RS485Module_h

#include <Arduino.h>
#include <SoftwareSerial.h>


    class RS485Module
    {
        public:
            HardwareSerial *_MySerial;
            RS485Module(HardwareSerial &serial);
            void read();
            void print(const char *msg);
            void begin(int baud);
            
        
        private:
        

    };

    #if !defined(NO_GLOBAL_INSTANCES)
        extern RS485Module RS485; 
    #endif

#endif
