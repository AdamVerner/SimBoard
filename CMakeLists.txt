cmake_minimum_required(VERSION 3.13)
project(CommDev)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DSIM_BOARD)

include_directories(libs/include/arduino)
include_directories(libs/include/common)
include_directories(libs/include/mbed)
include_directories(libs/include/)

file(GLOB ARDUINO_SOURCES "libs/src/arduino/*.cpp")
file(GLOB COMMON_SOURCES "libs/src/common/*.cpp")
file(GLOB MBED_SOURCES "libs/src/mbed/*.cpp")
file(GLOB SOURCES "libs/src/*.cpp")

add_executable(CommDev main.cpp BoardArduino/main.ino ${ARDUINO_SOURCES} ${COMMON_SOURCES} ${MBED_SOURCES} ${SOURCES})
target_link_libraries(CommDev pthread)