//
// Created by home-6 on 12.04.20.
//
#include <iostream>
#include <mbed/Pins.h>


#include "arduino/Pins.h"
#include "Log.h"
#include "common/ioPin.h"

InputOutputPin Arduino::_pinMap[13] = {};

void Arduino::digitalWrite(uint8_t pin, uint8_t value){
    // pinMap start from zero, but arduino indexes from 1-13

    std::string log_msg = "setting " + std::to_string(pin) + " to " + std::to_string(value) ;
    _pinMap[pin-1].set_state(value);
    Logger::dbg(log_msg);
}

void Arduino::pinMode(uint8_t pin, uint8_t mode) {

    std::string log_msg = "Configuring " + std::to_string(pin) +" as ";
    switch(mode) {
        case(Arduino::INPUT): log_msg += "INPUT"; break;
        case(Arduino::OUTPUT): log_msg += "OUTPUT"; break;
        case(Arduino::INPUT_PULLUP): log_msg += "INPUT_PULLUP"; break;
        default: throw std::invalid_argument("Unknown digital pin state");
    }

    _pinMap[pin-1].set_mode(mode);
    Logger::dbg(log_msg);

}


uint8_t Arduino:: digitalRead(uint8_t pin){
    return _pinMap[pin-1].get_state();
}

