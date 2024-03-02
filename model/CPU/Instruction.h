// A file containing instructions for the CPU
// It maps opcodes to their respective instructions

#ifndef GAMEBOY_EMULATOR_INSTRUCTION_H
#define GAMEBOY_EMULATOR_INSTRUCTION_H

#include <cstdint>
//#include "CPU.h"

class CPU;

class Instruction
{
public:
    /// @brief Process the given opcode and execute the instruction
    void processOpCode(uint8_t opcode, CPU& cpu);
    /// @brief Get the cycle count for the given opcode
    unsigned int getCycleCount(uint8_t opcode) const;
};

#endif // GAMEBOY_EMULATOR_INSTRUCTION_H