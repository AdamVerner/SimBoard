//
// Created by home-6 on 16.04.20.
//

#include <cstdint>
#include <stdexcept>
#include "common/Stream.h"


void Stream::write(uint8_t byte) {
    OutBuff.emplace_back(byte);
    OutSize++;
}

void Stream::write(char const * str){
    while(*str) {
        write(str[0]);
        str = str + sizeof(char);
    }
}

uint8_t Stream::read() {
    if(!connected) throw std::logic_error("Stream not connected");
    if(connected->OutSize == 0) return -1;

    uint8_t tmp = connected->OutBuff.front();
    connected->OutBuff.pop_front();
    connected->OutSize--;
    return tmp;
}

uint8_t Stream::peek() {
    if(!connected) throw std::logic_error("Stream not connected");
    if(connected->OutSize == 0) return -1;

    return connected->OutBuff.front();
}

int Stream::available() {
    if(!connected) throw std::logic_error("Stream not connected");

    return connected->OutSize;
}

