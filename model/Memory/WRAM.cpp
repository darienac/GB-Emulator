//
// Created by Tyson Peterson on 2/26/24.
//

#include "WRAM.h"

uint8_t WRAM::read(uint16_t address) {
    address -= 0xC000;
    return ram[address];
}

void WRAM::write(uint16_t address, uint8_t value) {
    address -= 0xC000;
    ram[address] = value;
}
