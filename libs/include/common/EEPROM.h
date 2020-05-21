
#pragma once

#include <cstdio>
#include <cstdint>
#include <sys/stat.h>

#define EEPROMDir ".EEPROM"
#define ArduinoEEPROMFile EEPROMDir"/Arduino"
#define STM32EEPROMFile EEPROMDir"/STM32"
#define EEPROMSize 1024
#define EEPROM_TYPE_ARDUINO 0
#define EEPROM_TYPE_STM 1


class EEPROMManager {
public:
    uint8_t read(int address);
    void write(int address, uint8_t value);
    explicit EEPROMManager(int type);
private:
    int type;
};
namespace Arduino {
    extern EEPROMManager EEPROM;
}
