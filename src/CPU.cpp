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
    if (currentTCycle_m < 4) {
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
        const auto opcode{ readFromPC() };
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
    initialize_JP_Opcodes();
    initialize_LD_R_u8_Opcodes();
    initializeMisceallenousOpcodes();
    initialize_LD_RR_u16_Opcodes();
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

uint16_t CPU::combineBytes(uint8_t lowerByte, uint8_t higherByte) noexcept {
    return (static_cast<uint16_t>(higherByte) << ByteDisplacement) | lowerByte;
}

// REMINDER: colocar en su lugar correcto
void CPU::initializeMisceallenousOpcodes() noexcept {
    opcodeTable[LD_addressU16_A_Opcode] = &CPU::LD_addressU16_A;
    opcodeTable[NOP_Opcode] = &CPU::NOP;
}

void CPU::initialize_LD_RR_u16_Opcodes() noexcept {
    opcodeTable[LD_BC_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::B, CPU::Registers::C>;
    opcodeTable[LD_DE_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::D, CPU::Registers::E>;
    opcodeTable[LD_HL_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::H, CPU::Registers::L>;
    opcodeTable[LD_SP_u16_Opcode] = &CPU::LD_RR_u16<CPU::Registers::SP_Up, CPU::Registers::SP_Low>;
}

void CPU::initialize_LD_addressRR_R_Opcodes() noexcept {
    opcodeTable[LD_address_BC_A_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::B, CPU::Registers::C, CPU::Registers::A>;
    opcodeTable[LD_address_DE_A_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::D, CPU::Registers::E, CPU::Registers::A>;
    opcodeTable[LD_address_HL_A_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::A>;
    opcodeTable[LD_address_HL_B_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::B>;
    opcodeTable[LD_address_HL_C_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::C>;
    opcodeTable[LD_address_HL_D_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::D>;
    opcodeTable[LD_address_HL_E_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::E>;
    opcodeTable[LD_address_HL_H_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::H>;
    opcodeTable[LD_address_HL_L_Opcode] = &CPU::LD_addressRR_R<CPU::Registers::H, CPU::Registers::L, CPU::Registers::L>;
}

void CPU::readNextByteAsLowerByte() {
    incrementPC();
    lowerByteAuxiliaryRegister_m = readFromPC();
}

void CPU::readNextByteAsHigherByte() {
    incrementPC();
    higherByteAuxiliaryRegister_m = readFromPC();
}

void CPU::asign_addressU16_from_A() {
    const auto address{ combineBytes(lowerByteAuxiliaryRegister_m, higherByteAuxiliaryRegister_m) };
    memoryBus_m->write(address, registers_m.getRegister(CPURegisters::Registers::A));
    incrementPC();
}

void CPU::assign_PC_from_u16() {
    setPC(combineBytes(lowerByteAuxiliaryRegister_m, higherByteAuxiliaryRegister_m));
}

uint8_t CPU::readFromPC() const {
    return memoryBus_m->read(registers_m.getCombinedRegister(CombinedRegisters::PC));
}

void CPU::incrementPC() {
    registers_m.setCombinedRegister(CPURegisters::CombinedRegisters::PC, registers_m.getCombinedRegister(CombinedRegisters::PC) + 1);
}

void CPU::setPC(uint16_t address) {
    registers_m.setCombinedRegister(CombinedRegisters::PC, address);
}

void CPU::LD_addressU16_A() {
    operationsQueue_m.push(&CPU::readNextByteAsLowerByte);
    operationsQueue_m.push(&CPU::readNextByteAsHigherByte);
    operationsQueue_m.push(&CPU::asign_addressU16_from_A);
}

void CPU::JP_u16() {
    operationsQueue_m.push(&CPU::readNextByteAsLowerByte);
    operationsQueue_m.push(&CPU::readNextByteAsHigherByte);
    operationsQueue_m.push(&CPU::assign_PC_from_u16);
}

void CPU::NOP() {
    // NADA
    incrementPC();
}

void CPU::invalidOpcode() {
    throw std::runtime_error{ std::string{ "Invalid opcode: " } + std::to_string(readFromPC()) };
}
