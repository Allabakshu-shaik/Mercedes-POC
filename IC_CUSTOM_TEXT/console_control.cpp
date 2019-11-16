#include "console_control.h"
#include "debug.h"


centerConsole::centerConsole(CanbusComm *c) {
    this->c = c;
}


/**
 * Simulates a button press of the lock doors button on the center console
 */
void centerConsole::lockDoors() {
    DPRINTLN(F("Locking doors"));
    f.can_id = 0x002C;
    f.can_dlc = 0x03;
    f.data[0] = 0x80;
    f.data[1] = 0x00;
    f.data[2] = 0x00;
    if (!this->c->sendFrame(CAN_BUS_B ,&f)) {
        Serial.println(F("Error sending lock doors command"));
    }
}

/**
 * Simulates a button press of the unlock doors button on the center console
 */
void centerConsole::unlockDoors() {
    DPRINTLN(F("Unlocking doors"));
    f.can_id = 0x002C;
    f.can_dlc = 0x03;
    f.data[0] = 0x40;
    f.data[1] = 0x00;
    f.data[2] = 0x00;
    if (!this->c->sendFrame(CAN_BUS_B, &f)) {
        Serial.println(F("Error sending unlock doors command"));
    }
}

/**
 * Simulates a button press of the lower rear headrests button on the center console
 */
void centerConsole::retractHeadRest() {
    DPRINTLN(F("Lowering head rests"));
    f.can_id = 0x002C;
    f.can_dlc = 0x03;
    f.data[0] = 0x08;
    f.data[1] = 0x00;
    f.data[2] = 0x00;
    if (!this->c->sendFrame(CAN_BUS_B, &f)) {
        Serial.println(F("Error sending lower head rests command"));
    }
}

/**
 * Simulates a button press of the ESP button on the center console
 */
void centerConsole::toggleESP() {
    DPRINTLN(F("Toggling ESP"));
    f.can_id = 0x002C;
    f.can_dlc = 0x03;
    f.data[0] = 0x02;
    f.data[1] = 0x00;
    f.data[2] = 0x00;
    if (!this->c->sendFrame(CAN_BUS_B, &f)) {
        Serial.println(F("Error sending ESP off command"));
    }
}
