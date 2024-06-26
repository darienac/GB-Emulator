//
// Created by Tyson Peterson on 2/26/24.
//

#include "HRAM.h"

void HRAM::write(uint16_t address, uint8_t value) {
    address -= 0xFF80;
    ram[address] = value;
}

uint8_t HRAM::read(uint16_t address) {
    address -= 0xFF80;
    return ram[address];
}
