#ifndef TELELFONKONYV_H
#define TELELFONKONYV_H
#include <iostream>
#include "string.h"
#include "nevjegy.h"
#include "gen.hpp"
#include "memtrace.h"

/**
 * \file telefonkonyv.h
 *
 * Telefonkonyv osztály deklarációja és inline függvényei
 */

class Telefonkonyv
{
    GenTomb<Nevjegy*> ember;        ///< névjegy adatai ami egy generikus tömbben van eltárolva
public:
    /// Függvény ami meghívja a push függvényt és hozzáad egy névjegy-et a tömbhöz
    /// @param n - Névjegy típusú pointer
    void Hozzaad (Nevjegy* n);
    /// Függvény ami meghívja a pop függvényt és töröl egy névjegy-et a tömbbõl
    /// @param n - Névjegy típusú pointer
    void Tororl (Nevjegy* n);
    /// Függgvény ami ostreamre kiírja az összes adatot ami a tömbben található
    /// @param os - ostream
    void listaz (std::ostream& os);
    /// Függvény ami ostreamre kiírja az összes embernek csak a nevét
    /// @param os - ostream
    void listaz_nev (std::ostream& os);
    /// Függvény ami megmondja, hogy hány névjegy található a tömbben
    /// @return ember.GetHossz - GenTömb hosszával
    int darab()
    {
        return ember.GetHossz();
    }

    /// Függvény ami kikeresi a tömbben az adott nevet és kiírja ostreamre
    /// A függvény figyelembe veszi hogy hány adat van megadva, így tehát képesek vagyunk csak becenév vagy kereszt és vezetéknév alapján keresni.
    /// @param n - Név típus
    /// @param os - ostream
    void KeresNev(const Nev& n, std::ostream& os);
    /// Függvény ami kikeresi a tömbben az adott telefonszámot és kiírja ostreamre
    /// A függvény figyelembe veszi hogy hány adat van megadva, így tehát képesek vagyunk csak magán telefonszám alapján keresni.
    /// @param t - Tel típus
    /// @param os - ostream
    void KeresTel(const Tel& t, std::ostream& os);
    /// Függvény ami kikeresi a tömbben az adott címet és kiírja ostreamre
    /// A függvény figyelembe veszi hogy hány adat van megadva, így tehát képesek vagyunk csak ország alapján keresni. Továbbá képesek vagyunk csak irányítószám és város megadásával keresni is.
    /// @param c - Cim típus
    /// @param os - ostream
    void KeresCim(const Cim& c, std::ostream& os);
};
#endif
