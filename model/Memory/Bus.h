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
#include "DMA.h"

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
    Bus(Cartridge* cart, VRAM* vRam, OamRAM* oamRam, HRAM* hram, WRAM* wram, DMA* dma/*, CPU* cpu*/) :
            cart(cart), vRam(vRam), oamRam(oamRam), hRam(hram), dma(dma) /*, cpu(cpu)*/ {}

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_BUS_H