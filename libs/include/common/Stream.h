//
// Created by home-6 on 16.04.20.
//

#pragma once

#include <list>
#include <cinttypes>

class Stream{
public:

    void write(uint8_t byte);
    void write( char const * str);

    int available();

    uint8_t read();
    uint8_t peek();

    void connect(Stream & other) {
        connected = &other;
    }


protected:
    size_t OutSize = 0; // TODO replace with OutBuff.size()
    std::list <uint8_t> OutBuff;

    Stream * connected = nullptr;

};



