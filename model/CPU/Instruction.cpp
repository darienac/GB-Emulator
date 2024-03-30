
#include <format>
#include "CPU.h"
#include "../../GlobalFlags.h"

// all these come from the opcode table at https://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html

void CPU::processOpCode(uint8_t opCode, Bus &bus)
{
    CPU::opCodeAdditionalCycles = false; // Set back to true if more cycles were needed for the instruction (conditional jumps, etc)
    uint16_t oldPC = getPC();
    switch (opCode)
    {
    case 0x00:
        // NOP
        process00(bus);
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
    if (oldPC == getPC() && !halted) {
        if (GlobalFlags::debug) {
            printf("Likely unimplemented opcode: 0x%02X\n", opCode);
        } else {
            char out[100];
            sprintf(out, "Likely unimplemented opcode: 0x%02X\n", opCode);
            throw runtime_error(out);
        }
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
    // 0x5
    case 0x50:
        return 4;
    case 0x51:
        return 4;
    case 0x52:
        return 4;
    case 0x53:
        return 4;
    case 0x54:
        return 4;
    case 0x55:
        return 4;
    case 0x56:
        return 8;
    case 0x57:
        return 4;
    case 0x58:
        return 4;
    case 0x59:
        return 4;
    case 0x5A:
        return 4;
    case 0x5B:
        return 4;
    case 0x5C:
        return 4;
    case 0x5D:
        return 4;
    case 0x5E:
        return 8;
    case 0x5F:
        return 4;
    // 0x6
    case 0x60:
        return 4;
    case 0x61:
        return 4;
    case 0x62:
        return 4;
    case 0x63:
        return 4;
    case 0x64:
        return 4;
    case 0x65:
        return 4;
    case 0x66:
        return 8;
    case 0x67:
        return 4;
    case 0x68:
        return 4;
    case 0x69:
        return 4;
    case 0x6A:
        return 4;
    case 0x6B:
        return 4;
    case 0x6C:
        return 4;
    case 0x6D:
        return 4;
    case 0x6E:
        return 8;
    case 0x6F:
        return 4;
    // 0x7
    case 0x70:
        return 8;
    case 0x71:
        return 8;
    case 0x72:
        return 8;
    case 0x73:
        return 8;
    case 0x74:
        return 8;
    case 0x75:
        return 8;
    case 0x76:
        return 4;
    case 0x77:
        return 8;
    case 0x78:
        return 4;
    case 0x79:
        return 4;
    case 0x7A:
        return 4;
    case 0x7B:
        return 4;
    case 0x7C:
        return 4;
    case 0x7D:
        return 4;
    case 0x7E:
        return 8;
    case 0x7F:
        return 4;
    // 0x8
    case 0x80:
        return 4;
    case 0x81:
        return 4;
    case 0x82:
        return 4;
    case 0x83:
        return 4;
    case 0x84:
        return 4;
    case 0x85:
        return 4;
    case 0x86:
        return 8;
    case 0x87:
        return 4;
    case 0x88:
        return 4;
    case 0x89:
        return 4;
    case 0x8A:
        return 4;
    case 0x8B:
        return 4;
    case 0x8C:
        return 4;
    case 0x8D:
        return 4;
    case 0x8E:
        return 8;
    case 0x8F:
        return 4;
    // 0x9
    case 0x90:
        return 4;
    case 0x91:
        return 4;
    case 0x92:
        return 4;
    case 0x93:
        return 4;
    case 0x94:
        return 4;
    case 0x95:
        return 4;
    case 0x96:
        return 8;
    case 0x97:
        return 4;
    case 0x98:
        return 4;
    case 0x99:
        return 4;
    case 0x9A:
        return 4;
    case 0x9B:
        return 4;
    case 0x9C:
        return 4;
    case 0x9D:
        return 4;
    case 0x9E:
        return 8;
    case 0x9F:
        return 4;
    // 0xA
    case 0xA0:
        return 4;
    case 0xA1:
        return 4;
    case 0xA2:
        return 4;
    case 0xA3:
        return 4;
    case 0xA4:
        return 4;
    case 0xA5:
        return 4;
    case 0xA6:
        return 8;
    case 0xA7:
        return 4;
    case 0xA8:
        return 4;
    case 0xA9:
        return 4;
    case 0xAA:
        return 4;
    case 0xAB:
        return 4;
    case 0xAC:
        return 4;
    case 0xAD:
        return 4;
    case 0xAE:
        return 8;
    case 0xAF:
        return 4;
    // 0xB
    case 0xB0:
        return 4;
    case 0xB1:
        return 4;
    case 0xB2:
        return 4;
    case 0xB3:
        return 4;
    case 0xB4:
        return 4;
    case 0xB5:
        return 4;
    case 0xB6:
        return 8;
    case 0xB7:
        return 4;
    case 0xB8:
        return 4;
    case 0xB9:
        return 4;
    case 0xBA:
        return 4;
    case 0xBB:
        return 4;
    case 0xBC:
        return 4;
    case 0xBD:
        return 4;
    case 0xBE:
        return 8;
    case 0xBF:
        return 4;
    // 0xC
    case 0xC0:
        if (opCodeAdditionalCycles) {
            return 20;
        }
        return 8;
    case 0xC1:
        return 12;
    case 0xC2:
        if (opCodeAdditionalCycles) {
            return 16;
        }
        return 12;
    case 0xC3:
        return 16;
    case 0xC4:
        if (opCodeAdditionalCycles) {
            return 24;
        }
        return 12;
    case 0xC5:
        return 16;
    case 0xC6:
        return 8;
    case 0xC7:
        return 16;
    case 0xC8:
        if (opCodeAdditionalCycles) {
            return 20;
        }
        return 8;
    case 0xC9:
        return 16;
    case 0xCA:
        if (opCodeAdditionalCycles) {
            return 16;
        }
        return 12;
    case 0xCB:
        if ((opcode & 0xF) == 0x6 || (opcode & 0xF) == 0xE) {
            return 20;
        }
        return 12;
    case 0xCC:
        if (opCodeAdditionalCycles) {
            return 24;
        }
        return 12;
    case 0xCD:
        return 24;
    case 0xCE:
        return 8;
    case 0xCF:
        return 16;
    // 0xD
    case 0xD0:
        if (opCodeAdditionalCycles) {
            return 20;
        }
        return 8;
    case 0xD1:
        return 12;
    case 0xD2:
        if (opCodeAdditionalCycles) {
            return 16;
        }
        return 12;
    case 0xD3:
        break; // Undefined
    case 0xD4:
        if (opCodeAdditionalCycles) {
            return 24;
        }
        return 12;
    case 0xD5:
        return 16;
    case 0xD6:
        return 8;
    case 0xD7:
        return 16;
    case 0xD8:
        if (opCodeAdditionalCycles) {
            return 20;
        }
        return 8;
    case 0xD9:
        return 16;
    case 0xDA:
        if (opCodeAdditionalCycles) {
            return 16;
        }
        return 12;
    case 0xDB:
        break; // Undefined
    case 0xDC:
        if (opCodeAdditionalCycles) {
            return 24;
        }
        return 12;
    case 0xDD:
        break; // Undefined
    case 0xDE:
        return 8;
    case 0xDF:
        return 16;
    // 0xE
    case 0xE0:
        return 12;
    case 0xE1:
        return 12;
    case 0xE2:
        return 8;
    case 0xE3:
        break; // Undefined
    case 0xE4:
        break; // Undefined
    case 0xE5:
        return 16;
    case 0xE6:
        return 8;
    case 0xE7:
        return 16;
    case 0xE8:
        return 16;
    case 0xE9:
        return 4;
    case 0xEA:
        return 16;
    case 0xEB:
        break; // Undefined
    case 0xEC:
        break; // Undefined
    case 0xED:
        break; // Undefined
    case 0xEE:
        return 8;
    case 0xEF:
        return 16;
    // 0xF
    case 0xF0:
        return 12;
    case 0xF1:
        return 12;
    case 0xF2:
        return 8;
    case 0xF3:
        return 4;
    case 0xF4:
        break; // Undefined
    case 0xF5:
        return 16;
    case 0xF6:
        return 8;
    case 0xF7:
        return 16;
    case 0xF8:
        return 12;
    case 0xF9:
        return 8;
    case 0xFA:
        return 16;
    case 0xFB:
        return 4;
    case 0xFC:
        break; // Undefined
    case 0xFD:
        break; // Undefined
    case 0xFE:
        return 8;
    case 0xFF:
        return 16;
    }

    if (GlobalFlags::debug) {
        printf("Unknown opcode: 0x%02X\n", opcode);
    } else {
        char out[100];
        sprintf(out, "Unknown opcode: 0x%02X\n", opcode);
        throw runtime_error(out);
    }

    return 0;
}

void CPU::process00(Bus &bus) {
    setPC(PC + 1);
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
    bus.write(getBCRegister(), registers.A);

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

void CPU::process07(Bus &bus)
{
    uint8_t msb = (getARegister() & 0x80) >> 7;
    // shift the A register left by one bit
    setARegister((getARegister() << 1) | msb);

    setZeroFlag(getARegister() == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(msb);

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

void CPU::process0F(Bus &bus)
{
    // set the carry flag if the rightmost bit was set
    uint8_t lsb = getARegister() & 0x01;
    // shift the A register right by one bit
    setARegister((getARegister() >> 1) | (lsb << 7));
    // clear the subtract and half-carry flags
    setZeroFlag(getARegister() == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(lsb);

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

void CPU::process17(Bus &bus)
{
    uint8_t msb = (getARegister() | 0x80) >> 7;
    // shift the A register left by one bit and set the carry flag to the value of the leftmost bit
    setARegister((getARegister() << 1) | getCarryFlag());

    setZeroFlag(getARegister() == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(msb);

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

void CPU::process1F(Bus &bus)
{
    // shift the A register right by one bit and set the carry flag to the value of the rightmost bit
    uint8_t lsb = getARegister() & 1;
    setARegister((getARegister() >> 1) | (getCarryFlag() << 7));

    setZeroFlag(getARegister() == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(lsb);

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
    // load the B register into the D register
    setDRegister(registers.B);
    setPC(PC + 1);
}

void CPU::process51(Bus &bus)
{
    // load the C register into the D register
    setDRegister(registers.C);
    setPC(PC + 1);
}

void CPU::process52(Bus &bus)
{
    // load the D register into the D register
    setDRegister(registers.D);
    setPC(PC + 1);
}

void CPU::process53(Bus &bus)
{
    // load the E register into the D register
    setDRegister(registers.E);
    setPC(PC + 1);
}

void CPU::process54(Bus &bus)
{
    // load the H register into the D register
    setDRegister(registers.H);
    setPC(PC + 1);
}

void CPU::process55(Bus &bus)
{
    // load the L register into the D register
    setDRegister(registers.L);
    setPC(PC + 1);
}

void CPU::process56(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the D register
    setDRegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process57(Bus &bus)
{
    // load the A register into the D register
    setDRegister(registers.A);
    setPC(PC + 1);
}

void CPU::process58(Bus &bus)
{
    // load the B register into the E register
    setERegister(registers.B);
    setPC(PC + 1);
}

void CPU::process59(Bus &bus)
{
    // load the C register into the E register
    setERegister(registers.C);
    setPC(PC + 1);
}

void CPU::process5A(Bus &bus)
{
    // load the D register into the E register
    setERegister(registers.D);
    setPC(PC + 1);
}

void CPU::process5B(Bus &bus)
{
    // load the E register into the E register
    setERegister(registers.E);
    setPC(PC + 1);
}

void CPU::process5C(Bus &bus)
{
    // load the H register into the E register
    setERegister(registers.H);
    setPC(PC + 1);
}

void CPU::process5D(Bus &bus)
{
    // load the L register into the E register
    setERegister(registers.L);
    setPC(PC + 1);
}

void CPU::process5E(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the E register
    setERegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process5F(Bus &bus)
{
    // load the A register into the E register
    setBRegister(registers.A);
    setPC(PC + 1);
}

void CPU::process60(Bus &bus)
{
    // load the B register into the H register
    setHRegister(registers.B);
    setPC(PC + 1);
}

void CPU::process61(Bus &bus)
{
    // load the C register into the H register
    setHRegister(registers.C);
    setPC(PC + 1);
}

void CPU::process62(Bus &bus)
{
    // load the D register into the H register
    setHRegister(registers.D);
    setPC(PC + 1);
}

void CPU::process63(Bus &bus)
{
    // load the E register into the H register
    setHRegister(registers.E);
    setPC(PC + 1);
}

void CPU::process64(Bus &bus)
{
    // load the H register into the H register
    setHRegister(registers.H);
    setPC(PC + 1);
}

void CPU::process65(Bus &bus)
{
    // load the L register into the H register
    setHRegister(registers.L);
    setPC(PC + 1);
}

void CPU::process66(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the H register
    setHRegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process67(Bus &bus)
{
    // load the A register into the H register
    setHRegister(registers.A);
    setPC(PC + 1);
}

void CPU::process68(Bus &bus)
{
    // load the B register into the L register
    setLRegister(registers.B);
    setPC(PC + 1);
}

void CPU::process69(Bus &bus)
{
    // load the C register into the L register
    setLRegister(registers.C);
    setPC(PC + 1);
}

void CPU::process6A(Bus &bus)
{
    // load the D register into the L register
    setLRegister(registers.D);
    setPC(PC + 1);
}

void CPU::process6B(Bus &bus)
{
    // load the E register into the L register
    setLRegister(registers.E);
    setPC(PC + 1);
}

void CPU::process6C(Bus &bus)
{
    // load the H register into the L register
    setLRegister(registers.H);
    setPC(PC + 1);
}

void CPU::process6D(Bus &bus)
{
    // load the L register into the L register
    setLRegister(registers.L);
    setPC(PC + 1);
}

void CPU::process6E(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the L register
    setLRegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process6F(Bus &bus)
{
    // load the A register into the L register
    setLRegister(registers.A);
    setPC(PC + 1);
}

void CPU::process70(Bus &bus)
{
    // get the location in memory from the HL register pair and load the B register into it
    bus.write(registers.HL, registers.B);
    setPC(PC + 1);
}

void CPU::process71(Bus &bus)
{
    // get the location in memory from the HL register pair and load the C register into it
    bus.write(registers.HL, registers.C);
    setPC(PC + 1);
}

void CPU::process72(Bus &bus)
{
    // get the location in memory from the HL register pair and load the D register into it
    bus.write(registers.HL, registers.D);
    setPC(PC + 1);
}

void CPU::process73(Bus &bus)
{
    // get the location in memory from the HL register pair and load the E register into it
    bus.write(registers.HL, registers.E);
    setPC(PC + 1);
}

void CPU::process74(Bus &bus)
{
    // get the location in memory from the HL register pair and load the H register into it
    bus.write(registers.HL, registers.H);
    setPC(PC + 1);
}

void CPU::process75(Bus &bus)
{
    // get the location in memory from the HL register pair and load the L register into it
    bus.write(registers.HL, registers.L);
    setPC(PC + 1);
}

void CPU::process76(Bus &bus)
{
    setHalted(true);
}

void CPU::process77(Bus &bus)
{
    // get the location in memory from the HL register pair and load the A register into it
    bus.write(registers.HL, registers.A);
    setPC(PC + 1);
}

void CPU::process78(Bus &bus)
{
    // load the B register into the A register
    setARegister(registers.B);
    setPC(PC + 1);
}

void CPU::process79(Bus &bus)
{
    // load the C register into the A register
    setARegister(registers.C);
    setPC(PC + 1);
}

void CPU::process7A(Bus &bus)
{
    // load the D register into the A register
    setARegister(registers.D);
    setPC(PC + 1);
}

void CPU::process7B(Bus &bus)
{
    // load the E register into the A register
    setARegister(registers.E);
    setPC(PC + 1);
}

void CPU::process7C(Bus &bus)
{
    // load the H register into the A register
    setARegister(registers.H);
    setPC(PC + 1);
}

void CPU::process7D(Bus &bus)
{
    // load the L register into the A register
    setARegister(registers.L);
    setPC(PC + 1);
}

void CPU::process7E(Bus &bus)
{
    // load the value at the memory address specified by the HL register pair into the A register
    setARegister(bus.read(registers.HL));
    setPC(PC + 1);
}

void CPU::process7F(Bus &bus)
{
    // load the A register into the A register
    setARegister(registers.A);
    setPC(PC + 1);
}

void CPU::process80(Bus &bus)
{
    // add the value of the B register to the A register
    uint16_t result = registers.A + registers.B;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process81(Bus &bus)
{
    // add the value of the C register to the A register
    uint16_t result = registers.A + registers.C;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process82(Bus &bus)
{
    // add the value of the D register to the A register
    uint16_t result = registers.A + registers.D;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process83(Bus &bus)
{
    // add the value of the E register to the A register
    uint16_t result = registers.A + registers.E;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process84(Bus &bus)
{
    // add the value of the H register to the A register
    uint16_t result = registers.A + registers.H;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process85(Bus &bus)
{
    // add the value of the L register to the A register
    uint16_t result = registers.A + registers.L;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process86(Bus &bus)
{
    // add the value at the address of HL to the A register
    uint16_t result = registers.A + registers.HL;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process87(Bus &bus)
{
    // add the value of the A register to the A register
    uint16_t result = registers.A + registers.A;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process88(Bus &bus)
{
    // add the value of the B register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.B + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process89(Bus &bus)
{
    // add the value of the C register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.C + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process8A(Bus &bus)
{
    // add the value of the D register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.D + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process8B(Bus &bus)
{
    // add the value of the E register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.E + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process8C(Bus &bus)
{
    // add the value of the H register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.H + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process8D(Bus &bus)
{
    // add the value of the L register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.L + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process8E(Bus &bus)
{
    // add the value from the address of HL and the Carry Flag to the A register
    uint16_t result = registers.A + registers.HL + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

void CPU::process8F(Bus &bus)
{
    // add the value of the A register and the Carry Flag to the A register
    uint16_t result = registers.A + registers.A + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 1);
}

// Opcodes 0x90 - 0x9F
void CPU::process90(Bus &bus)
{
    // Subtract the value in Register B from that in Register A
    uint16_t result = registers.A - registers.B;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.B);

    setPC(PC + 1);
}

void CPU::process91(Bus &bus)
{
    // Subtract the value in Register C from that in Register A
    uint16_t result = registers.A - registers.C;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.C);

    setPC(PC + 1);
}

void CPU::process92(Bus &bus)
{
    // Subtract the value in Register D from that in Register A
    uint16_t result = registers.A - registers.D;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.D);

    setPC(PC + 1);
}

void CPU::process93(Bus &bus)
{
    // Subtract the value in Register E from that in Register A
    uint16_t result = registers.A - registers.E;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.E);

    setPC(PC + 1);
}

void CPU::process94(Bus &bus)
{
    // Subtract the value in Register H from that in Register A
    uint16_t result = registers.A - registers.H;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.H);

    setPC(PC + 1);
}

void CPU::process95(Bus &bus)
{
    // Subtract the value in Register L from that in Register A
    uint16_t result = registers.A - registers.L;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.L);

    setPC(PC + 1);
}

void CPU::process96(Bus &bus)
{
    // Subtract the value pointed to by the address in HL from that in Register A
    uint16_t result = registers.A - bus.read(registers.HL);
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < bus.read(registers.HL));

    setPC(PC + 1);
}

void CPU::process97(Bus &bus)
{
    // Subtract the value in Register A from that in Register A
    uint16_t result = registers.A - registers.A;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.A);

    setPC(PC + 1);
}

void CPU::process98(Bus &bus)
{
    // Subtract the value in Register B and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.B + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.B + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process99(Bus &bus)
{
    // Subtract the value in Register C and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.C + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.C + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process9A(Bus &bus)
{
    // Subtract the value in Register D and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.D + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.D + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process9B(Bus &bus)
{
    // Subtract the value in Register E and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.E + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.E + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process9C(Bus &bus)
{
    // Subtract the value in Register H and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.H + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.H + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process9D(Bus &bus)
{
    // Subtract the value in Register L and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.L + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.L + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process9E(Bus &bus)
{
    // Subtract the value pointed to the address in HL and the Carry Flag from that in Register A
    uint16_t result = registers.A - (bus.read(registers.HL) + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (bus.read(registers.HL) + getCarryFlag()));

    setPC(PC + 1);
}

void CPU::process9F(Bus &bus)
{
    // Subtract the value in Register A and the Carry Flag from that in Register A
    uint16_t result = registers.A - (registers.A + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (registers.A + getCarryFlag()));

    setPC(PC + 1);
}

// Opcodes 0xA0 - 0xAF
void CPU::processA0(Bus &bus)
{
    // AND of Register A and Register B
    uint16_t result = registers.A & registers.B;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA1(Bus &bus)
{
    // AND of Register A and Register C
    uint16_t result = registers.A & registers.C;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA2(Bus &bus)
{
    // AND of Register A and Register D
    uint16_t result = registers.A & registers.D;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA3(Bus &bus)
{
    // AND of Register A and Register E
    uint16_t result = registers.A & registers.E;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA4(Bus &bus)
{
    // AND of Register A and Register H
    uint16_t result = registers.A & registers.H;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA5(Bus &bus)
{
    // AND of Register A and Register L
    uint16_t result = registers.A & registers.L;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA6(Bus &bus)
{
    // AND of Register A and the value pointed to by the address in HL
    uint16_t result = registers.A & bus.read(registers.HL);
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA7(Bus &bus)
{
    // AND of Register A and Register A
    uint16_t result = registers.A & registers.A;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(true);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA8(Bus &bus)
{
    // XOR of Register A and Register B
    uint16_t result = registers.A ^ registers.B;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processA9(Bus &bus)
{
    // XOR of Register A and Register C
    uint16_t result = registers.A ^ registers.C;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processAA(Bus &bus)
{
    // XOR of Register A and Register D
    uint16_t result = registers.A ^ registers.D;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processAB(Bus &bus)
{
    // XOR of Register A and Register E
    uint16_t result = registers.A ^ registers.E;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processAC(Bus &bus)
{
    // XOR of Register A and Register H
    uint16_t result = registers.A ^ registers.H;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processAD(Bus &bus)
{
    // XOR of Register A and Register L
    uint16_t result = registers.A ^ registers.L;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processAE(Bus &bus)
{
    // XOR of Register A and the value pointed to by the address in HL
    uint16_t result = registers.A ^ bus.read(registers.HL);
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processAF(Bus &bus)
{
    // XOR of Register A and Register A
    uint16_t result = registers.A ^ registers.A;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

// Opcodes 0xB0 - 0xBF
void CPU::processB0(Bus &bus)
{
    // OR of Register A and Register B
    uint16_t result = registers.A | registers.B;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB1(Bus &bus)
{
    // OR of Register A and Register C
    uint16_t result = registers.A | registers.C;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB2(Bus &bus)
{
    // OR of Register A and Register D
    uint16_t result = registers.A | registers.D;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB3(Bus &bus)
{
    // OR of Register A and Register E
    uint16_t result = registers.A | registers.E;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB4(Bus &bus)
{
    // OR of Register A and Register H
    uint16_t result = registers.A | registers.H;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB5(Bus &bus)
{
    // OR of Register A and Register L
    uint16_t result = registers.A | registers.L;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB6(Bus &bus)
{
    // OR of Register A and the value pointed to by the address in HL
    uint16_t result = registers.A | bus.read(registers.HL);
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB7(Bus &bus)
{
    // OR of Register A and Register A
    uint16_t result = registers.A | registers.A;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // clear the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag(false);
    // clear the carry flag
    setCarryFlag(false);

    setPC(PC + 1);
}

void CPU::processB8(Bus &bus)
{
    // Subtract the value in Register B from that in Register A
    uint16_t result = registers.A - registers.B;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.B);

    setPC(PC + 1);
}

void CPU::processB9(Bus &bus)
{
    // Subtract the value in Register C from that in Register A
    uint16_t result = registers.A - registers.C;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.C);

    setPC(PC + 1);
}

void CPU::processBA(Bus &bus)
{
    // Subtract the value in Register D from that in Register A
    uint16_t result = registers.A - registers.D;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.D);

    setPC(PC + 1);
}

void CPU::processBB(Bus &bus)
{
    // Subtract the value in Register E from that in Register A
    uint16_t result = registers.A - registers.E;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.E);

    setPC(PC + 1);
}

void CPU::processBC(Bus &bus)
{
// Subtract the value in Register H from that in Register A
uint16_t result = registers.A - registers.H;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.H);

    setPC(PC + 1);
}

void CPU::processBD(Bus &bus)
{
    // Subtract the value in Register L from that in Register A
    uint16_t result = registers.A - registers.L;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.L);

    setPC(PC + 1);
}

void CPU::processBE(Bus &bus)
{
    // Subtract the value pointed to by the address in HL from that in Register A
    uint16_t result = registers.A - bus.read(registers.HL);

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < bus.read(registers.HL));

    setPC(PC + 1);
}

void CPU::processBF(Bus &bus)
{
    // Subtract the value in Register A from that in Register A
    uint16_t result = registers.A - registers.A;

    // set the zero flag if the result is zero
    setZeroFlag(result == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < registers.A);

    setPC(PC + 1);
}

// Opcodes 0xC0 - 0xCF
void CPU::processC0(Bus &bus)
{
    /* Implement internal branch decision */

    // If the Zero Flag is NOT set
    setPC(PC + 1);
    if (!getZeroFlag()) {
        // Return from subroutine
        opCodeAdditionalCycles = true;
        setPC(stackPop(bus));
    }
}

void CPU::processC1(Bus &bus)
{
    setBCRegister(stackPop(bus));
    setPC(PC + 1);
}

void CPU::processC2(Bus &bus)
{
    // If Zero Flag is NOT set
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    if (!getZeroFlag()) {
        // fetch the 16-bit immediate value (little-endian)
        opCodeAdditionalCycles = true;
        setPC(address);
    }
}

void CPU::processC3(Bus &bus)
{
    uint16_t immediateValue = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(immediateValue);
}

void CPU::processC4(Bus &bus)
{
    // If Zero Flag is NOT set
    setPC(PC + 3);
    if (!getZeroFlag()) {
        opCodeAdditionalCycles = true;
        // fetch the 16-bit immediate value (little-endian)
        uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
        // Push address onto the stack
        stackPush(bus, PC);
        setPC(address);
    }
}

void CPU::processC5(Bus &bus)
{
    // Push onto the stack from register location BC
    stackPush(bus, registers.BC);
    setPC(PC + 1);
}

void CPU::processC6(Bus &bus)
{
    // fetch the u8 value from the bus
    uint8_t value = bus.read(PC + 1);
    // add the value to register A
    uint16_t result = registers.A + value;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 2);
}

void CPU::processC7(Bus &bus)
{
    // Set PC to 0x00
    stackPush(bus, PC + 1); // I think it's PC + 1 since the current instruction is only 1 byte
    setPC(0x00);
}

void CPU::processC8(Bus &bus)
{
    /* Implement internal branch decision */

    // If the Zero Flag is set
    setPC(PC + 1);
    if (getZeroFlag()) {
        // Return from subroutine
        opCodeAdditionalCycles = true;
        setPC(stackPop(bus));
    }
}

void CPU::processC9(Bus &bus)
{
    // Return from subroutine, a.k.a. Stack Pop
    setPC(stackPop(bus));
}

void CPU::processCA(Bus &bus)
{
    // If Zero Flag is set
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    if (getZeroFlag()) {
        // fetch the 16-bit immediate value (little-endian)
        opCodeAdditionalCycles = true;
        setPC(address);
    }
}

// CB instruction implemented in PrefixCB.cpp

void CPU::processCC(Bus &bus)
{
    // If Zero Flag is set
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    if (getZeroFlag()) {
        opCodeAdditionalCycles = true;
        // fetch the 16-bit immediate value (little-endian)
        // Push address onto the stack
        stackPush(bus, PC);
        setPC(address);
    }
}

void CPU::processCD(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    // Push address onto the stack
    stackPush(bus, PC);
    setPC(address);
}

void CPU::processCE(Bus &bus)
{
    // fetch the u8 value from the bus
    uint8_t value = bus.read(PC + 1);
    // add the value and the carry flag to register A
    uint16_t result = registers.A + value + getCarryFlag();
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(false);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 2);
}

void CPU::processCF(Bus &bus)
{
    // Set PC to 0x08
    stackPush(bus, PC + 1);
    setPC(0x08);
}

void CPU::processD0(Bus &bus)
{
    /* Implement internal branch decision */

    // If the Carry Flag is NOT set
    setPC(PC + 1);
    if (!getCarryFlag()) {
        // Return from subroutine
        opCodeAdditionalCycles = true;
        setPC(stackPop(bus));
    }
}

void CPU::processD1(Bus &bus)
{
    setDERegister(stackPop(bus));
    setPC(PC + 1);
}

void CPU::processD2(Bus &bus)
{
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    // If Carry Flag is NOT set
    if (!getCarryFlag()) {
        // fetch the 16-bit immediate value (little-endian)
        opCodeAdditionalCycles = true;
        setPC(address);
    }
}

void CPU::processD3(Bus &bus)
{
    return;
}

void CPU::processD4(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    // If Carry Flag is NOT set
    if (!getCarryFlag()) {
        opCodeAdditionalCycles = true;
        // Push address onto the stack
        stackPush(bus, PC);
        setPC(address);
    }
}

void CPU::processD5(Bus &bus)
{
    // Push onto the stack from register location DE
    stackPush(bus, registers.DE);
    setPC(PC + 1);
}

void CPU::processD6(Bus &bus)
{
    // fetch the u8 value from the bus
    uint8_t value = bus.read(PC + 1);
    // subtract the value to register A
    uint16_t result = registers.A - value;
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // clear the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // complement the carry flag
    setCarryFlag(result > 0xFFFF);

    setPC(PC + 2);
}

void CPU::processD7(Bus &bus)
{
    // Set PC to 0x10
    stackPush(bus, PC + 1);
    setPC(0x10);
}

void CPU::processD8(Bus &bus)
{
    /* Implement internal branch decision */

    setPC(PC + 1);
    // If the Carry Flag is set
    if (getCarryFlag()) {
        // Return from subroutine
        opCodeAdditionalCycles = true;
        setPC(stackPop(bus));
    }
}

void CPU::processD9(Bus &bus)
{
    // Enable Interrupts
    setImeFlag(true);
    // Return from subroutine
    setPC(stackPop(bus));
}

void CPU::processDA(Bus &bus)
{
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    // If Carry Flag is set
    if (getCarryFlag()) {
        // fetch the 16-bit immediate value (little-endian)
        opCodeAdditionalCycles = true;
        setPC(address);
    }
}

void CPU::processDB(Bus &bus)
{
    return;
}

void CPU::processDC(Bus &bus)
{
    // fetch the 16-bit immediate value (little-endian)
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    setPC(PC + 3);
    // If Carry Flag is set
    if (getCarryFlag()) {
        opCodeAdditionalCycles = true;
        // Push address onto the stack
        stackPush(bus, PC);
        setPC(address);
    }
}

void CPU::processDD(Bus &bus)
{
    return;
}

void CPU::processDE(Bus &bus)
{
    // fetch the u8 value from the bus
    uint8_t value = bus.read(PC + 1);
    // Subtract the value  and the Carry Flag from that in Register A
    uint16_t result = registers.A - (value + getCarryFlag());
    // load the result into the A register pair
    setARegister(result);
    // set the zero flag if the result is zero
    setZeroFlag(registers.A == 0);
    // set the subtract flag
    setSubtractFlag(true);
    // set the half-carry flag if the lower nibble overflowed
    setHalfCarryFlag((registers.A & 0x0F) == 0);
    // set the carry flag
    setCarryFlag(registers.A < (bus.read(registers.HL) + getCarryFlag()));

    setPC(PC + 2);
}

void CPU::processDF(Bus &bus)
{
    // Set PC to 0x18
    stackPush(bus, PC + 1);
    setPC(0x18);
}

void CPU::processE0(Bus &bus)
{
    uint8_t addr = bus.read(PC + 1);
    bus.write(0xFF00 + addr, registers.A);
    setPC(PC + 2);
}

void CPU::processE1(Bus &bus)
{
    setHLRegister(stackPop(bus));
    setPC(PC + 1);
}

void CPU::processE2(Bus &bus)
{
    bus.write(0xFF00 + registers.C, registers.A);
    setPC(PC + 2);
}

void CPU::processE3(Bus &bus)
{
    printf("Opcode 0xE3 not implemented\n");
}

void CPU::processE4(Bus &bus)
{
    printf("Opcode 0xE4 not implemented\n");
}

void CPU::processE5(Bus &bus)
{
    stackPush(bus, registers.HL);
    setPC(PC + 1);
}

void CPU::processE6(Bus &bus)
{
    uint8_t value = bus.read(PC + 1);
    registers.A &= value;
    setZeroFlag(registers.A == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(true);
    setCarryFlag(false);
    setPC(PC + 2);
}

void CPU::processE7(Bus &bus)
{
    stackPush(bus, PC + 1);
    setPC(0x20);
}

void CPU::processE8(Bus &bus)
{
    int8_t offset = static_cast<int8_t>(bus.read(PC + 1));
    int result = SP + offset;
    setZeroFlag(false);
    setSubtractFlag(false);
    setHalfCarryFlag(((SP & 0xF) + (offset & 0xF)) > 0xF);
    setCarryFlag(((SP & 0xFF) + (offset & 0xFF)) > 0xFF);
    setSP(static_cast<uint16_t>(result));
    setPC(PC + 2);
}

void CPU::processE9(Bus &bus)
{
    setPC(registers.HL);
}

void CPU::processEA(Bus &bus)
{
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    bus.write(address, registers.A);
    setPC(PC + 3);
}

void CPU::processEB(Bus &bus)
{
    printf("Opcode 0xEB not implemented\n");
}

void CPU::processEC(Bus &bus)
{
    printf("Opcode 0xEC not implemented\n");
}

void CPU::processED(Bus &bus)
{
    printf("Opcode 0xED not implemented\n");
}

void CPU::processEE(Bus &bus)
{
    uint8_t value = bus.read(PC + 1);
    registers.A ^= value;
    setZeroFlag(registers.A == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(false);
    setPC(PC + 2);
}

void CPU::processEF(Bus &bus)
{
    stackPush(bus, PC + 1);
    setPC(0x28);
}

void CPU::processF0(Bus &bus)
{
    uint8_t addr = bus.read(PC + 1);
    registers.A = bus.read(0xFF00 + addr);
    setPC(PC + 2);
}

// TODO: resolve this
void CPU::processF1(Bus &bus)
{
    uint16_t value = stackPop(bus);
    setAFRegister(value);
    setPC(PC + 1);
}

void CPU::processF2(Bus &bus)
{
    registers.A = bus.read(0xFF00 + registers.C);
    setPC(PC + 1); // Documentation inconsistency, Listed as 1 byte in GB complete technical reference, 2 bytes in gb opcodes table
}

void CPU::processF3(Bus &bus)
{
    setImeFlag(false);
    setPC(PC + 1);
}

void CPU::processF4(Bus &bus)
{
    printf("Opcode 0xF4 not implemented\n");
}

void CPU::processF5(Bus &bus)
{
    stackPush(bus, registers.AF);
    setPC(PC + 1);
}

void CPU::processF6(Bus &bus)
{
    uint8_t value = bus.read(PC + 1);
    registers.A |= value;
    setZeroFlag(registers.A == 0);
    setSubtractFlag(false);
    setHalfCarryFlag(false);
    setCarryFlag(false);
    setPC(PC + 2);
}

void CPU::processF7(Bus &bus)
{
    stackPush(bus, PC + 1);
    setPC(0x30);
}

void CPU::processF8(Bus &bus)
{
    int8_t offset = static_cast<int8_t>(bus.read(PC + 1));
    int result = SP + offset;
    setHLRegister(static_cast<uint16_t>(result));
    setZeroFlag(false);
    setSubtractFlag(false);
    setHalfCarryFlag(((SP & 0xF) + (offset & 0xF)) > 0xF);
    setCarryFlag(((SP & 0xFF) + (offset & 0xFF)) > 0xFF);
    setPC(PC + 2);
}

void CPU::processF9(Bus &bus)
{
    setSP(registers.HL);
    setPC(PC + 1);
}

void CPU::processFA(Bus &bus)
{
    uint16_t address = (bus.read(PC + 2) << 8) | bus.read(PC + 1);
    registers.A = bus.read(address);
    setPC(PC + 3);
}

void CPU::processFB(Bus &bus)
{
    setImeFlag(true);
    setPC(PC + 1);
}

void CPU::processFC(Bus &bus)
{
    printf("Opcode 0xFC not implemented\n");
}

void CPU::processFD(Bus &bus)
{
    printf("Opcode 0xFD not implemented\n");
}

void CPU::processFE(Bus &bus)
{
    uint8_t value = bus.read(PC + 1);
    auto result = getARegister() - value;
    setZeroFlag(result == 0);
    setSubtractFlag(true);
    setHalfCarryFlag((getARegister() & 0xF) < (value & 0xF));
    setCarryFlag(getARegister() < value);
    setPC(PC + 2);
}

void CPU::processFF(Bus &bus)
{
    stackPush(bus, PC + 1);
    setPC(0x38);
}
