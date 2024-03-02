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
    bus = new Bus(cart, vRam, oamRam, hRam, wRam, dma);
}

void Emulator::runFrame() {
    // TODO: make this do stuff
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
    delete bus;
}
