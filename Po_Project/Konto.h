#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
#include <cstring>
#include <direct.h>

#include "Zadanie.h";
#include "Spotkanie.h";

#define ErrColor 4
#define ConsColor 3
#define AcceptColor 2

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27

using namespace std;

extern AplikacjaTerminarz* app;

inline void logo() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
    fstream logo;
    string line;
    int k = 0;
    logo.open("nowy2.txt", ios::in);
    if (logo.good())
    {
        while (!logo.eof()) {
            getline(logo, line);
            cout << line << endl;
            if (k > 18) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            Sleep(50);
            k++;
        };
        logo.close();
    }
    else {
        cout << "blad wczytywania logo\n";
    }
}

inline bool sprawdzanieKont(string login)
{
    string test;
    fstream fp;
    int n = login.length();
    fp.open("konta.txt", ios::in);
    if (fp.good())
    {
        while (getline(fp, test))
        {
            if (strncmp(test.c_str(), login.c_str(), n) == 0)
            {
                return true;
            }
        }
        fp.close();
        return false;
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        cout << "Nie udalo sie zaladowac kont\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
        exit(2);
    }
}

inline bool sprawdzanieHasla(string login, string haslo)
{
    string testLogin;
    string testHaslo;
    string test;
    int tn;
    int t;
    fstream fp;
    int n = haslo.length();
    fp.open("konta.txt", ios::in);
    if (fp.good())
    {
        while (getline(fp, test))
        {
            t = test.find(',');
            tn = test.length();
            testLogin = test.substr(0, t);
            testHaslo = test.substr(t + 1, tn - 1);

            if (strcmp(login.c_str(), testLogin.c_str()) == 0)
            {
                if (strcmp(haslo.c_str(), testHaslo.c_str()) == 0)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AcceptColor);
                    cout << "Zalogowano sie\n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
                    return true;
                }
                else {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
                    cout << "Nieprawidlowe haslo\n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
                    return false;
                }
            }
        }
        fp.close();
        return false;
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        cout << "Nie udalo sie zaladowac kont\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);

        exit(2);
    }
}

inline void tworzenieKonta()
{
    string login, haslo;
    int k = 0;
    printf("REJESTRACJA\n\n");
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        if (k > 0) cout << "Juz istnieje takie konto!\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);

        cout << "Login: "; cin >> login;
        k++;

    } while (sprawdzanieKont(login));

    fstream fp;
    fp.open("konta.txt", ios::app);

    if (fp.good())
    {
        cout << "Haslo: "; cin >> haslo;
        fp << login << "," << haslo << "\n";
        fp.close();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AcceptColor);
        cout << "Konto zostalo utworzone pomyslnie\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        cout << "Wystapil blad przy tworzeniu konta...\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
        exit(2);
    }
}

inline string convertToString(char* a)
{
    string s(a);
    return s;
}

inline int posStr(string wyraz,char znak,int wystapienie)
{
    int flag = 0;
    bool czy_znak = false;

    for (int i = 0; i < wyraz.size(); i++)
    {
        if (wyraz[i] == znak){
            czy_znak = true;
            flag++;
        }
        else
            czy_znak = false;

        if (flag == wystapienie && czy_znak) return i;
    }
    return -1;
}

inline void logowanie()
{
    string login, haslo;
    int k = 0;
    printf("LOGOWANIE\n\n");
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        if (k > 0) cout << "Takie konto nie istnieje!\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
        cout << "Login: "; cin >> login;
        k++;
    } while (!sprawdzanieKont(login));

    char* pw = (char*)malloc(sizeof(char)*50);
    int x = 0;
    int intZnak=0;
    do
    {
        x = 0;
        cout << "Haslo: ";
        while (intZnak != KEY_ENTER)
        {
            intZnak = (char)getch();
            pw[x] = (char)intZnak;
            printf("*");
            x++;
        }
        pw[x - 1] = '\0';
        cout << endl;
        haslo = convertToString(pw);
    } while (!sprawdzanieHasla(login, haslo));
    
    app = new AplikacjaTerminarz(login, haslo);
}

inline char wybor()//key detection - WIP
{
    int c, ex;
    c = getch();
    char option;

    switch (c)
    {
    case KEY_ENTER:
        //cout << endl << "Enter" << endl;
        option = 'e';
        ex = c;
        break;
    case KEY_ESC:
        //cout << endl << "Esc" << endl;
        option = 'x';
        ex = c;
        break;
    default:
    {
        switch (ex = getch())
        {
        case KEY_UP:
            //cout << endl << "Up" << endl;//key up
            option='u';
            break;
        case KEY_DOWN:
            //cout << endl << "Down" << endl;   // key down
            option='d';
            break;
        case KEY_LEFT:
            //cout << endl << "Left" << endl;  // key left
            break;
        case KEY_RIGHT:
            //cout << endl << "Right" << endl;  // key right
            break;
        default:
            //cout << endl << (char)ex << endl;  // not arrow
            break;
        }
    }
    break;
    }
    //printf("key = %02x\n", ex);
    return option;
}

inline void opcje(int opcja)
{
    system("CLS");
    switch (opcja)
    {
    case 0:
        logowanie();
        break;
    case 1:
        tworzenieKonta();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }
    system("pause");
    system("CLS");
}

inline void menuLogowania()
{
    char option = 'u';
    int flag = 0;
    int testOption = 0;

    while (option != 'x')
    {
        system("CLS");
        switch (abs(flag) % 2)
        {
        case 0:
        {
            printf("Logowanie <\nRejestracja\n");
            break;
        }
        case 1:
            printf("Logowanie\nRejestracja <\n");
            break;
        default:
            break;
        }
        if (option == 'e')
        {
            opcje(abs(flag) % 2);
            if (abs(flag) % 2 == 0) {
                break;
            }
            else {
                option = 'u';
                flag = 0;
                continue;
            }
        }
        option = wybor();
        if (option == 'u') flag++;
        else if (option == 'd')flag--;
    }
}

inline void menuTermin(Termin* t1)
{
    int opcja = 0;
    while (opcja != KEY_ENTER)
    {
        system("CLS");
        cout << "0-Edytuj date\n";
        cout << "1-Wyswietl termin\n";
        if(t1->getType()==1) cout << "2-Zmien stan\n\n";
        cin >> opcja;
        cout << "\n\n";
        string nowaData;
        int typ;

        switch (opcja)
        {
        case 0:
        {
            cout << "Nowa data: "; cin >> nowaData;
            t1->edytujDate(nowaData);
            break;
        }
        case 1:
        {
            if (t1->getType() == 0)
                ((Spotkanie*)t1)->wyswietl();
            else
                ((Zadanie*)t1)->wyswietl();
            break;
        }
        case 2:
        {
            cout << "Nowy stan: \n";
            cout << "0-zaplanowany \n";
            cout << "1-zrealizowany\n";
            cout << "2-anulowany\n";

            cin >> typ;
            ((Zadanie*)t1)->zmienStan((typStanu)typ);
            break;
        }
        default:
            break;
        }
    }
}

inline void menuKalendarz(Kalendarz* k1)
{
    int opcja = 0;
    while (opcja != KEY_ENTER)
    {
        system("CLS");
        cout << "0-Dodaj termin\n";
        cout << "1-Wybierz termin\n";
        cout << "2-Wyswietl terminy\n";
        cout << "3-Usun termin\n\n";
        cout << "4-Usun termin\n\n";
        cin >> opcja;
        cout << "\n\n";
        string nazwaKal;
        string nazwaTerm;

        switch (opcja)
        {
        case 0:
        {
            k1->dodajTermin();
            break;
        }
        case 1:
        {
            cout << "Nazwa terminu: "; cin >> nazwaTerm;
            Termin* t1 = k1->wybierzTermin(nazwaTerm);
            if (t1 != nullptr) {

            }
            else {
                cout << "Wybrany termin nie istnieje\n";
            }
            system("pause");
            break;
        }
        case 2:
        {
            k1->wyswietlTerminy();
            system("pause");
            break;
        }
        case 3:
        {
            k1->wyswietlKalendarz();
            system("pause");
            break;
        }
        case 4:
        {
            break;
        }
        default:
            break;
        }
    }
}

inline void menuTerminarz()
{
    int opcja=0;
    while (opcja != KEY_ENTER)
    {
        system("CLS");
        cout << "0-Dodaj kalendarz\n";
        cout << "1-Wybierz kalendarz\n";
        cout << "2-Wyswietl kalendarze\n";
        cout << "3-Usun kalendarz\n\n";
        cin >> opcja;
        cout << "\n\n";
        string nazwa;

        switch (opcja)
        {
        case 0:
        {
            cout << "Nazwa kalendarza: "; cin >> nazwa;
            app->dodajKalendarz(nazwa, app->getLogin());
            break;
        }
        case 1:
        {
            cout << "Nazwa kalendarza: "; cin >> nazwa;
            Kalendarz* k1 = (app->wybierzKalendarz(nazwa));
            if (k1 != nullptr){
                menuKalendarz(k1);
            }
            else{
                cout << "Wybrany kalendarz nie istnieje\n";
            }
            system("pause");
            break;
        }
        case 2:
        {
            app->wyswietlKalendarze();
            system("pause");
            break;
        }
        case 3:
        {
            break;
        }
        default:
            break;
        }
    }
}

