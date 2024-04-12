#include "CPU.h"
#include "../../GlobalFlags.h"
#include "DebugLookupTable.h"

#define DEBUG

CPU::CPU() {
    // calling RESET here so that RESET is a single source of truth for what the registers are set to at startup
    RESET();
    std::ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        exit(1);
    }
}

void CPU::handleInterrupts(Bus &bus)
{
    uint8_t interrupts = getInterruptEnableFlag(bus) & getInterruptFlag(bus);
    if (getHalted() && !getImeFlag() && interrupts) {
        setHalted(false);
        return;
        // Optional: handle stuff with the halt bug here (not sure if necessary)
    }
    if (!this->imeFlag)
    {
        return;
    }

    if (!getImeFlag() || !interrupts)
    {
        return;
    }

    setHalted(false);
    stackPush(bus, PC);

    // check each interrupt type (there are 5)
    for (int i = 0; i < 5; i++)
    {
        uint8_t interruptMask = 1 << i;
        if (interrupts & interruptMask)
        {
            // NOTE: the order of this switch is the same as GB interrupt priority
            // i think changing it would be fine since we bit shift above, but to be safe let's not
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
    setImeFlag(false);
    setInterruptFlag(bus, getInterruptFlag(bus) & ~interrupt); // reset bit in IF register (interrupt has now been serviced)

    // push current PC to stack so we can return to it later
    stackPush(bus, PC);

    // go to interrupt address
    setPC(interruptAddress);
}

void CPU::stackPush(Bus &bus, uint16_t value)
{
    bus.write(getSP(), (value >> 8) & 0xFF); // high byte
    setSP(SP - 1);
    bus.write(getSP(), value & 0xFF); // low byte
    setSP(SP - 1);
}

uint16_t CPU::stackPop(Bus &bus)
{
    uint16_t value = (bus.read(getSP() + 2) << 8) | bus.read(getSP() + 1);
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
    return registers.AF >> 8;
}

uint8_t CPU::getBRegister() const
{
    return registers.BC >> 8;
}

uint8_t CPU::getCRegister() const
{
    return registers.BC & 0x00FF;
}

uint8_t CPU::getDRegister() const
{
    return registers.DE >> 8;
}

uint8_t CPU::getERegister() const
{
    return registers.DE & 0x00FF;
}

uint8_t CPU::getHRegister() const
{
    return registers.HL >> 8;
}

uint8_t CPU::getLRegister() const
{
    return registers.HL & 0x00FF;
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

uint8_t CPU::getFlagsByte() const
{
    return (flags.Z << 7) | (flags.N << 6) | (flags.H << 5) | (flags.C << 4);
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

bool CPU::getHalted() const
{
    return halted;
}

bool CPU::getImeFlag() const {
    return imeFlag;
}

uint8_t CPU::getInterruptEnableFlag(Bus &bus) {
    return bus.read(0xFFFF);
}

uint8_t CPU::getInterruptFlag(Bus &bus) {
    return bus.read(0xFF0F);
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

void CPU::setHalted(bool halted) {
    this->halted = halted;
}

void CPU::setImeFlag(bool flagValue) {
    imeFlag = flagValue;
}

void CPU::setInterruptFlag(Bus &bus, uint8_t interruptFlag) {
    bus.write(0xFF0F, interruptFlag);
}

void CPU::setInterruptEnable(Bus &bus, uint8_t interruptEnable) {
    bus.write(0xFFFF, interruptEnable);
}

void CPU::setRegisters(Registers registers)
{
    this->registers = registers;
}

void CPU::setARegister(uint8_t A)
{
    registers.AF = (registers.AF & 0x00FF) | (A << 8);
}

void CPU::setBRegister(uint8_t B)
{
    registers.BC = (registers.BC & 0x00FF) | (B << 8);
}

void CPU::setCRegister(uint8_t C)
{
    registers.BC = (registers.BC & 0xFF00) | C;
}

void CPU::setDRegister(uint8_t D)
{
    registers.DE = (registers.DE & 0x00FF) | (D << 8);
}

void CPU::setERegister(uint8_t E)
{
    registers.DE = (registers.DE & 0xFF00) | E;
}

void CPU::setHRegister(uint8_t H)
{
    registers.HL = (registers.HL & 0x00FF) | (H << 8);
}

void CPU::setLRegister(uint8_t L)
{
    registers.HL = (registers.HL & 0xFF00) | L;
}

void CPU::setAFRegister(uint16_t AF)
{
    registers.AF = AF;
    // set flags struct
    setFlagsByte(AF & 0x00FF);
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

void CPU::setFlagsByte(uint8_t flagsByte)
{
    flags.Z = (flagsByte & 0x80) >> 7;
    flags.N = (flagsByte & 0x40) >> 6;
    flags.H = (flagsByte & 0x20) >> 5;
    flags.C = (flagsByte & 0x10) >> 4;
}

void CPU::setZeroFlag(bool Z)
{
    flags.Z = Z;
    setAFRegister((registers.AF & 0xFF00) | getFlagsByte());
}

void CPU::setSubtractFlag(bool N)
{
    flags.N = N;
    setAFRegister((registers.AF & 0xFF00) | getFlagsByte());
}

void CPU::setHalfCarryFlag(bool H)
{
    flags.H = H;
    setAFRegister((registers.AF & 0xFF00) | getFlagsByte());
}

void CPU::setCarryFlag(bool C)
{
    flags.C = C;
    setAFRegister((registers.AF & 0xFF00) | getFlagsByte());
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
    if (!getHalted())
    {
        uint8_t opcode = fetch(bus);
        if (GlobalFlags::debug) {
            if (GlobalFlags::matchTranscript) printTranscript(bus);
            else {
                std::printf("PC: %04X SP: %04X Op: %02X - (%s)\n", getPC(), getSP(), opcode,
                            DebugLookupTable::getInstructionName(opcode, bus.read(PC + 1)).c_str());
                std::printf("d8/a8: %02X    d16/a16: %04X    count: %x\n", bus.read(PC + 1),
                            (bus.read(PC + 2) << 8) | bus.read(PC + 1), count++);
                if (GlobalFlags::showRegisters) {
                    std::printf("A F: %02X %02X\n", getARegister(), getFlagsByte());
                    std::printf("Z: %d N: %d H: %d C: %d IME: %d\n", getZeroFlag(), getSubtractFlag(), getHalfCarryFlag(),
                                getCarryFlag(), imeFlag);
                    std::printf("IE: %02X IF: %02X\n", bus.read(0xFFFF), bus.read(0xFF0F));
                    std::printf("B C: %02X %02X\n", getBRegister(), getCRegister());
                    std::printf("D E: %02X %02X\n", getDRegister(), getERegister());
                    std::printf("H L: %02X %02X\n", getHRegister(), getLRegister());
                }
                std::fflush(stdout);
            }
            if (GlobalFlags::manualdbg) std::cin.get();
        }
        processOpCode(opcode, bus);
    }
    else {
        cycleCount += 1;
    }
    handleInterrupts(bus);

    dbg->update(bus);
    dbg->print();
}

void CPU::RESET()
{
    setCycleCount(0);
    setPC(GlobalFlags::initialPC);
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

void CPU::printTranscript(Bus &bus) {
    if (count < 100000) {
        FILE* outputFile = std::fopen("output.txt", "a");

        std::fprintf(outputFile,
                     "A: %02X F: %02X B: %02X C: %02X D: %02X E: %02X H: %02X L: %02X SP: %04X PC: 00:%04X (%02X %02X %02X %02X)\n",
                     getARegister(), getFlagsByte(), getBRegister(), getCRegister(), getDRegister(),
                     getERegister(), getHRegister(), getLRegister(),
                     getSP(), getPC(), bus.read(PC), bus.read(PC + 1), bus.read(PC + 2), bus.read(PC + 3));

        std::fclose(outputFile);
    }
    else exit(0);
}