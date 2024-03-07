#include "Gamepad.h"

//
// Created by BYU Rental on 3/1/2024.
//



Gamepad::gamepad_state *Gamepad::get_state() {
    return &state;
}

void Gamepad::set_sel(uint8_t value) {
    button_selected = value & 0x20;
    direction_selected = value & 0x10;
}

uint8_t Gamepad::get_output() const {
    uint8_t  output = 0xCF;

    if(!button_selected){
        if(state.start){
            output &= ~(1 << 3);
        }
        if(state.select){
            output &= ~(1 << 2);
        }
        if(state.b){
            output &= ~(1 << 1);
        }
        if(state.a){
            output &= ~(1 << 0);
        }
    }

    if(!direction_selected){
        if(state.down){
            output &= ~(1 << 3);
        }
        if(state.up){
            output &= ~(1 << 2);
        }
        if(state.left){
            output &= ~(1 << 1);
        }
        if(state.right){
            output &= ~(1 << 0);
        }
    }
    return output;
}
