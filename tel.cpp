#include "tel.h"
#include "memtrace.h"
/// << oper�tor ami k�rja a Teljes telefonsz�mot ostreamre
std::ostream& operator<<(std::ostream& os, const Tel& s0)
{
    os << s0.getTel();
    return os;
}
