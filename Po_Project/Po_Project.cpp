#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>

#include "AplikacjaTerminarz.h"
#include "Kalendarz.h"
#include "Termin.h"
#include "Spotkanie.h"
#include "Zadanie.h"
#include "typStanu.h"
#include "typTerm.h"

using namespace std;

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

    AplikacjaTerminarz* app = new AplikacjaTerminarz;
    Kalendarz* k1 = new Kalendarz("imprezy");
    Termin* t1 = new Termin();
    app->dodajKalendarz(k1);
    Spotkanie* s1 = new Spotkanie();
    k1->dodajTermin(s1);
    k1->wyswietlTerminy();
    app->wyswietlKonto();
    return 0;
}
