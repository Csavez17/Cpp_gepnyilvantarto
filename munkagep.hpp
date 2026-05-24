#pragma once

#ifndef _MUNKAGEP_HPP_
#define _MUNKAGEP_HPP_

#include <iostream>
#include "auto.hpp"

class Munkagep: public Auto
{
public:
    // Konstruktor
    Munkagep(string rsz, int gev, string tip, int kw, int ho);

    int igenybevetel();
    void print();

    static int szervizLimit; // közös szerviz limit beállításához a teljes osztály számára

private:
    int kiloWatt_m;     // kapacitás (teljesítmény kW-ban)
    int hetiOra_m;      // igénybevétel (heti összesített munkaóra)
};

#endif // _MUNKAGEP_HPP_

