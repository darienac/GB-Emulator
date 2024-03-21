//
// Created by Tyson Peterson on 2/26/24.
//

#include <cstdint>

#ifndef GAMEBOY_EMULATOR_OAMRAM_H
#define GAMEBOY_EMULATOR_OAMRAM_H

#include "../Structs.h"

class OamRAM {
private:
    OamEntry ram[40];
public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);

    OamEntry getOamEntry(int index);
};


#endif //GAMEBOY_EMULATOR_OAMRAM_H
