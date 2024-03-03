
#include "CPU.h"

// all these come from the opcode table at https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html

void CPU::processOpCode(uint8_t opCode, Bus &bus)
{
    switch (opCode)
    {
    case 0x00:
        // NOP
        break;
    case 0x01:
        // LD BC, d16: load 16-bit immediate value into BC register pair
        process01(bus);
        cycleCount += getCycleCount(opCode);
        break;
    case 0x02:
        // LD (BC), A
        break;
    case 0x03:
        // INC BC
        break;
    }
}

unsigned int CPU::getCycleCount(uint8_t opcode) const
{
    switch (opcode)
    {
    case 0x00:
        return 4;
    case 0x01:
        return 12;
    }
    return 0;
}

void CPU::process01(Bus &bus)
{

    // fetch the 16-bit immediate value (little-endian) TODO: is that right?
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load immediate value into the BC register pair
    setBCRegister(immediateValue);
    // increment the program counter
    setPC(PC + 3);
}