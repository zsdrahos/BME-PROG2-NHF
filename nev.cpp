#include "nev.h"
#include "memtrace.h"
/// << operátor ami kiírja a Teljes nevet ostreamre
std::ostream& operator<<(std::ostream& os, const Nev& s0)
{
    os << s0.getTeljesnev();
    return os;
}
