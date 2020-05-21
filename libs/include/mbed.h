//
// Created by home-6 on 15.04.20.
//

#pragma once

#include "mbed/Pins.h"
#include "mbed/Time.h"
#include "mbed/Serial.h"
#include "mbed/EEPROM.h"

typedef enum {
    A0 = 0x0,
    A1 = 0x1,
    A2 = 0x2,
    A3 = 0x3,
    A4 = 0x4,
    A5 = 0x5,
    A6 = 0x6,
    A7 = 0x7,
    A8 = 0x8,
    A9 = 0x9
} pins;


namespace mbed{

    extern InputOutputPin _pinMap[10];
    extern Stream _Serial;


}