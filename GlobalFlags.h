//
// Created by dacma on 3/21/2024.
//

#ifndef GAMEBOY_EMULATOR_GLOBALFLAGS_H
#define GAMEBOY_EMULATOR_GLOBALFLAGS_H


class GlobalFlags {
public:
    static const bool debug;
    static const bool showRegisters;

    static const bool checkForStuckInstruction; // Checks if PC stays the same between instruction calls to try to detect unimplemented instructions

    static const bool showControls;

    static const bool manualdbg;
    static const bool matchTranscript;
};


#endif //GAMEBOY_EMULATOR_GLOBALFLAGS_H
