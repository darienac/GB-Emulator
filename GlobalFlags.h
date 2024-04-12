//
// Created by dacma on 3/21/2024.
//

#ifndef GAMEBOY_EMULATOR_GLOBALFLAGS_H
#define GAMEBOY_EMULATOR_GLOBALFLAGS_H


#include <cstdint>

class GlobalFlags {
public:
    static bool debug;
    static bool showRegisters;

    static bool checkForStuckInstruction; // Checks if PC stays the same between instruction calls to try to detect unimplemented instructions

    static bool showControls;

    static bool manualdbg;
    static bool matchTranscript;
    static bool printSerialOut;

    static uint16_t initialPC;
    static unsigned int framesPerSecond;
};


#endif //GAMEBOY_EMULATOR_GLOBALFLAGS_H
