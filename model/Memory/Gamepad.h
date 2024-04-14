//
// Created by BYU Rental on 3/1/2024.
//

#ifndef GAMEBOY_EMULATOR_GAMEPAD_H
#define GAMEBOY_EMULATOR_GAMEPAD_H

#include <cstdint>
#include "../../controller/IControls.h"
#include "../IEmulator.h"

class Gamepad{
private:
    bool buttonSelected;
    bool directionSelected;
    IControls* controls;
    uint8_t lastCheckedOutput = 0xFF;
    IEmulator* emu;

public:
    Gamepad(IControls* controls, IEmulator* emu): controls(controls), emu(emu) { buttonSelected = 0; directionSelected = 0;}
    [[nodiscard]] uint8_t get_output() const;
    void set_sel(uint8_t value);
    void checkForInterrupt();
};

#endif //GAMEBOY_EMULATOR_GAMEPAD_H
