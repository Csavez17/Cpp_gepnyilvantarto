#pragma once

#ifndef _AUTOBUSZ_HPP_ // if not defined - Ell., hogy van-e már ilyen azonosító
#define _AUTOBUSZ_HPP_ // létrehozza az azonosítót/makrót

#include <iostream>
#include "auto.hpp"

class Autobusz: public Auto
{
public:
    // Konstruktor
    Autobusz(string rsz, int gev, string tip, int fh, int bhkm);

    int igenybevetel();
    void print();

    static int szervizLimit; // közös szerviz limit beállításához a teljes osztály számára

private:
    int ferohely_m;     // kapacitás (férőhelyek száma)
    int buszHetiKm_m;   // igénybevétel (heti futott km)
};

#endif // _AUTOBUSZ_HPP_
