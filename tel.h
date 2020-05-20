#ifndef TEL_H
#define TEL_H

#include "string.h"
#include "memtrace.h"
/**
 * \file tel.h
 *
 * Tel oszt�ly deklar�ci�ja �s inline f�ggv�nyei
 */

class Tel
{
protected:
    String munkahelyi;              ///< Munkahelyi telefonsz�m
    String magan;                   ///< Mag�n telefonsz�m
    bool kontruktor_t;              ///< Seg�dv�ltoz� a konstruktor attrib�tumok sz�m�nak meghat�roz�s�ra
public:
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param munk - munkahelyi telefonsz�m megnevez�se
    /// @param mag - mag�n telefonsz�m megnevez�se
    Tel(const char *munk, const char *mag)         :munkahelyi(munk), magan(mag)
    {
        kontruktor_t = true;
    }
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param mag - mag�n telefonsz�m megnevez�se
    Tel(const char *mag)                           :magan(mag)
    {
        kontruktor_t = false;
    }
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param munk - String t�pus�
    /// @param mag - String t�pus�
    Tel(String munk, String mag)         :munkahelyi(munk), magan(mag)
    {
        kontruktor_t = true;
    }


    /// Telefonsz�m lek�rdez�se �rt�kad�s alapj�n
    /// Munkahelyi �s mag�n telefonsz�mmal val� visszat�r�s
    /// Illetve csak mag�n telefonsz�mmal val� visszat�r�s
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

    /// Attrib�tumok ki�r�sa egy stream-re
    /// @param os - output stream referencia
    /// @return output stream referencia
    virtual std::ostream& print(std::ostream& os) const
    {
        return os << getTel() << std::endl;
    }

    /// K�t Telefonsz�m egyez�s�g�t vizsg�lja konstruktor param�tereinek sz�ma alapj�n
    /// @param t - jobb oldali operandus
    /// @return true, ha egyezik a k�t telefonsz�m
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
    /// Adatok beolvas�sa istreamr�l
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

    /// Virtu�lis destruktor
    virtual ~Tel() {}
};
/// ki�r az ostream-re (printTel)
/// @param os - ostream t�pus� objektum
/// @param s0 - Tel, amit ki�runk
/// @return os
std::ostream& operator<<(std::ostream& os, const Tel& s0) ;

#endif
