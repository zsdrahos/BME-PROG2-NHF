#ifndef CIM_H
#define CIM_H

#include "string.h"
#include "memtrace.h"
/**
 * \file cim.h
 *
 * Cim osztály deklarációja és inline függvényei
 */

class Cim
{
protected:
    String orszag;                  ///< Ország
    String iranyitoszam;            ///< Irányírószám
    String varos;                   ///< Város
    String utca;                    ///< Utca
    String hazszam;                 ///< Házszám
    int kontruktor_t;               ///< Segédváltozó a konstruktor attribútumok számának meghatározására
public:

    /// Konstruktor beállítja az attribútumokat
    /// @param o - ország megnevezése
    /// @param i - irányítószám megnevezése
    /// @param v - város megnevezése
    /// @param u - utca megnevezése
    /// @param h - házszám megnevezése
    Cim(const char *o, const char * i, const char *v, const char *u, const char * h)         : orszag(o), iranyitoszam(i), varos(v), utca(u), hazszam(h)
    {
        kontruktor_t = 1;
    }

    /// Konstruktor beállítja az attribútumokat
    /// @param o - ország megnevezése
    Cim (const char *o)                                                                      : orszag(o)
    {
        kontruktor_t = 2;
    }

    /// Konstruktor beállítja az attribútumokat
    /// @param i - irányítószám megnevezése
    /// @param v - város megnevezése
    Cim (const char *i, const char *v)                                                       : iranyitoszam(i), varos(v)
    {
        kontruktor_t = 3;
    }
    /// Konstruktor beállítja az attribútumokat
    /// @param o - String típusú
    /// @param i - String típusú
    /// @param v - String típusú
    /// @param u - String típusú
    /// @param h - String típusú
    Cim(String o, String i,String v, String u, String h)         : orszag(o), iranyitoszam(i), varos(v), utca(u), hazszam(h)
    {
        kontruktor_t = 1;
    }

    /// Teljes cím lekérdezése konstruktor paramétereinek száma alapján
    /// Minden adattag: teljes cím vesszõvel elválasztva
    /// Csak országgal
    /// Csak Irányírószámmal és városnévvel
    /// @return - ha kontruktor_t == 1 akkor orszag + ", " + iranyitoszam + ", " + varos + ", " + utca + " " + hazszam
    /// @return - ha kontruktor_t == 2 akkor orszag
    /// @return - ha kontruktor_t == 3 akkor iranyitoszam + ", "+  varos
    String getTeljesCim() const
    {
        if (kontruktor_t == 1)
        {
            return orszag + ", " + iranyitoszam + ", " + varos + ", " + utca + " " + hazszam;
        }
        if (kontruktor_t == 2)
        {
            return orszag;
        }
        else
        {
            return iranyitoszam + ", "+  varos;
        }

    }


    /// Attribútumok kiírása egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << getTeljesCim() << std::endl;
    }

    /// Két cím egyezõségét vizsgálja
    /// @param c - jobb oldali operandus
    /// @return true, ha egyezik a két név
    bool operator==(const Cim& c) const
    {
        if (kontruktor_t == 1)
        {
            return orszag == c.orszag && iranyitoszam == c.iranyitoszam && varos == c.varos && utca == c.utca && hazszam == c.hazszam;
        }
        if (kontruktor_t == 2)
        {
            return orszag == c.orszag;
        }
        else
        {
            return iranyitoszam == c.iranyitoszam && varos == c.varos;
        }


    }
    /// Adatok beolvasása istreamrõl
    /// @return Cim - beolvasott adatokkal
    Cim beolvas_cim()
    {
        String o = "";
        String i = "";
        String v = "";
        String u = "";
        String h = "";
        std::cout << "Orszag: ";
        std::cin >> o;
        std::cout << "Iranyitoszam: ";
        std::cin >> i;
        std::cout << "Varos: ";
        std::cin >> v;
        std::cout << "Utca: ";
        std::cin >> u;
        std::cout << "Hazszam: ";
        std::cin >> h;
        return Cim(o,i,v, u, h);
    }

    /// Virtuális destruktor
    virtual ~Cim() {}
};

/// kiír az ostream-re (printCim)
/// @param os - ostream típusú objektum
/// @param s0 - Cim, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const Cim& s0);

#endif
