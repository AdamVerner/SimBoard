//
// Created by home-6 on 16.04.20.
//

#pragma once

#include <cstdarg>
#include <cstdio>
#include <mbed.h>

#include "common/Stream.h"
#include "mbed.h"

class Serial{
public:
    Serial(int tx, int rx) noexcept ;

    void baud(long baud);
    void printf(const char * format, ...);

    bool readable();
    void putc(uint8_t c);
    uint8_t getc();
    void attach( std::function<void()> * func);

    void connect_serial(Stream * ss){
        this->stream = ss;
    }

private:
    Stream * stream = nullptr;
    long _baud = 0;

    std::function<void()> * interrupt;

};