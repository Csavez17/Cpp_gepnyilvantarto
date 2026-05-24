#pragma once

#ifndef _AUTO_HPP_
#define _AUTO_HPP_

#include <string>

using namespace std;

class Auto
{
public:
    // Konstruktor
    Auto(string rsz, int gev, string tip);
    virtual ~Auto() {}

    // Setter-ek
    void setRendszam(string rsz) {rendszam_m = rsz;}
    void setGyartasiEv(int gev) {gyartasiEv_m = gev;}
    void setTipus(string tip) {tipus_m = tip;}

    // Getter-ek
    string rendszam() {return rendszam_m;}
    int gyartasiEv() {return gyartasiEv_m;}
    string tipus() {return tipus_m;}

    virtual void print();
    virtual int igenybevetel() = 0;

protected:
    string rendszam_m;
    int gyartasiEv_m;
    string tipus_m;
};

ostream& operator<< (ostream&, Auto* a);

#endif // _AUTO_HPP_
