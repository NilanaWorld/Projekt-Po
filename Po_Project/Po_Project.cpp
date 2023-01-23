#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
#include <cstring>
#include <filesystem>

#include "AplikacjaTerminarz.h"
#include "Kalendarz.h"
#include "Termin.h"
#include "Spotkanie.h"
#include "Zadanie.h"
#include "typStanu.h"
#include "typTerm.h"
#include "Konto.h"

#define ErrColor 4
#define ConsColor 3
#define AcceptColor 2

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;



int main()
{
    //tworzenie pliku konta i folderu z kontami
    fstream fp;
    fp.open("konta.txt", ios::app);
    fp.close();

    if (mkdir("./Konta") == -1)
        cerr << " Error : " << strerror(errno) << endl;

    else
        cout << "File Created\n";

    //
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
    cout << "Witamy w aplikacji KalenEX!\n";


    //arrow detection - WIP
    /*
    int c, ex;
    while (1)
    {
        c = getch();
        if (c && c != 224)
        {
            cout << endl << "Not arrow: " << (char)c << endl;
        }
        else
        {
            switch (ex = getch())
            {
            case KEY_UP:
                cout << endl << "Up" << endl;//key up
                break;
            case KEY_DOWN:
                cout << endl << "Down" << endl;   // key down
                break;
            case KEY_LEFT:
                cout << endl << "Left" << endl;  // key left
                break;
            case KEY_RIGHT:
                cout << endl << "Right" << endl;  // key right
                break;
            default:
                cout << endl << (char)ex << endl;  // not arrow
                break;
            }
        }
    }
    */

    //tworzenieKonta();
    logowanie();
    //sprawdzanieHasla()

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "Hello World!\n";
    //system("pause");
    //system("CLS");

    return 0;
}