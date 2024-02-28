

#include "Instruction.h"

void Instruction::processOpCode(uint8_t opCode)
{
    switch (opCode)
    {
    case 0x00:
        // NOP
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