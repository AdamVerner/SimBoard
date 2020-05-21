//
// Created by averner on 12.04.20.
//
// File for including
//

#pragma once

#include <chrono>
#include <thread>
#include <values.h>

#include "arduino/Pins.h"
#include "arduino/Serial.h"
#include "common/EEPROM.h"

namespace Arduino{

    void delay(unsigned long ms){
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    void delayMicroseconds(unsigned long us){
        std::this_thread::sleep_for(std::chrono::microseconds(us));
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    unsigned long micros(){
        auto current_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(current_time - start_time).count();
    }

    unsigned long millis(){
        return micros()/1000;
    }

    unsigned long random(unsigned long howbig){
        if (howbig == 0)
            return 0;
        return rand() % howbig;
    }

    unsigned long random(long howsmall, long howbig){
        if (howsmall >= howbig)
            return howsmall;

        long diff = howbig - howsmall;
        return random(diff) + howsmall;
    }

    void randomSeed(unsigned long seed){
        if (seed != 0)
            srand(seed);
    }

    long map(long x, long in_min, long in_max, long out_min, long out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }

}



