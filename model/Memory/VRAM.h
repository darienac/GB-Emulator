//
// Created by Tyson Peterson on 2/26/24.
//
#include <cstdint>

#ifndef GAMEBOY_EMULATOR_VRAM_H
#define GAMEBOY_EMULATOR_VRAM_H


class VRAM {
private:
    uint8_t ram[0x2000];
public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_VRAM_H
