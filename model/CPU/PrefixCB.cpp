//
// Created by dacma on 3/7/2024.
//

#include "CPU.h"

// The return value is the C flag
uint8_t RLCbyte(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 0x80;
    word8 = word8 << 1;
    word8 |= carry;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint16_t RLCshort(CPU& cpu, uint16_t word16) {
    bool carry = word16 & 0x8000;
    word16 = word16 << 1;
    word16 |= carry;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word16 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word16;
}

uint8_t RRCbyte(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 1;
    word8 = word8 >> 1;
    word8 |= carry*0x80;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint16_t RRCshort(CPU& cpu, uint16_t word16) {
    bool carry = word16 & 1;
    word16 = word16 >> 1;
    word16 |= carry*0x8000;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word16 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word16;
}

uint8_t RLbyte(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 0x80;
    word8 = word8 << 1;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint16_t RLshort(CPU& cpu, uint16_t word16) {
    bool carry = word16 & 0x8000;
    word16 = word16 << 1;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word16 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word16;
}

uint8_t RRbyte(CPU& cpu, uint8_t word8) {
    bool carry = word8 & 1;
    word8 = word8 >> 1;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word8 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word8;
}

uint16_t RRshort(CPU& cpu, uint16_t word16) {
    bool carry = word16 & 1;
    word16 = word16 >> 1;
    cpu.setCarryFlag(carry);
    cpu.setZeroFlag(word16 == 0);
    cpu.setSubtractFlag(false);
    cpu.setHalfCarryFlag(false);
    return word16;
}

void CPU::processCB(Bus &bus) {
    // Stub for opcode 0xCB
    setPC(PC + 1); // Prefixed instructions add one more byte before the related opcodes (the CB byte)
    switch (bus.read(PC)) {
        case 0x00:
            processCB00(bus);
            break;
        case 0x01:
            processCB01(bus);
            break;
        case 0x02:
            processCB02(bus);
            break;
        case 0x03:
            processCB03(bus);
            break;
        case 0x04:
            processCB04(bus);
            break;
        case 0x05:
            processCB05(bus);
            break;
        case 0x06:
            processCB06(bus);
            break;
        case 0x07:
            processCB07(bus);
            break;
        case 0x08:
            processCB08(bus);
            break;
        case 0x09:
            processCB09(bus);
            break;
        case 0x0A:
            processCB0A(bus);
            break;
        case 0x0B:
            processCB0B(bus);
            break;
        case 0x0C:
            processCB0C(bus);
            break;
        case 0x0D:
            processCB0D(bus);
            break;
        case 0x0E:
            processCB0E(bus);
            break;
        case 0x0F:
            processCB0F(bus);
            break;
        case 0x10:
            processCB10(bus);
            break;
        case 0x11:
            processCB11(bus);
            break;
        case 0x12:
            processCB12(bus);
            break;
        case 0x13:
            processCB13(bus);
            break;
        case 0x14:
            processCB14(bus);
            break;
        case 0x15:
            processCB15(bus);
            break;
        case 0x16:
            processCB16(bus);
            break;
        case 0x17:
            processCB17(bus);
            break;
        case 0x18:
            processCB18(bus);
            break;
        case 0x19:
            processCB19(bus);
            break;
        case 0x1A:
            processCB1A(bus);
            break;
        case 0x1B:
            processCB1B(bus);
            break;
        case 0x1C:
            processCB1C(bus);
            break;
        case 0x1D:
            processCB1D(bus);
            break;
        case 0x1E:
            processCB1E(bus);
            break;
        case 0x1F:
            processCB1F(bus);
            break;
    }
    setPC(PC + 2); // All prefixed instructions are 2 bytes long (after the leading CB)
}

void CPU::processCB00(Bus &bus) {
    setBRegister(RLCbyte(*this, getBRegister()));
}

void CPU::processCB01(Bus &bus) {
    setCRegister(RLCbyte(*this, getCRegister()));
}

void CPU::processCB02(Bus &bus) {
    setDRegister(RLCbyte(*this, getDRegister()));
}

void CPU::processCB03(Bus &bus) {
    setERegister(RLCbyte(*this, getERegister()));
}

void CPU::processCB04(Bus &bus) {
    setHRegister(RLCbyte(*this, getHRegister()));
}

void CPU::processCB05(Bus &bus) {
    setLRegister(RLCbyte(*this, getLRegister()));
}

void CPU::processCB06(Bus &bus) {
    setHLRegister(RLCshort(*this, getHLRegister()));
}

void CPU::processCB07(Bus &bus) {
    setARegister(RLCbyte(*this, getARegister()));
}

void CPU::processCB08(Bus &bus) {
    setBRegister(RRCbyte(*this, getBRegister()));
}

void CPU::processCB09(Bus &bus) {
    setCRegister(RRCbyte(*this, getCRegister()));
}

void CPU::processCB0A(Bus &bus) {
    setDRegister(RRCbyte(*this, getDRegister()));
}

void CPU::processCB0B(Bus &bus) {
    setERegister(RRCbyte(*this, getERegister()));
}

void CPU::processCB0C(Bus &bus) {
    setHRegister(RRCbyte(*this, getHRegister()));
}

void CPU::processCB0D(Bus &bus) {
    setLRegister(RRCbyte(*this, getLRegister()));
}

void CPU::processCB0E(Bus &bus) {
    setHLRegister(RRCshort(*this, getHLRegister()));
}

void CPU::processCB0F(Bus &bus) {
    setARegister(RRCbyte(*this, getBRegister()));
}

void CPU::processCB10(Bus &bus) {
    setBRegister(RLbyte(*this, getBRegister()));
}

void CPU::processCB11(Bus &bus) {
    setCRegister(RLbyte(*this, getCRegister()));
}

void CPU::processCB12(Bus &bus) {
    setDRegister(RLbyte(*this, getDRegister()));
}

void CPU::processCB13(Bus &bus) {
    setERegister(RLbyte(*this, getERegister()));
}

void CPU::processCB14(Bus &bus) {
    setHRegister(RLbyte(*this, getHRegister()));
}

void CPU::processCB15(Bus &bus) {
    setLRegister(RLbyte(*this, getLRegister()));
}

void CPU::processCB16(Bus &bus) {
    setHLRegister(RLshort(*this, getHLRegister()));
}

void CPU::processCB17(Bus &bus) {
    setARegister(RLbyte(*this, getARegister()));
}

void CPU::processCB18(Bus &bus) {
    setBRegister(RRbyte(*this, getBRegister()));
}

void CPU::processCB19(Bus &bus) {
    setCRegister(RRbyte(*this, getCRegister()));
}

void CPU::processCB1A(Bus &bus) {
    setDRegister(RRbyte(*this, getDRegister()));
}

void CPU::processCB1B(Bus &bus) {
    setERegister(RRbyte(*this, getERegister()));
}

void CPU::processCB1C(Bus &bus) {
    setHRegister(RRbyte(*this, getHRegister()));
}

void CPU::processCB1D(Bus &bus) {
    setLRegister(RRbyte(*this, getLRegister()));
}

void CPU::processCB1E(Bus &bus) {
    setHLRegister(RRshort(*this, getHLRegister()));
}

void CPU::processCB1F(Bus &bus) {
    setARegister(RRbyte(*this, getBRegister()));
}