//
// Created by Tyson Peterson on 2/28/24.
//

#ifndef GAMEBOY_EMULATOR_IO_H
#define GAMEBOY_EMULATOR_IO_H

#include <cstdint>
#include "../PPU/LCD.h"

class IO {
private:
    LCD* lcd;
public:
    IO(LCD* lcd) : lcd(lcd) { }
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_IO_H
