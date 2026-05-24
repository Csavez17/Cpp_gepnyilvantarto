#pragma once

#include <array>
#include "auto.hpp"

class Menu
{
public:
    Menu(): index_m(0) {}
    ~Menu();
    void execute();
    void newCar();
    void fullList();
    void listByPlate();
    void weeklyUsage();
    void serviceLimit();
    void overServiceTime();
private:
    int index_m;
    std::array<Auto*, 100> storage_m;
};
