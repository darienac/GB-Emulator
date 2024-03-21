//
// Created by Keiffer on 3/7/2024.
//

#ifndef GAMEBOY_EMULATOR_TIMER_H
#define GAMEBOY_EMULATOR_TIMER_H

#include <cstdint>

class Timer{
private:
    uint16_t div;
    uint8_t tima;
    uint8_t tma;
    uint8_t tac;

public:
    Timer(){div = 0xAC00;}
    void timerTick();
    uint8_t timerRead(uint16_t address) const;
    void timerWrite(uint16_t address, uint8_t value);
    void setDiv(uint16_t value);
};

#endif //GAMEBOY_EMULATOR_TIMER_H
