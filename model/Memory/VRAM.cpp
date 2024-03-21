//
// Created by Tyson Peterson on 2/26/24.
//

#include "VRAM.h"

uint8_t VRAM::read(uint16_t address) {
    if (address >= 0x8000) address -= 0x8000;
    return ram[address];
}
void VRAM::write(uint16_t address, uint8_t value) {
    if (address >= 0x8000) address -= 0x8000;
    ram[address] = value;
}