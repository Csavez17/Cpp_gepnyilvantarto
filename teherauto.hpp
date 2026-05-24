#pragma once

#ifndef _TEHERAUTO_HPP_
#define _TEHERAUTO_HPP_

#include <iostream>
#include "auto.hpp"

class Teherauto: public Auto
{
public:
    // Konstruktor
    Teherauto(string rsz, int gev, string tip, int ton, int thkm);

    int igenybevetel();
    void print();

    static int szervizLimit; // közös szerviz limit beállításához a teljes osztály számára

private:
    int tonna_m;        // kapacitás (teherbírás tonnában)
    int teherHetiKm_m;  // igénybevétel (heti futott km)
};

#endif // _TEHERAUTO_HPP_


