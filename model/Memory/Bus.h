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
#include "IO.h"
#include "CPU.h"

class DMA;

class Bus {
private:
    Cartridge* cart;
    VRAM* vRam;
    OamRAM* oamRam;
    HRAM* hRam;
    WRAM* wRam;
    IO* io;
    CPU* cpu;

    DMA* dma;
public:
    Bus(Cartridge* cart, VRAM* vRam, OamRAM* oamRam, HRAM* hram, WRAM* wRam, DMA* dma, IO* io) :
            cart(cart), vRam(vRam), wRam(wRam), oamRam(oamRam), hRam(hram), dma(dma), io(io) {}

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);
};


#endif //GAMEBOY_EMULATOR_BUS_H