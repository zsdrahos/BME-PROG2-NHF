#ifndef NEV_H
#define NEV_H

#include "string.h"
#include "memtrace.h"
/**
 * \file nev.h
 *
 * Nev oszt�ly deklar�ci�ja �s inline f�ggv�nyei
 */


class Nev
{
protected:
    String vezeteknev;      ///< Vezet�kn�v
    String keresztnev;      ///< Keresztn�v
    String becenev;         ///< Becen�v
    int kontruktor_t;       ///< Seg�dv�ltoz� a konstruktor attrib�tumok sz�m�nak meghat�roz�s�ra
public:

    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param k - keresztn�v megnevez�se
    /// @param v - vezet�kn�v megnevez�se
    /// @param b - becen�v megnevez�se
    Nev(const char *v, const char *k, const char *b)         : vezeteknev(v), keresztnev(k), becenev(b)
    {
        kontruktor_t = 1;
    }

    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param v - vezet�kn�v megnevez�se
    /// @param k - keresztn�v megnevez�se
    Nev(const char *v, const char *k)                                       : vezeteknev(v), keresztnev(k)
    {
        kontruktor_t = 2;
    }

    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param b - becen�v megnevez�se
    Nev(const char *b)                                                      : becenev(b)
    {
        kontruktor_t = 3;
    }
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param k - keresztn�v megnevez�se - String t�pus�
    /// @param v - vezet�kn�v megnevez�se - String t�pus�
    /// @param b - becen�v megnevez�se - String t�pus�
    Nev(String v, String k, String b)         : vezeteknev(v), keresztnev(k), becenev(b)
    {
        kontruktor_t = 1;
    }

    /// N�v lek�rdez�se �rt�kad�s alapj�n
    /// Mind a h�rom adattagnak van �rt�ke akkor visszat�r a teljes n�vvel (k�zep�n becen�vvel)
    /// Ha csak a vezet�kn�v �s a keresztn�v van megadva akkor csak azzal a kett�vel t�r vissza
    /// �s ha csak a becenevet adjuk meg akkor csak a becen�vvel t�r vissza
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

    /// Attrib�tumok ki�r�sa egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << getTeljesnev() << std::endl;
    }

    /// K�t n�v egyez�s�g�t vizsg�lja konstrukor konstruktor param�tereinek sz�ma alapj�n
    /// @param n - jobb oldali operandus
    /// @return true, ha egyezik a k�t n�v
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
    /// Adatok beolvas�sa istreamr�l
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

    /// Virtu�lis destruktor
    virtual ~Nev() {}
};

/// ki�r az ostream-re (printNev)
/// @param os - ostream t�pus� objektum
/// @param s0 - Nev, amit ki�runk
/// @return os
std::ostream& operator<<(std::ostream& os, const Nev& s0);


#endif
