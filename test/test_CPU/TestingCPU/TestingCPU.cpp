#include "TestingCPU.hpp"

void TestingCPU::processTCycle() {
    if (isOperationsQueueEmpty() && getCurrentTCycle() == 1) {
        printToLogFile();
    }

    CPU::processTCycle();
}

void TestingCPU::printToLogFile() noexcept {
    const auto registers{ getRegisters() };
    const auto pc_m{ getPC() };
    const auto sp_m{ getSP() };
    auto* memoryBus{ getMemoryBus() };

    std::stringstream stream;

    stream << std::hex << "A:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::A)) << " "
                       << "F:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::F)) << " "
                       << "B:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::B)) << " "
                       << "C:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::C)) << " "
                       << "D:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::D)) << " "
                       << "E:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::E)) << " "
                       << "H:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::H)) << " "
                       << "L:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(registers.getRegister(CPURegisters::Registers::L)) << " "

                       << "SP:" << std::setfill('0') << std::setw(4) << static_cast<uint16_t>(sp_m) << " "
                       << "PC:" << std::setfill('0') << std::setw(4) << static_cast<uint16_t>(pc_m) << " "

                       << "PCMEM:" << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(memoryBus->read(pc_m)) << "," 
                                   << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(memoryBus->read(pc_m + 1)) << "," 
                                   << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(memoryBus->read(pc_m + 2)) << "," 
                                   << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(memoryBus->read(pc_m + 3))
                       << "\n";
                    
    logFile_m.write(stream.str().c_str(), stream.str().size());
}
