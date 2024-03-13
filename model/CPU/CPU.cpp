#include "CPU.h"

void CPU::handleInterrupts(Bus &bus)
{
    if (!this->interruptsEnabled)
    {
        return;
    }

    uint8_t interrupt = getInterruptFlag() & getInterruptsEnabled();
    if (!interrupt)
    {
        return;
    }

    setHalted(false);
    stackPush(bus, PC);

    // check each interrupt type (there are 5)
    for (int i = 0; i < 5; i++)
    {
        uint8_t interruptMask = 1 << i;
        if (interrupt & interruptMask)
        {
            // NOTE: the order of this switch is CRITICAL
            // it is the same as GB interrupt priority
            // DO NOT CHANGE IT!
            switch (interruptMask)
            {
            case InterruptMasks::VBLANK:
                handleSingleInterrupt(bus, interruptMask, InterruptAddresses::VBLANK);
                return;
            case InterruptMasks::LCD_STAT:
                handleSingleInterrupt(bus, interruptMask, InterruptAddresses::LCD_STAT);
                return;
            case InterruptMasks::TIMER:
                handleSingleInterrupt(bus, interruptMask, InterruptAddresses::TIMER);
                return;
            case InterruptMasks::SERIAL:
                handleSingleInterrupt(bus, interruptMask, InterruptAddresses::SERIAL);
                return;
            case InterruptMasks::JOYPAD:
                handleSingleInterrupt(bus, interruptMask, InterruptAddresses::JOYPAD);
                return;
            }
        }
    }
}

void CPU::handleSingleInterrupt(Bus &bus, uint8_t interrupt, uint16_t interruptAddress)
{
    // temp disable interrupts TODO: right now this is not re-enabled afaik
    interruptsEnabled = false;

    // push current PC to stack so we can return to it later
    stackPush(bus, PC);

    // go to interrupt address
    PC = interruptAddress;
}

void CPU::stackPush(Bus &bus, uint16_t value)
{
    bus.write(getSP(), (value >> 8) & 0xFF); // high byte
    setSP(--SP);
    bus.write(getSP(), value & 0xFF); // low byte
    setSP(--SP);
}

uint16_t CPU::stackPop(Bus &bus)
{
    uint16_t value = (bus.read(getSP() + 1) << 8) | bus.read(getSP());
    setSP(SP + 2);
    return value;
}

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

uint16_t CPU::getBCRegister() const
{
    return registers.BC;
}

uint16_t CPU::getDERegister() const
{
    return registers.DE;
}

uint16_t CPU::getHLRegister() const
{
    return registers.HL;
}

CPU::Flags CPU::getFlags() const
{
    return flags;
}

bool CPU::getZeroFlag() const
{
    return flags.Z;
}

bool CPU::getSubtractFlag() const
{
    return flags.N;
}

bool CPU::getHalfCarryFlag() const
{
    return flags.H;
}

bool CPU::getCarryFlag() const
{
    return flags.C;
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

void CPU::setBCRegister(uint16_t BC)
{
    registers.BC = BC;
}

void CPU::setDERegister(uint16_t DE)
{
    registers.DE = DE;
}

void CPU::setHLRegister(uint16_t HL)
{
    registers.HL = HL;
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
    return data;
}

void CPU::execute(uint8_t opcode, Bus &bus)
{
    processOpCode(opcode, bus);
}

void CPU::tick(Bus &bus)
{
    uint8_t opcode = fetch(bus);
    processOpCode(opcode, bus);
    cycleCount += getCycleCount(opcode);
}

void CPU::RESET()
{
    setCycleCount(0);
    setPC(0x100);
    setSP(0xFFFE);

    // reset registers
    registers.AF = 0x01B0;
    registers.BC = 0x0013;
    registers.DE = 0x00D8;
    registers.HL = 0x014D;

    // reset flags
    setZeroFlag(true);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(false);
}