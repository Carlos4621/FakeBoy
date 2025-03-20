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
    using Flags = CPURegisters::Flags;

    static constexpr uint16_t NumberOfOpcodes{ 256 };
    static constexpr uint8_t ByteDisplacement{ 8 };
    static constexpr uint8_t TCyclesPerInstruction{ 4 };
    static constexpr uint8_t ByteMask{ 0x0F };

    static std::array<MemberFunction, NumberOfOpcodes> opcodeTable;
    static bool isOpcodeTableInitialized;

    MemoryBus* memoryBus_m;

    CPURegisters registers_m;

    std::queue<MemberFunction> operationsQueue_m;

    uint8_t currentTCycle_m{ 1 };

    static void initializeOpcodeTable() noexcept;

    static void initialieLDsOpcodes() noexcept;
    static void initialize_LD_R_R_Opcodes() noexcept;
    static void initialize_LD_R_u8_Opcodes() noexcept;
    static void initialize_JP_Opcodes() noexcept;
    static void initializeMiscellaneousOpcodes() noexcept;
    static void initialize_LD_RR_u16_Opcodes() noexcept;
    static void initialize_LD_addressRR_R_Opcodes() noexcept;
    static void initialize_LD_R_addressRR_Opcodes() noexcept;
    static void initialize_LD_addressHL_u8_Opcode() noexcept;
    static void initialize_LDI_LDD_Opcodes() noexcept;
    static void initialize_LD_SPs_HLs_Opcodes() noexcept;
    static void initialize_LDH_Opcodes();

    static void initializeINCsOpcodes() noexcept;
    static void initialiceDECsOpcodes() noexcept;

    void setZeroFlagIfRegisterIsZero(CPU::Registers reg);
    void setHalfCarryIfHalfCarryWillOcurr(CPU::Registers reg, uint8_t valueToAdd, bool isAdd);

    template<typename... Ops>
    void pushOperationsToQueue(Ops... ops);

    void fetchOpcode();
    void processNextOperation();

    void loadNextByteToLower();
    void loadNextByteToUpper();

    void from_addressU16_assignTo_PC();
    void from_U8_assignTo_addressHL();
    void from_HL_assignTo_SP();

    void from_0xFF00PlusU8_assignTo_A();
    void from_A_assignTo_0xFF00PlusU8();
    void from_A_assignTo_0xFF00PlusC();
    void from_0xFF00PlusC_assignTo_A();

    void fromAWriteToIORegisters(uint8_t offset);
    void fromIORegistersWriteToA(uint8_t offset);

    template<CPU::Registers Register, uint8_t offset = 0>
    void from_R_assignTo_addressU16();

    template<CPU::Registers Register, uint8_t offset = 0>
    void from_addressU16_assignTo_R();

    [[nodiscard]]
    uint8_t read_PC_Address() const;

    void incrementPC();
    void setPC(uint16_t address);

    template<CPU::Registers ToRegister>
    void assignNextByteToRegister();

    template<CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
    void from_addressRR_assignTo_R();

    template<CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister>
    void from_R_assignTo_addressRR();

    template<CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister, bool Increment>
    void from_addressRR_assignTo_R_and_incrementOrDecrementRR();

    template<CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister, bool Increment>
    void from_R_assignTo_addressRR_and_incrementOrDecrementRR();

    void addOrSubstractToRegister(CPU::Registers Register, uint8_t valueToAdd, bool isAdd);

    template <CPU::CombinedRegisters ToRegisters, CPU::Registers Register, uint8_t increment, bool isAdd>
    void AddOrSubstractRegisterAndAssignToAddressRR();

    template<CPU::CombinedRegisters Registers, uint8_t Increment, bool isAdd>
    void addOrSubstractToCombinedRegisters();

    template<CPU::Registers ToRegister, CPU::Registers FromRegister>
    void LD_R_R();

    void LD_addressU16_A();

    void LD_A_addressU16();

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

    void LD_SP_HL();

    void LD_addressU16_SP();

    void LDH_A_addressU8();
    void LDH_addressU8_A();

    void LD_A_addressC();
    void LD_addressC_A();

    template<CPU::Registers Register>
    void INC_R();

    void INC_addressHL();

    template<CPU::CombinedRegisters Registers>
    void INC_RR();

    template<CPU::Registers Register>
    void DEC_R();

    template<CPU::CombinedRegisters Registers>
    void DEC_RR();

    void DEC_addressHL();

    void JP_u16();

    void NOP();
    
    void invalidOpcode();
};

template <typename... Ops>
inline void CPU::pushOperationsToQueue(Ops... ops) {
    (operationsQueue_m.push(ops), ...);
}

template <CPU::Registers Register, uint8_t offset>
inline void CPU::from_R_assignTo_addressU16() {
    const auto address{ registers_m.getCombinedRegister(CombinedRegisters::Auxiliary) + offset };
    memoryBus_m->write(address, registers_m.getRegister(Register));
}

template <CPU::Registers Register, uint8_t offset>
inline void CPU::from_addressU16_assignTo_R() {
    const auto address{ registers_m.getCombinedRegister(CombinedRegisters::Auxiliary) + offset };
    registers_m.setRegister(Register, memoryBus_m->read(address));
}

template <CPU::Registers ToRegister>
inline void CPU::assignNextByteToRegister() {
    loadNextByteToLower();
    registers_m.setRegister(ToRegister, registers_m.getRegister(Registers::AuxiliaryLow));
}

template <CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
inline void CPU::from_addressRR_assignTo_R() {
    registers_m.setRegister(ToRegister, memoryBus_m->read(registers_m.getCombinedRegister(FromRegisters)));
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister>
inline void CPU::from_R_assignTo_addressRR() {
    memoryBus_m->write(registers_m.getCombinedRegister(ToRegisters), registers_m.getRegister(FromRegister));
}

template <CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister, bool Increment>
inline void CPU::from_addressRR_assignTo_R_and_incrementOrDecrementRR() {
    from_addressRR_assignTo_R<FromRegisters, ToRegister>();
    addOrSubstractToCombinedRegisters<FromRegisters, 1, Increment>();
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister, bool Increment>
inline void CPU::from_R_assignTo_addressRR_and_incrementOrDecrementRR() {
    from_R_assignTo_addressRR<ToRegisters, FromRegister>();
    addOrSubstractToCombinedRegisters<ToRegisters, 1, Increment>();
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers Register, uint8_t increment, bool isAdd>
inline void CPU::AddOrSubstractRegisterAndAssignToAddressRR() {
    addOrSubstractToRegister(Register, increment, isAdd);
    memoryBus_m->write(registers_m.getCombinedRegister(ToRegisters), registers_m.getRegister(Register));
}

template <CPU::CombinedRegisters Registers, uint8_t Increment, bool isAdd>
inline void CPU::addOrSubstractToCombinedRegisters() {
    registers_m.setCombinedRegister(Registers, registers_m.getCombinedRegister(Registers) + (isAdd ? Increment : -Increment));
}

template <CPU::Registers ToRegister, CPU::Registers FromRegister>
inline void CPU::LD_R_R() {
    registers_m.setRegister(ToRegister, registers_m.getRegister(FromRegister));
}

template <CPU::Registers ToRegister>
inline void CPU::LD_R_u8() {
    pushOperationsToQueue(&CPU::assignNextByteToRegister<ToRegister>);
}

template <CPU::Registers UpperRegister, CPU::Registers LowerRegister>
inline void CPU::LD_RR_u16() {
    pushOperationsToQueue(
        &CPU::assignNextByteToRegister<LowerRegister>,
        &CPU::assignNextByteToRegister<UpperRegister>);
}

template <CPU::CombinedRegisters ToRegisters, CPU::Registers FromRegister>
inline void CPU::LD_addressRR_R() {
    pushOperationsToQueue(&CPU::from_R_assignTo_addressRR<ToRegisters, FromRegister>);
}

template <CPU::CombinedRegisters FromRegisters, CPU::Registers ToRegister>
inline void CPU::LD_R_addressRR() {
    pushOperationsToQueue(&CPU::from_addressRR_assignTo_R<FromRegisters, ToRegister>);
}

template <CPU::Registers Register>
inline void CPU::INC_R() {
    addOrSubstractToRegister(Register, 1, true);
}

template <CPU::CombinedRegisters Registers>
inline void CPU::INC_RR() {
    pushOperationsToQueue(&CPU::addOrSubstractToCombinedRegisters<Registers, 1, true>);
}

template <CPU::Registers Register>
inline void CPU::DEC_R() {
    addOrSubstractToRegister(Register, 1, false);
}

template <CPU::CombinedRegisters Registers>
inline void CPU::DEC_RR() {
    pushOperationsToQueue(&CPU::addOrSubstractToCombinedRegisters<Registers, 1, false>);
}

#endif // !CPU_HPP