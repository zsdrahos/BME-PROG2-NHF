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
 * Nevjegy oszt�ly deklar�ci�ja �s inline f�ggv�nyei
 */

class Nevjegy
{
private:
    Nev TeljesNev;      ///< Teljes n�v (N�v konstruktort�l f�gg�en teljes vagy csak a becen�v)
    Cim TeljesCim;      ///< Teljes c�m (C�m konstruktort�l f�gg�en az �sszes vagy csak az orsz�g, ir�ny�t�sz�m, v�ros)
    Tel TeljesTel;      ///< Teljes telefonsz�m (tel konstruktort�l f�gg�en mindkett� vagy csak a mag�n)
    String Email;
public:
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param n - nev
    /// @param c - cim
    /// @param t - telefonszam
    /// @param e - Email String
    Nevjegy(const Nev& n, const Cim& c, const Tel& t, String e)     :TeljesNev(Nev(n)), TeljesCim(Cim(c)), TeljesTel(Tel(t)), Email(String(e)) {}

    /// F�ggv�ny ami visszat�r a TeljesN�v �rt�kkel
    /// @return TeljesNev
    Nev getNev()
    {
        return TeljesNev;
    }
    /// F�ggv�ny ami visszat�r a TeljesCim �rt�kkel
    /// @return TeljesCim
    Cim getCim()
    {
        return TeljesCim;
    }
    /// F�ggv�ny ami visszat�r a TeljesTel �rt�kkel
    /// @return TeljesTel
    Tel getTel()
    {
        return TeljesTel;
    }
    /// Virtu�lis f�ggv�ny ami ki�rja az adatokat "\n"-el elv�lasztva ostreamre
    /// @param os - ostream
    /// @return os << TeljesNev << "\n" << TeljesCim << "\n" << TeljesTel <<  "\n" << Email << "\n" << std::endl
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << TeljesNev << "\n" << TeljesCim << "\n" << TeljesTel <<  "\n" << Email << "\n" << std::endl;
    }
    /// Virtu�lis f�ggv�ny ami ki�rja az csak a neveket
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
