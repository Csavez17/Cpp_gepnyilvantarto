#include "autobusz.hpp"

Autobusz::Autobusz(string rsz, int gev, string tip, int fh, int bhkm): Auto(rsz, gev, tip), ferohely_m(fh), buszHetiKm_m(bhkm) {}

int Autobusz::szervizLimit = 0; // itt történik meg a memória foglalás és példányosítás

int Autobusz::igenybevetel()
{
    return buszHetiKm_m;
}

void Autobusz::print()
{
    Auto::print();    // Ez kiírja az alap adatokat (rendszám, év, típus)
    cout << "férőhelyek száma: " << ferohely_m << ",  heti futott km: " << buszHetiKm_m << ".";   // Ez még hozzá adja a specifikus addatokat
}

