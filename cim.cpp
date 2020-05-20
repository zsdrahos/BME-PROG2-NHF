#include "cim.h"
#include "memtrace.h"
/// << operátor ami kiírja a Teljes Címet ostreamre
std::ostream& operator<<(std::ostream& os, const Cim& s0)
{
    os << s0.getTeljesCim();
    return os;
}

