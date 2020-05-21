//
// Created by home-6 on 14.04.20.
//

#pragma once

#include <vector>
#include <functional>
#include <iostream>


class InputOutputPin{
public:

    ~InputOutputPin(){ disconnect();}

    void set_state( int state );
    int get_state() const;

    void set_mode( int mode );
    int get_mode() const;

    static const int LOW = 0, HIGH = 1;
    static const int OUTPUT = 1;
    static const int INPUT = 2, INPUT_PULLUP = 3, INPUT_PULLDOWN = 4;

    void connect(InputOutputPin & other);
    void disconnect();



private:

    int _state = LOW;
    int _mode = INPUT;

    std::vector < InputOutputPin * > connected_pins;

    std::vector < std::function<void(int, int)> > state_callbacks;

};
