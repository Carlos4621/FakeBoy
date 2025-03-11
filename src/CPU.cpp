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
        const auto& operation{ operationsQueue_m.front() };

        (this->*operation)();

        operationsQueue_m.pop();
    }
    else {
        const auto opcode{ read_PC_Address() };
        const auto& operation{ opcodeTable[opcode] };

        (this->*operation)();
    }
}

uint16_t CPU::getPC() const noexcept {
    return registers_m.getCombinedRegister(CPURegisters::CombinedRegisters::PC);
}

uint16_t CPU::getSP() const noexcept {
    return registers_m.getCombinedRegister(CPURegisters::CombinedRegisters::SP);
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

    initialize_LD_R_R_Opcodes();
    initialize_LD_R_u8_Opcodes();
    initialize_LD_RR_u16_Opcodes();
    initialize_LD_R_addressRR_Opcodes();
    initialize_LD_addressRR_R_Opcodes();
    initialize_LD_addressHL_u8_Opcode();
    initialize_LDI_LDD_Opcodes();
    initialize_LD_SPs_HLs_Opcodes();
    initialize_LDH_Opcodes();

    initialize_JP_Opcodes();
    initializeMiscellaneousOpcodes();
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

void CPU::initialize_JP_Opcodes() noexcept {
    opcodeTable[JP_u16_Opcode] = &CPU::JP_u16;
}

uint16_t CPU::combineBytes(uint8_t hightByte, uint8_t lowByte) noexcept {
    return (static_cast<uint16_t>(hightByte) << ByteDisplacement) | lowByte;
}

void CPU::initialize_LDH_Opcodes() {
    opcodeTable[LDH_A_addressU8_Opcode] = &CPU::LDH_A_addressU8;
    opcodeTable[LDH_addressU8_A_Opcode] = &CPU::LDH_addressU8_A;
    opcodeTable[LD_A_addressC_Opcode] = &CPU::LD_A_addressC;
    opcodeTable[LD_addressC_A_Opcode] = &CPU::LD_addressC_A;
}

// REMINDER: colocar en su lugar correcto
void CPU::initializeMiscellaneousOpcodes() noexcept {
    opcodeTable[LD_addressU16_A_Opcode] = &CPU::LD_addressU16_A;
    opcodeTable[LD_A_addressU16_Opcode] = &CPU::LD_A_addressU16;

    opcodeTable[NOP_Opcode] = &CPU::NOP;
}

void CPU::initialize_LD_RR_u16_Opcodes() noexcept {
    opcodeTable[LD_BC_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::B, CPU::Registers::C>;
    opcodeTable[LD_DE_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::D, CPU::Registers::E>;
    opcodeTable[LD_HL_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::H, CPU::Registers::L>;
    opcodeTable[LD_SP_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::SP_Up, CPU::Registers::SP_Low>;
}

void CPU::initialize_LD_addressRR_R_Opcodes() noexcept {
    opcodeTable[LD_address_BC_A_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::BC, CPU::Registers::A>;
    opcodeTable[LD_address_DE_A_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::DE, CPU::Registers::A>;
    opcodeTable[LD_address_HL_A_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::A>;
    opcodeTable[LD_address_HL_B_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::B>;
    opcodeTable[LD_address_HL_C_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::C>;
    opcodeTable[LD_address_HL_D_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::D>;
    opcodeTable[LD_address_HL_E_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::E>;
    opcodeTable[LD_address_HL_H_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::H>;
    opcodeTable[LD_address_HL_L_Opcode] = &CPU::LD_addressRR_R<CPU::CombinedRegisters::HL, CPU::Registers::L>;
}

void CPU::initialize_LD_R_addressRR_Opcodes() noexcept {
    opcodeTable[LD_A_address_BC_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::BC, CPU::Registers::A>;
    opcodeTable[LD_A_address_DE_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::DE, CPU::Registers::A>;
    opcodeTable[LD_A_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::A>;

    opcodeTable[LD_B_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::B>;
    opcodeTable[LD_C_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::C>;
    opcodeTable[LD_D_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::D>;
    opcodeTable[LD_E_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::E>;
    opcodeTable[LD_H_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::H>;
    opcodeTable[LD_L_address_HL_Opcode] = &CPU::LD_R_addressRR<CPU::CombinedRegisters::HL, CPU::Registers::L>;
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

void CPU::loadNextByteToLower() {
    incrementPC();
    lowerByteAuxiliaryRegister_m = read_PC_Address();
}

void CPU::loadNextByteToUpper() {
    incrementPC();
    higherByteAuxiliaryRegister_m = read_PC_Address();
}

void CPU::from_A_assignTo_addressU16() {
    const auto address{ combineBytes(higherByteAuxiliaryRegister_m, lowerByteAuxiliaryRegister_m) };
    memoryBus_m->write(address, registers_m.getRegister(CPURegisters::Registers::A));
    incrementPC();
}

void CPU::from_addressU16_assignTo_A() {
    const auto address{ combineBytes(higherByteAuxiliaryRegister_m, lowerByteAuxiliaryRegister_m) };
    registers_m.setRegister(CPURegisters::Registers::A, memoryBus_m->read(address));
    incrementPC();
}

void CPU::from_addressU16_assignTo_PC() {
    setPC(combineBytes(higherByteAuxiliaryRegister_m, lowerByteAuxiliaryRegister_m));
}

void CPU::from_U8_assignTo_addressHL() {
    memoryBus_m->write(registers_m.getCombinedRegister(CPU::CombinedRegisters::HL), lowerByteAuxiliaryRegister_m);
    incrementPC();
}

void CPU::from_HL_assignTo_SP() {
    registers_m.setCombinedRegister(CPU::CombinedRegisters::SP, registers_m.getCombinedRegister(CPU::CombinedRegisters::HL));
    incrementPC();
}

void CPU::fromAWriteToIORegisters(uint8_t offset) {
    const auto address{ 0xFF00 + offset };
    memoryBus_m->write(address, registers_m.getRegister(Registers::A));
    incrementPC();
}

void CPU::fromIORegistersWriteToA(uint8_t offset) {
    const auto address{ 0xFF00 + offset };
    registers_m.setRegister(Registers::A, memoryBus_m->read(address));
    incrementPC();
}

void CPU::from_A_assignTo_0xFF00PlusU8() {
    fromAWriteToIORegisters(lowerByteAuxiliaryRegister_m);
}

void CPU::from_A_assignTo_0xFF00PlusC() {
    fromAWriteToIORegisters(registers_m.getRegister(CPURegisters::Registers::C));
}

void CPU::from_0xFF00PlusU8_assignTo_A() {
    fromIORegistersWriteToA(lowerByteAuxiliaryRegister_m);
}

void CPU::from_0xFF00PlusC_assignTo_A() {
    fromIORegistersWriteToA(registers_m.getRegister(CPURegisters::Registers::C));
}

uint8_t CPU::read_PC_Address() const {
    return memoryBus_m->read(registers_m.getCombinedRegister(CombinedRegisters::PC));
}

void CPU::incrementPC() {
    registers_m.setCombinedRegister(CPURegisters::CombinedRegisters::PC, registers_m.getCombinedRegister(CombinedRegisters::PC) + 1);
}

void CPU::setPC(uint16_t address) {
    registers_m.setCombinedRegister(CombinedRegisters::PC, address);
}

void CPU::LD_addressU16_A() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_A_assignTo_addressU16);
}

void CPU::LD_A_addressU16() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_addressU16_assignTo_A);
}

void CPU::LD_addressHL_u8() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::from_U8_assignTo_addressHL);
}

void CPU::LDI_addressHL_A() {
    pushOperationsToQueue(&CPU::from_R_assignTo_addressHL_and_incrementOrDecrementRR<CPU::CombinedRegisters::HL, CPU::Registers::A, false>);
}

void CPU::LDD_addressHL_A() {
    pushOperationsToQueue(&CPU::from_R_assignTo_addressHL_and_incrementOrDecrementRR<CPU::CombinedRegisters::HL, CPU::Registers::A, true>);
}

void CPU::LDI_A_addressHL() {
   pushOperationsToQueue(&CPU::from_addressHL_assignTo_R_and_incrementOrDecrementRR<CPU::CombinedRegisters::HL, CPU::Registers::A, false>);
}

void CPU::LDD_A_addressHL() {
    pushOperationsToQueue(&CPU::from_addressHL_assignTo_R_and_incrementOrDecrementRR<CPU::CombinedRegisters::HL, CPU::Registers::A, true>);
}

void CPU::LD_SP_HL() {
    pushOperationsToQueue(&CPU::from_HL_assignTo_SP);
}

void CPU::LD_addressU16_SP() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_SPLow_or_SpUp_assignTo_addressU16<CPU::Registers::SP_Low, 0>,
        &CPU::from_addressU16_assignTo_SPLow_or_SPUp_and_increment<CPU::Registers::SP_Up, 1>);
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

void CPU::JP_u16() {
    pushOperationsToQueue(
        &CPU::loadNextByteToLower,
        &CPU::loadNextByteToUpper,
        &CPU::from_addressU16_assignTo_PC);
}

void CPU::NOP() {
    // NADA
    incrementPC();
}

void CPU::invalidOpcode() {
    throw std::runtime_error{ std::string{ "Invalid opcode: " } + std::to_string(read_PC_Address()) };
}
