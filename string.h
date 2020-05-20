#ifndef STRING_H
#define STRING_H
/**
 * \file string.h
 *
**/

#include <iostream>
#include "memtrace.h"
class String
{
    char *pData;            ///< pointer
    size_t len;             ///< szó hossza lezáró nulla nélkül
public:
    /// Kiírunk egy tetszõleges szöveget.
    /// @param txt - nullával lezárt szövegre mutató pointer
    void printDbg(const char *txt = "") const
    {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

    /// Konstruktor:
    String() :pData(0), len(0) {}

    /// String hosszával történõ visszatérés
    /// @return len;
    size_t size() const
    {
        return len;
    }
    /// Stringet visszaadó függvény
    /// @return pData;
    const char* c_str() const
    {
        if (pData == NULL) return "";
        else return pData;
    }
    /// Destruktor
    virtual ~String();
    /// Konstruktor: egy char karakterbõl
    /// @param ch - karakter
    String(char ch);
    /// Konstruktor: egy nullával lezárt char sorozatból
    /// @param p - C típusú string
    String(const char *p);
    /// Másoló konstruktor
    /// @param s1 - String
    String(const String& s1);
    /// Értékadó operátor
    /// @param rhs - String
    String& operator=(const String& rhs);
    /// Összeadó operaátor - Két Stringet fûz össze
    /// @param rhs - String
    /// @return új String
    String operator+(const String& rhs) const ;
    /// Egyenlõség operátor - Két stringet hasonlít össze
    /// @param lhs - String
    /// @param rhs - String
    /// @return true - ha a két stirng ugyan az
    friend bool operator== (const String& lhs, const String& rhs);
    /// Saját strcmp függvény - segédfüggvény
    /// @param rhs - String
    /// @return 0 - ha a két string egyezik
    int _strcmp(const String & rhs) const;


};
/// Ostreamre író függvény
/// @param os - ostream típusú objektum
/// @param s0 - String, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const String& s0);
/// String operator+(char ch, const String& str);
/// @param ch - karakter
/// @param str - String
/// @return új String
inline String operator+(char ch, const String& str)
{
    return String(ch) + str;
}
///Istreamrõl beolvasó függvény
/// @param is - istream típusú objektum
/// @param s0 - String, amibe beolvas
/// @return is
std::istream& operator>>(std::istream& is, String& s0);

#endif
