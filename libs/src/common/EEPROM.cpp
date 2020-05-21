#include "common/EEPROM.h"
#include <stdexcept>

EEPROMManager Arduino::EEPROM(EEPROM_TYPE_ARDUINO);

uint8_t EEPROMManager::read(int address) {
    if (address > (EEPROMSize - 1)) {
        throw std::length_error("Arduino EEPROM is only 1024 bytes big.");
    }

    FILE *fptr;

    fptr = fopen((type == EEPROM_TYPE_ARDUINO ? ArduinoEEPROMFile : (type == EEPROM_TYPE_STM ? STM32EEPROMFile : NULL)), "rb");
    if (fptr == nullptr) {
        return 255;
    }

    uint8_t byte;
    fseek(fptr, address, SEEK_SET);
    fread(&byte, sizeof(uint8_t), 1, fptr);

    return byte;

}

void EEPROMManager::write(int address, uint8_t value) {
    if (address > (EEPROMSize - 1)) {
        throw std::length_error("Arduino EEPROM is only 1024 bytes big.");
    }
    struct stat sb;
    if (stat(EEPROMDir, &sb) != 0) {
        mkdir(EEPROMDir, 0777);
    }
    FILE *fptr;
    fptr = fopen((type == EEPROM_TYPE_ARDUINO ? ArduinoEEPROMFile : (type == EEPROM_TYPE_STM ? STM32EEPROMFile : NULL)), "r");
    if (fptr == nullptr) {
        fptr = fopen((type == EEPROM_TYPE_ARDUINO ? ArduinoEEPROMFile : (type == EEPROM_TYPE_STM ? STM32EEPROMFile : NULL)), "wb");
        uint8_t ones = 255;
        for (int i = 0; i < EEPROMSize; i++) {
            fwrite(&ones, sizeof(uint8_t), 1, fptr);
        }
        fclose(fptr);
    }

    fptr = fopen((type == EEPROM_TYPE_ARDUINO ? ArduinoEEPROMFile : (type == EEPROM_TYPE_STM ? STM32EEPROMFile : NULL)), "rb+");
    if (fptr == nullptr) {
        throw std::runtime_error("Cannot read file.");
    }

    fseek(fptr, address, SEEK_SET);
    fwrite(&value, sizeof(uint8_t), 1, fptr);
    fclose(fptr);
}

EEPROMManager::EEPROMManager(int typ) {
    type = typ;
}