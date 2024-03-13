//
// Created by Tyson Peterson on 3/13/24.
//

#ifndef GAMEBOY_EMULATOR_IEMULATOR_H
#define GAMEBOY_EMULATOR_IEMULATOR_H

enum InterruptType {
    STAT,
    VBLANK
};

class IEmulator {
public:

    //PPU Functionality
    void triggerInterrupt(InterruptType interrupt);
    void updateFrame(char** frame);
};

#endif //GAMEBOY_EMULATOR_IEMULATOR_H
