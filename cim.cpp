#include "cim.h"
#include "memtrace.h"
/// << oper�tor ami ki�rja a Teljes C�met ostreamre
std::ostream& operator<<(std::ostream& os, const Cim& s0)
{
    os << s0.getTeljesCim();
    return os;
}

