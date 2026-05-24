#include <iostream>
#include <clocale> // Ékezetes betűk megjelenítéséhez kell
#include "menu.hpp"


using namespace std;

int main()
{
    setlocale(LC_ALL, "hu_HU.UTF-8"); // Területi nyelv beállítások, ékezetes magyar betűk miatt kell

    Menu m;
    m.execute();

    return 0;
}
