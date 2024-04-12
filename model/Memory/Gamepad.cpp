#include "Gamepad.h"

//
// Created by Keiffer on 3/1/2024.
//


void Gamepad::set_sel(uint8_t value) {
    buttonSelected = value & 0x20;
    directionSelected = value & 0x10;
}

uint8_t Gamepad::get_output() const {
    uint8_t  output = 0xCF;

    if(!buttonSelected){
        if(controls->start()){
            output &= ~(1 << 3);
        }
        if(controls->select()){
            output &= ~(1 << 2);
        }
        if(controls->B()){
            output &= ~(1 << 1);
        }
        if(controls->A()){
            output &= ~(1 << 0);
        }
    }

    if(!directionSelected){
        if(controls->down()){
            output &= ~(1 << 3);
        }
        if(controls->up()){
            output &= ~(1 << 2);
        }
        if(controls->left()){
            output &= ~(1 << 1);
        }
        if(controls->right()){
            output &= ~(1 << 0);
        }
    }

    return output;
}

void Gamepad::checkForInterrupt() {
    uint8_t output = get_output();
    if ((~output & 0xFF) & (lastCheckedOutput & 0xFF)) {
        emu->triggerInterrupt(InterruptType::JOYPAD);
    }
    lastCheckedOutput = output;
}
