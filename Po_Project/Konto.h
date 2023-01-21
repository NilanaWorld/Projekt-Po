#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
#include <cstring>
#include <direct.h>

#define ErrColor 4
#define ConsColor 3
#define AcceptColor 2

using namespace std;


bool sprawdzanieKont(string login)
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

bool sprawdzanieHasla(string login, string haslo)
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

void tworzenieKonta()
{
    string login, haslo;
    int k = 0;
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        if (k > 0) cout << "Juz istnieje takie konto!\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);

        cout << "Login: "; cin >> login;
        k++;

    } while (sprawdzanieKont(login));

    fstream fp,fpDKal;
    fp.open("konta.txt", ios::app);

    if (fp.good())
    {
        cout << "Haslo: "; cin >> haslo;
        fp << login << "," << haslo << "\n";
        
        string core = ".\\Konta\\";
        core = core + login;
        wstring temp = wstring(core.begin(), core.end());
        string path2 = "./Konta/" + login + "/Default.txt";//tworzenie domyslnego kalendarza
        const char* pathKal = path2.c_str();

        LPCWSTR path = temp.c_str();
        CreateDirectory(path, NULL);//zrob ze jak folder sie nie zrobi to usuwa konto uzytkowanika

        fpDKal.open(pathKal,ios::app);//tworzenie domyslnego kalendarza
        fpDKal.close();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AcceptColor);
        cout << "Konto zostalo utworzone pomyslnie\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
        fp.close();
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        cout << "Wystapil blad przy tworzeniu konta...\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
        exit(2);
    }
}

void logowanie()
{
    string login, haslo;
    int k = 0;
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ErrColor);
        if (k > 0) cout << "Takie konto nie istnieje!\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
        cout << "Login: "; cin >> login;
        k++;
    } while (!sprawdzanieKont(login));

    do
    {
        cout << "Haslo: "; cin >> haslo;
    } while (!sprawdzanieHasla(login, haslo));
}