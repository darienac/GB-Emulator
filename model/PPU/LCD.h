//
// Created by Tyson Peterson on 2/27/24.
//

#ifndef GAMEBOY_EMULATOR_LCD_H
#define GAMEBOY_EMULATOR_LCD_H

#include <cstdint>
#include "../Memory/DMA.h"
#include "../BitManip.h"
#include "../Structs.h"

enum lcdMode {
    MODE_HBLANK,
    MODE_VBLANK,
    MODE_OAM,
    MODE_XFER
};

class LCD {
private:
    LcdRegs lcdRegs;

    DMA* dma;

    unsigned char colorsDefault[4] = {3, 2, 1, 0};
public:
    uint8_t bgColors[4];
    uint8_t sp1Colors[4];
    uint8_t sp2Colors[4];

    LCD(DMA* dma);

    void resetLy();
    uint8_t getLy();
    void incrementLy();

    uint8_t getWinY() { return lcdRegs.winY; }
    uint8_t getWinX() { return lcdRegs.winX; }


    uint8_t getLyCompare();

    //Control register settings
    bool getBgWEnabled() const;
    bool getObjEnabled() const;
    uint8_t getObjHeight() const;
    uint16_t getBgMapArea() const;
    uint16_t getBgWDataArea() const;
    bool getWinEnabled() const;
    uint16_t getWinMapArea() const;
    bool getLcdEnabled() const;

    //Status register settings
    lcdMode getLcdMode() const;
    void setLcdMode(lcdMode mode);
    bool getLycFlag() const;
    void setLycFlag(bool value);
    bool getHBlankInt() const;
    bool getVBlankInt() const;
    bool getOAMInt() const;
    bool getLycInt() const;

    uint8_t read(uint16_t address);
    void write(uint16_t address, uint8_t value);

    void updatePalette(uint8_t paletteData, uint8_t palette);

    uint8_t getScrollY();

    uint8_t getScrollX();
};


#endif //GAMEBOY_EMULATOR_LCD_H
