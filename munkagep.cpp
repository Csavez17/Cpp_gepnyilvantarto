#include "munkagep.hpp"

Munkagep::Munkagep(string rsz, int gev, string tip, int kw, int ho): Auto(rsz, gev, tip), kiloWatt_m(kw), hetiOra_m(ho) {}

int Munkagep::szervizLimit = 0; // itt történik meg a memória foglalás és példányosítás

int Munkagep::igenybevetel()
{
    return hetiOra_m;
}

void Munkagep::print()
{
    Auto::print();    // Ez kiírja az alap adatokat (rendszám, év, típus)
    cout << "teljesítmény (kW-ban): " << kiloWatt_m << ", heti összesített munkaóra: " << hetiOra_m << ".";   // Ez még hozzá adja a specifikus adatokat
}
