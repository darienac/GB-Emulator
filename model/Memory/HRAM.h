//
// Created by Tyson Peterson on 2/26/24.
//

#include <cstdint>

#ifndef GAMEBOY_EMULATOR_HRAM_H
#define GAMEBOY_EMULATOR_HRAM_H


class HRAM {
private:
    uint8_t ram[0x80];
public:
    void write(uint16_t address, uint8_t value);
    uint8_t read(uint16_t address);
};


#endif //GAMEBOY_EMULATOR_HRAM_H
