//
// Created by Tyson Peterson on 2/26/24.
//

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>

#ifndef GAMEBOY_EMULATOR_PPU_H
#define GAMEBOY_EMULATOR_PPU_H

struct OAMEntry {
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

class PPU {
private:
    OAMEntry oamRAM[40];

public:
    PPU();
    void ppu_tick();

    char** debugTiles();
};


#endif //GAMEBOY_EMULATOR_PPU_H
