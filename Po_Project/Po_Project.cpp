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
    app->dodajKalendarz(k1);
    app->wyswietlKalendarze();
    return 0;
}
