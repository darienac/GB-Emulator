//
// Created by Tyson Peterson on 2/26/24.
//

#include <cstdint>

#ifndef GAMEBOY_EMULATOR_OAMRAM_H
#define GAMEBOY_EMULATOR_OAMRAM_H

struct OamEntry {
    uint8_t x;
    uint8_t y;
    uint8_t tile;

    unsigned f_gbc_pn : 3;
    unsigned f_gbc_vram_bank : 1;
    unsigned f_pn : 1;
    unsigned f_x_flip : 1;
    unsigned f_y_flip : 1;
    unsigned f_bgp : 1;
};

class OamRAM {
private:
    OamEntry ram[40];
public:
    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_OAMRAM_H
