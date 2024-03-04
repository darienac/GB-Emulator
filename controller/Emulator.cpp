//
// Created by dacma on 2/29/2024.
//

#include "Emulator.h"

Emulator::Emulator(IScreen *screen, IControls *controls, const std::string& cartPath): screen(screen), controls(controls) {
    cpu = new CPU();
    ppu = new PPU();

    cart = new Cartridge(cartPath);
    vRam = new VRAM();
    oamRam = new OamRAM();
    hRam = new HRAM();
    wRam = new WRAM();
    dma = new DMA(oamRam);
    lcd = new LCD(dma);
    io = new IO(lcd);
    bus = new Bus(cart, vRam, oamRam, hRam, wRam, dma, io);

    targetCPUDotCount = cpu->getCycleCount();

    cart->printHeaderInfo();
}

void Emulator::runFrame() {
//    cpu->tick(*bus);
//    ppu->ppu_tick();
    for (unsigned int r = 0; r < 144; r++) {
        ppuMode = OAM_SCAN;
        runForDots(80);
        ppuMode = DRAW_PIXELS;
        runForDots(172); // Certain operations make drawing take longer, but not considering that for now
        ppuMode = HBLANK;
        runForDots(204); // differs based on length of DRAW_PIXELS mode
    }
    ppuMode = VBLANK;
    runForDots(4560);
}

Emulator::~Emulator() {
    delete cpu;
    delete ppu;

    delete cart;
    delete vRam;
    delete oamRam;
    delete hRam;
    delete wRam;
    delete dma;
    delete lcd;
    delete io;
    delete bus;
}

void Emulator::runForDots(unsigned int dots) {
//    ppu->ppu_tick();
    targetCPUDotCount += dots;
    while (cpu->getCycleCount() < targetCPUDotCount) {
        cpu->tick(*bus);
    }
}
