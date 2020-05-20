#include<iostream>

#include "memtrace.h"
#ifndef GEN_HPP
#define GEN_HPP

/**
 * \file gen.hpp
 *
 * Generikus Tömb osztály deklarációja és inline függvényei
 */


template<class T>
class GenTomb
{
protected:
    T *elems;       ///< T osztály pointer
    int size;       ///< elemek száma a tömbben
public:
    /// Alapértelmezett Konstruktor
    /// size - automatikusan 0 értéket állít be
    /// lefoglalja a helyet dinamikusan
    GenTomb(): size(0)
    {
        elems=new T[size];
    }
    /// Másoló konstruktor
    /// helyet dinamikusan foglalja
    /// @param s - konstans T-ket tartalmazó referenciát vesz át
    GenTomb(const GenTomb<T>& s)
    {
        size=s.size;
        elems=new T[size];
        for(int i=0; i<size; i++)
            elems[i]=s.elems[i];
    }
    /// Destruktor
    ~GenTomb()
    {
        delete[] elems;
    }
    /// Indexelõ operátor
    /// @return elems[inedx] - visszatér a tömb index-edik elemével.
    T& operator[](int index)
    {
        return elems[index];
    }
    /// Értékadó operátor
    GenTomb& operator=(T temp)
    {
        for(int i=0; i<size; i++)
            elems[i]=temp;
        return *this;
    }
    /// Függvény ami visszatér a tömb hosszával
    /// @return size
    int GetHossz()
    {
        return size;
    }

    /// Függvény ami hozzáad egy elemet a tömb végéhez
    /// @param n - Nevjegy pointer
    void push(Nevjegy* n)
    {
        T* temp = new T[size+1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = elems[i];
        }
        temp[size] = n;
        size++;
        delete[] elems;
        elems = temp;

    }
    /// Függvény ami töröl egy elemet a tömbbõl
    /// Vizsgálja, hogy nem lehet üres a tömb
    /// @param n - Nevjegy pointer
    void pop(Nevjegy* n)
    {
        T* temp = new T[size-1];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (elems[i] != n && size != 0)
            {
                temp[j++] = elems[i];
            }
        }
        size--;
        delete[] elems;
        elems = temp;

    }


};
#endif



