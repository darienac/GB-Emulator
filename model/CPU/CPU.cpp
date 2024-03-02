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

uint8_t CPU::getARegister() const
{
    return registers.AF & 0x00FF;
}

uint8_t CPU::getBRegister() const
{
    return registers.BC & 0x00FF;
}

uint8_t CPU::getCRegister() const
{
    return (registers.BC & 0xFF00) >> 8;
}

uint8_t CPU::getDRegister() const
{
    return registers.DE & 0x00FF;
}

uint8_t CPU::getERegister() const
{
    return (registers.DE & 0xFF00) >> 8;
}

uint8_t CPU::getHRegister() const
{
    return registers.HL & 0x00FF;
}

uint8_t CPU::getLRegister() const
{
    return (registers.HL & 0xFF00) >> 8;
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

void CPU::setARegister(uint8_t A)
{
    registers.AF = (registers.AF & 0xFF00) | A;
}

void CPU::setBRegister(uint8_t B)
{
    registers.BC = (registers.BC & 0xFF00) | B;
}

void CPU::setCRegister(uint8_t C)
{
    registers.BC = (registers.BC & 0x00FF) | (C << 8);
}

void CPU::setDRegister(uint8_t D)
{
    registers.DE = (registers.DE & 0xFF00) | D;
}

void CPU::setERegister(uint8_t E)
{
    registers.DE = (registers.DE & 0x00FF) | (E << 8);
}

void CPU::setHRegister(uint8_t H)
{
    registers.HL = (registers.HL & 0xFF00) | H;
}

void CPU::setLRegister(uint8_t L)
{
    registers.HL = (registers.HL & 0x00FF) | (L << 8);
}

void CPU::setFlags(Flags flags)
{
    this->flags = flags;
}

void CPU::setZeroFlag(bool Z)
{
    flags.Z = Z;
}

void CPU::setSubtractFlag(bool N)
{
    flags.N = N;
}

void CPU::setHalfCarryFlag(bool H)
{
    flags.H = H;
}

void CPU::setCarryFlag(bool C)
{
    flags.C = C;
}

uint8_t CPU::fetch(Bus &bus)
{
    uint8_t data = bus.read(PC);
    PC++; // increment program counter
    return data;

}

void CPU::RESET()
{
    cycleCount = 0;
    PC = 0x100;
    SP = 0xFFFE;

    // reset registers
    registers.AF = 0x01B0;
    registers.BC = 0x0013;
    registers.DE = 0x00D8;
    registers.HL = 0x014D;

    // reset flags
    flags.Z = true;
    flags.N = false;
    flags.H = false;
    flags.C = false;

    // reset memory
    // TODO: idk if we will do this from CPU or from memory class
    for (int i = 0; i < 0xFFFF; ++i)
    {
        memory[i] = 0;
    }
}