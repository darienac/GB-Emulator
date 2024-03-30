//
// Created by dacma on 3/29/2024.
//

#ifndef GAMEBOY_EMULATOR_DEBUGLOOKUPTABLE_H
#define GAMEBOY_EMULATOR_DEBUGLOOKUPTABLE_H


#include <string>
#include <cstdint>

class DebugLookupTable {
public:
    static const std::string INSTRUCTION_NAME[256];
    static const std::string CB_INSTRUCTION_NAME[256];

    static const std::string& getInstructionName(uint8_t opcode, uint8_t cb);
};


#endif //GAMEBOY_EMULATOR_DEBUGLOOKUPTABLE_H
