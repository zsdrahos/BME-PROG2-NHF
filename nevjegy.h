#ifndef NEVJEGY_H
#define NEVJEGY_H

#include "nev.h"
#include "string.h"
#include "cim.h"
#include "tel.h"
#include "memtrace.h"
/**
 * \file nevjegy.h
 *
 * Nevjegy osztály deklarációja és inline függvényei
 */

class Nevjegy
{
private:
    Nev TeljesNev;      ///< Teljes név (Név konstruktortól függõen teljes vagy csak a becenév)
    Cim TeljesCim;      ///< Teljes cím (Cím konstruktortól függõen az összes vagy csak az ország, irányítószám, város)
    Tel TeljesTel;      ///< Teljes telefonszám (tel konstruktortól függõen mindkettõ vagy csak a magán)
    String Email;
public:
    /// Konstruktor beállítja az attribútumokat
    /// @param n - nev
    /// @param c - cim
    /// @param t - telefonszam
    /// @param e - Email String
    Nevjegy(const Nev& n, const Cim& c, const Tel& t, String e)     :TeljesNev(Nev(n)), TeljesCim(Cim(c)), TeljesTel(Tel(t)), Email(String(e)) {}

    /// Függvény ami visszatér a TeljesNév értékkel
    /// @return TeljesNev
    Nev getNev()
    {
        return TeljesNev;
    }
    /// Függvény ami visszatér a TeljesCim értékkel
    /// @return TeljesCim
    Cim getCim()
    {
        return TeljesCim;
    }
    /// Függvény ami visszatér a TeljesTel értékkel
    /// @return TeljesTel
    Tel getTel()
    {
        return TeljesTel;
    }
    /// Virtuális függvény ami kiírja az adatokat "\n"-el elválasztva ostreamre
    /// @param os - ostream
    /// @return os << TeljesNev << "\n" << TeljesCim << "\n" << TeljesTel <<  "\n" << Email << "\n" << std::endl
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << TeljesNev << "\n" << TeljesCim << "\n" << TeljesTel <<  "\n" << Email << "\n" << std::endl;
    }
    /// Virtuális függvény ami kiírja az csak a neveket
    /// @param os - ostream
    /// @return os << TeljesNev << "\n" << std::endl
    virtual std::ostream& print_nev(std::ostream& os) const
    {
        return os << TeljesNev << "\n" << std::endl;
    }


    /// Destruktor
    virtual ~Nevjegy() {}

};
#endif
