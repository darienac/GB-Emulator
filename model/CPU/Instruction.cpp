
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
    case 0x04:
        return 4;
    case 0x05:
        return 4;
    case 0x06:
        return 8;
    case 0x07:
        return 4;
    case 0x08:
        return 20;
    case 0x09:
        return 8;
    case 0x0A:
        return 8;
    case 0x0B:
        return 8;
    case 0x0C:
        return 4;
    case 0x0D:
        return 4;
    case 0x0E:
        return 8;
    case 0x0F:
        return 8;
    case 0x10:
        return 20;
    case 0x11:
        return 12;
    case 0x12:
        return 8;
    case 0x13:
        return 8;
    case 0x14:
        return 4;
    case 0x15:
        return 4;
    case 0x16:
        return 8;
    case 0x17:
        return 4;
    case 0x18:
        return 12;
    case 0x19:
        return 8;
    case 0x1A:
        return 8;
    case 0x1B:
        return 8;
    case 0x1C:
        return 4;
    case 0x1D:
        return 4;
    case 0x1E:
        return 8;
    case 0x1F:
        return 8;
    case 0x20:
        return 8;
    case 0x21:
        return 12;
    case 0x22:
        return 8;
    case 0x23:
        return 8;
    case 0x24:
        return 4;
    case 0x25:
        return 4;
    case 0x26:
        return 8;
    case 0x27:
        return 4;
    case 0x28:
        return 8;
    case 0x29:
        return 8;
    case 0x2A:
        return 8;
    case 0x2B:
        return 8;
    case 0x2C:
        return 4;
    case 0x2D:
        return 4;
    case 0x2E:
        return 8;
    case 0x2F:
        return 8;
    case 0x30:
        return 8;
    case 0x31:
        return 12;
    case 0x32:
        return 8;
    case 0x33:
        return 8;
    case 0x34:
        return 12;
    case 0x35:
        return 12;
    case 0x36:
        return 12;
    case 0x37:
        return 8;
    case 0x38:
        return 8;
    case 0x39:
        return 8;
    case 0x3A:
        return 8;
    case 0x3B:
        return 8;
    case 0x3C:
        return 4;
    case 0x3D:
        return 4;
    case 0x3E:
        return 8;
    case 0x3F:
        return 8;
    case 0x40:
        return 4;
    case 0x41:
        return 4;
    case 0x42:
        return 4;
    case 0x43:
        return 4;
    case 0x44:
        return 4;
    case 0x45:
        return 4;
    case 0x46:
        return 8;
    case 0x47:
        return 4;
    case 0x48:
        return 4;
    case 0x49:
        return 4;
    case 0x4A:
        return 4;
    case 0x4B:
        return 4;
    case 0x4C:
        return 4;
    case 0x4D:
        return 4;
    case 0x4E:
        return 8;
    case 0x4F:
        return 8;
    case 0x50:
        return 4;
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

    setPC(PC + 3);
}

void CPU::process02(Bus &bus)
{
    // get the location in memory from the BC register pair
    uint16_t address = bus.read(registers.BC); // TODO: is this right?
    bus.write(address, registers.A);

    setPC(PC + 1);
}

void CPU::process03(Bus &bus)
{
    // increment the BC register pair
    setBCRegister(registers.BC + 1);

    setPC(PC + 1);
}

void CPU::process04(Bus &bus)
{
    // increment the B register
    setBRegister(registers.B + 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.B == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.B & 0x0F) == 0);

    setPC(PC + 1);
}

void CPU::process05(Bus &bus)
{
    // decrement the B register
    setBRegister(registers.B - 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.B == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.B & 0x0F) == 0);

    setPC(PC + 1);
}

void CPU::process06(Bus &bus)
{
    // load the 8-bit immediate value into the B register
    setBRegister(bus.read(PC + 1));

    setPC(PC + 2);
}

// TODO: is this right? RLCA is kinda confusing
void CPU::process07(Bus &bus)
{
    // shift the A register left by one bit
    setARegister(registers.A << 1);
    // set the carry flag if the leftmost bit was set
    setCarryFlag((registers.A & 0x80) != 0);
    // clear the subtract and half-carry flags
    setSubtractFlag(false);
    setHalfCarryFlag(false);

    setPC(PC + 1);
}

void CPU::process08(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load immediate value into the memory address specified by the immediate value
    bus.write(immediateValue, SP & 0x00FF);
    bus.write(immediateValue + 1, (SP & 0xFF00) >> 8);

    setPC(PC + 3);
}

void CPU::process09(Bus &bus)
{
    uint16_t result = registers.HL + registers.BC;
    // load the result into the HL register pair
    setHLRegister(result);
    // update flags
    setSubtractFlag(false);
    setHalfCarryFlag((registers.HL & 0x0FFF) < (registers.BC & 0x0FFF));
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process0A(Bus &bus)
{
    // get the location in memory from the BC register pair
    uint16_t address = bus.read(registers.BC);
    setARegister(bus.read(address));

    setPC(PC + 1);
}

void CPU::process0B(Bus &bus)
{
    // decrement the BC register pair
    setBCRegister(registers.BC - 1);

    setPC(PC + 1);
}

void CPU::process0C(Bus &bus)
{
    // increment the C register
    setCRegister(registers.C + 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.C == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.C & 0x0F) == 0);

    setPC(PC + 1);
}

void CPU::process0D(Bus &bus)
{
    // decrement C register
    setCRegister(registers.C - 1);
    // update flags
    setZeroFlag(registers.C == 0);
    setSubtractFlag(true);
    setHalfCarryFlag((registers.C & 0x0F) == 0);

    setPC(PC + 1);
}

void CPU::process0E(Bus &bus)
{
    // load the 8-bit immediate value into the C register
    setCRegister(bus.read(PC + 1));

    setPC(PC + 2);
}

// TODO: is this right? RRCA
void CPU::process0F(Bus &bus)
{
    // shift the A register right by one bit
    setARegister(registers.A >> 1);
    // set the carry flag if the rightmost bit was set
    setCarryFlag((registers.A & 0x01) != 0);
    // clear the subtract and half-carry flags
    setSubtractFlag(false);
    setHalfCarryFlag(false);

    setPC(PC + 1);
}

void CPU::process10(Bus &bus)
{
    // STOP instruction TODO: how?

    setPC(PC + 2);
}

void CPU::process11(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load immediate value into the DE register pair
    setDERegister(immediateValue);
    setPC(PC + 3);
}

void CPU::process12(Bus &bus)
{
    // get the location in memory from the DE register pair and load the A register into it
    bus.write(registers.DE, registers.A);
    setPC(PC + 1);
}

void CPU::process13(Bus &bus)
{
    // increment the DE register pair
    setDERegister(registers.DE + 1);
    setPC(PC + 1);
}

void CPU::process14(Bus &bus)
{
    // increment the D register
    setDRegister(registers.D + 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.D == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.D & 0x0F) == 0);

    setPC(PC + 1);
}

void CPU::process15(Bus &bus)
{
    // decrement the D register
    setDRegister(registers.D - 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.D == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.D & 0x0F) == 0);

    setPC(PC + 1);
}

void CPU::process16(Bus &bus)
{
    // load the 8-bit immediate value into the D register
    setDRegister(bus.read(PC + 1));

    setPC(PC + 2);
}

// TODO: RLA needs a check for correctness
void CPU::process17(Bus &bus)
{
    // shift the A register left by one bit and set the carry flag to the value of the leftmost bit
    setARegister(registers.A << 1);
    setCarryFlag((registers.A & 0x80) != 0);
    setPC(PC + 1);
}

void CPU::process18(Bus &bus)
{
    // add the 8-bit immediate value to the program counter
    int8_t offset = (int8_t)bus.read(PC + 1);
    setPC(PC + offset + 2);
}

void CPU::process19(Bus &bus)
{
    // add the value of the DE register pair to the HL register pair
    uint16_t result = registers.HL + registers.DE;
    setHLRegister(result);
    // update flags
    setSubtractFlag(false);
    setHalfCarryFlag((registers.HL & 0x0FFF) < (registers.DE & 0x0FFF));
    setCarryFlag(result > 0xFFFF);
    setPC(PC + 1);
}

void CPU::process1A(Bus &bus)
{
    // get the location in memory from the DE register pair and load the value into the A register
    setARegister(bus.read(registers.DE));
    setPC(PC + 1);
}

void CPU::process1B(Bus &bus)
{
    // decrement the DE register pair
    setDERegister(registers.DE - 1);
    setPC(PC + 1);
}

void CPU::process1C(Bus &bus)
{
    // increment the E register
    setERegister(registers.E + 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.E == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.E & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process1D(Bus &bus)
{
    // decrement the E register
    setERegister(registers.E - 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.E == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.E & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process1E(Bus &bus)
{
    // load the 8-bit immediate value into the E register
    setERegister(bus.read(PC + 1));
    setPC(PC + 2);
}

// TODO: check RRA for correctness
void CPU::process1F(Bus &bus)
{
    // shift the A register right by one bit and set the carry flag to the value of the rightmost bit
    setARegister(registers.A >> 1);
    setCarryFlag((registers.A & 0x01) != 0);
    setPC(PC + 1);
}
void CPU::process20(Bus &bus)
{
    // fetch the 8-bit immediate value
    int8_t offset = (int8_t)bus.read(PC + 1);
    // if the zero flag is not set, add the offset to the program counter
    if (!getZeroFlag())
    {
        setPC(PC + offset + 2);
    }
    else
    {
        setPC(PC + 2);
    }
}

void CPU::process21(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load immediate value into the HL register pair
    setHLRegister(immediateValue);
    setPC(PC + 3);
}

// TODO: double check on LD HL+
void CPU::process22(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load the value of the HL register pair into the memory address specified by the immediate value
    bus.write(immediateValue, registers.L);
    bus.write(immediateValue + 1, registers.H);
    setPC(PC + 3);
}

void CPU::process23(Bus &bus)
{
    // increment the HL register pair
    setHLRegister(registers.HL + 1);
    setPC(PC + 1);
}

void CPU::process24(Bus &bus)
{
    // increment the H register
    setHRegister(registers.H + 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.H == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.H & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process25(Bus &bus)
{
    // decrement the H register
    setHRegister(registers.H - 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.H == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.H & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process26(Bus &bus)
{
    // load the 8-bit immediate value into the H register
    setHRegister(bus.read(PC + 1));
    setPC(PC + 2);
}

// TODO: how to do DAA? what even is that?
void CPU::process27(Bus &bus)
{
    printf("Opcode 0x27 not implemented\n");
}

void CPU::process28(Bus &bus)
{
    // fetch the 8-bit immediate value
    int8_t offset = (int8_t)bus.read(PC + 1);
    // if the zero flag is set, add the offset to the program counter
    if (getZeroFlag())
    {
        setPC(PC + offset + 2);
    }
    else
    {
        setPC(PC + 2);
    }
}

void CPU::process29(Bus &bus)
{
    // add the value of the HL register pair to itself
    uint16_t result = registers.HL + registers.HL;
    // load the result into the HL register pair
    setHLRegister(result);
    // update flags
    setSubtractFlag(false);
    setHalfCarryFlag((registers.HL & 0x0FFF) < (registers.HL & 0x0FFF));
    setCarryFlag(result > 0xFFFF);
    setPC(PC + 1);
}

// TODO: check on LD HL+
void CPU::process2A(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load the value of the memory address specified by the immediate value into the HL register pair
    setHLRegister(bus.read(immediateValue) | (bus.read(immediateValue + 1) << 8));
    setPC(PC + 3);
}

void CPU::process2B(Bus &bus)
{
    // decrement the HL register pair
    setHLRegister(registers.HL - 1);
    setPC(PC + 1);
}

void CPU::process2C(Bus &bus)
{
    // increment the L register
    setLRegister(registers.L + 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.L == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.L & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process2D(Bus &bus)
{
    // decrement the L register
    setLRegister(registers.L - 1);
    // set the zero flag if the result is zero
    setZeroFlag(registers.L == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.L & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process2E(Bus &bus)
{
    // load the 8-bit immediate value into the L register
    setLRegister(bus.read(PC + 1));
    setPC(PC + 2);
}

// TODO: check on CPL
void CPU::process2F(Bus &bus)
{
    // complement the A register
    setARegister(~registers.A);
    // set the subtract and half-carry flags
    setSubtractFlag(true);
    setHalfCarryFlag(true);
    setPC(PC + 1);
}

void CPU::process30(Bus &bus)
{
    // fetch the 8-bit immediate value
    int8_t offset = (int8_t)bus.read(PC + 1);
    // if the carry flag is not set, add the offset to the program counter
    if (!getCarryFlag())
    {
        setPC(PC + offset + 2);
    }
    else
    {
        setPC(PC + 2);
    }
}

void CPU::process31(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load immediate value into the stack pointer
    setSP(immediateValue);
    setPC(PC + 3);
}

// TODO: check on HL-
void CPU::process32(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load the value of the A register into the memory address specified by the immediate value
    bus.write(immediateValue, registers.A);
    setPC(PC + 3);
}

void CPU::process33(Bus &bus)
{
    // increment the stack pointer
    setSP(SP + 1);
    setPC(PC + 1);
}

void CPU::process34(Bus &bus)
{
    // increment the value at the memory address specified by the HL register pair
    uint8_t value = bus.read(registers.HL);
    bus.write(registers.HL, value + 1);
    // update flags
    setZeroFlag(value == 0);
    setSubtractFlag(false);
    setHalfCarryFlag((value & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process35(Bus &bus)
{
    // decrement the value at the memory address specified by the HL register pair
    uint8_t value = bus.read(registers.HL);
    bus.write(registers.HL, value - 1);
    // update flags
    setZeroFlag(value == 0);
    setSubtractFlag(true);
    setHalfCarryFlag((value & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process36(Bus &bus)
{
    // load the 8-bit immediate value into the memory address specified by the HL register pair
    bus.write(registers.HL, bus.read(PC + 1));
    setPC(PC + 2);
}

// TODO: what the hay is SCF?
void CPU::process37(Bus &bus)
{
    // Stub for opcode 0x37
}

void CPU::process38(Bus &bus)
{
    // fetch the 8-bit immediate value
    int8_t offset = (int8_t)bus.read(PC + 1);
    // if the carry flag is set, add the offset to the program counter
    if (getCarryFlag())
    {
        setPC(PC + offset + 2);
    }
    else
    {
        setPC(PC + 2);
    }
}

void CPU::process39(Bus &bus)
{
    // add the value of the stack pointer to the HL register pair
    uint16_t result = registers.HL + SP;
    // load the result into the HL register pair
    setHLRegister(result);
    // update flags
    setSubtractFlag(false);
    setHalfCarryFlag((registers.HL & 0x0FFF) < (SP & 0x0FFF));
    setCarryFlag(result > 0xFFFF);
    setPC(PC + 1);
}

// TODO: check on HL-
void CPU::process3A(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // load the value of the memory address specified by the immediate value into the A register
    setARegister(bus.read(immediateValue));
    setPC(PC + 3);
}

void CPU::process3B(Bus &bus)
{
    // decrement the stack pointer
    setSP(SP - 1);
    setPC(PC + 1);
}

void CPU::process3C(Bus &bus)
{
    // increment A
    setARegister(registers.A + 1);
    setZeroFlag(registers.A == 0);
    setSubtractFlag(false);
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process3D(Bus &bus)
{
    // decrement A
    setARegister(registers.A - 1);
    setZeroFlag(registers.A == 0);
    setSubtractFlag(true);
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    setPC(PC + 1);
}

void CPU::process3E(Bus &bus)
{
    // load the 8-bit immediate value into the A register
    setARegister(bus.read(PC + 1));
    setPC(PC + 2);
}

// TODO: check on CCF
void CPU::process3F(Bus &bus)
{
    // complement the carry flag
    setCarryFlag(!getCarryFlag());
    setPC(PC + 1);
}

void CPU::process40(Bus &bus)
{
    // load the B register into the B register
    setBRegister(registers.B);
    setPC(PC + 1);
}

void CPU::process41(Bus &bus)
{
    // load the C register into the B register
    setBRegister(registers.C);
    setPC(PC + 1);
}

void CPU::process42(Bus &bus)
{
    // load the D register into the B register
    setBRegister(registers.D);
    setPC(PC + 1);
}

void CPU::process43(Bus &bus)
{
    // load the E register into the B register
    setBRegister(registers.E);
    setPC(PC + 1);
}

void CPU::process44(Bus &bus)
{
    // load the H register into the B register
    setBRegister(registers.H);
    setPC(PC + 1);
}

void CPU::process45(Bus &bus)
{
    // load the L register into the B register
    setBRegister(registers.L);
    setPC(PC + 1);
}

void CPU::process46(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the B register
    setBRegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process47(Bus &bus)
{
    // load the A register into the B register
    setBRegister(registers.A);
    setPC(PC + 1);
}

void CPU::process48(Bus &bus)
{
    // load the B register into the C register
    setCRegister(registers.B);
    setPC(PC + 1);
}

void CPU::process49(Bus &bus)
{
    // load the C register into the C register
    setCRegister(registers.C);
    setPC(PC + 1);
}

void CPU::process4A(Bus &bus)
{
    // load the D register into the C register
    setCRegister(registers.D);
    setPC(PC + 1);
}

void CPU::process4B(Bus &bus)
{
    // load the E register into the C register
    setCRegister(registers.E);
    setPC(PC + 1);
}

void CPU::process4C(Bus &bus)
{
    // load the H register into the C register
    setCRegister(registers.H);
    setPC(PC + 1);
}

void CPU::process4D(Bus &bus)
{
    // load the L register into the C register
    setCRegister(registers.L);
    setPC(PC + 1);
}

void CPU::process4E(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the C register
    setCRegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process4F(Bus &bus)
{
    // load the A register into the C register
    setCRegister(registers.A);
    setPC(PC + 1);
}

void CPU::process50(Bus &bus)
{
    // Stub for opcode 0x50
}

void CPU::process50(Bus &bus)
{
    // Stub for opcode 0x50
}

void CPU::process51(Bus &bus)
{
    // Stub for opcode 0x51
}

void CPU::process52(Bus &bus)
{
    // Stub for opcode 0x52
}

void CPU::process53(Bus &bus)
{
    // Stub for opcode 0x53
}

void CPU::process54(Bus &bus)
{
    // Stub for opcode 0x54
}

void CPU::process55(Bus &bus)
{
    // Stub for opcode 0x55
}

void CPU::process56(Bus &bus)
{
    // Stub for opcode 0x56
}

void CPU::process57(Bus &bus)
{
    // Stub for opcode 0x57
}

void CPU::process58(Bus &bus)
{
    // Stub for opcode 0x58
}

void CPU::process59(Bus &bus)
{
    // Stub for opcode 0x59
}

void CPU::process5A(Bus &bus)
{
    // Stub for opcode 0x5A
}

void CPU::process5B(Bus &bus)
{
    // Stub for opcode 0x5B
}

void CPU::process5C(Bus &bus)
{
    // Stub for opcode 0x5C
}

void CPU::process5D(Bus &bus)
{
    // Stub for opcode 0x5D
}

void CPU::process5E(Bus &bus)
{
    // Stub for opcode 0x5E
}

void CPU::process5F(Bus &bus)
{
    // Stub for opcode 0x5F
}

void CPU::process60(Bus &bus)
{
    // Stub for opcode 0x60
}

void CPU::process61(Bus &bus)
{
    // Stub for opcode 0x61
}

void CPU::process62(Bus &bus)
{
    // Stub for opcode 0x62
}

void CPU::process63(Bus &bus)
{
    // Stub for opcode 0x63
}

void CPU::process64(Bus &bus)
{
    // Stub for opcode 0x64
}

void CPU::process65(Bus &bus)
{
    // Stub for opcode 0x65
}

void CPU::process66(Bus &bus)
{
    // Stub for opcode 0x66
}

void CPU::process67(Bus &bus)
{
    // Stub for opcode 0x67
}

void CPU::process68(Bus &bus)
{
    // Stub for opcode 0x68
}

void CPU::process69(Bus &bus)
{
    // Stub for opcode 0x69
}

void CPU::process6A(Bus &bus)
{
    // Stub for opcode 0x6A
}

void CPU::process6B(Bus &bus)
{
    // Stub for opcode 0x6B
}

void CPU::process6C(Bus &bus)
{
    // Stub for opcode 0x6C
}

void CPU::process6D(Bus &bus)
{
    // Stub for opcode 0x6D
}

void CPU::process6E(Bus &bus)
{
    // Stub for opcode 0x6E
}

void CPU::process6F(Bus &bus)
{
    // Stub for opcode 0x6F
}

void CPU::process70(Bus &bus)
{
    // Stub for opcode 0x70
}

void CPU::process71(Bus &bus)
{
    // Stub for opcode 0x71
}

void CPU::process72(Bus &bus)
{
    // Stub for opcode 0x72
}

void CPU::process73(Bus &bus)
{
    // Stub for opcode 0x73
}

void CPU::process74(Bus &bus)
{
    // Stub for opcode 0x74
}

void CPU::process75(Bus &bus)
{
    // Stub for opcode 0x75
}

void CPU::process76(Bus &bus)
{
    // Stub for opcode 0x76
}

void CPU::process77(Bus &bus)
{
    // Stub for opcode 0x77
}

void CPU::process78(Bus &bus)
{
    // Stub for opcode 0x78
}

void CPU::process79(Bus &bus)
{
    // Stub for opcode 0x79
}

void CPU::process7A(Bus &bus)
{
    // Stub for opcode 0x7A
}

void CPU::process7B(Bus &bus)
{
    // Stub for opcode 0x7B
}

void CPU::process7C(Bus &bus)
{
    // Stub for opcode 0x7C
}

void CPU::process7D(Bus &bus)
{
    // Stub for opcode 0x7D
}

void CPU::process7E(Bus &bus)
{
    // Stub for opcode 0x7E
}

void CPU::process7F(Bus &bus)
{
    // Stub for opcode 0x7F
}

void CPU::process80(Bus &bus)
{
    // Stub for opcode 0x80
}

void CPU::process81(Bus &bus)
{
    // Stub for opcode 0x81
}

void CPU::process82(Bus &bus)
{
    // Stub for opcode 0x82
}

void CPU::process83(Bus &bus)
{
    // Stub for opcode 0x83
}

void CPU::process84(Bus &bus)
{
    // Stub for opcode 0x84
}

void CPU::process85(Bus &bus)
{
    // Stub for opcode 0x85
}

void CPU::process86(Bus &bus)
{
    // Stub for opcode 0x86
}

void CPU::process87(Bus &bus)
{
    // Stub for opcode 0x87
}

void CPU::process88(Bus &bus)
{
    // Stub for opcode 0x88
}

void CPU::process89(Bus &bus)
{
    // Stub for opcode 0x89
}

void CPU::process8A(Bus &bus)
{
    // Stub for opcode 0x8A
}

void CPU::process8B(Bus &bus)
{
    // Stub for opcode 0x8B
}

void CPU::process8C(Bus &bus)
{
    // Stub for opcode 0x8C
}

void CPU::process8D(Bus &bus)
{
    // Stub for opcode 0x8D
}

void CPU::process8E(Bus &bus)
{
    // Stub for opcode 0x8E
}

void CPU::process8F(Bus &bus)
{
    // Stub for opcode 0x8F
}

void CPU::process90(Bus &bus)
{
    // Stub for opcode 0x90
}

void CPU::process91(Bus &bus)
{
    // Stub for opcode 0x91
}

void CPU::process92(Bus &bus)
{
    // Stub for opcode 0x92
}

void CPU::process93(Bus &bus)
{
    // Stub for opcode 0x93
}

void CPU::process94(Bus &bus)
{
    // Stub for opcode 0x94
}

void CPU::process95(Bus &bus)
{
    // Stub for opcode 0x95
}

void CPU::process96(Bus &bus)
{
    // Stub for opcode 0x96
}

void CPU::process97(Bus &bus)
{
    // Stub for opcode 0x97
}

void CPU::process98(Bus &bus)
{
    // Stub for opcode 0x98
}

void CPU::process99(Bus &bus)
{
    // Stub for opcode 0x99
}

void CPU::process9A(Bus &bus)
{
    // Stub for opcode 0x9A
}

void CPU::process9B(Bus &bus)
{
    // Stub for opcode 0x9B
}

void CPU::process9C(Bus &bus)
{
    // Stub for opcode 0x9C
}

void CPU::process9D(Bus &bus)
{
    // Stub for opcode 0x9D
}

void CPU::process9E(Bus &bus)
{
    // Stub for opcode 0x9E
}

void CPU::process9F(Bus &bus)
{
    // Stub for opcode 0x9F
}

void CPU::processA0(Bus &bus)
{
    // Stub for opcode 0xA0
}

void CPU::processA1(Bus &bus)
{
    // Stub for opcode 0xA1
}

void CPU::processA2(Bus &bus)
{
    // Stub for opcode 0xA2
}

void CPU::processA3(Bus &bus)
{
    // Stub for opcode 0xA3
}

void CPU::processA4(Bus &bus)
{
    // Stub for opcode 0xA4
}

void CPU::processA5(Bus &bus)
{
    // Stub for opcode 0xA5
}

void CPU::processA6(Bus &bus)
{
    // Stub for opcode 0xA6
}

void CPU::processA7(Bus &bus)
{
    // Stub for opcode 0xA7
}

void CPU::processA8(Bus &bus)
{
    // Stub for opcode 0xA8
}

void CPU::processA9(Bus &bus)
{
    // Stub for opcode 0xA9
}

void CPU::processAA(Bus &bus)
{
    // Stub for opcode 0xAA
}

void CPU::processAB(Bus &bus)
{
    // Stub for opcode 0xAB
}

void CPU::processAC(Bus &bus)
{
    // Stub for opcode 0xAC
}

void CPU::processAD(Bus &bus)
{
    // Stub for opcode 0xAD
}

void CPU::processAE(Bus &bus)
{
    // Stub for opcode 0xAE
}

void CPU::processAF(Bus &bus)
{
    // Stub for opcode 0xAF
}

void CPU::processB0(Bus &bus)
{
    // Stub for opcode 0xB0
}

void CPU::processB1(Bus &bus)
{
    // Stub for opcode 0xB1
}

void CPU::processB2(Bus &bus)
{
    // Stub for opcode 0xB2
}

void CPU::processB3(Bus &bus)
{
    // Stub for opcode 0xB3
}

void CPU::processB4(Bus &bus)
{
    // Stub for opcode 0xB4
}

void CPU::processB5(Bus &bus)
{
    // Stub for opcode 0xB5
}

void CPU::processB6(Bus &bus)
{
    // Stub for opcode 0xB6
}

void CPU::processB7(Bus &bus)
{
    // Stub for opcode 0xB7
}

void CPU::processB8(Bus &bus)
{
    // Stub for opcode 0xB8
}

void CPU::processB9(Bus &bus)
{
    // Stub for opcode 0xB9
}

void CPU::processBA(Bus &bus)
{
    // Stub for opcode 0xBA
}

void CPU::processBB(Bus &bus)
{
    // Stub for opcode 0xBB
}

void CPU::processBC(Bus &bus)
{
    // Stub for opcode 0xBC
}

void CPU::processBD(Bus &bus)
{
    // Stub for opcode 0xBD
}

void CPU::processBE(Bus &bus)
{
    // Stub for opcode 0xBE
}

void CPU::processBF(Bus &bus)
{
    // Stub for opcode 0xBF
}

void CPU::processC0(Bus &bus)
{
    // Stub for opcode 0xC0
}

void CPU::processC1(Bus &bus)
{
    // Stub for opcode 0xC1
}

void CPU::processC2(Bus &bus)
{
    // Stub for opcode 0xC2
}

void CPU::processC3(Bus &bus)
{
    // Stub for opcode 0xC3
}

void CPU::processC4(Bus &bus)
{
    // Stub for opcode 0xC4
}

void CPU::processC5(Bus &bus)
{
    // Stub for opcode 0xC5
}

void CPU::processC6(Bus &bus)
{
    // Stub for opcode 0xC6
}

void CPU::processC7(Bus &bus)
{
    // Stub for opcode 0xC7
}

void CPU::processC8(Bus &bus)
{
    // Stub for opcode 0xC8
}

void CPU::processC9(Bus &bus)
{
    // Stub for opcode 0xC9
}

void CPU::processCA(Bus &bus)
{
    // Stub for opcode 0xCA
}

void CPU::processCB(Bus &bus)
{
    // Stub for opcode 0xCB
}

void CPU::processCC(Bus &bus)
{
    // Stub for opcode 0xCC
}

void CPU::processCD(Bus &bus)
{
    // Stub for opcode 0xCD
}

void CPU::processCE(Bus &bus)
{
    // Stub for opcode 0xCE
}

void CPU::processCF(Bus &bus)
{
    // Stub for opcode 0xCF
}

void CPU::processD0(Bus &bus)
{
    // Stub for opcode 0xD0
}

void CPU::processD1(Bus &bus)
{
    // Stub for opcode 0xD1
}

void CPU::processD2(Bus &bus)
{
    // Stub for opcode 0xD2
}

void CPU::processD3(Bus &bus)
{
    // Stub for opcode 0xD3
}

void CPU::processD4(Bus &bus)
{
    // Stub for opcode 0xD4
}

void CPU::processD5(Bus &bus)
{
    // Stub for opcode 0xD5
}

void CPU::processD6(Bus &bus)
{
    // Stub for opcode 0xD6
}

void CPU::processD7(Bus &bus)
{
    // Stub for opcode 0xD7
}

void CPU::processD8(Bus &bus)
{
    // Stub for opcode 0xD8
}

void CPU::processD9(Bus &bus)
{
    // Stub for opcode 0xD9
}

void CPU::processDA(Bus &bus)
{
    // Stub for opcode 0xDA
}

void CPU::processDB(Bus &bus)
{
    // Stub for opcode 0xDB
}

void CPU::processDC(Bus &bus)
{
    // Stub for opcode 0xDC
}

void CPU::processDD(Bus &bus)
{
    // Stub for opcode 0xDD
}

void CPU::processDE(Bus &bus)
{
    // Stub for opcode 0xDE
}

void CPU::processDF(Bus &bus)
{
    // Stub for opcode 0xDF
}

void CPU::processE0(Bus &bus)
{
    // Stub for opcode 0xE0
}

void CPU::processE1(Bus &bus)
{
    // Stub for opcode 0xE1
}

void CPU::processE2(Bus &bus)
{
    // Stub for opcode 0xE2
}

void CPU::processE3(Bus &bus)
{
    // Stub for opcode 0xE3
}

void CPU::processE4(Bus &bus)
{
    // Stub for opcode 0xE4
}

void CPU::processE5(Bus &bus)
{
    // Stub for opcode 0xE5
}

void CPU::processE6(Bus &bus)
{
    // Stub for opcode 0xE6
}

void CPU::processE7(Bus &bus)
{
    // Stub for opcode 0xE7
}

void CPU::processE8(Bus &bus)
{
    // Stub for opcode 0xE8
}

void CPU::processE9(Bus &bus)
{
    // Stub for opcode 0xE9
}

void CPU::processEA(Bus &bus)
{
    // Stub for opcode 0xEA
}

void CPU::processEB(Bus &bus)
{
    // Stub for opcode 0xEB
}

void CPU::processEC(Bus &bus)
{
    // Stub for opcode 0xEC
}

void CPU::processED(Bus &bus)
{
    // Stub for opcode 0xED
}

void CPU::processEE(Bus &bus)
{
    // Stub for opcode 0xEE
}

void CPU::processEF(Bus &bus)
{
    // Stub for opcode 0xEF
}

void CPU::processF0(Bus &bus)
{
    // Stub for opcode 0xF0
}

void CPU::processF1(Bus &bus)
{
    // Stub for opcode 0xF1
}

void CPU::processF2(Bus &bus)
{
    // Stub for opcode 0xF2
}

void CPU::processF3(Bus &bus)
{
    // Stub for opcode 0xF3
}

void CPU::processF4(Bus &bus)
{
    // Stub for opcode 0xF4
}

void CPU::processF5(Bus &bus)
{
    // Stub for opcode 0xF5
}

void CPU::processF6(Bus &bus)
{
    // Stub for opcode 0xF6
}

void CPU::processF7(Bus &bus)
{
    // Stub for opcode 0xF7
}

void CPU::processF8(Bus &bus)
{
    // Stub for opcode 0xF8
}

void CPU::processF9(Bus &bus)
{
    // Stub for opcode 0xF9
}

void CPU::processFA(Bus &bus)
{
    // Stub for opcode 0xFA
}

void CPU::processFB(Bus &bus)
{
    // Stub for opcode 0xFB
}

void CPU::processFC(Bus &bus)
{
    // Stub for opcode 0xFC
}

void CPU::processFD(Bus &bus)
{
    // Stub for opcode 0xFD
}

void CPU::processFE(Bus &bus)
{
    // Stub for opcode 0xFE
}

void CPU::processFF(Bus &bus)
{
    // Stub for opcode 0xFF
}