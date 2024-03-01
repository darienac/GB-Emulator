//
// Created by Tyson Peterson on 2/27/24.
//

#include "BitManip.h"

void BitManip::setBit(uint8_t *byte, uint8_t pos, bool value) {
    if (value) *byte |= (1 << pos);
    else *byte &= ~(1 << pos);
}

bool BitManip::getBit(uint8_t byte, uint8_t pos) {
    if (byte & (1 << pos)) return true;
    else return false;
}
