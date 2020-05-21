//
// Created by home-6 on 15.04.20.
//

#pragma once

#include <chrono>
#include <thread>


class Timer {
public:
    Timer() noexcept { }

    void start();
    void stop();
    void reset();
    float read();

    int read_ms();
    int read_us();


private:

    std::chrono::steady_clock::time_point _start;
    uint64_t accumulated_micro = 0;

    bool running = false;
};

void wait(float seconds);