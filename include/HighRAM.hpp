#ifndef HIGH_RAM_HPP
#define HIGH_RAM_HPP

#include "MemoryMap.hpp"
#include <array>
#include <string>
#include <stdexcept>
#include "AddressMaper.hpp"

class HighRAM : public AddressMapper<High_RAM_Start_Address, High_RAM_End_Address> {
};

#endif // !HIGH_RAM_HPP