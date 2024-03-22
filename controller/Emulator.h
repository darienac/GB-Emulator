//
// Created by dacma on 2/29/2024.
//

#ifndef GAMEBOY_EMULATOR_EMULATOR_H
#define GAMEBOY_EMULATOR_EMULATOR_H


#include "IControls.h"
#include "IScreen.h"
#include "../model/IEmulator.h"
#include "../model/CPU/CPU.h"
#include "../model/PPU/PPU.h"

class Emulator : public IEmulator {
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
    Gamepad* gamepad;
    Timer* timer;
    IO* io;

    // runtime state
    unsigned int targetCPUDotCount;
    unsigned int lastPPUTicks;
    unsigned int ppuTicks;

    void cpuRunForDots(unsigned int dots);
    void syncCPUWithPPU();
public:
    Emulator(IScreen* screen, IControls* controls, const std::string& cartPath);

    void runFrame();

    void triggerInterrupt(InterruptType interrupt) override;
    void updateFrame(char** frame) override;

    ~Emulator();
};


#endif //GAMEBOY_EMULATOR_EMULATOR_H
