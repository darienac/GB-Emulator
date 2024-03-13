//
// Created by dacma on 2/29/2024.
//

#include "Emulator.h"

Emulator::Emulator(IScreen *screen, IControls *controls, const std::string& cartPath): screen(screen), controls(controls) {
    cpu = new CPU();

    cart = new Cartridge(cartPath);
    vRam = new VRAM();
    oamRam = new OamRAM();
    hRam = new HRAM();
    wRam = new WRAM();
    dma = new DMA(oamRam);
    lcd = new LCD(dma);
    io = new IO(lcd);
    bus = new Bus(cart, vRam, oamRam, hRam, wRam, dma, io);
    ppu = new PPU(lcd, bus);

    targetCPUDotCount = cpu->getCycleCount();
    lastPPUTicks = 0;
    ppuTicks = 0;

    cart->printHeaderInfo();
}

void Emulator::runFrame() {
//    cpu->tick(*bus);
//    ppu->tick();
//    for (unsigned int r = 0; r < 144; r++) {
//        ppuMode = OAM_SCAN;
//        cpuRunForDots(80);
//        ppuMode = DRAW_PIXELS;
//        cpuRunForDots(172); // Certain operations make drawing take longer, but not considering that for now
//        ppuMode = HBLANK;
//        cpuRunForDots(204); // differs based on length of DRAW_PIXELS mode
//    }
//    ppuMode = VBLANK;
//    cpuRunForDots(4560);
    for (uint8_t r = 0; r < 144; r++) {
        while (lcd->getLcdMode() == lcdMode::MODE_OAM) {
            ppu->tick();
            ppuTicks++;
            syncCPUWithPPU();
        }
        while (lcd->getLcdMode() == lcdMode::MODE_XFER) {
            ppu->tick();
            ppuTicks++;
            syncCPUWithPPU();
        }
        while (lcd->getLcdMode() == lcdMode::MODE_HBLANK) {
            ppu->tick();
            ppuTicks++;
            syncCPUWithPPU();
        }
    }
    while (lcd->getLcdMode() == lcdMode::MODE_VBLANK) {
        ppu->tick();
        ppuTicks++;
        syncCPUWithPPU();
    }
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

void Emulator::cpuRunForDots(unsigned int dots) {
    targetCPUDotCount += dots;
    while (cpu->getCycleCount() < targetCPUDotCount) {
        cpu->tick(*bus);
    }
}

void Emulator::syncCPUWithPPU() {
    cpuRunForDots(ppuTicks - lastPPUTicks);
    lastPPUTicks = ppuTicks;
}
