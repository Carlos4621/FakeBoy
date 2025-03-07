#pragma once
#ifndef OPCODES_HPP
#define OPCODES_HPP

static constexpr uint16_t NOP_Opcode = 0x00;

static constexpr uint16_t LD_B_B_Opcode{ 0x40 };
static constexpr uint16_t LD_B_C_Opcode{ 0x41 };
static constexpr uint16_t LD_B_D_Opcode{ 0x42 };
static constexpr uint16_t LD_B_E_Opcode{ 0x43 };
static constexpr uint16_t LD_B_H_Opcode{ 0x44 };
static constexpr uint16_t LD_B_L_Opcode{ 0x45 };
static constexpr uint16_t LD_B_A_Opcode{ 0x47 };

static constexpr uint16_t LD_C_B_Opcode{ 0x48 };
static constexpr uint16_t LD_C_C_Opcode{ 0x49 };
static constexpr uint16_t LD_C_D_Opcode{ 0x4A };
static constexpr uint16_t LD_C_E_Opcode{ 0x4B };
static constexpr uint16_t LD_C_H_Opcode{ 0x4C };
static constexpr uint16_t LD_C_L_Opcode{ 0x4D };
static constexpr uint16_t LD_C_A_Opcode{ 0x4F };

static constexpr uint16_t LD_D_B_Opcode{ 0x50 };
static constexpr uint16_t LD_D_C_Opcode{ 0x51 };
static constexpr uint16_t LD_D_D_Opcode{ 0x52 };
static constexpr uint16_t LD_D_E_Opcode{ 0x53 };
static constexpr uint16_t LD_D_H_Opcode{ 0x54 };
static constexpr uint16_t LD_D_L_Opcode{ 0x55 };
static constexpr uint16_t LD_D_A_Opcode{ 0x57 };

static constexpr uint16_t LD_E_B_Opcode{ 0x58 };
static constexpr uint16_t LD_E_C_Opcode{ 0x59 };
static constexpr uint16_t LD_E_D_Opcode{ 0x5A };
static constexpr uint16_t LD_E_E_Opcode{ 0x5B };
static constexpr uint16_t LD_E_H_Opcode{ 0x5C };
static constexpr uint16_t LD_E_L_Opcode{ 0x5D };
static constexpr uint16_t LD_E_A_Opcode{ 0x5F };

static constexpr uint16_t LD_H_B_Opcode{ 0x60 };
static constexpr uint16_t LD_H_C_Opcode{ 0x61 };
static constexpr uint16_t LD_H_D_Opcode{ 0x62 };
static constexpr uint16_t LD_H_E_Opcode{ 0x63 };
static constexpr uint16_t LD_H_H_Opcode{ 0x64 };
static constexpr uint16_t LD_H_L_Opcode{ 0x65 };
static constexpr uint16_t LD_H_A_Opcode{ 0x67 };

static constexpr uint16_t LD_L_B_Opcode{ 0x68 };
static constexpr uint16_t LD_L_C_Opcode{ 0x69 };
static constexpr uint16_t LD_L_D_Opcode{ 0x6A };
static constexpr uint16_t LD_L_E_Opcode{ 0x6B };
static constexpr uint16_t LD_L_H_Opcode{ 0x6C };
static constexpr uint16_t LD_L_L_Opcode{ 0x6D };
static constexpr uint16_t LD_L_A_Opcode{ 0x6F };

static constexpr uint16_t LD_A_B_Opcode{ 0x78 };
static constexpr uint16_t LD_A_C_Opcode{ 0x79 };
static constexpr uint16_t LD_A_D_Opcode{ 0x7A };
static constexpr uint16_t LD_A_E_Opcode{ 0x7B };
static constexpr uint16_t LD_A_H_Opcode{ 0x7C };
static constexpr uint16_t LD_A_L_Opcode{ 0x7D };
static constexpr uint16_t LD_A_A_Opcode{ 0x7F };

static constexpr uint16_t LD_addressU16_A_Opcode{ 0xEA };
static constexpr uint16_t LD_A_addressU16_Opcode{ 0xFA };

static constexpr uint16_t LD_A_u8_Opcode{ 0x3E };
static constexpr uint16_t LD_B_u8_Opcode{ 0x06 };
static constexpr uint16_t LD_C_u8_Opcode{ 0x0E };
static constexpr uint16_t LD_D_u8_Opcode{ 0x16 };
static constexpr uint16_t LD_E_u8_Opcode{ 0x1E };
static constexpr uint16_t LD_H_u8_Opcode{ 0x26 };
static constexpr uint16_t LD_L_u8_Opcode{ 0x2E };

static constexpr uint16_t LD_BC_u16_Opcode{ 0x01 };
static constexpr uint16_t LD_DE_u16_Opcode{ 0x11 };
static constexpr uint16_t LD_HL_u16_Opcode{ 0x21 };
static constexpr uint16_t LD_SP_u16_Opcode{ 0x31 };

static constexpr uint16_t LD_address_BC_A_Opcode{ 0x02 };
static constexpr uint16_t LD_address_DE_A_Opcode{ 0x12 };
static constexpr uint16_t LD_address_HL_A_Opcode{ 0x77 };
static constexpr uint16_t LDD_address_HL_A_Opcode{ 0x32 };
static constexpr uint16_t LDI_address_HL_A_Opcode{ 0x22 };

static constexpr uint16_t LD_address_HL_B_Opcode{ 0x70 };
static constexpr uint16_t LD_address_HL_C_Opcode{ 0x71 };
static constexpr uint16_t LD_address_HL_D_Opcode{ 0x72 };
static constexpr uint16_t LD_address_HL_E_Opcode{ 0x73 };
static constexpr uint16_t LD_address_HL_H_Opcode{ 0x74 };
static constexpr uint16_t LD_address_HL_L_Opcode{ 0x75 };

static constexpr uint16_t LD_A_address_BC_Opcode{ 0x0A };
static constexpr uint16_t LD_A_address_DE_Opcode{ 0x1A };
static constexpr uint16_t LD_A_address_HL_Opcode{ 0x7E };

static constexpr uint16_t LD_B_address_HL_Opcode{ 0x46 };
static constexpr uint16_t LD_C_address_HL_Opcode{ 0x4E };
static constexpr uint16_t LD_D_address_HL_Opcode{ 0x56 };
static constexpr uint16_t LD_E_address_HL_Opcode{ 0x5E };
static constexpr uint16_t LD_H_address_HL_Opcode{ 0x66 };
static constexpr uint16_t LD_L_address_HL_Opcode{ 0x6E };

static constexpr uint16_t LD_address_HL_u8_Opcode{ 0x36 };

static constexpr uint16_t LDD_A_address_HL_Opcode{ 0x3A };
static constexpr uint16_t LDI_A_address_HL_Opcode{ 0x2A };

static constexpr uint16_t JP_u16_Opcode{ 0xC3 };

#endif // !OPCODES_HPP