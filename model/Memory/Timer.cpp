//
// Created by Keiffer on 3/7/2024.
//

#include <iostream>
#include "Timer.h"

void Timer::setDiv(uint16_t value) {
    div = value;
}

void Timer::tick() { // Ticks every T cycle
    uint16_t prevDiv = div;
    div++;
    bool timerUpdate = false;

    switch(tac & (0b11)){
        case 0b00:
            timerUpdate = (prevDiv & (1 << 9)) && (!(div & (1 << 9)));
            break;
        case 0b01:
            timerUpdate = (prevDiv & (1 << 3)) && (!(div & (1 << 3)));
            break;
        case 0b10:
            timerUpdate = (prevDiv & (1 << 5)) && (!(div & (1 << 5)));
            break;
        case 0b11:
            timerUpdate = (prevDiv & (1 << 7)) && (!(div & (1 << 7)));
            break;
        default:
            break;
    }

    if (timerUpdate && tac & (1 << 2)){
        tima++;
        if (tima == 0xFF) {
            tima = tma;
            emu->triggerInterrupt(InterruptType::TIMER);
        }
    }
}

uint8_t Timer::read(uint16_t address) const {
    switch(address){
        case 0xFF04:
            return div >> 8;
        case 0xFF05:
            return tima;
        case 0xFF06:
            return tma;
        case 0xFF07:
            return tac & 0b111;
        default:
            return 0;
    }
}

void Timer::write(uint16_t address, uint8_t value) {
    switch (address) {
        case 0xFF04:
            div = 0;
            break;
        case 0xFF05:
            tima = value;
            break;
        case 0xFF06:
            tma = value;
            break;
        case 0xFF07:
            tac = (tac & ~0b111) | (value & 0b111);
            break;
        default:
            break;
    }
}
