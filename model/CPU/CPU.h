// CPU h file for Gameboy Emulator

#ifndef GAMEBOY_EMULATOR_CPU_H
#define GAMEBOY_EMULATOR_CPU_H

#include <cstdint>
#include <string>
#include "Bus.h"

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

    Instruction instructionSet = Instruction();

    /// @brief The CPU's program counter
    uint16_t PC = 0x100;
    /// @brief The CPU's stack pointer
    uint16_t SP = 0xFFFE;

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

    /// @brief Fetch an instruction from memory
    uint8_t fetch(Bus &bus);

public:
    /// @brief The CPU's cycle count
    unsigned int getCycleCount() const;

    /// @brief The CPU's instruction set
    Instruction getInstructionSet() const;

    /// @brief The CPU's program counter
    uint16_t getPC() const;

    /// @brief The CPU's stack pointer
    uint16_t getSP() const;

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

    /// @brief The CPU's flags
    Flags getFlags() const;

    /// @brief The CPU's memory
    uint8_t *getMemory();

    /// @brief The CPU's cycle count
    void setCycleCount(unsigned int cycleCount);

    /// @brief The CPU's program counter
    void setPC(uint16_t PC);

    /// @brief The CPU's stack pointer
    void setSP(uint16_t SP);

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

    /// @brief Set the CPU's flags
    void setFlags(Flags flags);
    /// @brief Set the zero flag
    void setZeroFlag(bool Z);
    /// @brief Set the subtract flag
    void setSubtractFlag(bool N);
    /// @brief Set the half carry flag
    void setHalfCarryFlag(bool H);
    /// @brief Set the carry flag
    void setCarryFlag(bool C);

    /// @brief Execute an instruction
    void execute(uint8_t opcode, Bus &bus);

    /// @brief Tick the CPU
    void tick(Bus &bus);

    /// @brief Resets the CPU to its initial state
    void RESET();
};

#endif // GAMEBOY_EMULATOR_CPU_H