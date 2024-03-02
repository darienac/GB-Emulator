//
// Created by Tyson Peterson on 2/27/24.
//

#ifndef GAMEBOY_EMULATOR_BITMANIP_H
#define GAMEBOY_EMULATOR_BITMANIP_H

#include <cstdint>

class BitManip {
public:
    static bool getBit(uint8_t byte, uint8_t pos);
    static void setBit(uint8_t* byte, uint8_t pos, bool value);
};


#endif //GAMEBOY_EMULATOR_BITMANIP_H
