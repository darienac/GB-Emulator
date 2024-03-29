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

class DMA;

class Bus {
private:
    Cartridge* cart;
    VRAM* vRam;
    OamRAM* oamRam;
    HRAM* hRam;
    WRAM* wRam;
    IO* io;

    DMA* dma;

    uint8_t interruptFlag = 0xE0;
    uint8_t interruptEnable = 0x00;
public:
    Bus(Cartridge* cart, VRAM* vRam, OamRAM* oamRam, HRAM* hram, WRAM* wRam, DMA* dma, IO* io) :
            cart(cart), vRam(vRam), wRam(wRam), oamRam(oamRam), hRam(hram), dma(dma), io(io) {}

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);

    OamEntry getOamEntry(int index) { return oamRam->getOamEntry(index); }
};


#endif //GAMEBOY_EMULATOR_BUS_H