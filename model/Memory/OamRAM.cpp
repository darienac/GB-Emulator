//
// Created by Tyson Peterson on 2/26/24.
//

#include <iostream>
#include "OamRAM.h"

uint8_t OamRAM::read(uint16_t address) {
    if (address >= 0xFE00) address -= 0xFE00;
    uint8_t entryNum = address >> 2;
    uint8_t entryPos = address & 0x3;
    OamEntry* entry = &ram[entryNum];
    switch (entryPos) {
        case 0:
            return entry->y;
        case 1:
            return entry->x;
        case 2:
            return entry->tile;
        case 3:
            uint8_t out = 0;
            out |= entry->f_gbc_pn & 0b111;
            out |= (entry->f_gbc_vram_bank & 1) << 3;
            out |= (entry->f_pn & 1) << 4;
            out |= (entry->f_x_flip & 1) << 5;
            out |= (entry->f_y_flip & 1) << 6;
            out |= (entry->f_bgp & 1) << 7;
            return out;
    }

//    auto *p = reinterpret_cast<uint8_t*>(ram);
//    return p[address];
}

void OamRAM::write(uint16_t address, uint8_t value) {
    if (address >= 0xFE00) address -= 0xFE00;
    uint8_t entryNum = address >> 2;
    uint8_t entryPos = address & 0x3;
    OamEntry* entry = &ram[entryNum];
    switch (entryPos) {
        case 0:
            entry->y = value;
            break;
        case 1:
            entry->x = value;
            break;
        case 2:
            entry->tile = value;
            break;
        case 3:
            entry->f_gbc_pn = value & 0b111;
            value = value >> 3;
            entry->f_gbc_vram_bank = value & 1;
            value = value >> 1;
            entry->f_pn = value & 1;
            value = value >> 1;
            entry->f_x_flip = value & 1;
            value = value >> 1;
            entry->f_y_flip = value & 1;
            value = value >> 1;
            entry->f_bgp = value & 1;
            break;
    }
//    auto *p = reinterpret_cast<uint8_t*>(ram);
//    p[address] = value;
}

OamEntry OamRAM::getOamEntry(int index) {
    return ram[index];
}
