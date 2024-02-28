//
// Created by Tyson Peterson on 2/26/24.
//

#include "VRAM.h"

uint8_t VRAM::read(uint16_t address) {
    if (address >= 0xFE00) address -= 0xFE00;
    return ram[address];
}
void VRAM::write(uint16_t address, uint8_t value) {
    if (address >= 0xFE00) address -= 0xFE00;
    ram[address] = value;
}