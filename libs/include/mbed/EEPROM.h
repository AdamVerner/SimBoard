#include "common/EEPROM.h"

class EEPROM {
    public:
        EEPROM(int sda, int scl, uint8_t address, int type);
        void write(uint32_t address, uint8_t data);
        void read(uint32_t address, uint8_t& data);
    private:
        EEPROMManager manager;
};

