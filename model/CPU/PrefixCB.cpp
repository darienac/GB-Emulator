//
// Created by dacma on 3/7/2024.
//

#include "CPU.h"

// The return value is the C flag
uint8_t RLC(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 0x80;
    word8 = word8 << 1;
    word8 |= carry;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint8_t RRC(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 1;
    word8 = word8 >> 1;
    word8 |= carry*0x80;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint8_t RL(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 0x80;
    word8 = word8 << 1;
    word8 |= cpu.getCarryFlag();
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint8_t RR(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 1;
    word8 = word8 >> 1;
    word8 |= cpu.getCarryFlag()*0x80;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint8_t SLA(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 0x80;
    word8 = word8 << 1;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint8_t SRA(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 1;
    uint8_t MSB = word8 & 0x80;
    word8 = word8 >> 1;
    word8 |= MSB;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint8_t SWAP(CPU& cpu, uint8_t word8) {
    uint8_t swapped = (word8 & 0x0F) << 4 | (word8 & 0xF0) >> 4;

    cpu.setZeroFlag(swapped == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    cpu.setCarryFlag(false);

    return swapped;
}

uint8_t SRL(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 1;
    word8 = word8 >> 1;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

void BIT(CPU& cpu, uint8_t bitMask, uint8_t data) {
    cpu.setZeroFlag(!(data & bitMask));
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(true);
}

uint8_t RES(CPU& cpu, uint8_t bitMask, uint8_t data) {
    return data & (~bitMask);
}

uint8_t SET(CPU& cpu, uint8_t bitMask, uint8_t data) {
    return data | bitMask;
}

uint8_t getOperand(CPU& cpu, Bus &bus, uint8_t operand) {
    switch(operand) {
        case 0:
            return cpu.getBRegister();
        case 1:
            return cpu.getCRegister();
        case 2:
            return cpu.getDRegister();
        case 3:
            return cpu.getERegister();
        case 4:
            return cpu.getHRegister();
        case 5:
            return cpu.getLRegister();
        case 6:
            return bus.read(cpu.getHLRegister());
        case 7:
            return cpu.getARegister();
    }
    return 0;
}

void setOperand(CPU& cpu, Bus &bus, uint8_t operand, uint8_t value) {
    switch(operand) {
        case 0:
            cpu.setBRegister(value);
            break;
        case 1:
            cpu.setCRegister(value);
            break;
        case 2:
            cpu.setDRegister(value);
            break;
        case 3:
            cpu.setERegister(value);
            break;
        case 4:
            cpu.setHRegister(value);
            break;
        case 5:
            cpu.setLRegister(value);
            break;
        case 6:
            bus.write(cpu.getHLRegister(), value);
            break;
        case 7:
            cpu.setARegister(value);
            break;
    }
}

void CPU::processCB(Bus &bus) {
    setPC(PC + 1); // Prefixed instructions add one more byte before the related opcodes (the CB byte)
    uint8_t instruction = bus.read(PC);
    uint8_t operand = instruction & 7;
    uint8_t data = getOperand(*this, bus, operand);
    instruction = instruction >> 3;
    switch(instruction) {
        case 0: // RLC
            data = RLC(*this, data);
            break;
        case 1: // RRC
            data = RRC(*this, data);
            break;
        case 2: // RL
            data = RL(*this, data);
            break;
        case 3: // RR
            data = RR(*this, data);
            break;
        case 4: // SLA
            data = SLA(*this, data);
            break;
        case 5: // SRA
            data = SRA(*this, data);
            break;
        case 6: // SWAP
            data = SWAP(*this, data);
            break;
        case 7: // SRL
            data = SRL(*this, data);
            break;
        default: // bitwise
            uint8_t bitIndex = instruction & 7;
            uint8_t bitMask = 1;
            if (bitIndex & 1) {
                bitMask = bitMask << 1;
            }
            if (bitIndex & 2) {
                bitMask = bitMask << 2;
            }
            if (bitIndex & 4) {
                bitMask = bitMask << 4;
            }
            instruction = instruction >> 3;
            switch(instruction) {
                case 1: // BIT
                    BIT(*this, bitMask, data);
                    break;
                case 2: // RES
                    data = RES(*this, bitMask, data);
                    break;
                case 3: // SET
                    data = SET(*this, bitMask, data);
                    break;
                default:
                    break;
            }
    }
    setOperand(*this, bus, operand, data);

    setPC(PC + 1);
}