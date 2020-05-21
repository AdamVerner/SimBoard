// ----- IGNORE THIS BEGIN -----
#ifndef SIM_BOARD
    #define log_info(x)
#else
    #include "Arduino.h"
    #include "Log.h"
    #define log_info(x) Logger::info(x)
    using namespace Arduino;
#endif
// ----- IGNORE THIS END -----



void setup() {

    pinMode(1, OUTPUT);
    pinMode(2, INPUT);
    Serial.begin(9600);
    Serial.print("Board Set up");

    // Try to write and read from EEPROM
    EEPROM.write(7, 134);
    log_info(std::to_string(EEPROM.read(7)));

    // wait for data
    while (Serial.available() == 0) { delay(10); }

    std::string s;
    while (Serial.available() > 0) {
        // read the incoming byte:
        s += Serial.read();
    }
    log_info("received: '" + s + "' from st board");

    randomSeed(0xdeadbeef);

}


int i = 0;

void loop(){

   log_info("Randmo value: " + std::to_string(random(100, 420)));

    log_info("Loop iteration: " + std::to_string(i++) + "; Time elapsed:" + std::to_string(millis()) + "ms");

    digitalWrite(1, !digitalRead(1));

    log_info("D1:  " + std::to_string(digitalRead(1)) + " D2:  " + std::to_string(digitalRead(2)));

    delay(1000);

}