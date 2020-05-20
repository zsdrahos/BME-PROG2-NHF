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
 * Telefonkonyv oszt�ly deklar�ci�ja �s inline f�ggv�nyei
 */

class Telefonkonyv
{
    GenTomb<Nevjegy*> ember;        ///< n�vjegy adatai ami egy generikus t�mbben van elt�rolva
public:
    /// F�ggv�ny ami megh�vja a push f�ggv�nyt �s hozz�ad egy n�vjegy-et a t�mbh�z
    /// @param n - N�vjegy t�pus� pointer
    void Hozzaad (Nevjegy* n);
    /// F�ggv�ny ami megh�vja a pop f�ggv�nyt �s t�r�l egy n�vjegy-et a t�mbb�l
    /// @param n - N�vjegy t�pus� pointer
    void Tororl (Nevjegy* n);
    /// F�gggv�ny ami ostreamre ki�rja az �sszes adatot ami a t�mbben tal�lhat�
    /// @param os - ostream
    void listaz (std::ostream& os);
    /// F�ggv�ny ami ostreamre ki�rja az �sszes embernek csak a nev�t
    /// @param os - ostream
    void listaz_nev (std::ostream& os);
    /// F�ggv�ny ami megmondja, hogy h�ny n�vjegy tal�lhat� a t�mbben
    /// @return ember.GetHossz - GenT�mb hossz�val
    int darab()
    {
        return ember.GetHossz();
    }

    /// F�ggv�ny ami kikeresi a t�mbben az adott nevet �s ki�rja ostreamre
    /// A f�ggv�ny figyelembe veszi hogy h�ny adat van megadva, �gy teh�t k�pesek vagyunk csak becen�v vagy kereszt �s vezet�kn�v alapj�n keresni.
    /// @param n - N�v t�pus
    /// @param os - ostream
    void KeresNev(const Nev& n, std::ostream& os);
    /// F�ggv�ny ami kikeresi a t�mbben az adott telefonsz�mot �s ki�rja ostreamre
    /// A f�ggv�ny figyelembe veszi hogy h�ny adat van megadva, �gy teh�t k�pesek vagyunk csak mag�n telefonsz�m alapj�n keresni.
    /// @param t - Tel t�pus
    /// @param os - ostream
    void KeresTel(const Tel& t, std::ostream& os);
    /// F�ggv�ny ami kikeresi a t�mbben az adott c�met �s ki�rja ostreamre
    /// A f�ggv�ny figyelembe veszi hogy h�ny adat van megadva, �gy teh�t k�pesek vagyunk csak orsz�g alapj�n keresni. Tov�bb� k�pesek vagyunk csak ir�ny�t�sz�m �s v�ros megad�s�val keresni is.
    /// @param c - Cim t�pus
    /// @param os - ostream
    void KeresCim(const Cim& c, std::ostream& os);
};
#endif
