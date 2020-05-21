//
// Created by home-6 on 16.04.20.
//

#include <cstdarg>
#include <cstdio>
#include <Serial.h>


#include "mbed.h"

Stream mbed::_Serial = {};


void Serial::baud(long baud) {
    this->_baud = baud;
}

void Serial::printf(const char *format, ...) {

    // TODO check baud and stream

    va_list args;
    va_start(args, format);
    char buff[100];
    vsprintf(buff, format, args);

    stream->write(buff);

}

Serial::Serial(int tx, int rx) noexcept{
    this->stream = &mbed::_Serial;
}

bool Serial::readable() {
    return stream->available() > 0;
}

void Serial::putc(uint8_t c) {
    stream->write(c);
}

uint8_t Serial::getc() {
    return stream->read();
}

void Serial::attach(std::function<void()> * func) {
     interrupt = func;
     // TODO implement
}

