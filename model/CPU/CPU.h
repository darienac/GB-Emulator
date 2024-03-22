#ifndef GAMEBOY_EMULATOR_CPU_H
#define GAMEBOY_EMULATOR_CPU_H

#include <cstdint>
#include <string>
#include "../Memory/Bus.h"

/// @brief InterruptMask values TODO: move these outside of this file to a more static location?
namespace InterruptMasks
{
    const uint8_t VBLANK = 0x01;
    const uint8_t LCD_STAT = 0x02;
    const uint8_t TIMER = 0x04;
    const uint8_t SERIAL = 0x08;
    const uint8_t JOYPAD = 0x10;
}

/// @brief InterruptAddress values TODO: move these outside of this file to a more static location?
namespace InterruptAddresses
{
    const uint16_t VBLANK = 0x0040;
    const uint16_t LCD_STAT = 0x0048;
    const uint16_t TIMER = 0x0050;
    const uint16_t SERIAL = 0x0058;
    const uint16_t JOYPAD = 0x0060;
}

struct RegisterPair
{
    uint8_t high;
    uint8_t low;
};

/// @brief Header file for the CPU class
class CPU
{
private:
    // Internal state of the CPU
    /// @brief The CPU's memory
    // TODO: put memory here?
    /// @brief The CPU's cycle count
    unsigned int cycleCount = 0;
    // TODO: put other internal state vars here

    /// @brief The CPU's program counter
    uint16_t PC = 0x100;
    /// @brief The CPU's stack pointer
    uint16_t SP = 0xFFFE;

    /// @brief CPU halt status
    bool halted = false;

    /// @brief IME flag (interrupts enabled)
    bool imeFlag = true;

    /// @brief The CPU's registers. All initial values are from the powerup sequence ref on PanDocs using the DMG model
    struct Registers
    {
        union
        {
            struct
            {
                /// @brief The CPU's flags
                uint8_t F;
                /// @brief The CPU's accumulator
                uint8_t A;
            };
            /// @brief The CPU's AF register pair (accumulator and flags)
            uint16_t AF = 0x01B0;
        };
        union
        {
            struct
            {
                /// @brief The CPU's general purpose register B
                uint8_t B;
                /// @brief The CPU's general purpose register C
                uint8_t C;
            };
            /// @brief The CPU's BC register pair
            uint16_t BC = 0x0013;
        };
        union
        {
            struct
            {
                /// @brief The CPU's general purpose register D
                uint8_t D;
                /// @brief The CPU's general purpose register E
                uint8_t E;
            };
            /// @brief The CPU's DE register pair
            uint16_t DE = 0x00D8;
        };
        union
        {
            struct
            {
                /// @brief The CPU's general purpose register H
                uint8_t H;
                /// @brief The CPU's general purpose register L
                uint8_t L;
            };
            /// @brief The CPU's HL register pair
            uint16_t HL = 0x014D;
        };
    } registers;

    /// @brief The CPU's flags. All initial values are from the powerup sequence ref on PanDocs using the DMG model
    struct Flags
    {
        /// @brief Zero flag; is the result of the last operation zero?
        bool Z = true;
        /// @brief Subtract flag (binary coded decimal support); was the previous operation a subtraction?
        bool N = false;
        // TODO: if header checksum is 0x00, then H and C are 0; otherwise, H and C are 1; tbh idk what this means so i gotta do more research
        /// @brief Half carry flag (binary coded decimal support); did the last operation cause a carry from bit 3 to bit 4? (lower 4 bits)
        bool H = false;
        /// @brief Carry flag; did the last operation cause a carry from bit 7 to bit 8? (upper 4 bits)
        bool C = false;
    } flags;

    /// @brief The interrupt flag (IF)
    uint8_t interruptFlag = 0xE0;

    /// @brief The interrupt enable register (IE)
    uint8_t interruptEnable = 0x00;

    /// @brief Fetch an instruction from memory
    uint8_t fetch(Bus &bus);

    /// @brief Handle interrupts TODO: read more about HALT bug and make sure this works with it
    void handleInterrupts(Bus &bus);

    /// @brief Handle a single interrupt
    void handleSingleInterrupt(Bus &bus, uint8_t interruptBit, uint16_t interruptVector);

    /// @brief Push a value onto the stack
    void stackPush(Bus &bus, uint16_t value);

    /// @brief Pop a value from the stack
    uint16_t stackPop(Bus &bus);

    // functions to process each opcode
    void process00(Bus &bus);
    void process01(Bus &bus);
    void process02(Bus &bus);
    void process03(Bus &bus);
    void process04(Bus &bus);
    void process05(Bus &bus);
    void process06(Bus &bus);
    void process07(Bus &bus);
    void process08(Bus &bus);
    void process09(Bus &bus);
    void process0A(Bus &bus);
    void process0B(Bus &bus);
    void process0C(Bus &bus);
    void process0D(Bus &bus);
    void process0E(Bus &bus);
    void process0F(Bus &bus);
    void process10(Bus &bus);
    void process11(Bus &bus);
    void process12(Bus &bus);
    void process13(Bus &bus);
    void process14(Bus &bus);
    void process15(Bus &bus);
    void process16(Bus &bus);
    void process17(Bus &bus);
    void process18(Bus &bus);
    void process19(Bus &bus);
    void process1A(Bus &bus);
    void process1B(Bus &bus);
    void process1C(Bus &bus);
    void process1D(Bus &bus);
    void process1E(Bus &bus);
    void process1F(Bus &bus);
    void process20(Bus &bus);
    void process21(Bus &bus);
    void process22(Bus &bus);
    void process23(Bus &bus);
    void process24(Bus &bus);
    void process25(Bus &bus);
    void process26(Bus &bus);
    void process27(Bus &bus);
    void process28(Bus &bus);
    void process29(Bus &bus);
    void process2A(Bus &bus);
    void process2B(Bus &bus);
    void process2C(Bus &bus);
    void process2D(Bus &bus);
    void process2E(Bus &bus);
    void process2F(Bus &bus);
    void process30(Bus &bus);
    void process31(Bus &bus);
    void process32(Bus &bus);
    void process33(Bus &bus);
    void process34(Bus &bus);
    void process35(Bus &bus);
    void process36(Bus &bus);
    void process37(Bus &bus);
    void process38(Bus &bus);
    void process39(Bus &bus);
    void process3A(Bus &bus);
    void process3B(Bus &bus);
    void process3C(Bus &bus);
    void process3D(Bus &bus);
    void process3E(Bus &bus);
    void process3F(Bus &bus);
    void process40(Bus &bus);
    void process41(Bus &bus);
    void process42(Bus &bus);
    void process43(Bus &bus);
    void process44(Bus &bus);
    void process45(Bus &bus);
    void process46(Bus &bus);
    void process47(Bus &bus);
    void process48(Bus &bus);
    void process49(Bus &bus);
    void process4A(Bus &bus);
    void process4B(Bus &bus);
    void process4C(Bus &bus);
    void process4D(Bus &bus);
    void process4E(Bus &bus);
    void process4F(Bus &bus);
    void process50(Bus &bus);
    void process51(Bus &bus);
    void process52(Bus &bus);
    void process53(Bus &bus);
    void process54(Bus &bus);
    void process55(Bus &bus);
    void process56(Bus &bus);
    void process57(Bus &bus);
    void process58(Bus &bus);
    void process59(Bus &bus);
    void process5A(Bus &bus);
    void process5B(Bus &bus);
    void process5C(Bus &bus);
    void process5D(Bus &bus);
    void process5E(Bus &bus);
    void process5F(Bus &bus);
    void process60(Bus &bus);
    void process61(Bus &bus);
    void process62(Bus &bus);
    void process63(Bus &bus);
    void process64(Bus &bus);
    void process65(Bus &bus);
    void process66(Bus &bus);
    void process67(Bus &bus);
    void process68(Bus &bus);
    void process69(Bus &bus);
    void process6A(Bus &bus);
    void process6B(Bus &bus);
    void process6C(Bus &bus);
    void process6D(Bus &bus);
    void process6E(Bus &bus);
    void process6F(Bus &bus);
    void process70(Bus &bus);
    void process71(Bus &bus);
    void process72(Bus &bus);
    void process73(Bus &bus);
    void process74(Bus &bus);
    void process75(Bus &bus);
    void process76(Bus &bus);
    void process77(Bus &bus);
    void process78(Bus &bus);
    void process79(Bus &bus);
    void process7A(Bus &bus);
    void process7B(Bus &bus);
    void process7C(Bus &bus);
    void process7D(Bus &bus);
    void process7E(Bus &bus);
    void process7F(Bus &bus);
    void process80(Bus &bus);
    void process81(Bus &bus);
    void process82(Bus &bus);
    void process83(Bus &bus);
    void process84(Bus &bus);
    void process85(Bus &bus);
    void process86(Bus &bus);
    void process87(Bus &bus);
    void process88(Bus &bus);
    void process89(Bus &bus);
    void process8A(Bus &bus);
    void process8B(Bus &bus);
    void process8C(Bus &bus);
    void process8D(Bus &bus);
    void process8E(Bus &bus);
    void process8F(Bus &bus);
    void process90(Bus &bus);
    void process91(Bus &bus);
    void process92(Bus &bus);
    void process93(Bus &bus);
    void process94(Bus &bus);
    void process95(Bus &bus);
    void process96(Bus &bus);
    void process97(Bus &bus);
    void process98(Bus &bus);
    void process99(Bus &bus);
    void process9A(Bus &bus);
    void process9B(Bus &bus);
    void process9C(Bus &bus);
    void process9D(Bus &bus);
    void process9E(Bus &bus);
    void process9F(Bus &bus);
    void processA0(Bus &bus);
    void processA1(Bus &bus);
    void processA2(Bus &bus);
    void processA3(Bus &bus);
    void processA4(Bus &bus);
    void processA5(Bus &bus);
    void processA6(Bus &bus);
    void processA7(Bus &bus);
    void processA8(Bus &bus);
    void processA9(Bus &bus);
    void processAA(Bus &bus);
    void processAB(Bus &bus);
    void processAC(Bus &bus);
    void processAD(Bus &bus);
    void processAE(Bus &bus);
    void processAF(Bus &bus);
    void processB0(Bus &bus);
    void processB1(Bus &bus);
    void processB2(Bus &bus);
    void processB3(Bus &bus);
    void processB4(Bus &bus);
    void processB5(Bus &bus);
    void processB6(Bus &bus);
    void processB7(Bus &bus);
    void processB8(Bus &bus);
    void processB9(Bus &bus);
    void processBA(Bus &bus);
    void processBB(Bus &bus);
    void processBC(Bus &bus);
    void processBD(Bus &bus);
    void processBE(Bus &bus);
    void processBF(Bus &bus);
    void processC0(Bus &bus);
    void processC1(Bus &bus);
    void processC2(Bus &bus);
    void processC3(Bus &bus);
    void processC4(Bus &bus);
    void processC5(Bus &bus);
    void processC6(Bus &bus);
    void processC7(Bus &bus);
    void processC8(Bus &bus);
    void processC9(Bus &bus);
    void processCA(Bus &bus);
    void processCB(Bus &bus);
    void processCC(Bus &bus);
    void processCD(Bus &bus);
    void processCE(Bus &bus);
    void processCF(Bus &bus);
    void processD0(Bus &bus);
    void processD1(Bus &bus);
    void processD2(Bus &bus);
    void processD3(Bus &bus);
    void processD4(Bus &bus);
    void processD5(Bus &bus);
    void processD6(Bus &bus);
    void processD7(Bus &bus);
    void processD8(Bus &bus);
    void processD9(Bus &bus);
    void processDA(Bus &bus);
    void processDB(Bus &bus);
    void processDC(Bus &bus);
    void processDD(Bus &bus);
    void processDE(Bus &bus);
    void processDF(Bus &bus);
    void processE0(Bus &bus);
    void processE1(Bus &bus);
    void processE2(Bus &bus);
    void processE3(Bus &bus);
    void processE4(Bus &bus);
    void processE5(Bus &bus);
    void processE6(Bus &bus);
    void processE7(Bus &bus);
    void processE8(Bus &bus);
    void processE9(Bus &bus);
    void processEA(Bus &bus);
    void processEB(Bus &bus);
    void processEC(Bus &bus);
    void processED(Bus &bus);
    void processEE(Bus &bus);
    void processEF(Bus &bus);
    void processF0(Bus &bus);
    void processF1(Bus &bus);
    void processF2(Bus &bus);
    void processF3(Bus &bus);
    void processF4(Bus &bus);
    void processF5(Bus &bus);
    void processF6(Bus &bus);
    void processF7(Bus &bus);
    void processF8(Bus &bus);
    void processF9(Bus &bus);
    void processFA(Bus &bus);
    void processFB(Bus &bus);
    void processFC(Bus &bus);
    void processFD(Bus &bus);
    void processFE(Bus &bus);
    void processFF(Bus &bus);

public:
    /// @brief The CPU's cycle count
    unsigned int getCycleCount() const;

    /// @brief The CPU's program counter
    uint16_t getPC() const;

    /// @brief The CPU's stack pointer
    uint16_t getSP() const;

    /// @brief The CPU's halt status
    bool getHalted() const;

    /// @brief The CPU's interrupts enabled status
    bool getImeFlag() const;

    /// @brief The CPU's interrupt flag
    uint8_t getInterruptFlag() const;

    /// @brief The CPU's registers
    Registers getRegisters() const;

    /// @brief The value of the A register
    uint8_t getARegister() const;
    /// @brief The value of the B register
    uint8_t getBRegister() const;
    /// @brief The value of the C register
    uint8_t getCRegister() const;
    /// @brief The value of the D register
    uint8_t getDRegister() const;
    /// @brief The value of the E register
    uint8_t getERegister() const;
    /// @brief The value of the H register
    uint8_t getHRegister() const;
    /// @brief The value of the L register
    uint8_t getLRegister() const;
    /// @brief The value of the BC register pair
    uint16_t getBCRegister() const;
    /// @brief The value of the DE register pair
    uint16_t getDERegister() const;
    /// @brief The value of the HL register pair
    uint16_t getHLRegister() const;

    /// @brief The CPU's flags
    Flags getFlags() const;

    /// @brief Get flags as a single byte
    uint8_t getFlagsByte() const;

    /// @brief get zero flag
    bool getZeroFlag() const;

    /// @brief get subtract flag
    bool getSubtractFlag() const;

    /// @brief get half carry flag
    bool getHalfCarryFlag() const;

    /// @brief get carry flag
    bool getCarryFlag() const;

    /// @brief The CPU's memory
    uint8_t *getMemory();

    /// @brief The CPU's cycle count
    void setCycleCount(unsigned int cycleCount);

    /// @brief The CPU's program counter
    void setPC(uint16_t PC);

    /// @brief The CPU's stack pointer
    void setSP(uint16_t SP);

    /// @brief Set the value of the halt status
    void setHalted(bool halted);

    /// @brief Set the value of the interrupts enabled status
    void setImeFlag(bool flagValue);

    /// @brief Set the value of the interrupt flag
    void setInterruptFlag(uint8_t interruptFlag);

    /// @brief Set the value of the interrupts enabled register
    void setInterruptEnable(uint8_t interruptEnable);

    /// @brief The CPU's registers
    void setRegisters(Registers registers);

    /// @brief Set the value of the A register
    void setARegister(uint8_t A);
    /// @brief Set the value of the B register
    void setBRegister(uint8_t B);
    /// @brief Set the value of the C register
    void setCRegister(uint8_t C);
    /// @brief Set the value of the D register
    void setDRegister(uint8_t D);
    /// @brief Set the value of the E register
    void setERegister(uint8_t E);
    /// @brief Set the value of the H register
    void setHRegister(uint8_t H);
    /// @brief Set the value of the L register
    void setLRegister(uint8_t L);
    /// @brief Set AF register pair
    void setAFRegister(uint16_t AF);
    /// @brief Set the value of the BC register pair
    void setBCRegister(uint16_t BC);
    /// @brief Set the value of the DE register pair
    void setDERegister(uint16_t DE);
    /// @brief Set the value of the HL register pair
    void setHLRegister(uint16_t HL);

    /// @brief Set the CPU's flags
    void setFlags(Flags flags);
    ///@brief Set flags via a single byte
    void setFlagsByte(uint8_t flagsByte);
    /// @brief Set the zero flag
    void setZeroFlag(bool Z);
    /// @brief Set the subtract flag
    void setSubtractFlag(bool N);
    /// @brief Set the half carry flag
    void setHalfCarryFlag(bool H);
    /// @brief Set the carry flag
    void setCarryFlag(bool C);

    /// @brief Process an opcode
    void processOpCode(uint8_t opCode, Bus &bus);

    /// @brief Get the cycle count for the given opcode
    unsigned int getCycleCount(uint8_t opcode) const;

    /// @brief Execute an instruction
    void execute(uint8_t opcode, Bus &bus);

    /// @brief Tick the CPU
    void tick(Bus &bus);

    /// @brief Resets the CPU to its initial state
    void RESET();
};

#endif // GAMEBOY_EMULATOR_CPU_H