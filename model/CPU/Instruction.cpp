
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
        break;
    case 0x02:
        // LD (BC), A
        process02(bus);
        break;
    case 0x03:
        // INC BC
        process03(bus);

        break;
    case 0x04:
        // INC B
        process04(bus);

        break;
    case 0x05:
        // DEC B
        process05(bus);

        break;
    case 0x06:
        // LD B, d8: load 8-bit immediate value into B register
        process06(bus);

        break;
    case 0x07:
        // RLCA
        process07(bus);

        break;
    case 0x08:
        // LD (a16), SP: store Stack Pointer (SP) at address a16
        process08(bus);

        break;
    case 0x09:
        // ADD HL, BC: add BC register pair to HL register pair
        process09(bus);

        break;
    case 0x0A:
        // LD A, (BC): load value from address pointed to by BC into A register
        process0A(bus);

        break;
    case 0x0B:
        // DEC BC: decrement BC register pair
        process0B(bus);

        break;
    case 0x0C:
        // INC C: increment C register
        process0C(bus);

        break;
    case 0x0D:
        // DEC C: decrement C register
        process0D(bus);

        break;
    case 0x0E:
        // LD C, d8: load 8-bit immediate value into C register
        process0E(bus);

        break;
    case 0x0F:
        // RRCA
        process0F(bus);

        break;
    case 0x10:
        // STOP
        process10(bus);

        break;
    case 0x11:
        // LD DE, d16: load 16-bit immediate value into DE register pair
        process11(bus);

        break;
    case 0x12:
        // LD (DE), A
        process12(bus);

        break;
    case 0x13:
        // INC DE
        process13(bus);

        break;
    case 0x14:
        // INC D
        process14(bus);

        break;
    case 0x15:
        // DEC D
        process15(bus);

        break;
    case 0x16:
        // LD D, d8: load 8-bit immediate value into D register
        process16(bus);

        break;
    case 0x17:
        // RLA
        process17(bus);

        break;
    case 0x18:
        // JR r8: relative jump by signed immediate value
        process18(bus);

        break;
    case 0x19:
        // ADD HL, DE: add DE register pair to HL register pair
        process19(bus);

        break;
    case 0x1A:
        // LD A, (DE): load value from address pointed to by DE into A register
        process1A(bus);

        break;
    case 0x1B:
        // DEC DE: decrement DE register pair
        process1B(bus);

        break;
    case 0x1C:
        // INC E: increment E register
        process1C(bus);

        break;
    case 0x1D:
        // DEC E: decrement E register
        process1D(bus);

        break;
    case 0x1E:
        // LD E, d8: load 8-bit immediate value into E register
        process1E(bus);

        break;
    case 0x1F:
        // RRA
        process1F(bus);

        break;

        break;
    case 0x20:
        // LD HL, d16: load 16-bit immediate value into HL register pair
        process20(bus);

        break;
    case 0x21:
        // LD (HL+), A: load value from A register into memory address pointed to by HL, and increment HL
        process21(bus);

        break;
    case 0x22:
        // LD (HL-), A: load value from A register into memory address pointed to by HL, and decrement HL
        process22(bus);

        break;
    case 0x23:
        // INC HL: increment HL register pair
        process23(bus);

        break;
    case 0x24:
        // INC H: increment H register
        process24(bus);

        break;
    case 0x25:
        // DEC H: decrement H register
        process25(bus);

        break;
    case 0x26:
        // LD H, d8: load 8-bit immediate value into H register
        process26(bus);

        break;
    case 0x27:
        // DAA: adjust A register for BCD arithmetic
        process27(bus);

        break;
    case 0x28:
        // JR Z, r8: relative jump by signed immediate value if last result was zero
        process28(bus);

        break;
    case 0x29:
        // ADD HL, HL: add HL register pair to HL register pair
        process29(bus);

        break;
    case 0x2A:
        // LD A, (HL+): load value from memory address pointed to by HL into A register, and increment HL
        process2A(bus);

        break;
    case 0x2B:
        // DEC HL: decrement HL register pair
        process2B(bus);

        break;
    case 0x2C:
        // INC L: increment L register
        process2C(bus);

        break;
    case 0x2D:
        // DEC L: decrement L register
        process2D(bus);

        break;
    case 0x2E:
        // LD L, d8: load 8-bit immediate value into L register
        process2E(bus);

        break;
    case 0x2F:
        // CPL: bitwise complement of A register (flip all bits)
        process2F(bus);
        break;
    case 0x30:
        // JR NC, r8: relative jump by signed immediate value if last result did not cause carry
        process30(bus);

        break;
    case 0x31:
        // LD SP, d16: load 16-bit immediate value into SP register pair
        process31(bus);

        break;
    case 0x32:
        // LD (HL-), A: load value from A register into memory address pointed to by HL, and decrement HL
        process32(bus);

        break;
    case 0x33:
        // INC SP: increment SP register pair
        process33(bus);

        break;
    case 0x34:
        // INC (HL): increment value at memory address pointed to by HL
        process34(bus);

        break;
    case 0x35:
        // DEC (HL): decrement value at memory address pointed to by HL
        process35(bus);

        break;
    case 0x36:
        // LD (HL), d8: load 8-bit immediate value into memory address pointed to by HL
        process36(bus);

        break;
    case 0x37:
        // SCF: set carry flag
        process37(bus);

        break;
    case 0x38:
        // JR C, r8: relative jump by signed immediate value if last result caused carry
        process38(bus);

        break;
    case 0x39:
        // ADD HL, SP: add SP register pair to HL register pair
        process39(bus);

        break;
    case 0x3A:
        // LD A, (HL-): load value from memory address pointed to by HL into A register, and decrement HL
        process3A(bus);

        break;
    case 0x3B:
        // DEC SP: decrement SP register pair
        process3B(bus);

        break;
    case 0x3C:
        // INC A: increment A register
        process3C(bus);

        break;
    case 0x3D:
        // DEC A: decrement A register
        process3D(bus);

        break;
    case 0x3E:
        // LD A, d8: load 8-bit immediate value into A register
        process3E(bus);

        break;
    case 0x3F:
        // CCF: complement carry flag
        process3F(bus);

        break;
    case 0x40:
        // LD B, B: copy value from B register to B register (NOP)
        process40(bus);

        break;
    case 0x41:
        // LD B, C: copy value from C register to B register
        process41(bus);

        break;
    case 0x42:
        // LD B, D: copy value from D register to B register
        process42(bus);

        break;
    case 0x43:
        // LD B, E: copy value from E register to B register
        process43(bus);

        break;
    case 0x44:
        // LD B, H: copy value from H register to B register
        process44(bus);

        break;
    case 0x45:
        // LD B, L: copy value from L register to B register
        process45(bus);

        break;
    case 0x46:
        // LD B, (HL): load value from memory address pointed to by HL into B register
        process46(bus);

        break;
    case 0x47:
        // LD B, A: copy value from A register to B register
        process47(bus);

        break;
    case 0x48:
        // LD C, B: copy value from B register to C register
        process48(bus);

        break;
    case 0x49:
        // LD C, C: copy value from C register to C register (NOP)
        process49(bus);

        break;
    case 0x4A:
        // LD C, D: copy value from D register to C register
        process4A(bus);

        break;
    case 0x4B:
        // LD C, E: copy value from E register to C register
        process4B(bus);

        break;
    case 0x4C:
        // LD C, H: copy value from H register to C register
        process4C(bus);

        break;
    case 0x4D:
        // LD C, L: copy value from L register to C register
        process4D(bus);

        break;
    case 0x4E:
        // LD C, (HL): load value from memory address pointed to by HL into C register
        process4E(bus);

        break;
    case 0x4F:
        // LD C, A: copy value from A register to C register
        process4F(bus);

        break;
    case 0x50:
        // LD D, B: copy value from B register to D register
        process50(bus);

        break;
    case 0x51:
        // LD D, C: copy value from C register to D register
        process51(bus);

        break;
    case 0x52:
        // LD D, D: copy value from D register to D register (NOP)
        process52(bus);

        break;
    case 0x53:
        // LD D, E: copy value from E register to D register
        process53(bus);

        break;
    case 0x54:
        // LD D, H: copy value from H register to D register
        process54(bus);

        break;
    case 0x55:
        // LD D, L: copy value from L register to D register
        process55(bus);

        break;
    case 0x56:
        // LD D, (HL): load value from memory address pointed to by HL into D register
        process56(bus);

        break;
    case 0x57:
        // LD D, A: copy value from A register to D register
        process57(bus);

        break;
    case 0x58:
        // LD E, B: copy value from B register to E register
        process58(bus);

        break;
    case 0x59:
        // LD E, C: copy value from C register to E register
        process59(bus);

        break;
    case 0x5A:
        // LD E, D: copy value from D register to E register
        process5A(bus);

        break;
    case 0x5B:
        // LD E, E: copy value from E register to E register (NOP)
        process5B(bus);

        break;
    case 0x5C:
        // LD E, H: copy value from H register to E register
        process5C(bus);

        break;
    case 0x5D:
        // LD E, L: copy value from L register to E register
        process5D(bus);

        break;
    case 0x5E:
        // LD E, (HL): load value from memory address pointed to by HL into E register
        process5E(bus);

        break;
    case 0x5F:
        // LD E, A: copy value from A register to E register
        process5F(bus);

        break;
    case 0x60:
        // LD H, B: copy value from B register to H register
        process60(bus);

        break;
    case 0x61:
        // LD H, C: copy value from C register to H register
        process61(bus);

        break;
    case 0x62:
        // LD H, D: copy value from D register to H register
        process62(bus);

        break;
    case 0x63:
        // LD H, E: copy value from E register to H register
        process63(bus);

        break;
    case 0x64:
        // LD H, H: copy value from H register to H register (NOP)
        process64(bus);

        break;
    case 0x65:
        // LD H, L: copy value from L register to H register
        process65(bus);

        break;
    case 0x66:
        // LD H, (HL): load value from memory address pointed to by HL into H register
        process66(bus);

        break;
    case 0x67:
        // LD H, A: copy value from A register to H register
        process67(bus);

        break;
    case 0x68:
        // LD L, B: copy value from B register to L register
        process68(bus);

        break;
    case 0x69:
        // LD L, C: copy value from C register to L register
        process69(bus);

        break;
    case 0x6A:
        // LD L, D: copy value from D register to L register
        process6A(bus);

        break;
    case 0x6B:
        // LD L, E: copy value from E register to L register
        process6B(bus);

        break;
    case 0x6C:
        // LD L, H: copy value from H register to L register
        process6C(bus);

        break;
    case 0x6D:
        // LD L, L: copy value from L register to L register (NOP)
        process6D(bus);

        break;
    case 0x6E:
        // LD L, (HL): load value from memory address pointed to by HL into L register
        process6E(bus);

        break;
    case 0x6F:
        // LD L, A: copy value from A register to L register
        process6F(bus);

        break;
    case 0x70:
        // LD (HL), B: load value from B register into memory address pointed to by HL
        process70(bus);

        break;
    case 0x71:
        // LD (HL), C: load value from C register into memory address pointed to by HL
        process71(bus);

        break;
    case 0x72:
        // LD (HL), D: load value from D register into memory address pointed to by HL
        process72(bus);

        break;
    case 0x73:
        // LD (HL), E: load value from E register into memory address pointed to by HL
        process73(bus);

        break;
    case 0x74:
        // LD (HL), H: load value from H register into memory address pointed to by HL
        process74(bus);

        break;
    case 0x75:
        // LD (HL), L: load value from L register into memory address pointed to by HL
        process75(bus);

        break;
    case 0x76:
        // HALT: halt CPU and LCD display until interrupt occurs
        process76(bus);

        break;
    case 0x77:
        // LD (HL), A: load value from A register into memory address pointed to by HL
        process77(bus);

        break;
    case 0x78:
        // LD A, B: copy value from B register to A register
        process78(bus);

        break;
    case 0x79:
        // LD A, C: copy value from C register to A register
        process79(bus);

        break;
    case 0x7A:
        // LD A, D: copy value from D register to A register
        process7A(bus);

        break;
    case 0x7B:
        // LD A, E: copy value from E register to A register
        process7B(bus);

        break;
    case 0x7C:
        // LD A, H: copy value from H register to A register
        process7C(bus);

        break;
    case 0x7D:
        // LD A, L: copy value from L register to A register
        process7D(bus);

        break;
    case 0x7E:
        // LD A, (HL): load value from memory address pointed to by HL into A register
        process7E(bus);

        break;
    case 0x7F:
        // LD A, A: copy value from A register to A register (NOP)
        process7F(bus);

        break;
    case 0x80:
        // ADD A, B: add value of B register to A register
        process80(bus);

        break;
    case 0x81:
        // ADD A, C: add value of C register to A register
        process81(bus);

        break;
    case 0x82:
        // ADD A, D: add value of D register to A register
        process82(bus);

        break;
    case 0x83:
        // ADD A, E: add value of E register to A register
        process83(bus);

        break;
    case 0x84:
        // ADD A, H: add value of H register to A register
        process84(bus);

        break;
    case 0x85:
        // ADD A, L: add value of L register to A register
        process85(bus);

        break;
    case 0x86:
        // ADD A, (HL): add value of memory address pointed to by HL to A register
        process86(bus);

        break;
    case 0x87:
        // ADD A, A: add value of A register to A register
        process87(bus);

        break;
    case 0x88:
        // ADC A, B: add value of B register and carry flag to A register
        process88(bus);

        break;
    case 0x89:
        // ADC A, C: add value of C register and carry flag to A register
        process89(bus);

        break;
    case 0x8A:
        // ADC A, D: add value of D register and carry flag to A register
        process8A(bus);

        break;
    case 0x8B:
        // ADC A, E: add value of E register and carry flag to A register
        process8B(bus);

        break;
    case 0x8C:
        // ADC A, H: add value of H register and carry flag to A register
        process8C(bus);

        break;
    case 0x8D:
        // ADC A, L: add value of L register and carry flag to A register
        process8D(bus);

        break;
    case 0x8E:
        // ADC A, (HL): add value of memory address pointed to by HL and carry flag to A register
        process8E(bus);

        break;
    case 0x8F:
        // ADC A, A: add value of A register and carry flag to A register
        process8F(bus);

        break;
    case 0x90:
        // SUB B: subtract value of B register from A register
        process90(bus);

        break;
    case 0x91:
        // SUB C: subtract value of C register from A register
        process91(bus);

        break;
    case 0x92:
        // SUB D: subtract value of D register from A register
        process92(bus);

        break;
    case 0x93:
        // SUB E: subtract value of E register from A register
        process93(bus);

        break;
    case 0x94:
        // SUB H: subtract value of H register from A register
        process94(bus);

        break;
    case 0x95:
        // SUB L: subtract value of L register from A register
        process95(bus);

        break;
    case 0x96:
        // SUB (HL): subtract value of memory address pointed to by HL from A register
        process96(bus);

        break;
    case 0x97:
        // SUB A: subtract value of A register from A register (NOP)
        process97(bus);

        break;
    case 0x98:
        // SBC A, B: subtract value of B register and carry flag from A register
        process98(bus);

        break;
    case 0x99:
        // SBC A, C: subtract value of C register and carry flag from A register
        process99(bus);

        break;
    case 0x9A:
        // SBC A, D: subtract value of D register and carry flag from A register
        process9A(bus);

        break;
    case 0x9B:
        // SBC A, E: subtract value of E register and carry flag from A register
        process9B(bus);

        break;
    case 0x9C:
        // SBC A, H: subtract value of H register and carry flag from A register
        process9C(bus);

        break;
    case 0x9D:
        // SBC A, L: subtract value of L register and carry flag from A register
        process9D(bus);

        break;
    case 0x9E:
        // SBC A, (HL): subtract value of memory address pointed to by HL and carry flag from A register
        process9E(bus);

        break;
    case 0x9F:
        // SBC A, A: subtract value of A register and carry flag from A register
        process9F(bus);

        break;
    case 0xA0:
        // AND B: logical AND value of B register with A register
        processA0(bus);

        break;
    case 0xA1:
        // AND C: logical AND value of C register with A register
        processA1(bus);

        break;
    case 0xA2:
        // AND D: logical AND value of D register with A register
        processA2(bus);

        break;
    case 0xA3:
        // AND E: logical AND value of E register with A register
        processA3(bus);

        break;
    case 0xA4:
        // AND H: logical AND value of H register with A register
        processA4(bus);

        break;
    case 0xA5:
        // AND L: logical AND value of L register with A register
        processA5(bus);

        break;
    case 0xA6:
        // AND (HL): logical AND value of memory address pointed to by HL with A register
        processA6(bus);

        break;
    case 0xA7:
        // AND A: logical AND value of A register with A register
        processA7(bus);

        break;
    case 0xA8:
        // XOR B: logical XOR value of B register with A register
        processA8(bus);

        break;
    case 0xA9:
        // XOR C: logical XOR value of C register with A register
        processA9(bus);

        break;
    case 0xAA:
        // XOR D: logical XOR value of D register with A register
        processAA(bus);

        break;
    case 0xAB:
        // XOR E: logical XOR value of E register with A register
        processAB(bus);

        break;
    case 0xAC:
        // XOR H: logical XOR value of H register with A register
        processAC(bus);

        break;
    case 0xAD:
        // XOR L: logical XOR value of L register with A register
        processAD(bus);

        break;
    case 0xAE:
        // XOR (HL): logical XOR value of memory address pointed to by HL with A register
        processAE(bus);

        break;
    case 0xAF:
        // XOR A: logical XOR value of A register with A register (result is 0)
        processAF(bus);

        break;
    case 0xB0:
        // OR B: logical OR value of B register with A register
        processB0(bus);

        break;
    case 0xB1:
        // OR C: logical OR value of C register with A register
        processB1(bus);

        break;
    case 0xB2:
        // OR D: logical OR value of D register with A register
        processB2(bus);

        break;
    case 0xB3:
        // OR E: logical OR value of E register with A register
        processB3(bus);

        break;
    case 0xB4:
        // OR H: logical OR value of H register with A register
        processB4(bus);

        break;
    case 0xB5:
        // OR L: logical OR value of L register with A register
        processB5(bus);

        break;
    case 0xB6:
        // OR (HL): logical OR value of memory address pointed to by HL with A register
        processB6(bus);

        break;
    case 0xB7:
        // OR A: logical OR value of A register with A register
        processB7(bus);

        break;
    case 0xB8:
        // CP B: compare value of B register with A register
        processB8(bus);

        break;
    case 0xB9:
        // CP C: compare value of C register with A register
        processB9(bus);

        break;
    case 0xBA:
        // CP D: compare value of D register with A register
        processBA(bus);

        break;
    case 0xBB:
        // CP E: compare value of E register with A register
        processBB(bus);

        break;
    case 0xBC:
        // CP H: compare value of H register with A register
        processBC(bus);

        break;
    case 0xBD:
        // CP L: compare value of L register with A register
        processBD(bus);

        break;
    case 0xBE:
        // CP (HL): compare value of memory address pointed to by HL with A register
        processBE(bus);

        break;
    case 0xBF:
        // CP A: compare value of A register with A register (result is 0)
        processBF(bus);

        break;
    case 0xC0:
        // RET NZ: return if last result was not zero
        processC0(bus);

        break;
    case 0xC1:
        // POP BC: pop 16-bit value from stack into BC register pair
        processC1(bus);

        break;
    case 0xC2:
        // JP NZ, a16: absolute jump to 16-bit immediate value if last result was not zero
        processC2(bus);

        break;
    case 0xC3:
        // JP a16: absolute jump to 16-bit immediate value
        processC3(bus);

        break;
    case 0xC4:
        // CALL NZ, a16: call subroutine at 16-bit immediate value if last result was not zero
        processC4(bus);

        break;
    case 0xC5:
        // PUSH BC: push BC register pair onto stack
        processC5(bus);

        break;
    case 0xC6:
        // ADD A, d8: add 8-bit immediate value to A register
        processC6(bus);

        break;
    case 0xC7:
        // RST 00H: call subroutine at memory address 0x00
        processC7(bus);

        break;
    case 0xC8:
        // RET Z: return if last result was zero
        processC8(bus);

        break;
    case 0xC9:
        // RET: return from subroutine
        processC9(bus);

        break;
    case 0xCA:
        // JP Z, a16: absolute jump to 16-bit immediate value if last result was zero
        processCA(bus);

        break;
    case 0xCB:
        // CB prefix: extended instruction set
        processCB(bus);

        break;
    case 0xCC:
        // CALL Z, a16: call subroutine at 16-bit immediate value if last result was zero
        processCC(bus);

        break;
    case 0xCD:
        // CALL a16: call subroutine at 16-bit immediate value
        processCD(bus);

        break;
    case 0xCE:
        // ADC A, d8: add 8-bit immediate value and carry flag to A register
        processCE(bus);

        break;
    case 0xCF:
        // RST 08H: call subroutine at memory address 0x08
        processCF(bus);

        break;
    case 0xD0:
        // RET NC: return if last result did not cause carry
        processD0(bus);

        break;
    case 0xD1:
        // POP DE: pop 16-bit value from stack into DE register pair
        processD1(bus);

        break;
    case 0xD2:
        // JP NC, a16: absolute jump to 16-bit immediate value if last result did not cause carry
        processD2(bus);

        break;
    case 0xD4:
        // CALL NC, a16: call subroutine at 16-bit immediate value if last result did not cause carry
        processD4(bus);

        break;
    case 0xD5:
        // PUSH DE: push DE register pair onto stack
        processD5(bus);

        break;
    case 0xD6:
        // SUB d8: subtract 8-bit immediate value from A register
        processD6(bus);

        break;
    case 0xD7:
        // RST 10H: call subroutine at memory address 0x10
        processD7(bus);

        break;
    case 0xD8:
        // RET C: return if last result caused carry
        processD8(bus);

        break;
    case 0xD9:
        // RETI: return from interrupt
        processD9(bus);

        break;
    case 0xDA:
        // JP C, a16: absolute jump to 16-bit immediate value if last result caused carry
        processDA(bus);

        break;
    case 0xDC:
        // CALL C, a16: call subroutine at 16-bit immediate value if last result caused carry
        processDC(bus);

        break;
    case 0xDE:
        // SBC A, d8: subtract 8-bit immediate value and carry flag from A register
        processDE(bus);

        break;
    case 0xDF:
        // RST 18H: call subroutine at memory address 0x18
        processDF(bus);

        break;
    case 0xE0:
        // LD (FF00 + a8), A: load value from A register into memory address FF00 + 8-bit immediate value
        processE0(bus);

        break;
    case 0xE1:
        // POP HL: pop 16-bit value from stack into HL register pair
        processE1(bus);

        break;
    case 0xE2:
        // LD (FF00 + C), A: load value from A register into memory address FF00 + value of C register
        processE2(bus);

        break;
    case 0xE5:
        // PUSH HL: push HL register pair onto stack
        processE5(bus);

        break;
    case 0xE6:
        // AND d8: logical AND 8-bit immediate value with A register
        processE6(bus);

        break;
    case 0xE7:
        // RST 20H: call subroutine at memory address 0x20
        processE7(bus);

        break;
    case 0xE8:
        // ADD SP, r8: add signed 8-bit immediate value to stack pointer SP
        processE8(bus);

        break;
    case 0xE9:
        // JP (HL): absolute jump to address contained in HL register pair
        processE9(bus);

        break;
    case 0xEA:
        // LD (a16), A: load value from A register into memory address specified by 16-bit immediate value
        processEA(bus);

        break;
    case 0xEE:
        // XOR d8: logical XOR 8-bit immediate value with A register
        processEE(bus);

        break;
    case 0xEF:
        // RST 28H: call subroutine at memory address 0x28
        processEF(bus);

        break;
    case 0xF0:
        // LD A, (FF00 + a8): load value from memory address FF00 + 8-bit immediate value into A register
        processF0(bus);

        break;
    case 0xF1:
        // POP AF: pop 16-bit value from stack into AF register pair
        processF1(bus);

        break;
    case 0xF2:
        // LD A, (FF00 + C): load value from memory address FF00 + value of C register into A register
        processF2(bus);

        break;
    case 0xF3:
        // DI: disable interrupts
        processF3(bus);

        break;
    case 0xF5:
        // PUSH AF: push AF register pair onto stack
        processF5(bus);

        break;
    case 0xF6:
        // OR d8: logical OR 8-bit immediate value with A register
        processF6(bus);

        break;
    case 0xF7:
        // RST 30H: call subroutine at memory address 0x30
        processF7(bus);

        break;
    case 0xF8:
        // LD HL, SP+r8: load value of stack pointer SP plus signed 8-bit immediate value into HL register pair
        processF8(bus);

        break;
    case 0xF9:
        // LD SP, HL: copy value of HL register pair into stack pointer SP
        processF9(bus);

        break;
    case 0xFA:
        // LD A, (a16): load value from memory address specified by 16-bit immediate value into A register
        processFA(bus);

        break;
    case 0xFB:
        // EI: enable interrupts
        processFB(bus);

        break;
    case 0xFE:
        // CP d8: compare 8-bit immediate value with A register
        processFE(bus);

        break;
    case 0xFF:
        // RST 38H: call subroutine at memory address 0x38
        processFF(bus);

        break;
    }
    cycleCount += getCycleCount(opCode);
}

unsigned int CPU::getCycleCount(uint8_t opcode) const
{
    switch (opcode)
    {
    case 0x00:
        return 4;
    case 0x01:
        return 12;
    case 0x02:
        return 8;
    case 0x03:
        return 8;
    }

    printf("Unknown opcode: 0x%02X\n", opcode);
    return 0;
}

void CPU::process01(Bus &bus)
{

    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load immediate value into the BC register pair
    setBCRegister(immediateValue);
    // increment the program counter
    setPC(PC + 3);
}

void CPU::process02(Bus &bus)
{
    // get the location in memory from the BC register pair
    uint16_t address = bus.read(registers.BC); // TODO: is this right?
    bus.write(address, registers.A);
    // increment the program counter
    setPC(PC + 1);
}