#include <CPU.hpp>

std::array<CPU::MemberFunction, CPU::NumberOfOpcodes> CPU::opcodeTable{};

bool CPU::isOpcodeTableInitialized{ false };

CPU::CPU(MemoryBus *memoryBus) noexcept 
    : memoryBus_m{ memoryBus }
{
    if (!isOpcodeTableInitialized) {
        initializeOpcodeTable();
        isOpcodeTableInitialized = true;
    }
}

void CPU::processTCycle() {
    if (currentTCycle_m < TCyclesPerInstruction) {
        ++currentTCycle_m;
        return;
    }
    
    currentTCycle_m = 1;

    if (!operationsQueue_m.empty()) {
        processNextOperation();
    }
    else {
        fetchOpcode();
    }
}

uint16_t CPU::getPC() const noexcept {
    return registers_m.getCombinedRegister(CombinedRegisters::PC);
}

uint16_t CPU::getSP() const noexcept {
    return registers_m.getCombinedRegister(CombinedRegisters::SP);
}

CPURegisters CPU::getRegisters() const noexcept {
    return registers_m;
}

MemoryBus* CPU::getMemoryBus() const noexcept {
    return memoryBus_m;
}

uint8_t CPU::getCurrentTCycle() const noexcept {
    return currentTCycle_m;
}

bool CPU::isOperationsQueueEmpty() const noexcept {
    return operationsQueue_m.empty();
}

void CPU::initializeOpcodeTable() noexcept {
    opcodeTable.fill(&CPU::invalidOpcode);

    initialieLDsOpcodes();
    initializeINCsOpcodes();
    initializeDECsOpcodes();

    initializeANDsOpcodes();
    initializeORsOpcodes();
    initializeXORsOpcodes();

    initializeADDsOpcodes();
    initializeSUBsOpcodes();
    initializeCPsOpcodes();

    initializeJPsOpcodes();
    initializeMiscellaneousOpcodes();
}

void CPU::initialieLDsOpcodes() noexcept {
    initialize_LD_R_R_Opcodes();
    initialize_LD_R_u8_Opcodes();
    initialize_LD_RR_u16_Opcodes();
    initialize_LD_R_addressRR_Opcodes();
    initialize_LD_addressRR_R_Opcodes();
    initialize_LD_addressHL_u8_Opcode();
    initialize_LDI_LDD_Opcodes();
    initialize_LD_SPs_HLs_Opcodes();
    initialize_LDH_Opcodes();
}

void CPU::initialize_LD_R_R_Opcodes() noexcept {
    opcodeTable[LD_B_B_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::B>;
    opcodeTable[LD_B_C_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::C>;
    opcodeTable[LD_B_D_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::D>;
    opcodeTable[LD_B_E_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::E>;
    opcodeTable[LD_B_H_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::H>;
    opcodeTable[LD_B_L_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::L>;
    opcodeTable[LD_B_A_Opcode] = &CPU::LD_R_R<CPU::Registers::B, CPU::Registers::A>;
    
    opcodeTable[LD_C_B_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::B>;
    opcodeTable[LD_C_C_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::C>;
    opcodeTable[LD_C_D_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::D>;
    opcodeTable[LD_C_E_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::E>;
    opcodeTable[LD_C_H_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::H>;
    opcodeTable[LD_C_L_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::L>;
    opcodeTable[LD_C_A_Opcode] = &CPU::LD_R_R<CPU::Registers::C, CPU::Registers::A>;

    opcodeTable[LD_D_B_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::B>;
    opcodeTable[LD_D_C_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::C>;
    opcodeTable[LD_D_D_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::D>;
    opcodeTable[LD_D_E_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::E>;
    opcodeTable[LD_D_H_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::H>;
    opcodeTable[LD_D_L_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::L>;
    opcodeTable[LD_D_A_Opcode] = &CPU::LD_R_R<CPU::Registers::D, CPU::Registers::A>;

    opcodeTable[LD_E_B_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::B>;
    opcodeTable[LD_E_C_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::C>;
    opcodeTable[LD_E_D_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::D>;
    opcodeTable[LD_E_E_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::E>;
    opcodeTable[LD_E_H_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::H>;
    opcodeTable[LD_E_L_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::L>;
    opcodeTable[LD_E_A_Opcode] = &CPU::LD_R_R<CPU::Registers::E, CPU::Registers::A>;

    opcodeTable[LD_H_B_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::B>;
    opcodeTable[LD_H_C_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::C>;
    opcodeTable[LD_H_D_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::D>;
    opcodeTable[LD_H_E_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::E>;
    opcodeTable[LD_H_H_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::H>;
    opcodeTable[LD_H_L_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::L>;
    opcodeTable[LD_H_A_Opcode] = &CPU::LD_R_R<CPU::Registers::H, CPU::Registers::A>;

    opcodeTable[LD_L_B_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::B>;
    opcodeTable[LD_L_C_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::C>;
    opcodeTable[LD_L_D_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::D>;
    opcodeTable[LD_L_E_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::E>;
    opcodeTable[LD_L_H_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::H>;
    opcodeTable[LD_L_L_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::L>;
    opcodeTable[LD_L_A_Opcode] = &CPU::LD_R_R<CPU::Registers::L, CPU::Registers::A>;

    opcodeTable[LD_A_B_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::B>;
    opcodeTable[LD_A_C_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::C>;
    opcodeTable[LD_A_D_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::D>;
    opcodeTable[LD_A_E_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::E>;
    opcodeTable[LD_A_H_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::H>;
    opcodeTable[LD_A_L_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::L>;
    opcodeTable[LD_A_A_Opcode] = &CPU::LD_R_R<CPU::Registers::A, CPU::Registers::A>;
}

void CPU::initialize_LD_R_u8_Opcodes() noexcept {
    opcodeTable[LD_A_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::A>;
    opcodeTable[LD_B_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::B>;
    opcodeTable[LD_C_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::C>;
    opcodeTable[LD_D_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::D>;
    opcodeTable[LD_E_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::E>;
    opcodeTable[LD_H_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::H>;
    opcodeTable[LD_L_u8_Opcode] = &CPU::LD_R_u8<CPU::Registers::L>;
}

void CPU::initialize_LDH_Opcodes() noexcept {
    opcodeTable[LDH_A_addressU8_Opcode] = &CPU::LDH_A_addressU8;
    opcodeTable[LDH_addressU8_A_Opcode] = &CPU::LDH_addressU8_A;
    opcodeTable[LD_A_addressC_Opcode] = &CPU::LD_A_addressC;
    opcodeTable[LD_addressC_A_Opcode] = &CPU::LD_addressC_A;
}

void CPU::initializeINCsOpcodes() noexcept {
    opcodeTable[INC_B_Opcode] = &CPU::INC_R<Registers::B>;
    opcodeTable[INC_C_Opcode] = &CPU::INC_R<Registers::C>;
    opcodeTable[INC_D_Opcode] = &CPU::INC_R<Registers::D>;
    opcodeTable[INC_E_Opcode] = &CPU::INC_R<Registers::E>;
    opcodeTable[INC_H_Opcode] = &CPU::INC_R<Registers::H>;
    opcodeTable[INC_L_Opcode] = &CPU::INC_R<Registers::L>;
    opcodeTable[INC_A_Opcode] = &CPU::INC_R<Registers::A>;
    
    opcodeTable[INC_addressHL_Opcode] = &CPU::INC_addressHL;

    opcodeTable[INC_BC_Opcode] = &CPU::INC_RR<CombinedRegisters::BC>;
    opcodeTable[INC_DE_Opcode] = &CPU::INC_RR<CombinedRegisters::DE>;
    opcodeTable[INC_HL_Opcode] = &CPU::INC_RR<CombinedRegisters::HL>;
    opcodeTable[INC_SP_Opcode] = &CPU::INC_RR<CombinedRegisters::SP>;
}

void CPU::initializeDECsOpcodes() noexcept {
    opcodeTable[DEC_B_Opcode] = &CPU::DEC_R<Registers::B>;
    opcodeTable[DEC_C_Opcode] = &CPU::DEC_R<Registers::C>;
    opcodeTable[DEC_D_Opcode] = &CPU::DEC_R<Registers::D>;
    opcodeTable[DEC_E_Opcode] = &CPU::DEC_R<Registers::E>;
    opcodeTable[DEC_H_Opcode] = &CPU::DEC_R<Registers::H>;
    opcodeTable[DEC_L_Opcode] = &CPU::DEC_R<Registers::L>;
    opcodeTable[DEC_A_Opcode] = &CPU::DEC_R<Registers::A>;

    opcodeTable[DEC_addressHL_Opcode] = &CPU::DEC_addressHL;

    opcodeTable[DEC_BC_Opcode] = &CPU::DEC_RR<CombinedRegisters::BC>;
    opcodeTable[DEC_DE_Opcode] = &CPU::DEC_RR<CombinedRegisters::DE>;
    opcodeTable[DEC_HL_Opcode] = &CPU::DEC_RR<CombinedRegisters::HL>;
    opcodeTable[DEC_SP_Opcode] = &CPU::DEC_RR<CombinedRegisters::SP>;
}

void CPU::initializeANDsOpcodes() noexcept {
    opcodeTable[AND_A_A_Opcode] = &CPU::AND_A_R<Registers::A>;
    opcodeTable[AND_A_B_Opcode] = &CPU::AND_A_R<Registers::B>;
    opcodeTable[AND_A_C_Opcode] = &CPU::AND_A_R<Registers::C>;
    opcodeTable[AND_A_D_Opcode] = &CPU::AND_A_R<Registers::D>;
    opcodeTable[AND_A_E_Opcode] = &CPU::AND_A_R<Registers::E>;
    opcodeTable[AND_A_H_Opcode] = &CPU::AND_A_R<Registers::H>;
    opcodeTable[AND_A_L_Opcode] = &CPU::AND_A_R<Registers::L>;

    opcodeTable[AND_A_u8_Opcode] = &CPU::AND_A_u8;
    opcodeTable[AND_A_addressHL_Opcode] = &CPU::AND_A_addressHL;
}

void CPU::initializeORsOpcodes() noexcept {
    opcodeTable[OR_A_A_Opcode] = &CPU::OR_A_R<Registers::A>;
    opcodeTable[OR_A_B_Opcode] = &CPU::OR_A_R<Registers::B>;
    opcodeTable[OR_A_C_Opcode] = &CPU::OR_A_R<Registers::C>;
    opcodeTable[OR_A_D_Opcode] = &CPU::OR_A_R<Registers::D>;
    opcodeTable[OR_A_E_Opcode] = &CPU::OR_A_R<Registers::E>;
    opcodeTable[OR_A_H_Opcode] = &CPU::OR_A_R<Registers::H>;
    opcodeTable[OR_A_L_Opcode] = &CPU::OR_A_R<Registers::L>;

    opcodeTable[OR_A_u8_Opcode] = &CPU::OR_A_u8;
    opcodeTable[OR_A_addressHL_Opcode] = &CPU::OR_A_addressHL;
}

void CPU::initializeXORsOpcodes() noexcept {
    opcodeTable[XOR_A_A_Opcode] = &CPU::XOR_A_R<Registers::A>;
    opcodeTable[XOR_A_B_Opcode] = &CPU::XOR_A_R<Registers::B>;
    opcodeTable[XOR_A_C_Opcode] = &CPU::XOR_A_R<Registers::C>;
    opcodeTable[XOR_A_D_Opcode] = &CPU::XOR_A_R<Registers::D>;
    opcodeTable[XOR_A_E_Opcode] = &CPU::XOR_A_R<Registers::E>;
    opcodeTable[XOR_A_H_Opcode] = &CPU::XOR_A_R<Registers::H>;
    opcodeTable[XOR_A_L_Opcode] = &CPU::XOR_A_R<Registers::L>;

    opcodeTable[XOR_A_u8_Opcode] = &CPU::XOR_A_u8;
    opcodeTable[XOR_A_addressHL_Opcode] = &CPU::XOR_A_addressHL;
}

void CPU::initializeADDsOpcodes() noexcept {
    opcodeTable[ADD_A_A_Opcode] = &CPU::ADD_A_R<Registers::A>;
    opcodeTable[ADD_A_B_Opcode] = &CPU::ADD_A_R<Registers::B>;
    opcodeTable[ADD_A_C_Opcode] = &CPU::ADD_A_R<Registers::C>;
    opcodeTable[ADD_A_D_Opcode] = &CPU::ADD_A_R<Registers::D>;
    opcodeTable[ADD_A_E_Opcode] = &CPU::ADD_A_R<Registers::E>;
    opcodeTable[ADD_A_H_Opcode] = &CPU::ADD_A_R<Registers::H>;
    opcodeTable[ADD_A_L_Opcode] = &CPU::ADD_A_R<Registers::L>;

    opcodeTable[ADD_A_u8_Opcode] = &CPU::ADD_A_u8;
    opcodeTable[ADD_A_addressHL_Opcode] = &CPU::ADD_A_addressHL;

    opcodeTable[ADD_HL_BC_Opcode] = &CPU::ADD_HL_RR<CombinedRegisters::BC>;
    opcodeTable[ADD_HL_DE_Opcode] = &CPU::ADD_HL_RR<CombinedRegisters::DE>;
    opcodeTable[ADD_HL_HL_Opcode] = &CPU::ADD_HL_RR<CombinedRegisters::HL>;
    opcodeTable[ADD_HL_SP_Opcode] = &CPU::ADD_HL_RR<CombinedRegisters::SP>;
}

void CPU::initializeSUBsOpcodes() noexcept {
    opcodeTable[SUB_A_A_Opcode] = &CPU::SUB_A_R<Registers::A>;
    opcodeTable[SUB_A_B_Opcode] = &CPU::SUB_A_R<Registers::B>;
    opcodeTable[SUB_A_C_Opcode] = &CPU::SUB_A_R<Registers::C>;
    opcodeTable[SUB_A_D_Opcode] = &CPU::SUB_A_R<Registers::D>;
    opcodeTable[SUB_A_E_Opcode] = &CPU::SUB_A_R<Registers::E>;
    opcodeTable[SUB_A_H_Opcode] = &CPU::SUB_A_R<Registers::H>;
    opcodeTable[SUB_A_L_Opcode] = &CPU::SUB_A_R<Registers::L>;

    opcodeTable[SUB_A_u8_Opcode] = &CPU::SUB_A_u8;
    opcodeTable[SUB_A_addressHL_Opcode] = &CPU::SUB_A_addressHL;
}

void CPU::initializeCPsOpcodes() noexcept {
    opcodeTable[CP_A_A_Opcode] = &CPU::CP_A_R<Registers::A>;
    opcodeTable[CP_A_B_Opcode] = &CPU::CP_A_R<Registers::B>;
    opcodeTable[CP_A_C_Opcode] = &CPU::CP_A_R<Registers::C>;
    opcodeTable[CP_A_D_Opcode] = &CPU::CP_A_R<Registers::D>;
    opcodeTable[CP_A_E_Opcode] = &CPU::CP_A_R<Registers::E>;
    opcodeTable[CP_A_H_Opcode] = &CPU::CP_A_R<Registers::H>;
    opcodeTable[CP_A_L_Opcode] = &CPU::CP_A_R<Registers::L>;

    opcodeTable[CP_A_u8_Opcode] = &CPU::CP_A_u8;
}

void CPU::setZeroFlagIfRegisterIsZero(Registers reg) {
    registers_m.setFlag(Flags::Z, (registers_m.getRegister(reg) == 0));
}

void CPU::setHalfCarryIfHalfCarryWillOcurr_8Bits(Registers reg, uint8_t valueToAdd, bool isAdd) {
    const auto registerValue{ registers_m.getRegister(reg) };

    if(isAdd) {
        registers_m.setFlag(Flags::H, (((registerValue & ByteMask) + (valueToAdd & ByteMask)) & HalfCarryByteMask_8Bits) != 0);
    }
    else {
        registers_m.setFlag(Flags::H, ((registerValue & ByteMask) < ((registerValue - valueToAdd) & ByteMask)));
    }
}

void CPU::setCarryIfCarryWillOcurr_8bits(CPU::Registers reg, uint8_t valueToAdd, bool isAdd) {
    const auto registerValue{ registers_m.getRegister(reg) };

    if(isAdd) {
        registers_m.setFlag(Flags::C, static_cast<uint8_t>(registerValue + valueToAdd) < registerValue);
    }
    else {
        registers_m.setFlag(Flags::C, (registerValue < valueToAdd));
    }
}

void CPU::setZeroFlagIfCombinedRegisterIsZero(CombinedRegisters reg) {
    registers_m.setFlag(Flags::Z, (registers_m.getCombinedRegister(reg) == 0));
}

void CPU::setHalfCarryIfHalfCarryWillOcurr_16Bits(CombinedRegisters reg, uint16_t valueToAdd, bool isAdd) {
    const auto registerValue{ registers_m.getCombinedRegister(reg) };

    if (isAdd) {
        registers_m.setFlag(Flags::H, ((registerValue & HalfCarryByteMask_16Bits) + (valueToAdd & HalfCarryByteMask_16Bits)) > HalfCarryByteMask_16Bits);
    }
    else {
        registers_m.setFlag(Flags::H, (registerValue & HalfCarryByteMask_16Bits) < (valueToAdd & HalfCarryByteMask_16Bits));
    }
}

void CPU::setCarryIfCarryWillOcurr_16bits(CombinedRegisters reg, uint16_t valueToAdd, bool isAdd) {
    const auto registerValue{ registers_m.getCombinedRegister(reg) };
    if (isAdd) {
        registers_m.setFlag(Flags::C, static_cast<uint16_t>(registerValue + valueToAdd) < registerValue);
    }
    else {
        registers_m.setFlag(Flags::C, (registerValue < valueToAdd));
    }
}

void CPU::initializeJPsOpcodes() noexcept {
    opcodeTable[JP_u16_Opcode] = &CPU::JP_u16;
}

// REMINDER: colocar en su lugar correcto
void CPU::initializeMiscellaneousOpcodes() noexcept {
    opcodeTable[LD_addressU16_A_Opcode] = &CPU::LD_addressU16_A;
    opcodeTable[LD_A_addressU16_Opcode] = &CPU::LD_A_addressU16;

    opcodeTable[NOP_Opcode] = &CPU::NOP;
}

void CPU::initialize_LD_RR_u16_Opcodes() noexcept {
    opcodeTable[LD_BC_u16_Opcode] = &CPU::LD_RR_u16<Registers::B, Registers::C>;
    opcodeTable[LD_DE_u16_Opcode] = &CPU::LD_RR_u16<Registers::D, Registers::E>;
    opcodeTable[LD_HL_u16_Opcode] = &CPU::LD_RR_u16<Registers::H, Registers::L>;
    opcodeTable[LD_SP_u16_Opcode] = &CPU::LD_RR_u16<Registers::SP_Up, Registers::SP_Low>;
}

void CPU::initialize_LD_addressRR_R_Opcodes() noexcept {
    opcodeTable[LD_address_BC_A_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::BC, Registers::A>;
    opcodeTable[LD_address_DE_A_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::DE, Registers::A>;
    opcodeTable[LD_address_HL_A_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::A>;
    opcodeTable[LD_address_HL_B_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::B>;
    opcodeTable[LD_address_HL_C_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::C>;
    opcodeTable[LD_address_HL_D_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::D>;
    opcodeTable[LD_address_HL_E_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::E>;
    opcodeTable[LD_address_HL_H_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::H>;
    opcodeTable[LD_address_HL_L_Opcode] = &CPU::LD_addressRR_R<CombinedRegisters::HL, Registers::L>;
}

void CPU::initialize_LD_R_addressRR_Opcodes() noexcept {
    opcodeTable[LD_A_address_BC_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::BC, Registers::A>;
    opcodeTable[LD_A_address_DE_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::DE, Registers::A>;
    opcodeTable[LD_A_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::A>;
    opcodeTable[LD_B_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::B>;
    opcodeTable[LD_C_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::C>;
    opcodeTable[LD_D_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::D>;
    opcodeTable[LD_E_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::E>;
    opcodeTable[LD_H_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::H>;
    opcodeTable[LD_L_address_HL_Opcode] = &CPU::LD_R_addressRR<CombinedRegisters::HL, Registers::L>;
}

void CPU::initialize_LD_addressHL_u8_Opcode() noexcept {
    opcodeTable[LD_address_HL_u8_Opcode] = &CPU::LD_addressHL_u8;
}

void CPU::initialize_LDI_LDD_Opcodes() noexcept {
    opcodeTable[LDI_address_HL_A_Opcode] = &CPU::LDI_addressHL_A;
    opcodeTable[LDD_address_HL_A_Opcode] = &CPU::LDD_addressHL_A;

    opcodeTable[LDI_A_address_HL_Opcode] = &CPU::LDI_A_addressHL;
    opcodeTable[LDD_A_address_HL_Opcode] = &CPU::LDD_A_addressHL;
}

void CPU::initialize_LD_SPs_HLs_Opcodes() noexcept {
    opcodeTable[LD_SP_HL_Opcode] = &CPU::LD_SP_HL;
    opcodeTable[LD_addressU16_SP_Opcode] = &CPU::LD_addressU16_SP;
}

void CPU::logicalOperation_A_R(CPU::Registers reg, LogicalOperations operation) {
    uint8_t registerAValue = registers_m.getRegister(Registers::A);
    uint8_t registerRValue = registers_m.getRegister(reg);
    uint8_t result{};
    
    switch(operation) {
        case LogicalOperations::AND:
            result = registerAValue & registerRValue;
            registers_m.setFlag(Flags::H, true);
            break;

        case LogicalOperations::OR:
            result = registerAValue | registerRValue;
            registers_m.setFlag(Flags::H, false);
            break;

        case LogicalOperations::XOR:
            result = registerAValue ^ registerRValue;
            registers_m.setFlag(Flags::H, false);
            break;
    }
    
    registers_m.setRegister(Registers::A, result);
    setZeroFlagIfRegisterIsZero(Registers::A);
    registers_m.setFlag(Flags::N, false);
    registers_m.setFlag(Flags::C, false);
}

void CPU::fetchOpcode() {
    const auto opcode{ read_PC_Address() };
    const auto& operation{ opcodeTable[opcode] };

    incrementPC();

    (this->*operation)();
}

void CPU::processNextOperation() {
    const auto& operation{ operationsQueue_m.front() };

    (this->*operation)();

    operationsQueue_m.pop();
}

void CPU::loadNextByteToLower() {
    registers_m.setRegister(Registers::AuxiliaryLow, read_PC_Address());
    incrementPC();
}

void CPU::loadNextByteToUpper() {
    registers_m.setRegister(Registers::AuxiliaryUp, read_PC_Address());
    incrementPC();
}

void CPU::from_addressU16_assignTo_PC() {
    setPC(registers_m.getCombinedRegister(CombinedRegisters::Auxiliary));
}

void CPU::from_U8_assignTo_addressHL() {
    memoryBus_m->write(registers_m.getCombinedRegister(CombinedRegisters::HL), registers_m.getRegister(Registers::AuxiliaryLow));
}

void CPU::from_HL_assignTo_SP() {
    registers_m.setCombinedRegister(CombinedRegisters::SP, registers_m.getCombinedRegister(CombinedRegisters::HL));
}

void CPU::fromAWriteToIORegisters(uint8_t offset) {
    const auto address{ 0xFF00 + offset };
    memoryBus_m->write(address, registers_m.getRegister(Registers::A));
}

void CPU::fromIORegistersWriteToA(uint8_t offset) {
    const auto address{ 0xFF00 + offset };
    registers_m.setRegister(Registers::A, memoryBus_m->read(address));
}

void CPU::from_A_assignTo_0xFF00PlusU8() {
    fromAWriteToIORegisters(registers_m.getRegister(Registers::AuxiliaryLow));
}

void CPU::from_A_assignTo_0xFF00PlusC() {
    fromAWriteToIORegisters(registers_m.getRegister(Registers::C));
}

void CPU::from_0xFF00PlusU8_assignTo_A() {
    fromIORegistersWriteToA(registers_m.getRegister(Registers::AuxiliaryLow));
}

void CPU::from_0xFF00PlusC_assignTo_A() {
    fromIORegistersWriteToA(registers_m.getRegister(Registers::C));
}

uint8_t CPU::read_PC_Address() const {
    return memoryBus_m->read(registers_m.getCombinedRegister(CombinedRegisters::PC));
}

void CPU::incrementPC() {
    registers_m.setCombinedRegister(CombinedRegisters::PC, registers_m.getCombinedRegister(CombinedRegisters::PC) + 1);
}

void CPU::setPC(uint16_t address) {
    registers_m.setCombinedRegister(CombinedRegisters::PC, address);
}

void CPU::addOrSubstractToRegister(Registers Register, uint8_t valueToAdd, bool isAdd, bool detectCarry) {
    setHalfCarryIfHalfCarryWillOcurr_8Bits(Register, valueToAdd, isAdd);

    if (detectCarry) {
        setCarryIfCarryWillOcurr_8bits(Register, valueToAdd, isAdd);
    }

    registers_m.setRegister(Register, registers_m.getRegister(Register) + (isAdd ? valueToAdd : -valueToAdd));

    setZeroFlagIfRegisterIsZero(Register);
    registers_m.setFlag(Flags::N, !isAdd);
}

void CPU::LD_addressU16_A() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_R_assignTo_addressU16<Registers::A>);
}

void CPU::LD_A_addressU16() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_addressU16_assignTo_R<Registers::A>);
}

void CPU::LD_addressHL_u8() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::from_U8_assignTo_addressHL);
}

void CPU::LDI_addressHL_A() {
    pushOperationsToQueue(&CPU::from_R_assignTo_addressRR_and_incrementOrDecrementRR<CombinedRegisters::HL, Registers::A, true>);
}

void CPU::LDD_addressHL_A() {
    pushOperationsToQueue(&CPU::from_R_assignTo_addressRR_and_incrementOrDecrementRR<CombinedRegisters::HL, Registers::A, false>);
}

void CPU::LDI_A_addressHL() {
   pushOperationsToQueue(&CPU::from_addressRR_assignTo_R_and_incrementOrDecrementRR<CombinedRegisters::HL, Registers::A, true>);
}

void CPU::LDD_A_addressHL() {
    pushOperationsToQueue(&CPU::from_addressRR_assignTo_R_and_incrementOrDecrementRR<CombinedRegisters::HL, Registers::A, false>);
}

void CPU::LD_SP_HL() {
    pushOperationsToQueue(&CPU::from_HL_assignTo_SP);
}

void CPU::LD_addressU16_SP() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_R_assignTo_addressU16<Registers::SP_Low, 0>,
        &CPU::from_R_assignTo_addressU16<Registers::SP_Up, 1>);
}

void CPU::LDH_A_addressU8() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::from_0xFF00PlusU8_assignTo_A);
}

void CPU::LD_A_addressC() {
    pushOperationsToQueue(&CPU::from_0xFF00PlusC_assignTo_A);
}

void CPU::LD_addressC_A() {
    pushOperationsToQueue(&CPU::from_A_assignTo_0xFF00PlusC);
}

void CPU::LDH_addressU8_A() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::from_A_assignTo_0xFF00PlusU8);
}

void CPU::INC_addressHL() {
    pushOperationsToQueue(
        &CPU::from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>,
        &CPU::addOrSubstractRegisterAndAssignToAddressRR<CombinedRegisters::HL, Registers::AuxiliaryLow, 1, true>
    );
}

void CPU::DEC_addressHL() {
    pushOperationsToQueue(
        &CPU::from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>,
        &CPU::addOrSubstractRegisterAndAssignToAddressRR<CombinedRegisters::HL, Registers::AuxiliaryLow, 1, false>
    );
}

void CPU::AND_A_u8() {
    loadNextByteToLower();
    pushOperationsToQueue(&CPU::AND_A_R<Registers::AuxiliaryLow>);
}

void CPU::AND_A_addressHL() {
    from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>();
    pushOperationsToQueue(&CPU::AND_A_R<Registers::AuxiliaryLow>);
}

void CPU::OR_A_u8() {
    loadNextByteToLower();
    pushOperationsToQueue(&CPU::OR_A_R<Registers::AuxiliaryLow>);
}

void CPU::OR_A_addressHL() {
    from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>();
    pushOperationsToQueue(&CPU::OR_A_R<Registers::AuxiliaryLow>);
}

void CPU::XOR_A_u8() {
    loadNextByteToLower();
    pushOperationsToQueue(&CPU::XOR_A_R<Registers::AuxiliaryLow>);
}

void CPU::XOR_A_addressHL() {
    from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>();
    pushOperationsToQueue(&CPU::XOR_A_R<Registers::AuxiliaryLow>);
}

void CPU::ADD_A_u8() {
    loadNextByteToLower();
    pushOperationsToQueue(&CPU::ADD_A_R<Registers::AuxiliaryLow>);
}

void CPU::ADD_A_addressHL() {
    from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>();
    pushOperationsToQueue(&CPU::ADD_A_R<Registers::AuxiliaryLow>);
}

void CPU::SUB_A_u8() {
    loadNextByteToLower();
    pushOperationsToQueue(&CPU::SUB_A_R<Registers::AuxiliaryLow>);
}

void CPU::SUB_A_addressHL() {
    from_addressRR_assignTo_R<CombinedRegisters::HL, Registers::AuxiliaryLow>();
    pushOperationsToQueue(&CPU::SUB_A_R<Registers::AuxiliaryLow>);
}

void CPU::CP_A_u8() {
    loadNextByteToLower();
    pushOperationsToQueue(&CPU::CP_A_R<Registers::AuxiliaryLow>);
}

void CPU::JP_u16() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_addressU16_assignTo_PC);
}

void CPU::NOP() {
    // NADA
}

void CPU::invalidOpcode() {
    throw std::runtime_error{ std::string{ "Invalid opcode: " } + std::to_string(read_PC_Address()) };
}
