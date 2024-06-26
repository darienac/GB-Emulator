//
// Created by Tyson Peterson on 3/12/24.
//

#ifndef GAMEBOY_EMULATOR_STRUCTS_H
#define GAMEBOY_EMULATOR_STRUCTS_H

struct OamEntry {
    uint8_t y;
    uint8_t x;
    uint8_t tile;

    uint8_t f_gbc_pn : 3; // CGB palette
    uint8_t f_gbc_vram_bank : 1; // Bank
    uint8_t f_pn : 1; // DMG palette
    uint8_t f_x_flip : 1; // X flip
    uint8_t f_y_flip : 1; // Y flip
    uint8_t f_bgp : 1; // Priority
};

struct LcdRegs {
    uint8_t lcdControl;
    uint8_t lcdStatus;

    uint8_t scrollY;
    uint8_t scrollX;
    uint8_t ly;
    uint8_t lyCompare;
    uint8_t dma;
    uint8_t bgPalette;
    uint8_t spPalette[2];

    uint8_t winY;
    uint8_t winX;
};

#endif //GAMEBOY_EMULATOR_STRUCTS_H
