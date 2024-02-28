//
// Created by Tyson Peterson on 2/26/24.
//


#ifndef GAMEBOY_EMULATOR_DMA_H
#define GAMEBOY_EMULATOR_DMA_H

//#include "Bus.h"
#include "OamRam.h"
#include <cstdint>


class DMA {
private:
    bool active;
    uint8_t byte;
    uint8_t value;
    uint8_t startDelay;

//    Bus* bus;
    OamRAM* oamRam;
public:
//    DMA(Bus* bus, OamRAM* oamRam) : bus(bus), oamRam(oamRam) {}
    DMA(OamRAM* oamRam) : oamRam(oamRam) {}

    void start(uint8_t start);
    void tick();

    bool transferring();
};


#endif //GAMEBOY_EMULATOR_DMA_H
