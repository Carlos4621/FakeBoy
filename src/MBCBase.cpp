#include "MBCBase.hpp"

bool MBCBase::isRAM_enabled() const noexcept {
    return RAM_enabled_m;
}

void MBCBase::enableRAM() noexcept {
    RAM_enabled_m = true;
}

void MBCBase::disableRAM() noexcept {
    RAM_enabled_m = false;
}
