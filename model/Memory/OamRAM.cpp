//
// Created by Tyson Peterson on 2/26/24.
//

#include "OamRAM.h"

uint8_t OamRAM::read(uint16_t address) {
    if (address >= 0xFE00) address -= 0xFE00;

    auto *p = reinterpret_cast<uint8_t*>(ram);
    return p[address];
}
void OamRAM::write(uint16_t address, uint8_t value) {
    if (address >= 0xFE00) address -= 0xFE00;

    auto *p = reinterpret_cast<uint8_t*>(ram);
    p[address] = value;
}

OamEntry OamRAM::getOamEntry(int index) {
    return ram[index];
}
