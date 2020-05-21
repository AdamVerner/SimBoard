//
// Created by home-6 on 15.04.20.
//
#include <chrono>
#include "mbed/Time.h"

/*
void wait(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}*/

void wait(float seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(int(seconds * 1000)));

}

void Timer::start() {

    _start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    running = true;
}

void Timer::stop() {
    accumulated_micro += read_us();
    running = false;
}

float Timer::read() {
    return (float)read_us() / (float)1000000.0;

}

int Timer::read_ms(){
    if (! running)
        return accumulated_micro / 1000;

    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - _start).count() + accumulated_micro/1000;
}


int Timer::read_us(){
    if (! running)
        return accumulated_micro;

    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(now - _start).count() + accumulated_micro;
}


void Timer::reset() {
    accumulated_micro = 0;
    _start = std::chrono::steady_clock::now();
}
