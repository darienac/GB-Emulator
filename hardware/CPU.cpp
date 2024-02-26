#include "CPU.h"

unsigned int CPU::getCycleCount() const
{
    return cycleCount;
}

uint16_t CPU::getPC() const
{
    return PC;
}

uint16_t CPU::getSP() const
{
    return SP;
}

CPU::Registers CPU::getRegisters() const
{
    return registers;
}

CPU::Flags CPU::getFlags() const
{
    return flags;
}

uint8_t *CPU::getMemory()
{
    return memory;
}

void CPU::setCycleCount(unsigned int cycleCount)
{
    this->cycleCount = cycleCount;
}

void CPU::setPC(uint16_t PC)
{
    this->PC = PC;
}

void CPU::setSP(uint16_t SP)
{
    this->SP = SP;
}

void CPU::setRegisters(Registers registers)
{
    this->registers = registers;
}

void CPU::RESET()
{
    cycleCount = 0;
    PC = 0x100;
    SP = 0xFFFE;

    //reset registers
    registers.AF = 0x01B0;
    registers.BC = 0x0013;
    registers.DE = 0x00D8;
    registers.HL = 0x014D;

    //reset flags
    flags.Z = true;
    flags.N = false;
    flags.H = false;
    flags.C = false;

    //reset memory
    //TODO: idk if we will do this from CPU or from memory class
    for (int i = 0; i < 0xFFFF; ++i)
    {
        memory[i] = 0;
    }
}