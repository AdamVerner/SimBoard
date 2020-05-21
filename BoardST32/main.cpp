// ----- IGNORE THIS BEGIN -----
#ifndef SIM_BOARD
    #define log_info(x)
#else
    #include "Log.h"
    #define log_info(x) Logger::info(x)
#endif
// ----- IGNORE THIS END -----


#include "mbed.h"

DigitalIn input_A0(A0);
DigitalIn input_A1(A1);
DigitalOut output_A6(A6);

// unfortunately Serial clashes with Arduino::Serial, :: needed to direct the linker
::Serial serial_device(A2, A3); // pins are ignored now
::EEPROM eeprom(A7, A8, 0x07, true); // all parameters are ignored now

Timer t1;


int st_main(){

    serial_device.baud(9600);
    serial_device.printf("Hello from ST32 board");

    t1.start();
    eeprom.write(627, 149);
    uint8_t eeprombyte;
    eeprom.read(627, eeprombyte);
    log_info(std::to_string(eeprombyte));

    wait(0.1);
    log_info(" mode A0 = " + std::to_string(input_A0.pin->get_mode()) + " A1 = " + std::to_string(input_A1.pin->get_mode()));

    while (true){

        wait(1);
        log_info("A0 = " + std::to_string((bool)input_A0) + " A1 = " + std::to_string((bool)input_A1) + "time: " + std::to_string(t1.read()));
        output_A6 = !output_A6;

    }

}


// ----- IGNORE THIS BEGIN -----
#ifndef SIM_BOARD
int main(){
    return st_main();
}
#endif
// ----- IGNORE THIS END -----
