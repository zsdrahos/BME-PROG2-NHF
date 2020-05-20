#include "tel.h"
#include "memtrace.h"
/// << operátor ami kírja a Teljes telefonszámot ostreamre
std::ostream& operator<<(std::ostream& os, const Tel& s0)
{
    os << s0.getTel();
    return os;
}
