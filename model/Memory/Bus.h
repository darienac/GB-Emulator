//
// Created by Tyson Peterson on 2/26/24.
//

#ifndef GAMEBOY_EMULATOR_BUS_H
#define GAMEBOY_EMULATOR_BUS_H

#include <cstdint>
#include "Cartridge.h"
#include "VRAM.h"
#include "OamRAM.h"
#include "HRAM.h"
#include "WRAM.h"

class DMA;
class Bus {
private:
    Cartridge* cart;
    VRAM* vRam;
    OamRAM* oamRam;
    HRAM* hRam;
    WRAM* wRam;

    //CPU* cpu to set the enable register
    //IO*
    DMA* dma;
public:
    Bus(Cartridge* cart, VRAM* vRam, OamRAM* oamRam, HRAM* hram, WRAM* wRam, DMA* dma) :
            cart(cart), vRam(vRam), wRam(wRam), oamRam(oamRam), hRam(hram), dma(dma) {}

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_BUS_H