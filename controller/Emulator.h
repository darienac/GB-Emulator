//
// Created by dacma on 2/29/2024.
//

#ifndef GAMEBOY_EMULATOR_EMULATOR_H
#define GAMEBOY_EMULATOR_EMULATOR_H


#include "IControls.h"
#include "IScreen.h"
#include "../model/CPU/CPU.h"
#include "../model/PPU/PPU.h"

class Emulator {
public:
    enum PPU_Mode {
        HBLANK,
        VBLANK,
        OAM_SCAN,
        DRAW_PIXELS
    };
private:
    // view interfaces
    IScreen* screen;
    IControls* controls;
    // model classes
    CPU* cpu;
    PPU* ppu;

    Cartridge* cart;
    VRAM* vRam;
    OamRAM* oamRam;
    HRAM* hRam;
    WRAM* wRam;
    DMA* dma;
    Bus* bus;
    LCD* lcd;
    IO* io;

    // runtime state
    PPU_Mode ppuMode;
    unsigned int targetCPUDotCount;

    void runForDots(unsigned int dots);
public:
    Emulator(IScreen* screen, IControls* controls, const std::string& cartPath);

    void runFrame();

    ~Emulator();
};


#endif //GAMEBOY_EMULATOR_EMULATOR_H
