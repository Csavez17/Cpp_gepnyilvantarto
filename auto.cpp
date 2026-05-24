#include <iostream>
#include "auto.hpp"

using namespace std;

Auto::Auto(string rsz, int gev, string tip): rendszam_m(rsz), gyartasiEv_m(gev), tipus_m(tip) {}

void Auto::print()
{
    cout << "Rendszám: " <<rendszam_m << ", gyártási év: " << gyartasiEv_m << ", típus: " << tipus_m << ", ";
}

ostream& operator<< (ostream& s, Auto* a)
{
    s << a->rendszam() << " " << a->gyartasiEv() << " " << a->tipus();
    return s;
}
