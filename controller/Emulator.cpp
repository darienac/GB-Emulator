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
    dma = new DMA(bus, oamRam);
    lcd = new LCD(dma);
    gamepad = new Gamepad(controls, this);
    timer = new Timer(this);
    io = new IO(lcd, gamepad, timer);
    bus = new Bus(cart, vRam, oamRam, hRam, wRam, dma, io);
    ppu = new PPU(lcd, bus, this);

    targetCPUDotCount = cpu->getCycleCount();
    lastPPUTicks = 0;
    ppuTicks = 0;

    cart->printHeaderInfo();
}

void Emulator::runFrame() {
    gamepad->checkForInterrupt();
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
    for (unsigned int i = 0; i < dots; i++) {
        timer->timerTick();
    }
}

void Emulator::syncCPUWithPPU() {
    cpuRunForDots(ppuTicks - lastPPUTicks);
    lastPPUTicks = ppuTicks;
}

void Emulator::triggerInterrupt(InterruptType interrupt) {
    switch(interrupt) {
        case InterruptType::STAT:
            queueInterrupt(2, bus);
            break;
        case InterruptType::VBLANK:
            queueInterrupt(1, bus);
            break;
        case InterruptType::TIMER:
            queueInterrupt(4, bus);
            break;
        case InterruptType::JOYPAD:
            queueInterrupt(16, bus);
            break;
        case InterruptType::SERIAL:
            queueInterrupt(8, bus);
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
