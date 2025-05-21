#ifndef TEST_HEADERS_HPP
#define TEST_HEADERS_HPP

#include "Cartridge.hpp"
#include "CPU.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include "TestingCPU.hpp"
#include <vector>

// Estructura para representar el estado esperado de las banderas
struct FlagTestState {
    std::string description;  // Descripción para identificar esta prueba
    uint16_t additionalCycles; // Ciclos a ejecutar antes de comprobar (desde los ciclos mínimos)
    bool z;  // Valor esperado para flag Zero
    bool h;  // Valor esperado para flag Half Carry
    bool n;  // Valor esperado para flag Negative
    bool c;  // Valor esperado para flag Carry
};

// Estructura que contiene todos los parámetros de configuración para una prueba
struct CPUOpCodeTestConfig {
    std::string_view cartridgePath;
    uint16_t minimumTCyclesNeeded;
    std::vector<uint8_t> expectedValues;
    uint16_t baseAddress = 0xA000;  // Dirección base para leer valores
    uint8_t cycleBetweenFlagTests = 0; // Ciclos entre pruebas de flags (0 si no aplica)
    std::vector<FlagTestState> flagTests; // Lista de pruebas de flags a realizar
};

// Clase base para todas las pruebas de operaciones de CPU
class CPUOpCodeTestBase : public ::testing::Test {
protected:
    const CPUOpCodeTestConfig config_m;
    
    Cartridge cartridge_m;
    VideoRAM videoRAM_m;
    WorkingRAM workingRAM_m;
    HighRAM highRAM_m;
    EchoRAM echoRAM_m;

    MemoryBus memorybus_m;
    TestingCPU cpu_m;

    // Constructor que recibe la configuración
    explicit CPUOpCodeTestBase(const CPUOpCodeTestConfig& config) 
        : config_m(config),
          cartridge_m(config.cartridgePath),
          echoRAM_m(&workingRAM_m),
          memorybus_m(&cartridge_m, &workingRAM_m, &highRAM_m, &echoRAM_m, &videoRAM_m),
          cpu_m(&memorybus_m) {}

    void SetUp() override {
        for (size_t i = 0; i < config_m.minimumTCyclesNeeded; ++i) {
            cpu_m.processTCycle();
        }
    }

    // Método común para procesar ciclos adicionales
    void processTCycles(uint16_t cycles) {
        for (size_t i = 0; i < cycles; ++i) {
            cpu_m.processTCycle();
        }
    }
    
    // Método para verificar un estado específico de banderas
    void verifyFlags(bool z, bool h, bool n, bool c) {
        EXPECT_EQ(z, cpu_m.getRegisters().getFlag(CPURegisters::Flags::Z)) << "Z flag mismatch";
        EXPECT_EQ(h, cpu_m.getRegisters().getFlag(CPURegisters::Flags::H)) << "H flag mismatch";
        EXPECT_EQ(n, cpu_m.getRegisters().getFlag(CPURegisters::Flags::N)) << "N flag mismatch";
        EXPECT_EQ(c, cpu_m.getRegisters().getFlag(CPURegisters::Flags::C)) << "C flag mismatch";
    }
};

// Macro para definir una nueva clase de prueba para una operación específica
#define DEFINE_OPCODE_TEST_CLASS(className, configVar) \
class className : public CPUOpCodeTestBase { \
protected: \
    className() : CPUOpCodeTestBase(configVar) {} \
};

// Macro para crear la prueba básica que verifica los valores esperados
#define DEFINE_BASIC_VALUE_TEST(className, testName) \
TEST_F(className, testName) { \
    for (size_t i = 0; i < config_m.expectedValues.size(); ++i) { \
        const auto address = config_m.baseAddress + i; \
        const auto value = memorybus_m.read(address); \
        EXPECT_EQ(value, config_m.expectedValues[i]); \
    } \
}

// Macro para generar todas las pruebas de flags configuradas
#define DEFINE_ALL_FLAG_TESTS(className, baseTestName) \
TEST_F(className, baseTestName) { \
    uint16_t currentCycle = 0; \
    for (const auto& flagTest : config_m.flagTests) { \
        processTCycles(flagTest.additionalCycles - currentCycle); \
        currentCycle = flagTest.additionalCycles; \
        verifyFlags(flagTest.z, flagTest.h, flagTest.n, flagTest.c); \
    } \
}

// Macro para pruebas de flags individuales para casos más específicos
#define DEFINE_FLAG_TEST(className, testName, index) \
TEST_F(className, testName) { \
    ASSERT_LT(index, config_m.flagTests.size()) << "Flag test index out of range"; \
    const auto& flagTest = config_m.flagTests[index]; \
    processTCycles(flagTest.additionalCycles); \
    verifyFlags(flagTest.z, flagTest.h, flagTest.n, flagTest.c); \
}

// Macro alternativo para definir tests de flags individuales de forma explícita
#define DEFINE_INDIVIDUAL_FLAG_TEST(className, testName, cycles, Z, H, N, C) \
TEST_F(className, testName) { \
    processTCycles(cycles); \
    verifyFlags(Z, H, N, C); \
}

#endif // !TEST_HEADERS_HPP