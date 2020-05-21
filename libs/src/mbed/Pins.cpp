//
// Created by home-6 on 15.04.20.
//

#include "mbed/Pins.h"

InputOutputPin mbed::_pinMap[10] = {};

DigitalInOut & DigitalInOut::operator=(int state) {
    this->pin->set_state(state);
    return *this;
}


DigitalInOut::DigitalInOut(int pin) {
    this->pin = & mbed::_pinMap[pin];
}