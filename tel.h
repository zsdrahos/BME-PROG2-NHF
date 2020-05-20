#ifndef TEL_H
#define TEL_H

#include "string.h"
#include "memtrace.h"
/**
 * \file tel.h
 *
 * Tel osztály deklarációja és inline függvényei
 */

class Tel
{
protected:
    String munkahelyi;              ///< Munkahelyi telefonszám
    String magan;                   ///< Magán telefonszám
    bool kontruktor_t;              ///< Segédváltozó a konstruktor attribútumok számának meghatározására
public:
    /// Konstruktor beállítja az attribútumokat
    /// @param munk - munkahelyi telefonszám megnevezése
    /// @param mag - magán telefonszám megnevezése
    Tel(const char *munk, const char *mag)         :munkahelyi(munk), magan(mag)
    {
        kontruktor_t = true;
    }
    /// Konstruktor beállítja az attribútumokat
    /// @param mag - magán telefonszám megnevezése
    Tel(const char *mag)                           :magan(mag)
    {
        kontruktor_t = false;
    }
    /// Konstruktor beállítja az attribútumokat
    /// @param munk - String típusú
    /// @param mag - String típusú
    Tel(String munk, String mag)         :munkahelyi(munk), magan(mag)
    {
        kontruktor_t = true;
    }


    /// Telefonszám lekérdezése értékadás alapján
    /// Munkahelyi és magán telefonszámmal való visszatérés
    /// Illetve csak magán telefonszámmal való visszatérés
    /// @return - ha kontruktor_t == true akkor munkahelyi + " / " + magan;
    /// @return - ha kontruktor_t == false akkor magan
    String getTel() const
    {
        if (kontruktor_t)
        {
            return munkahelyi + " / " + magan;
        }
        else
        {
            return magan;
        }
    }

    /// Attribútumok kiírása egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << getTel() << std::endl;
    }

    /// Két Telefonszám egyezõségét vizsgálja konstruktor paramétereinek száma alapján
    /// @param t - jobb oldali operandus
    /// @return true, ha egyezik a két telefonszám
    bool operator==(const Tel& t) const
    {
        if (kontruktor_t)
        {
            return munkahelyi == t.munkahelyi && magan == t.magan;
        }
        else
        {
            return magan == t.magan;
        }

    }
    /// Adatok beolvasása istreamrõl
    /// @return Tel - beolvasott adatokkal
    Tel beolvas_tel()
    {
        String munk = "";
        String mag = "";
        std::cout << "Munkahelyi: ";
        std::cin >> munk;
        std::cout << "Magan: ";
        std::cin >> mag;

        return Tel(munk, mag);
    }

    /// Virtuális destruktor
    virtual ~Tel() {}
};
/// kiír az ostream-re (printTel)
/// @param os - ostream típusú objektum
/// @param s0 - Tel, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const Tel& s0) ;

#endif
