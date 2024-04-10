//
// Created by Tyson Peterson on 2/26/24.
//

#include "PPU.h"

PPU::PPU(LCD* lcd, Bus* bus, IEmulator* emu) : lcd(lcd), emu(emu), bus(bus) {
    currFrame = 0;
    lineTicks = 0;
    windowLine = 0;

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
}

void PPU::runOamMode() {
    if (lineTicks >= 80) {
        lcd->setLcdMode(MODE_XFER);
        pipelineZeros();
    }
    if (lineTicks == 0) {
        loadLineSprites();
    }
}

void PPU::runXferMode() {
    pipelineProcess();
    if (pushX >= X_RES) {
        pipelineReset();

        lcd->setLcdMode(MODE_HBLANK);
    }
}

void PPU::runVBlankMode() {
    if (lineTicks >= TICKS_PER_LINE) {
        //Increment and check line count
        handleLy();
        if (lcd->getLy() >= LINES_PER_FRAME) {
            lcd->setLcdMode(MODE_OAM);
            lcd->resetLy();
            windowLine = 0;
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

            emu->triggerInterrupt(VBLANK);
            if (lcd->getVBlankInt()) {
                emu->triggerInterrupt(STAT);
            }

            currFrame++;


        } else {
            lcd->setLcdMode(MODE_OAM);
        }

        emu->updateFrame(display);
    }
}

bool PPU::windowVisible() {
    return lcd->getWinEnabled() && lcd->getWinX() >= 0 && lcd->getWinX() < X_RES && lcd->getWinY() >= 0 &&
           lcd->getWinY() < Y_RES;
}

void PPU::handleLy() {
    if (windowVisible() && lcd->getLy() >= lcd->getWinY() && lcd->getLy() < lcd->getWinY() + Y_RES) windowLine++;

    lcd->incrementLy();

    if (lcd->getLy() == lcd->getLyCompare()) {
        lcd->setLycFlag(true);
        lcd->resetLy();

        if (lcd->getLycInt()) {
            emu->triggerInterrupt(STAT);
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
            fetchEntryCount = 0;

            if (lcd->getBgWEnabled()) {
                bgwFetchData[0] = bus->read(lcd->getBgMapArea() + (mapX / 8) + ((mapY / 8) * 32));
                if (lcd->getBgWDataArea() == 0x8800) {
                    bgwFetchData[0] += 128;
                }
                pipelineLoadWindowTile();
            }

            if (lcd->getObjEnabled() && !lineSprites.empty()) {
                pipelineLoadSpriteTile();
            }

            fetchX += 8;
            fetchState = DATA0;
            break;

        case DATA0:
            bgwFetchData[1] = bus->read(lcd->getBgWDataArea() + bgwFetchData[0] * 16 + tileY);
            fetchState = DATA1;
            pipelineLoadSpriteData(0);
            break;
        case DATA1:
            bgwFetchData[2] = bus->read(lcd->getBgWDataArea() + bgwFetchData[0] * 16 + tileY + 1);
            fetchState = SLEEP;
            pipelineLoadSpriteData(1);
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

uint8_t PPU::fetchSpritePixel(uint8_t color, uint8_t bgColor) {
    for (int i = 0; i < fetchEntryCount; i++) {
        int spX = (fetchedEntries[i].x - 8) + (lcd->getScrollX() % 8);
        if (spX + 8 > fifoX) continue;

        int offset = spX - fifoX;
        if (offset < 0 || offset > 7) continue;

        int bit = 7 - offset;
        if (lineSprites.at(i).f_x_flip) bit = offset;

        uint8_t low = ((fetchEntryData[i*2] & (1 << bit)) != 0);
        uint8_t high = ((fetchEntryData[(i*2)+1] & (1 << bit)) != 0) << 1;

        uint8_t val = high|low;
        bool bgPriority = fetchedEntries[i].f_bgp;
        if (!val) continue;
        if (!bgPriority || bgColor == 0) color = fetchedEntries[i].f_pn ? lcd->sp1Colors[val] : lcd->sp2Colors[val];
    }
    return color;
}

bool PPU::pipelineAdd() {
    if (fifo.size() > 8) return false;
    int x = fetchX - (8 - lcd->getScrollX() % 8);

    //Calculate pixel intensity
    for (int bit = 7; bit >= 0; bit--) {
        uint8_t low = ((bgwFetchData[1] & (1 << bit)) != 0);
        uint8_t high = ((bgwFetchData[2] & (1 << bit)) != 0) << 1;
        uint8_t pixel = high | low;

        if (!lcd->getBgWEnabled()) pixel = 0;
        if (lcd->getObjEnabled()) pixel = fetchSpritePixel(pixel, high|low);

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

void PPU::loadLineSprites() {
    int curY = lcd->getLy();
    int spriteHeight = lcd->getObjHeight();

    while (lineSprites.size()) lineSprites.pop_front();

    for (int i = 0; i < 40; i++) {
        OamEntry e = bus->getOamEntry(i);
        if (e.x == 0) continue;

        if (lineSprites.size() == 10) break;

        if (e.y <= curY + 16 && e.y + spriteHeight > curY + 16) {
            lineSprites.push_front(e);


            //sort
            for (int j = 0; j < lineSprites.size() - 1;  j++) {
                if (lineSprites.at(j).x > lineSprites.at(j + 1).x) {
                    OamEntry temp = lineSprites.at(j);
                    lineSprites.at(j) = lineSprites.at(j + 1);
                    lineSprites.at(j) = temp;
                }
            }
        }
    }
}

void PPU::pipelineLoadSpriteTile() {
    for (int i = 0; i < lineSprites.size(); i++) {
        int spX = (lineSprites.at(i).x - 8) + (lcd->getScrollX() % 8);

        if ((spX >= fetchX && spX < fetchX + 8) || (spX + 8 >= fetchX && spX + 8 < fetchX + 8)) {
            fetchedEntries[fetchEntryCount++] = lineSprites.at(i);
        }

        if (fetchEntryCount >= 3) break;
    }
}

void PPU::pipelineLoadSpriteData(int pos) {
    int curY = lcd->getLy();
    int spriteHeight = lcd->getObjHeight();

    for (int i = 0; i < fetchEntryCount; i++) {
        uint8_t ty = ((curY + 16) - fetchedEntries[i].y) * 2;
        if (fetchedEntries[i].f_y_flip) ty = ((spriteHeight * 2) - 2) - ty;
        int tileIndex = fetchedEntries[i].tile;
        if (spriteHeight == 16) tileIndex &= ~(1);

        fetchEntryData[i*2 + pos] = bus->read(0x8000 + (tileIndex * 16) + ty + pos);
    }
}

void PPU::pipelineLoadWindowTile() {
    if (!windowVisible()) return;
    if (fetchX + 7 >= lcd->getWinX() && fetchX + 7 < X_RES + lcd->getWinX() + 14) {
        if (lcd->getLy()>= lcd->getWinY() && lcd->getLy() < Y_RES + lcd->getWinY()) {
            bgwFetchData[0] = bus->read(lcd->getWinMapArea() + (fetchX + 7 - lcd->getWinX()) + ((windowLine / 8) * 32));
            if (lcd->getBgWDataArea() == 0x8800) bgwFetchData[0] += 128;
        }

    }
}
