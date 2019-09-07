#ifndef RS485Module_h
#define RS485Module_h

#include <Arduino.h>
#include <SoftwareSerial.h>

//#define SOFTWARE_SERIAL_ENABLED

    class RS485Module
    {
        public:
            //constructor declaration
            #ifndef SOFTWARE_SERIAL_ENABLED
                HardwareSerial *_MySerial;
                RS485Module(HardwareSerial &serial, int WritePin);
            #else
                SoftwareSerial *_MySerial;
                RS485Module(SoftwareSerial &serial, int WritePin);
            #endif
            //=========================================
            int _WritePin;          //write pin module control
            //========================================
            void read();
            void print(const char *msg);
            void println(const char *msg);
            void begin(int baud);
            //=================================
            void writeEnable();
            void writeDisable();
            
        
        private:
        

    };

    #if !defined(NO_GLOBAL_INSTANCES)
        extern RS485Module RS485; 
    #endif

#endif
