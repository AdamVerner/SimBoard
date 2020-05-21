//
// Created by home-6 on 12.04.20.
//

#include <stdexcept>

#include "Log.h"
#include "arduino/Serial.h"

SerialConnector Arduino::Serial = {};
SerialConnector Arduino::Serial2 = {};

void SerialConnector::begin(unsigned long bd) {
    baud = bd;
    up = true;
}


void SerialConnector::end() {
    up = false;
}


void SerialConnector::print(const char c, bool log) {
    if (!up) throw std::logic_error("Serial is not set up");

    if (log) Logger::info("Writing '" + std::to_string(c) + "' to Serial");

    // TODO write to buffer
    write( c );

}

void SerialConnector::print(const std::string &str) {

    Logger::info("Writing '" + str + "' to Serial");

    this->write(str.c_str());
}
