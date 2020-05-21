#include <iostream>
#include <thread>

#include "BoardArduino/main.ino"
#include "BoardST32/main.cpp"
#include "libs/include/Log.h"

void arduino_wrapper(){
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

    Logger::dbg("Starting Arduino setup");
    setup();
    Logger::dbg("Arduino setup finished");


    for(;;){
        Logger::dbg("Starting Arduino Loop");
        loop();
    }
#pragma clang diagnostic pop
}


/*
 * Connect board pins
 * */
void connections(){
    // connect pin 1 and pin 2
    Arduino::_pinMap[0].connect(mbed::_pinMap[A0]);
    Arduino::_pinMap[1].connect(mbed::_pinMap[A1]);

    mbed::_Serial.connect(Arduino::Serial);
    Arduino::Serial.connect(mbed::_Serial);

}


int main() {
    Logger::severity = Logger::INFO;

    connections();


    Logger::dbg("Starting ST32 in another thread");
    std::thread stMain (st_main);
    Logger::dbg("ST32  main started");


    std::thread arduinoLoop (arduino_wrapper);


    Logger::info("press CTRL-D to exit (CTRL-Z on windows)");
    char c;
    while (std::cin >> c);

    Logger::info("Exiting....");

}

