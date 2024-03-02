//
// Created by Tyson Peterson on 2/28/24.
//

#include "IO.h"

uint8_t IO::read(uint16_t address) {
    if (address == 0xFF00) {
        //Gamepad stuff
    }

    if (address == 0xFF01) {
        //Link Cable Stuff
    }

    if (address == 0xFF02) {
        //Link Cable Stuff
    }

    if (0xFF04 <= address && address <= 0xFF07) {
        //Timer Stuff
    }

    if (address == 0xFF0F) {
        //Interrupt stuff
    }

    if (0xFF10 <= address && address <= 0xFF3F) {
        //Sound Stuff
    }

    if (0xFF40 <= address && address <= 0xFF4B) {
        //Screen Stuff
        return lcd->read(address);
    }

    //Unsupported
    return 0;
}

void IO::write(uint16_t address, uint8_t value) {
    if (address == 0xFF00) {
        //Gamepad Stuff
    }

    if (address == 0xFF01) {
        //Link Cable Stuff
    }

    if (address == 0xFF02) {
        //Link Cable Stuff
    }

    if (0xFF04 <= address && address <= 0xFF07) {
        //Timer Stuff
    }

    if (address == 0xFF0F) {
        //Interrupt Stuff
    }

    if (0xFF10 <= address && address <= 0xFF3F) {
        //Sound Stuff
    }

    if (0xFF40 <= address && address <= 0xFF4B) {
        lcd->write(address, value);
        return;
    }

    //Unsupported
    return;
}
