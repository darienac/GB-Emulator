//
// Created by Tyson Peterson on 3/13/24.
//

#ifndef GAMEBOY_EMULATOR_IEMULATOR_H
#define GAMEBOY_EMULATOR_IEMULATOR_H

enum InterruptType {
    STAT,
    VBLANK,
    TIMER
};

class IEmulator {
public:
    //PPU Functionality
    virtual void triggerInterrupt(InterruptType interrupt) = 0;
    virtual void updateFrame(char** frame) = 0;
};

#endif //GAMEBOY_EMULATOR_IEMULATOR_H
