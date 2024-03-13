//
// Created by Tyson Peterson on 2/26/24.
//

#include "PPU.h"

PPU::PPU(LCD* lcd, Bus* bus) : lcd(lcd) {
    currFrame = 0;
    lineTicks = 0;
    pipelineZeros();

    display =  new char*[Y_RES];
    for (int x = 0; x < Y_RES; x++)
    {
        display[x] = new char[X_RES];
    }
}

void PPU::tick() {
    lineTicks++;

    switch(lcd->getLcdMode()) {
        case MODE_OAM:
            runOamMode();
            break;
        case MODE_XFER:
            runXferMode();
            break;
        case MODE_VBLANK:
            runVBlankMode();
            break;
        case MODE_HBLANK:
            runHBlankMode();
            break;
    }
};

void PPU::runOamMode() {
    if (lineTicks >= 80) {
        lcd->setLcdMode(MODE_XFER);
        pipelineZeros();
    }
}

void PPU::runXferMode() {
    pipelineProcess();
    if (pushX >= X_RES) lcd->setLcdMode(MODE_HBLANK);
}

void PPU::runVBlankMode() {
    if (lineTicks >= TICKS_PER_LINE) {
        //Increment and check line count
        handleLy();

        if (lcd->getLy() >= LINES_PER_FRAME) {
            lcd->setLcdMode(MODE_OAM);
            lcd->resetLy();
        }

        lineTicks = 0;
    }
}

void PPU::runHBlankMode() {
    if (lineTicks >= TICKS_PER_LINE) {
        //Increment and check line count
        handleLy();

        if (lcd->getLy() >= Y_RES) {
            lcd->setLcdMode(MODE_VBLANK);

            //TODO send VBLANK interrupt
            if (lcd->getVBlankInt()) {
                //TODO send STAT interrupt
            }

            currFrame++;
        } else {
            lcd->setLcdMode(MODE_OAM);
        }
        //TODO send display to UI
        lineTicks = 0;
    }
}

void PPU::handleLy() {
    lcd->incrementLy();
    if (lcd->getLy() == lcd->getLyCompare()) {
        lcd->setLycFlag(true);
        lcd->resetLy();

        if (lcd->getLycInt()) {
            //TODO send STAT interrupt
        }

    } else {
        lcd->setLycFlag(false);
    }
}

void PPU::fifoPush(uint8_t value) {
    fifo.push_back(value);
}

uint8_t PPU::fifoPop() {
    uint8_t returnValue = fifo.front();
    fifo.pop_front();
    return returnValue;
}

void PPU::pipelineZeros() {
    fetchState = TILE;
    lineX = 0;
    fetchX = 0;
    pushX = 0;
    fifoX = 0;
}

void PPU::pipelineProcess() {
    mapY = lcd->getLy() + lcd->getScrollY();
    mapX = fetchX + lcd->getScrollX();
    tileY = ((lcd->getLy() + lcd->getScrollY()) % 8) * 2;

    //Every other line
    if (!(lineTicks % 2)) {
        fetchPixel();
    }
    pushPixel();
}

void PPU ::pushPixel() {
    if (fifo.size() > 8) {
        uint8_t pixel = fifoPop();

        if (lineX >= (lcd->getScrollX() % 8)) {
            display[lcd->getLy()][pushX] = pixel;
            pushX++;
        }

        lineX++;
    }
}

void PPU::fetchPixel() {
    switch (fetchState) {
        case TILE:
            if (lcd->getBgWEnabled()) {
                bgwFetchData[0] = bus->read(lcd->getBgMapArea() + (mapX / 8) + ((mapY / 8) * 32));

                if (lcd->getBgWDataArea() == 0x8800) {
                    bgwFetchData[0] += 128;
                }

                fetchX += 8;
                fetchState = DATA0;
            }
            break;
        case DATA0:
            bgwFetchData[1] = bus->read(lcd->getBgWDataArea() + bgwFetchData[0] * 16 + tileY);
            fetchState = DATA1;
            break;
        case DATA1:
            bgwFetchData[2] = bus->read(lcd->getBgWDataArea() + bgwFetchData[0] * 16 + tileY + 1);
            fetchState = SLEEP;
            break;
        case SLEEP:
            fetchState = PUSH;
            break;
        case PUSH:
            if (pipelineAdd()) {
                fetchState = TILE;
            }
            break;
    }
}

bool PPU::pipelineAdd() {
    if (fifo.size() > 8) return false;
    int x = fetchX - (8 - lcd->getScrollX() % 8);

    //Calculate pixel intensity
    for (int bit = 7; bit >= 0; bit--) {
        uint8_t low = ((bgwFetchData[1] & (1 << bit)) != 0);
        uint8_t high = ((bgwFetchData[2] & (1 << bit)) != 0) << 1;
        uint8_t pixel = high | low;

        if (x >= 0) {
            fifoPush(pixel);
            fifoX++;
        }
    }

    return true;
}

void PPU::pipelineReset() {
    while (fifo.size() > 0) fifo.pop_front();
}
