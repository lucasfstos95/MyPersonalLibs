#ifndef RS485Module_h
#define RS485Module_h

#include <Arduino.h>
#include <SoftwareSerial.h>

//#define SOFTWARE_SERIAL_ENABLED

    class RS485Module
    {
        public:

            #ifndef SOFTWARE_SERIAL_ENABLED
                HardwareSerial *_MySerial;
                RS485Module(HardwareSerial &serial);
            #else
                SoftwareSerial *_MySerial;
                RS485Module(SoftwareSerial &serial);
            #endif
            
            
            
            void read();
            void print(const char *msg);
            void println(const char *msg);
            void begin(int baud);
            
        
        private:
        

    };

    #if !defined(NO_GLOBAL_INSTANCES)
        extern RS485Module RS485; 
    #endif

#endif
