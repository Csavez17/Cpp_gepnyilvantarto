#include <iostream>
#include <string>
#include <stdlib.h>
#include "menu.hpp"
#include "auto.hpp"
#include "autobusz.hpp"
#include "munkagep.hpp"
#include "teherauto.hpp"

using namespace std;

void Menu::execute()
{
    bool isRunning = true;

    while (isRunning) {
        string selectedMenu;

        // Kiírjuk a főmenüt
        cout << "List start" << endl;
        cout << "(1) - Új autó hozzáadás" << endl;      // newCar
        cout << "(2) - Autók adatai, teljes lista" << endl;       // fullList
        cout << "(3) - Keresés rendszám alapján" << endl;        // listByPlate
        cout << "(4) - Igénybevétel összesítése kategóriánként" << endl;        // weeklyUsage
        cout << "(5) - Igénybevételi határ beállítása kategóriánként" << endl;       //serviceLimit
        cout << "(6) - Igénybevételi határt túllépő autók" << endl;     //overServiceTime
        cout << "(7) - Kilépés" << endl;
        cout << "List end" << endl;

        // Beolvassuk a választott műveletet
        cin >> selectedMenu;
        cout << endl;
        char sm = selectedMenu[0];

        // Választástól függő elágaztatás, mindig a megfelelő metódust hívjuk meg
        switch (sm) {
        case '1':
            newCar();
            break;
        case '2':
            fullList();
            break;
        case '3':
            listByPlate();
            break;
        case '4':
            weeklyUsage();
            break;
        case '5':
            serviceLimit();
            break;
        case '6':
            overServiceTime();
            break;
        case '7':
            isRunning = false;
            break;
        default:
           cout << "HIBA! NINCS ILYEN MENÜPONT!" << endl;
           break;
        }
    }
}

void Menu::newCar()
{
    bool isNextCar = true; // a while ciklusból való kilépéshez
    string rsz, tip, buffer;
    int gev, kap, ige;

    while(isNextCar) {
        // Bekérem az új jármű adatait
        cout << "KÉREM ADJA MEG AZ AUTÓ ADATAIT" << endl;
        cout << "Rendszám: ";
        cin >> rsz;
        cout << "Gyártási Év: ";
        cin >> buffer;
        gev = atoi(buffer.c_str());
        cout << "Típus (m/t/a): ";
        cin >> buffer;

        if(buffer[0] == 'm'){
            tip = "munkagép";
            cout << "Kapacitás (teljesítmény kW-ban): ";
            cin >> buffer;
            kap = atoi(buffer.c_str());
            cout << "Igénybevétel (heti összesített munkaóra): ";
            cin >> buffer;
            ige = atoi(buffer.c_str());
            Munkagep* mptr = new Munkagep(rsz, gev, tip, kap, ige);
            storage_m[index_m] = mptr;
        } else if (buffer[0] == 't') {
            tip = "teherautó";
            cout << "Kapacitás (teherbírás tonnában): ";
            cin >> buffer;
            kap = atoi(buffer.c_str());
            cout << "Igénybevétel (heti futott km): ";
            cin >> buffer;
            ige = atoi(buffer.c_str());
            Teherauto* tptr = new Teherauto(rsz, gev, tip, kap, ige);
            storage_m[index_m] = tptr;
        } else {
            tip = "autóbusz";
            cout << "Kapacitás (férőhelyek száma): ";
            cin >> buffer;
            kap = atoi(buffer.c_str());
            cout << "Igénybevétel (heti futott km): ";
            cin >> buffer;
            ige = atoi(buffer.c_str());
            Autobusz* aptr = new Autobusz (rsz, gev, tip, kap, ige);
            storage_m[index_m] = aptr;
        }
        cout << endl;

        // Ellenőrző kiíratás a végén, csak itt léptetjük index_m-et:
        cout << "Új autó került mentésre a következő adatokkal: " << endl;

        storage_m[index_m]->print(); // Az imént elmentett autó adatainak a kiíratása a print metódussal
        cout << endl;

        ++index_m;
        cout << endl;

        cout << "Szeretné még egy autó adatait elmenteni? (i/n) ";
        char c;
        cin >> c;
        isNextCar = (c == 'i') ? true : false;
        cout << endl;
    }
}

void Menu::fullList()
{
    for (int i = 0; i < index_m; ++i){
        cout << (i+1) << ". jármű adatai: " << endl;
        storage_m[i]->print();
        cout << endl; // Új sorban jelennek meg a következő autó adatai
    }
    cout << endl;
}

void Menu::listByPlate()
{
    bool isNextPlate = true; // a while ciklusból való kilépéshez
    string bekertRendszam;

    while (isNextPlate){    // a ciklus addig fut amíg újabb rendszámokra akarunk rákeresni
        bool found = false; // az újra induló ciklus elején kell beállítani az értékét, hogy ne maradjon véletlenül "igaz"-ra állítva
        cout << "Adja meg a keresett rendszámot: ";
        cin >> bekertRendszam;

        // A mentett adatok közti keresés rendszám egyezés alapján
        for (int i = 0; i < index_m; ++i){
            if (bekertRendszam == storage_m[i]->rendszam()){
                storage_m[i]->print();
                found = true; // egyezés esetén "igaz"-ra kell állítani
                break;  // mivel elvileg csak egyszer szerepelhetne egy rendszám, ezért találat esetén leáll a keresés
            }
        }

        // ha a for ciklus nem talált egyezést
        if (!found){
            cout << "Nincs ilyen rendszám a rendszerben!";
        }

        cout << endl;

        cout << "Szeretne újabb rendszámra rákeresni? (i/n) ";
        char d;
        cin >> d;
        isNextPlate = (d == 'i') ? true : false;
        cout << endl;
    }
}

void Menu::weeklyUsage()
{
    // az összesítéshez használt változók deklarálása
    int allMGep = 0;
    int allTeher = 0;
    int allBusz = 0;

    for (int i = 0; i < index_m; ++i){
        if (storage_m[i]->tipus() == "munkagép"){
            allMGep += storage_m[i]->igenybevetel();
        }
        else if (storage_m[i]->tipus() == "teherautó"){
            allTeher += storage_m[i]->igenybevetel();
        }
        else {
            allBusz += storage_m[i]->igenybevetel();
        }
    }
    cout << "Munkagépek heti összesített igénybevétele: " << allMGep << " óra." << endl;
    cout << "Teherautók heti összesített igénybevétele: " << allTeher << " km." << endl;
    cout << "Autóbuszok heti összesített igénybevétele: " << allBusz << " km." << endl;
    cout << endl;
}

void Menu::serviceLimit()
{
    int beolvasottSzervizLimit;

    bool isNextLimit = true; // a while ciklusból való kilépéshez
    char kategoriaValasztas;

    while (isNextLimit){
        cout << "Melyik kategória szervíz igénybevételi határát szeretné beállítani? (m/t/a) ";
        cin >> kategoriaValasztas;

        if (kategoriaValasztas == 'm'){
            cout << "Adja meg a munkagépek szervíz határát: ";
            cin >> beolvasottSzervizLimit;
            Munkagep::szervizLimit = beolvasottSzervizLimit;
        }
        else if (kategoriaValasztas == 't'){
            cout << "Adja meg a teherautók szervíz határát: ";
            cin >> beolvasottSzervizLimit;
            Teherauto::szervizLimit = beolvasottSzervizLimit;
        }
        else {
            cout << "Adja meg az autobuszok szervíz határát: ";
            cin >> beolvasottSzervizLimit;
            Autobusz::szervizLimit = beolvasottSzervizLimit;
        }

        cout << endl;

        cout << "Szeretne újabb szervíz határt megadni? (i/n) ";
        char e;
        cin >> e;
        isNextLimit = (e == 'i') ? true : false;
        cout << endl;
    }
}

void Menu::overServiceTime()
{
    string autoTipus;

    bool foundOneM = false; // hogy lehessen vizsgálni, hogy van-e legalább egy ami átlépi a határértéket
    bool foundOneT = false;
    bool foundOneA = false;


    // külön for ciklus minden auto típus vizsgálatához, így kategóriákra bontott listát lehet megjeleníteni

    // végig megyünk a mentett autók listáján, először munkagépeket vizsgálunk
    cout << "Munkagépek, melyek a szervíz igénybevételi határt túllépték: " << endl;
    for (int i = 0; i < index_m; ++i){
        autoTipus = storage_m[i]->tipus();

        if (autoTipus == "munkagép"){
            if (storage_m[i]->igenybevetel() > Munkagep::szervizLimit){
                storage_m[i]->print();
                foundOneM = true; // ha van ami átlépi a határt átállítjuk "igaz"-ra
                cout << endl;
            }
        }
    }

    // Vizsgáljuk, hogy a for ciklus talált-e egyezést és átállította-e a logikai változót "igaz"-ra, ha nem akkor jön a kiíratás
    if (!foundOneM) {
        cout << "Egy munkagép sem lépte át a megadott határértéket!" << endl;
    }

    // ismét végig megyünk a mentett autók listáján, most teherautókat vizsgálunk
    cout << "Teherautók, melyek a szervíz igénybevételi határt túllépték: " << endl;
    for (int i = 0; i < index_m; ++i){
        autoTipus = storage_m[i]->tipus();

        if (autoTipus == "teherautó"){
            if (storage_m[i]->igenybevetel() > Teherauto::szervizLimit){
                storage_m[i]->print();
                foundOneT = true;
                cout << endl;
            }
        }
    }

    // Vizsgáljuk, hogy a for ciklus talált-e egyezést és átállította-e a logikai változót "igaz"-ra, ha nem akkor jön a kiíratás
    if (!foundOneT) {
        cout << "Egy teherautó sem lépte át a megadott határértéket!" << endl;
    }

    // ismét végig megyünk a mentett autók listáján, most autóbuszokat vizsgálunk
    cout << "Autóbuszok, melyek a szervíz igénybevételi határt túllépték: " << endl;
    for (int i = 0; i < index_m; ++i){
        autoTipus = storage_m[i]->tipus();

        if (autoTipus == "autóbusz"){
            if (storage_m[i]->igenybevetel() > Autobusz::szervizLimit){
                storage_m[i]->print();
                foundOneA = true;
                cout << endl;
            }
        }
    }

    // Vizsgáljuk, hogy a for ciklus talált-e egyezést és átállította-e a logikai változót "igaz"-ra, ha nem akkor jön a kiíratás
    if (!foundOneA){
        cout << "Egy autóbusz sem lépte át a megadott határértéket!" << endl;
    }
}

Menu::~Menu()
{
    for(int i = 0; i < index_m; ++i)
        delete storage_m[i];
}
