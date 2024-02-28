//
// Created by Tyson Peterson on 2/26/24.
//

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>

#ifndef GAMEBOY_EMULATOR_PPU_H
#define GAMEBOY_EMULATOR_PPU_H

class PPU {
private:

public:
    PPU();
    void ppu_tick();

    char** debugTiles();
};


#endif //GAMEBOY_EMULATOR_PPU_H
