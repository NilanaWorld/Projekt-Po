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
#include <math.h>
#include <direct.h>

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
#define KEY_ENTER 13
#define KEY_ESC 27

using namespace std;

AplikacjaTerminarz* app;

int main()
{
    //tworzenie pliku konta i folderu z kontami
    fstream fp;
    fp.open("konta.txt", ios::app);
    fp.close();

    if (mkdir("./Konta") == -1){
        //cerr << " Error : " << strerror(errno) << endl;
    }else {
        //cout << "File Created\n";
    }
    //
    logo();

    

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsColor);
    cout << "Witamy w aplikacji KalendEX!\n";
    system("pause");
    string login;

    menuLogowania();
    
    
    menuTerminarz();

    
    
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "Hello World!\n";

    return 0;
}