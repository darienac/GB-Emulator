//
// Created by BYU Rental on 3/1/2024.
//

#ifndef GAMEBOY_EMULATOR_IO_H
#define GAMEBOY_EMULATOR_IO_H

#include <cstdint>
#include "Gamepad.h"
#include "../PPU/LCD.h"

class IO{
private:
    Gamepad* gamepad;
    LCD* lcd;

public:
    IO(LCD* lcd, Gamepad* gamepad) : lcd(lcd), gamepad(gamepad){}

    uint8_t io_read(uint16_t address);

    void io_write(uint16_t address, uint8_t value);
};

#endif //GAMEBOY_EMULATOR_IO_H
