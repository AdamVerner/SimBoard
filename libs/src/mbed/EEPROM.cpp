#include "mbed/EEPROM.h"


EEPROM::EEPROM(int sda, int scl, uint8_t address, int type) : manager(EEPROM_TYPE_STM) {}

void EEPROM::write(uint32_t address, uint8_t data) {
    manager.write(address, data);
}

void EEPROM::read(uint32_t address, uint8_t &data) {
    data = manager.read(address);
}
