//
// Created by dacma on 2/29/2024.
//

#include "Emulator.h"

void queueInterrupt(uint8_t mask, Bus* bus) {
    uint8_t data = bus->read(0xFF0F); // Interrupt flag
    data |= mask;
    bus->write(0xFF0F, data);
}

Emulator::Emulator(IScreen *screen, IControls *controls, const std::string& cartPath): screen(screen), controls(controls) {
    cpu = new CPU();

    cart = new Cartridge(cartPath);
    vRam = new VRAM();
    oamRam = new OamRAM();
    hRam = new HRAM();
    wRam = new WRAM();
    dma = new DMA(oamRam);
    lcd = new LCD(dma);
    gamepad = new Gamepad(controls);
    timer = new Timer();
    io = new IO(lcd, gamepad, timer);
    bus = new Bus(cart, vRam, oamRam, hRam, wRam, dma, io);
    ppu = new PPU(lcd, bus, this);

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
            dma->tick();
            ppuTicks++;
            syncCPUWithPPU();
        }
        while (lcd->getLcdMode() == lcdMode::MODE_XFER) {
            ppu->tick();
            dma->tick();
            ppuTicks++;
            syncCPUWithPPU();
        }
        while (lcd->getLcdMode() == lcdMode::MODE_HBLANK) {
            ppu->tick();
            dma->tick();
            ppuTicks++;
            syncCPUWithPPU();
        }
    }
    while (lcd->getLcdMode() == lcdMode::MODE_VBLANK) {
        ppu->tick();
        dma->tick();
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
    delete gamepad;
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

void Emulator::triggerInterrupt(InterruptType interrupt) {
    switch(interrupt) {
        case InterruptType::STAT:
            // TODO: Figure this out (FF41 register)
            break;
        case InterruptType::VBLANK:
            queueInterrupt(1, bus);
            break;
        default:
            break;
    }
}

void Emulator::updateFrame(char **frame) {
    // May have to reverse 1 or 2 of the loops if the image is flipped
    unsigned char** screenOut = screen->getBitmap();
    for (uint8_t r = 0; r < 144; r++) {
        for (uint8_t c = 0; c < 160; c++) {
            screenOut[r][c] = frame[r][c];
        }
    }
}
