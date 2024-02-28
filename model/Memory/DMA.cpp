//
// Created by Tyson Peterson on 2/26/24.
//

#include "DMA.h"

void DMA::start(uint8_t start) {
    active = true;
    byte = 0;
    startDelay = 2;
    value = start;
}

void DMA::tick() {
    if (!active) {
        return;
    }

    if (startDelay) {
        startDelay--;
        return;
    }

    oamRam->write(byte, bus->read((value * 0x100) + byte));

    byte++;

    active = byte < 0xA0;
}

bool DMA::transferring() {
    return active;
}
