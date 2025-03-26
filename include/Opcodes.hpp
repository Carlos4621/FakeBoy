#pragma once
#ifndef OPCODES_HPP
#define OPCODES_HPP

static constexpr uint8_t NOP_Opcode = 0x00;

static constexpr uint8_t LD_B_B_Opcode{ 0x40 };
static constexpr uint8_t LD_B_C_Opcode{ 0x41 };
static constexpr uint8_t LD_B_D_Opcode{ 0x42 };
static constexpr uint8_t LD_B_E_Opcode{ 0x43 };
static constexpr uint8_t LD_B_H_Opcode{ 0x44 };
static constexpr uint8_t LD_B_L_Opcode{ 0x45 };
static constexpr uint8_t LD_B_A_Opcode{ 0x47 };

static constexpr uint8_t LD_C_B_Opcode{ 0x48 };
static constexpr uint8_t LD_C_C_Opcode{ 0x49 };
static constexpr uint8_t LD_C_D_Opcode{ 0x4A };
static constexpr uint8_t LD_C_E_Opcode{ 0x4B };
static constexpr uint8_t LD_C_H_Opcode{ 0x4C };
static constexpr uint8_t LD_C_L_Opcode{ 0x4D };
static constexpr uint8_t LD_C_A_Opcode{ 0x4F };

static constexpr uint8_t LD_D_B_Opcode{ 0x50 };
static constexpr uint8_t LD_D_C_Opcode{ 0x51 };
static constexpr uint8_t LD_D_D_Opcode{ 0x52 };
static constexpr uint8_t LD_D_E_Opcode{ 0x53 };
static constexpr uint8_t LD_D_H_Opcode{ 0x54 };
static constexpr uint8_t LD_D_L_Opcode{ 0x55 };
static constexpr uint8_t LD_D_A_Opcode{ 0x57 };

static constexpr uint8_t LD_E_B_Opcode{ 0x58 };
static constexpr uint8_t LD_E_C_Opcode{ 0x59 };
static constexpr uint8_t LD_E_D_Opcode{ 0x5A };
static constexpr uint8_t LD_E_E_Opcode{ 0x5B };
static constexpr uint8_t LD_E_H_Opcode{ 0x5C };
static constexpr uint8_t LD_E_L_Opcode{ 0x5D };
static constexpr uint8_t LD_E_A_Opcode{ 0x5F };

static constexpr uint8_t LD_H_B_Opcode{ 0x60 };
static constexpr uint8_t LD_H_C_Opcode{ 0x61 };
static constexpr uint8_t LD_H_D_Opcode{ 0x62 };
static constexpr uint8_t LD_H_E_Opcode{ 0x63 };
static constexpr uint8_t LD_H_H_Opcode{ 0x64 };
static constexpr uint8_t LD_H_L_Opcode{ 0x65 };
static constexpr uint8_t LD_H_A_Opcode{ 0x67 };

static constexpr uint8_t LD_L_B_Opcode{ 0x68 };
static constexpr uint8_t LD_L_C_Opcode{ 0x69 };
static constexpr uint8_t LD_L_D_Opcode{ 0x6A };
static constexpr uint8_t LD_L_E_Opcode{ 0x6B };
static constexpr uint8_t LD_L_H_Opcode{ 0x6C };
static constexpr uint8_t LD_L_L_Opcode{ 0x6D };
static constexpr uint8_t LD_L_A_Opcode{ 0x6F };

static constexpr uint8_t LD_A_B_Opcode{ 0x78 };
static constexpr uint8_t LD_A_C_Opcode{ 0x79 };
static constexpr uint8_t LD_A_D_Opcode{ 0x7A };
static constexpr uint8_t LD_A_E_Opcode{ 0x7B };
static constexpr uint8_t LD_A_H_Opcode{ 0x7C };
static constexpr uint8_t LD_A_L_Opcode{ 0x7D };
static constexpr uint8_t LD_A_A_Opcode{ 0x7F };

static constexpr uint8_t LD_addressU16_A_Opcode{ 0xEA };
static constexpr uint8_t LD_A_addressU16_Opcode{ 0xFA };

static constexpr uint8_t LD_SP_HL_Opcode{ 0xF9 };

static constexpr uint8_t LD_A_u8_Opcode{ 0x3E };
static constexpr uint8_t LD_B_u8_Opcode{ 0x06 };
static constexpr uint8_t LD_C_u8_Opcode{ 0x0E };
static constexpr uint8_t LD_D_u8_Opcode{ 0x16 };
static constexpr uint8_t LD_E_u8_Opcode{ 0x1E };
static constexpr uint8_t LD_H_u8_Opcode{ 0x26 };
static constexpr uint8_t LD_L_u8_Opcode{ 0x2E };

static constexpr uint8_t LD_BC_u16_Opcode{ 0x01 };
static constexpr uint8_t LD_DE_u16_Opcode{ 0x11 };
static constexpr uint8_t LD_HL_u16_Opcode{ 0x21 };
static constexpr uint8_t LD_SP_u16_Opcode{ 0x31 };

static constexpr uint8_t LD_address_BC_A_Opcode{ 0x02 };
static constexpr uint8_t LD_address_DE_A_Opcode{ 0x12 };
static constexpr uint8_t LD_address_HL_A_Opcode{ 0x77 };
static constexpr uint8_t LDD_address_HL_A_Opcode{ 0x32 };
static constexpr uint8_t LDI_address_HL_A_Opcode{ 0x22 };

static constexpr uint8_t LD_address_HL_B_Opcode{ 0x70 };
static constexpr uint8_t LD_address_HL_C_Opcode{ 0x71 };
static constexpr uint8_t LD_address_HL_D_Opcode{ 0x72 };
static constexpr uint8_t LD_address_HL_E_Opcode{ 0x73 };
static constexpr uint8_t LD_address_HL_H_Opcode{ 0x74 };
static constexpr uint8_t LD_address_HL_L_Opcode{ 0x75 };

static constexpr uint8_t LD_A_address_BC_Opcode{ 0x0A };
static constexpr uint8_t LD_A_address_DE_Opcode{ 0x1A };
static constexpr uint8_t LD_A_address_HL_Opcode{ 0x7E };

static constexpr uint8_t LD_B_address_HL_Opcode{ 0x46 };
static constexpr uint8_t LD_C_address_HL_Opcode{ 0x4E };
static constexpr uint8_t LD_D_address_HL_Opcode{ 0x56 };
static constexpr uint8_t LD_E_address_HL_Opcode{ 0x5E };
static constexpr uint8_t LD_H_address_HL_Opcode{ 0x66 };
static constexpr uint8_t LD_L_address_HL_Opcode{ 0x6E };

static constexpr uint8_t LD_address_HL_u8_Opcode{ 0x36 };

static constexpr uint8_t LDD_A_address_HL_Opcode{ 0x3A };
static constexpr uint8_t LDI_A_address_HL_Opcode{ 0x2A };

static constexpr uint8_t LDH_A_addressU8_Opcode{ 0xF0 };
static constexpr uint8_t LDH_addressU8_A_Opcode{ 0xE0 };

static constexpr uint8_t LD_A_addressC_Opcode{ 0xF2 };
static constexpr uint8_t LD_addressC_A_Opcode{ 0xE2 };

static constexpr uint8_t LD_addressU16_SP_Opcode{ 0x08 };

static constexpr uint8_t INC_A_Opcode{ 0x3C };
static constexpr uint8_t INC_B_Opcode{ 0x04 };
static constexpr uint8_t INC_C_Opcode{ 0x0C };
static constexpr uint8_t INC_D_Opcode{ 0x14 };
static constexpr uint8_t INC_E_Opcode{ 0x1C };
static constexpr uint8_t INC_H_Opcode{ 0x24 };
static constexpr uint8_t INC_L_Opcode{ 0x2C };
static constexpr uint8_t INC_addressHL_Opcode{ 0x34 };

static constexpr uint8_t INC_BC_Opcode{ 0x03 };
static constexpr uint8_t INC_DE_Opcode{ 0x13 };
static constexpr uint8_t INC_HL_Opcode{ 0x23 };
static constexpr uint8_t INC_SP_Opcode{ 0x33 };

static constexpr uint8_t DEC_A_Opcode{ 0x3D };
static constexpr uint8_t DEC_B_Opcode{ 0x05 };
static constexpr uint8_t DEC_C_Opcode{ 0x0D };
static constexpr uint8_t DEC_D_Opcode{ 0x15 };
static constexpr uint8_t DEC_E_Opcode{ 0x1D };
static constexpr uint8_t DEC_H_Opcode{ 0x25 };
static constexpr uint8_t DEC_L_Opcode{ 0x2D };

static constexpr uint8_t DEC_BC_Opcode{ 0x0B };
static constexpr uint8_t DEC_DE_Opcode{ 0x1B };
static constexpr uint8_t DEC_HL_Opcode{ 0x2B };
static constexpr uint8_t DEC_SP_Opcode{ 0x3B };
static constexpr uint8_t DEC_addressHL_Opcode{ 0x35 };

static constexpr uint8_t AND_A_A_Opcode{ 0xA7 };
static constexpr uint8_t AND_A_B_Opcode{ 0xA0 };
static constexpr uint8_t AND_A_C_Opcode{ 0xA1 };
static constexpr uint8_t AND_A_D_Opcode{ 0xA2 };
static constexpr uint8_t AND_A_E_Opcode{ 0xA3 };
static constexpr uint8_t AND_A_H_Opcode{ 0xA4 };
static constexpr uint8_t AND_A_L_Opcode{ 0xA5 };
static constexpr uint8_t AND_A_u8_Opcode{ 0xE6 };
static constexpr uint8_t AND_A_addressHL_Opcode{ 0xA6 };

static constexpr uint8_t OR_A_A_Opcode{ 0xB7 };
static constexpr uint8_t OR_A_B_Opcode{ 0xB0 };
static constexpr uint8_t OR_A_C_Opcode{ 0xB1 };
static constexpr uint8_t OR_A_D_Opcode{ 0xB2 };
static constexpr uint8_t OR_A_E_Opcode{ 0xB3 };
static constexpr uint8_t OR_A_H_Opcode{ 0xB4 };
static constexpr uint8_t OR_A_L_Opcode{ 0xB5 };
static constexpr uint8_t OR_A_u8_Opcode{ 0xF6 };
static constexpr uint8_t OR_A_addressHL_Opcode{ 0xB6 };

static constexpr uint8_t XOR_A_A_Opcode{ 0xAF };
static constexpr uint8_t XOR_A_B_Opcode{ 0xA8 };
static constexpr uint8_t XOR_A_C_Opcode{ 0xA9 };
static constexpr uint8_t XOR_A_D_Opcode{ 0xAA };
static constexpr uint8_t XOR_A_E_Opcode{ 0xAB };
static constexpr uint8_t XOR_A_H_Opcode{ 0xAC };
static constexpr uint8_t XOR_A_L_Opcode{ 0xAD };
static constexpr uint8_t XOR_A_u8_Opcode{ 0xEE };
static constexpr uint8_t XOR_A_addressHL_Opcode{ 0xAE };

static constexpr uint8_t ADD_A_A_Opcode{ 0x87 };
static constexpr uint8_t ADD_A_B_Opcode{ 0x80 };
static constexpr uint8_t ADD_A_C_Opcode{ 0x81 };
static constexpr uint8_t ADD_A_D_Opcode{ 0x82 };
static constexpr uint8_t ADD_A_E_Opcode{ 0x83 };
static constexpr uint8_t ADD_A_H_Opcode{ 0x84 };
static constexpr uint8_t ADD_A_L_Opcode{ 0x85 };
static constexpr uint8_t ADD_A_u8_Opcode{ 0xC6 };
static constexpr uint8_t ADD_A_addressHL_Opcode{ 0x86 };

static constexpr uint8_t ADD_HL_BC_Opcode{ 0x09 };
static constexpr uint8_t ADD_HL_DE_Opcode{ 0x19 };
static constexpr uint8_t ADD_HL_HL_Opcode{ 0x29 };
static constexpr uint8_t ADD_HL_SP_Opcode{ 0x39 };

static constexpr uint8_t JP_u16_Opcode{ 0xC3 };

#endif // !OPCODES_HPP