//
// Created by home-6 on 12.04.20.
//

#pragma once

#include "common/ioPin.h"

namespace Arduino
{
    static const int OUTPUT = 1;
    static const int INPUT = 2;
    static const int INPUT_PULLUP = 3;


    const uint8_t HIGH = 1;
    const uint8_t LOW  = 0;

    const uint8_t CHANGE = 1;
    const uint8_t FALLING = 2;
    const uint8_t RISING = 3;

    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, uint8_t val);
    uint8_t digitalRead(uint8_t pin);

    int analogRead(uint8_t pin);
    void analogReference(uint8_t mode);
    void analogWrite(uint8_t pin, int val);

    unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout); // TODO
    unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout); //TODO

    void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);  //TODO
    uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);  //TODO

    void attachInterrupt(uint8_t interruptNum, void (*userFunc)(), int mode);  //TODO
    void detachInterrupt(uint8_t interruptNum);  //TODO


    extern InputOutputPin _pinMap[13];

}