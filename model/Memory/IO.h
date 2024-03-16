//
// Created by Tyson Peterson on 2/28/24.
//

#ifndef GAMEBOY_EMULATOR_IO_H
#define GAMEBOY_EMULATOR_IO_H

#include <cstdint>
#include "../PPU/LCD.h"
#include "Gamepad.h"
#include "Timer.h"

class IO {
private:
    LCD* lcd;
    Gamepad* gamepad;
    Timer* timer;
    static uint8_t serialData[2];


public:
    IO(LCD* lcd, Gamepad* gamepad, Timer* timer) : lcd(lcd), gamepad(gamepad), timer(timer){ }
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_IO_H
