//
// Created by home-6 on 14.04.20.
//

#include "../../include/common/ioPin.h"

void InputOutputPin::set_state(const int state) {

    if (this->_mode != OUTPUT) throw std::logic_error("can't set state on non-output pin");

    this->_state = state;
    for(const auto &pin: this->connected_pins){

        if (pin->_mode == OUTPUT && pin->_state != state) throw std::logic_error("pins shorted");
        // if pin is not output, it must be input...

        pin->_state = state;

    }

}

int InputOutputPin::get_state() const {
    return _state;
}

void InputOutputPin::set_mode(int mode) {
    _mode = mode;
}

int InputOutputPin::get_mode() const {
    return _mode;
}

void InputOutputPin::connect(InputOutputPin &other) {
    this->connected_pins.push_back(&other);
    other.connected_pins.push_back(this);
}

void InputOutputPin::disconnect() {
    /*
     * Iterate through connection lists of other pins and erase reference about this.
     * once none knows about this, delete references about others from connected pins
     * */

    for(const auto &pin: this->connected_pins)
        for(const auto &other: pin->connected_pins)
            // TODO set state of unconnected pins to default (e.g. if input_pullup),and nothing is connected, set HIGH

            // C++17 https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
            other->connected_pins.erase(
                    std::remove(
                            other->connected_pins.begin(),
                            other->connected_pins.end(),
                            this),
                    other->connected_pins.end());

    this->connected_pins.clear();
}
