//
// Created by home-6 on 12.04.20.
//

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>

#include <common/Stream.h>

class SerialConnector: public Stream{
public:

    void begin(unsigned long bd);
    void end();

    void print(const std::string & str);
    void print(char c, bool log = true);
    inline void println(const std::string & str) { print(str); print('\n', false); }


private:
    bool up = false;
    unsigned long baud = 0;


};
namespace Arduino {
    extern SerialConnector Serial;
    extern SerialConnector Serial2;
}
