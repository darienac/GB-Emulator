//
// Created by Tyson Peterson on 2/26/24.
//



#ifndef GAMEBOY_EMULATOR_PPU_H
#define GAMEBOY_EMULATOR_PPU_H

#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <deque>
#include "LCD.h"
#include "../Memory/Bus.h"

static const int LINES_PER_FRAME = 154;
static const int TICKS_PER_LINE = 456;
static const int Y_RES = 144;
static const int X_RES = 160 ;

enum FetchState {
    TILE,
    DATA0,
    DATA1,
    SLEEP,
    PUSH
};

class PPU {
private:
    uint32_t currFrame;
    uint32_t lineTicks;

    char** display;

    LCD* lcd;
    Bus* bus;

    //Pipeline Stuff
    FetchState fetchState;
    uint8_t lineX;
    uint8_t pushX;
    uint8_t fetchX;
    uint8_t bgwFetchData[3];
    uint8_t fetchEntryData[6];
    uint8_t mapY;
    uint8_t mapX;
    uint8_t tileY;
    uint8_t fifoX;

    std::deque<uint8_t> fifo;

    void runOamMode();
    void runXferMode();
    void runVBlankMode();
    void runHBlankMode();

    void handleLy();

    void fifoPush(uint8_t value);
    uint8_t fifoPop();

    void pipelineZeros();
    void pipelineProcess();
    bool pipelineAdd();
    void pipelineReset();
    void pushPixel();
    void fetchPixel();

public:
    PPU(LCD* lcd, Bus* bus);
    void tick();
};


#endif //GAMEBOY_EMULATOR_PPU_H
