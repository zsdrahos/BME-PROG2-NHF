#ifndef NEV_H
#define NEV_H

#include "string.h"
#include "memtrace.h"
/**
 * \file nev.h
 *
 * Nev osztály deklarációja és inline függvényei
 */


class Nev
{
protected:
    String vezeteknev;      ///< Vezetéknév
    String keresztnev;      ///< Keresztnév
    String becenev;         ///< Becenév
    int kontruktor_t;       ///< Segédváltozó a konstruktor attribútumok számának meghatározására
public:

    /// Konstruktor beállítja az attribútumokat
    /// @param k - keresztnév megnevezése
    /// @param v - vezetéknév megnevezése
    /// @param b - becenév megnevezése
    Nev(const char *v, const char *k, const char *b)         : vezeteknev(v), keresztnev(k), becenev(b)
    {
        kontruktor_t = 1;
    }

    /// Konstruktor beállítja az attribútumokat
    /// @param v - vezetéknév megnevezése
    /// @param k - keresztnév megnevezése
    Nev(const char *v, const char *k)                                       : vezeteknev(v), keresztnev(k)
    {
        kontruktor_t = 2;
    }

    /// Konstruktor beállítja az attribútumokat
    /// @param b - becenév megnevezése
    Nev(const char *b)                                                      : becenev(b)
    {
        kontruktor_t = 3;
    }
    /// Konstruktor beállítja az attribútumokat
    /// @param k - keresztnév megnevezése - String típusú
    /// @param v - vezetéknév megnevezése - String típusú
    /// @param b - becenév megnevezése - String típusú
    Nev(String v, String k, String b)         : vezeteknev(v), keresztnev(k), becenev(b)
    {
        kontruktor_t = 1;
    }

    /// Név lekérdezése értékadás alapján
    /// Mind a három adattagnak van értéke akkor visszatér a teljes névvel (közepén becenévvel)
    /// Ha csak a vezetéknév és a keresztnév van megadva akkor csak azzal a kettõvel tér vissza
    /// És ha csak a becenevet adjuk meg akkor csak a becenévvel tér vissza
    /// @return - ha kontruktor_t == 1 akkor vezeteknev + " \"" + becenev + "\" " + keresztnev
    /// @return - ha kontruktor_t == 2 akkor vezeteknev + " " + keresztnev
    /// @return - ha kontruktor_t == 3 akkor becenev
    String getTeljesnev() const
    {

        if (kontruktor_t == 1)
        {
            return vezeteknev + " \"" + becenev + "\" " + keresztnev;
        }
        if (kontruktor_t == 2)
        {
            return vezeteknev + " " +keresztnev;
        }
        else
        {
            return becenev;
        }
    }

    /// Attribútumok kiírása egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << getTeljesnev() << std::endl;
    }

    /// Két név egyezõségét vizsgálja konstrukor konstruktor paramétereinek száma alapján
    /// @param n - jobb oldali operandus
    /// @return true, ha egyezik a két név
    bool operator==(const Nev& n) const
    {
        if (kontruktor_t == 1)
        {
            return vezeteknev == n.vezeteknev && keresztnev == n.keresztnev && becenev == n.becenev;
        }
        if (kontruktor_t == 2)
        {
            return vezeteknev == n.vezeteknev && keresztnev == n.keresztnev;
        }
        else
        {
            return becenev == n.becenev;
        }

    }
    /// Adatok beolvasása istreamrõl
    /// @return Nev - beolvasott adatokkal
    Nev beolvas_nev()
    {
        String v = "";
        String k = "";
        String b = "";
        std::cout << "Vezetek: ";
        std::cin >> v;
        std::cout << "Kereszt: ";
        std::cin >> k;
        std::cout << "Bece: ";
        std::cin >> b;
        return Nev(v,k,b);
    }

    /// Virtuális destruktor
    virtual ~Nev() {}
};

/// kiír az ostream-re (printNev)
/// @param os - ostream típusú objektum
/// @param s0 - Nev, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const Nev& s0);


#endif
