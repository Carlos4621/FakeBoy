#pragma once
#ifndef TESTING_CPU_HPP
#define TESTING_CPU_HPP

#include "CPU.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

class TestingCPU : public CPU {
public:
    using CPU::CPU;
    
    void processTCycle();

    using CPU::getRegisters;

private:
    void printToLogFile() noexcept;

    std::ofstream logFile_m{ "log", std::ios::out };

};

#endif // !TESTING_CPU_HPP