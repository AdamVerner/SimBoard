//
// Created by home-6 on 15.04.20.
//

#pragma once

#include "common/ioPin.h"
#include "mbed.h"


class DigitalInOut{
public:

    DigitalInOut() = delete;

    explicit DigitalInOut(int pin);

    virtual DigitalInOut & operator=(int state );

    virtual explicit operator bool() const { return pin->get_state(); }

    InputOutputPin * pin;
};



class DigitalOut : public DigitalInOut{
public:
    explicit DigitalOut(int pin) noexcept(true) : DigitalInOut(pin) {
        std::cout << "setting" << pin << " mode to " << InputOutputPin::OUTPUT << std::endl;
        this->pin->set_mode(InputOutputPin::OUTPUT);
    }

    DigitalOut & operator=(int state ){
        this->pin->set_mode(InputOutputPin::OUTPUT);
        this->pin->set_state(state);
        return *this;
    }


private:
};

class DigitalIn : public DigitalInOut{
public:
    explicit DigitalIn(int pin) noexcept(true) : DigitalInOut(pin) {

        std::cout << "setting" << pin << " mode to " << InputOutputPin::INPUT << std::endl;
        this->pin->set_mode(InputOutputPin::INPUT);

    }
private:
};