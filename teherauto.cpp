#include "teherauto.hpp"

Teherauto::Teherauto(string rsz, int gev, string tip, int ton, int thkm): Auto(rsz, gev, tip), tonna_m(ton), teherHetiKm_m(thkm) {}

int Teherauto::szervizLimit = 0; // itt történik meg a memória foglalás és példányosítás

int Teherauto::igenybevetel()
{
    return teherHetiKm_m;
}

void Teherauto::print()
{
    Auto::print();    // Ez kiírja az alap adatokat (rendszám, év, típus)
    cout << "teherbírás (tonnában): " << tonna_m << ", heti futott km: " << teherHetiKm_m << ".";   // Ez még hozzá adja a specifikus addatokat
}
