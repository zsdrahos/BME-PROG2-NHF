#ifndef CIM_H
#define CIM_H

#include "string.h"
#include "memtrace.h"
/**
 * \file cim.h
 *
 * Cim oszt�ly deklar�ci�ja �s inline f�ggv�nyei
 */

class Cim
{
protected:
    String orszag;                  ///< Orsz�g
    String iranyitoszam;            ///< Ir�ny�r�sz�m
    String varos;                   ///< V�ros
    String utca;                    ///< Utca
    String hazszam;                 ///< H�zsz�m
    int kontruktor_t;               ///< Seg�dv�ltoz� a konstruktor attrib�tumok sz�m�nak meghat�roz�s�ra
public:

    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param o - orsz�g megnevez�se
    /// @param i - ir�ny�t�sz�m megnevez�se
    /// @param v - v�ros megnevez�se
    /// @param u - utca megnevez�se
    /// @param h - h�zsz�m megnevez�se
    Cim(const char *o, const char * i, const char *v, const char *u, const char * h)         : orszag(o), iranyitoszam(i), varos(v), utca(u), hazszam(h)
    {
        kontruktor_t = 1;
    }

    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param o - orsz�g megnevez�se
    Cim (const char *o)                                                                      : orszag(o)
    {
        kontruktor_t = 2;
    }

    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param i - ir�ny�t�sz�m megnevez�se
    /// @param v - v�ros megnevez�se
    Cim (const char *i, const char *v)                                                       : iranyitoszam(i), varos(v)
    {
        kontruktor_t = 3;
    }
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param o - String t�pus�
    /// @param i - String t�pus�
    /// @param v - String t�pus�
    /// @param u - String t�pus�
    /// @param h - String t�pus�
    Cim(String o, String i,String v, String u, String h)         : orszag(o), iranyitoszam(i), varos(v), utca(u), hazszam(h)
    {
        kontruktor_t = 1;
    }

    /// Teljes c�m lek�rdez�se konstruktor param�tereinek sz�ma alapj�n
    /// Minden adattag: teljes c�m vessz�vel elv�lasztva
    /// Csak orsz�ggal
    /// Csak Ir�ny�r�sz�mmal �s v�rosn�vvel
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


    /// Attrib�tumok ki�r�sa egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << getTeljesCim() << std::endl;
    }

    /// K�t c�m egyez�s�g�t vizsg�lja
    /// @param c - jobb oldali operandus
    /// @return true, ha egyezik a k�t n�v
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
    /// Adatok beolvas�sa istreamr�l
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

    /// Virtu�lis destruktor
    virtual ~Cim() {}
};

/// ki�r az ostream-re (printCim)
/// @param os - ostream t�pus� objektum
/// @param s0 - Cim, amit ki�runk
/// @return os
std::ostream& operator<<(std::ostream& os, const Cim& s0);

#endif
