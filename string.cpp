/**
 *
 * \file string.cpp
 *
 */

#include <iostream>
#include <cstring>
#include "memtrace.h"
#include "string.h"

/// Konstruktorok: egy char karakterből

String::String(char ch)
{
    len = 1;
    pData = new char[len+1];
    pData[0] = ch;
    pData[1] = '\0';
}

/// egy nullával lezárt char sorozatból

String::String(const char *p)
{
    len = strlen(p);
    pData = new char[len+1];
    strcpy(pData, p);
}

/// Másoló konstruktor: String-ből készít
String::String(const String& s1)
{
    len = s1.len;
    pData = new char[len+1];
    strcpy(pData, s1.pData);
}


/// Destruktor (disposeString)
String::~String()
{
    delete[] pData;
}


/// operator=
String& String::operator=(const String& rhs)
{
    if (this != &rhs)
    {
        delete[] pData;
        len = rhs.len;
        pData = new char[len+1];
        strcpy(pData, rhs.pData);
    }
    return *this;
}


/// + operátorok:
String String::operator+(const String& rhs) const
{
    String temp;
    temp.len = len + rhs.len;
    delete []temp.pData;
    temp.pData = new char[temp.len+1];
    strcpy(temp.pData, pData);
    strcat(temp.pData, rhs.pData);
    return temp;
}

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& s0)
{
    os << s0.c_str();
    return os;
}
/// Segéd strcmp függvény
int String::_strcmp(const String & rhs) const
{

    if (size() < rhs.size())
        return 1;
    else if (size() > rhs.size())
        return -1;

    return strcmp(c_str(), rhs.c_str());
}
/// == összehasonlító operátor
bool operator == (const String & lhs, const String & rhs)
{
    return lhs._strcmp(rhs) == 0;
}
/// >> operator, ami beolvas az istream-ről
std::istream& operator>>(std::istream& is, String& s0)
{
    unsigned char ch;
    s0 = String("");
    std::ios_base::fmtflags fl = is.flags();
    is.setf(std::ios_base::skipws);
    while (is >> ch)
    {
        is.unsetf(std::ios_base::skipws);
        if (isspace(ch))
        {
            is.putback(ch);
            break;
        }
        else
        {
            s0 = s0 + ch;
        }
    }
    is.setf(fl);
    return is;
}




