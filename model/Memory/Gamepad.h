//
// Created by BYU Rental on 3/1/2024.
//

#ifndef GAMEBOY_EMULATOR_GAMEPAD_H
#define GAMEBOY_EMULATOR_GAMEPAD_H

#include <cstdint>
#include "../../controller/IControls.h"

class Gamepad{
private:
    bool buttonSelected;
    bool directionSelected;
    IControls* controls;



public:
    Gamepad(IControls* controls): controls(controls){}
    [[nodiscard]] uint8_t get_output() const;
    void set_sel(uint8_t value);

};

#endif //GAMEBOY_EMULATOR_GAMEPAD_H
