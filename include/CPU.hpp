#pragma once
#ifndef CPU_HPP
#define CPU_HPP

#include "MemoryBus.hpp"
#include "CPURegisters.hpp"
#include <array>
#include <queue>
#include "Opcodes.hpp"
#include <iostream>

class CPU {
public:

    explicit CPU(MemoryBus* memoryBus) noexcept;

    void processTCycle();

protected:

    [[nodiscard]]
    uint16_t getPC() const noexcept;

    [[nodiscard]]
    uint16_t getSP() const noexcept;

    [[nodiscard]]
    CPURegisters getRegisters() const noexcept;

    [[nodiscard]]
    MemoryBus* getMemoryBus() const noexcept;

    [[nodiscard]]
    uint8_t getCurrentTCycle() const noexcept;

    [[nodiscard]]
    bool isOperationsQueueEmpty() const noexcept;

private:

    using MemberFunction = void (CPU::*)();
    using Registers = CPURegisters::Registers;
    using CombinedRegisters = CPURegisters::CombinedRegisters;

    static constexpr uint16_t NumberOfOpcodes{ 256 };
    static constexpr uint8_t ByteDisplacement{ 8 };

    static std::array<MemberFunction, NumberOfOpcodes> opcodeTable;
    static bool isOpcodeTableInitialized;

    MemoryBus* memoryBus_m;

    CPURegisters registers_m;

    uint8_t lowerByteAuxiliaryRegister_m{ 0 };
    uint8_t higherByteAuxiliaryRegister_m{ 0 };

    std::queue<MemberFunction> operationsQueue_m;

    uint8_t currentTCycle_m{ 1 };

    static void initializeOpcodeTable() noexcept;
    static void initialize_LD_R_R_Opcodes() noexcept;
    static void initialize_LD_R_u8_Opcodes() noexcept;
    static void initialize_JP_Opcodes() noexcept;
    static void initializeMisceallenousOpcodes() noexcept;
    static void initialize_LD_RR_u16_Opcodes() noexcept;
    static void initialize_LD_addressRR_R_Opcodes() noexcept;
    static void initialize_LD_R_addressRR_Opcodes() noexcept;
    static void initialize_LD_addressHL_u8_Opcode() noexcept;
    
    static uint16_t getCombinedBytes(uint8_t hightByte, uint8_t lowByte) noexcept;

    void readNextByteAsLowerByte();
    void readNextByteAsHigherByte();
    void from_A_assignTo_addressU16();
    void from_addressU16_assign_ToPC();
    void from_U8_assignTo_addressHL();

    [[nodiscard]]
    uint8_t read_PC_Address() const;

    void incrementPC();
    void setPC(uint16_t address);

    template<CPU::Registers ToRegister>
    void asignNextByteToRegister();

    template<CPU::Registers ToRegister>
    void asignNextByteToRegisterAndIncrementPC();

    template<CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
    void from_addressRR_asignTo_R();

    template<CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister>
    void from_R_asignTo_addressRR();

    template<CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister, bool Decrement>
    void from_addressRR_asignTo_R_and_incrementOrDecrementRR();

    template<CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister, bool Decrement>
    void from_R_assignTo_address_and_incrementOrDecrementRR();

    template<CPU::Registers ToRegister, CPU::Registers FromRegister>
    void LD_R_R();

    void LD_addressU16_A();

    template<CPU::Registers ToRegister>
    void LD_R_u8();

    template<CPU::Registers UpperRegister, CPU::Registers LowerRegister>
    void LD_RR_u16();

    template<CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
    void LD_addressRR_R();

    template<CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegisters>
    void LD_R_addressRR();

    void LD_addressHL_u8();

    void LDI_addressHL_A();
    void LDD_addressHL_A();

    void LDI_A_addressHL();
    void LDD_A_addressHL();

    void JP_u16();

    void NOP();
    
    void invalidOpcode();
};

template <CPU::Registers ToRegister>
inline void CPU::asignNextByteToRegister() {
    readNextByteAsLowerByte();
    registers_m.setRegister(ToRegister, lowerByteAuxiliaryRegister_m);
}

template <CPU::Registers ToRegister>
inline void CPU::asignNextByteToRegisterAndIncrementPC() {
    asignNextByteToRegister<ToRegister>();
    incrementPC();
}

template <CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
inline void CPU::from_addressRR_asignTo_R() {
    registers_m.setRegister(ToRegister, memoryBus_m->read(registers_m.getCombinedRegister(FromRegisters)));
    
    incrementPC();
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister>
inline void CPU::from_R_asignTo_addressRR() {
    memoryBus_m->write(registers_m.getCombinedRegister(ToRegisters), registers_m.getRegister(FromRegister));
    
    incrementPC();
}

template <CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister, bool Decrement>
inline void CPU::from_addressRR_asignTo_R_and_incrementOrDecrementRR() {
    from_addressRR_asignTo_R<FromRegisters, ToRegister>();
    registers_m.setCombinedRegister(FromRegisters, registers_m.getCombinedRegister(FromRegisters) + (Decrement ? -1 : 1));
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister, bool Decrement>
inline void CPU::from_R_assignTo_address_and_incrementOrDecrementRR() {
    from_R_asignTo_addressRR<ToRegisters, FromRegister>();
    registers_m.setCombinedRegister(ToRegisters, registers_m.getCombinedRegister(ToRegisters) + (Decrement ? -1 : 1));
}

template <CPU::Registers ToRegister, CPU::Registers FromRegister>
inline void CPU::LD_R_R() {
    registers_m.setRegister(ToRegister, registers_m.getRegister(FromRegister));
    
    incrementPC();
}

template <CPU::Registers ToRegister>
inline void CPU::LD_R_u8() {
    operationsQueue_m.push(&CPU::asignNextByteToRegisterAndIncrementPC<ToRegister>);
}

template <CPU::Registers UpperRegister, CPU::Registers LowerRegister>
inline void CPU::LD_RR_u16() {
    operationsQueue_m.push(&CPU::asignNextByteToRegister<LowerRegister>);
    operationsQueue_m.push(&CPU::asignNextByteToRegisterAndIncrementPC<UpperRegister>);
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister>
inline void CPU::LD_addressRR_R() {
    operationsQueue_m.push(&CPU::from_R_asignTo_addressRR<ToRegisters, FromRegister>);
}

template <CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
inline void CPU::LD_R_addressRR() {
    operationsQueue_m.push(&CPU::from_addressRR_asignTo_R<FromRegisters, ToRegister>);
}

#endif // !CPU_HPP