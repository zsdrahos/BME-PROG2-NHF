/**
 *
 * \file telefonkonyv.cpp
 *
 */

#include "telefonkonyv.h"
#include <iostream>
#include "memtrace.h"
using std::cout;
using std::endl;
using std::cin;

/// Függvény ami hozzáadja a tömbhöz az adott névjegyet
void Telefonkonyv::Hozzaad (Nevjegy* n)
{
    ember.push(n);
}
/// Függvény ami kitörli az adott névjegyet a tömbbõl
void Telefonkonyv::Tororl (Nevjegy* n)
{

    if (ember.GetHossz() == 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        ember.pop(n);
    }

}
/// Függvény ami kilistázza az adatokat
void Telefonkonyv::listaz (std::ostream& os)
{
    if (ember.GetHossz() == 0)
    {
        cout << "Ures a tomb!" << endl;
    }
    for(int i = 0; i < ember.GetHossz(); i++)
    {
        os << i+1 << ". nevjegy:" << std::endl;
        ember[i]->print(os);
    }
}
/// Függvény ami kilistázza csak a neveket
void Telefonkonyv::listaz_nev (std::ostream& os)
{
    if (ember.GetHossz() == 0)
    {
        cout << "Ures a tomb!" << endl;
    }
    for(int i = 0; i < ember.GetHossz(); i++)
    {
        os << i+1 << ". nevjegy:" << std::endl;
        ember[i]->print_nev(os);
    }
}
/// Függvény ami megkeresi az adott nevû névjegyet
void Telefonkonyv::KeresNev(const Nev& n, std::ostream& os)
{
    int db = 0;
    if (ember.GetHossz() == 1)
    {
        if (n == ember[0]->getNev())
        {
            ember[0]->print(os);
            db++;
        }
    }
    else
    {
        for(int i = 0; i < ember.GetHossz(); i++)
        {
            if (n == ember[i]->getNev())
            {
                ember[i]->print(os);
                db++;
            }
        }
    }
    if (db == 0)
    {
        cout << "Nincs ilyen nev az adatbazisban!" << endl;
    }
}
/// Függvény ami megkeresi az adott telefonszámú névjegyet
void Telefonkonyv::KeresTel(const Tel& n, std::ostream& os)
{
    int db = 0;
    if (ember.GetHossz() == 1)
    {
        if (n == ember[0]->getTel())
        {
            ember[0]->print(os);
            db++;
        }
    }
    else
    {
        for(int i = 0; i < ember.GetHossz(); i++)
        {
            if (n == ember[i]->getTel())
            {
                ember[i]->print(os);
                db++;
            }
        }
    }
    if (db == 0)
    {
        cout << "Nincs ilyen telefonszam az adatbazisban!" << endl;
    }
}
/// Függvény ami megkeresi az adott címû névjegyet
void Telefonkonyv::KeresCim(const Cim& n, std::ostream& os)
{
    int db = 0;
    if (ember.GetHossz() == 1)
    {
        if (n == ember[0]->getCim())
        {
            ember[0]->print(os);
            db++;
        }
    }
    else
    {
        for(int i = 0; i < ember.GetHossz(); i++)
        {
            if (n == ember[i]->getCim())
            {
                ember[i]->print(os);
                db++;
            }
        }
    }
    if (db == 0)
    {
        cout << "Nincs ilyen cim az adatbazisban!" << endl;
    }
}





