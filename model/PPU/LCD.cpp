//
// Created by Tyson Peterson on 2/27/24.
//

#include "LCD.h"

LCD::LCD(DMA* dma) : dma(dma) {
    lcdRegs.lcdControl = 0x91;
    lcdRegs.scrollX = 0;
    lcdRegs.scrollY = 0;
    lcdRegs.ly = 0;
    lcdRegs.lyCompare = 0;
    lcdRegs.bgPalette = 0xFC;
    lcdRegs.spPalette[0] = 0xFF;
    lcdRegs.spPalette[1] = 0xFF;
    lcdRegs.winX = 0;
    lcdRegs.winY = 0;

    setLcdMode(MODE_OAM);

    for (int i = 0; i < 4; i++) bgColors[i] = sp1Colors[i] = sp2Colors[i] = colorsDefault[i];
}

bool LCD::getObjEnabled() const { return BitManip::getBit(lcdRegs.lcdControl, 1); }
bool LCD::getBgWEnabled() const { return BitManip::getBit(lcdRegs.lcdControl, 0); }
uint8_t LCD::getObjHeight() const { return BitManip::getBit(lcdRegs.lcdControl, 2) ? 16 : 8; }
uint16_t LCD::getBgMapArea() const { return BitManip::getBit(lcdRegs.lcdControl, 3) ? 0x9C00 : 0x9800; }
uint16_t LCD::getBgWDataArea() const { return BitManip::getBit(lcdRegs.lcdControl, 4) ? 0x8000 : 0x8800; }
bool LCD::getWinEnabled() const { return BitManip::getBit(lcdRegs.lcdControl, 5); }
uint16_t LCD::getWinMapArea() const { return BitManip::getBit(lcdRegs.lcdControl, 6) ? 0x9C00 : 0x9800; }
bool LCD::getLcdEnabled() const { return BitManip::getBit(lcdRegs.lcdControl, 7); }

//First 2 bits
lcdMode LCD::getLcdMode() const { return static_cast<lcdMode>(lcdRegs.lcdStatus & 0b11); }
void LCD::setLcdMode(lcdMode mode) { lcdRegs.lcdStatus &= ~0b11; lcdRegs.lcdStatus |= mode; }

// 1 bit
bool LCD::getLycFlag() const { return BitManip::getBit(lcdRegs.lcdStatus, 2); }
void LCD::setLycFlag(bool value) { BitManip::setBit(&lcdRegs.lcdStatus, 2, value); }

// 1 bit
bool LCD::getHBlankInt() const { return BitManip::getBit(lcdRegs.lcdStatus, 3);}
bool LCD::getVBlankInt() const { return BitManip::getBit(lcdRegs.lcdStatus, 4);}

bool LCD::getOAMInt() const { return BitManip::getBit(lcdRegs.lcdStatus, 5);}
bool LCD::getLycInt() const { return BitManip::getBit(lcdRegs.lcdStatus, 6);}

uint8_t LCD::read(uint16_t address) {
    int offset = address - 0xFF40;
    auto *p = reinterpret_cast<uint8_t*>(&lcdRegs);
    return p[offset];
}

void LCD::write(uint16_t address, uint8_t value) {
    int offset = address - 0xFF40;
    auto *p = reinterpret_cast<uint8_t*>(&lcdRegs);
    p[offset] = value;
    if (offset == 6) {
        //0xFF46 = DMA
        dma->start(value);
    }

    if (address == 0xFF47) {
        updatePalette(value, 0);
    } else if (address == 0xFF48) {
        updatePalette(value & 0b11111100, 1);
    } else if (address == 0xFF49) {
        updatePalette(value & 0b11111100, 2);
    }
}

void LCD::updatePalette(uint8_t paletteData, uint8_t palette) {
    if (palette == 0) {
        bgColors[0] = colorsDefault[paletteData & 0b11];
        bgColors[1] = colorsDefault[(paletteData) >> 2 & 0b11];
        bgColors[2] = colorsDefault[(paletteData) >> 4 & 0b11];
        bgColors[3] = colorsDefault[(paletteData) >> 6 & 0b11];
    } else if (palette == 1) {
        sp1Colors[0] = colorsDefault[paletteData & 0b11];
        sp1Colors[1] = colorsDefault[(paletteData) >> 2 & 0b11];
        sp1Colors[2] = colorsDefault[(paletteData) >> 4 & 0b11];
        sp1Colors[3] = colorsDefault[(paletteData) >> 6 & 0b11];
    } else if (palette == 2) {
        sp2Colors[0] = colorsDefault[paletteData & 0b11];
        sp2Colors[1] = colorsDefault[(paletteData) >> 2 & 0b11];
        sp2Colors[2] = colorsDefault[(paletteData) >> 4 & 0b11];
        sp2Colors[3] = colorsDefault[(paletteData) >> 6 & 0b11];
    }

}

uint8_t LCD::getLy() {
    return lcdRegs.ly;
}

void LCD::incrementLy() { // TODO: make sure I did this right
    lcdRegs.ly++;
}

uint8_t LCD::getLyCompare() { // TODO: make sure I did this right also
    return lcdRegs.lyCompare;
}


void LCD::resetLy() {
    lcdRegs.ly = 0;
}

uint8_t LCD::getScrollY() {
    return lcdRegs.scrollY;
}

uint8_t LCD::getScrollX() {
    return lcdRegs.scrollX;
}


