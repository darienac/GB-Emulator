// A file containing instructions for the CPU
// It maps opcodes to their respective instructions

#include <cstdint>

class Instruction
{
public:
    /// @brief Process the given opcode and execute the instruction
    void processOpCode(uint8_t opcode);
    /// @brief Get the cycle count for the given opcode
    unsigned int getCycleCount(uint8_t opcode) const;
};