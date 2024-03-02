
#include "Instruction.h"

// all these come from the opcode table at https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html

void Instruction::processOpCode(uint8_t opCode, CPU& cpu)
{
    switch (opCode)
    {
    case 0x00:
        // NOP
        break;
    case 0x01:
        // LD BC, d16: load 16-bit immediate value into BC register pair
        break;
    case 0x02:
        // LD (BC), A
        break;
    case 0x03:
        // INC BC
        break;
    }
}

unsigned int Instruction::getCycleCount(uint8_t opcode) const
{
    switch (opcode)
    {
    case 0x00:
        return 4;
    }
    return 0;
}