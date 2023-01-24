///////////////////////////////////////////////////////////
//  AplikacjaTerminarz.cpp
//  Implementation of the Class AplikacjaTerminarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "AplikacjaTerminarz.h"
#include "Konto.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <tchar.h>
#include <experimental/filesystem>
using namespace std;

using namespace std::experimental::filesystem;
using namespace std::experimental::filesystem::v1;


AplikacjaTerminarz::AplikacjaTerminarz(){
	this->login = "niewiem";
	this->haslo = "niewiem";
	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1 = new Kalendarz("Default",login);
	this->Kalendarze->push_back(k1);
}



AplikacjaTerminarz::~AplikacjaTerminarz(){

}





AplikacjaTerminarz::AplikacjaTerminarz(string login, string haslo){
	this->login = login;
	this->haslo = haslo;

	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1;

	fstream fpDKal;
	string path2 = "./Konta/" + login + "/Default.txt";
	const char* pathKal = path2.c_str();
	fpDKal.open(pathKal, ios::app);//tworzenie domyslnego kalendarza jeœli nie istnieje
	fpDKal.close();

	//ladowanie danych
	//lista plikow w folderze
	path2 = "./Konta/" + login + "/";
	string nazwa;
	

	//path path{ u8path(u8"bruh.txt") };
	//string path_string{ path.u8string() };

	//lista kalendarzy
	for (const auto& entry : directory_iterator(path2))
	{
		nazwa = entry.path().generic_string();
		path2 = entry.path().generic_string();
		pathKal = path2.c_str();

		cout << entry.path().generic_string() << endl;
		nazwa = nazwa.substr(nazwa.rfind("/")+1,nazwa.size());
		nazwa.pop_back();
		nazwa.pop_back();
		nazwa.pop_back();
		nazwa.pop_back();

		cout << "nazwa: " << nazwa<<endl;

		k1 = new Kalendarz(nazwa, login);
		this->Kalendarze->push_back(k1);

		//lista terminow
		string linia,tytul,data,opis,miejsce;
		int typ,stan;
		int poz1, poz2;

		fpDKal.open(pathKal, ios::in);//otwieranie kalendarza i pobieranie tresci z niego
		if (fpDKal.good())
		{
			while (fpDKal.eof())
			{
				getline(fpDKal, linia);
				typ = linia[0];
				poz1 = posStr(linia, ',', 1);
				poz2 = posStr(linia, ',', 2);
				tytul = linia.substr(poz1 + 1, poz2 - poz1);
				cout << "tytul: " << tytul << endl;
				poz1 = posStr(linia, ',', 2);
				poz2 = posStr(linia, ',', 3);
				data = linia.substr(poz1 + 1, poz2 - poz1);
				cout << "data: " << data << endl;
				poz1 = posStr(linia, ',', 3);
				poz2 = posStr(linia, ',', 4);
				opis = linia.substr(poz1 + 1, poz2 - poz1);
				cout << "opis: " << opis << endl;


				if (typ == 0)
				{
					poz1 = posStr(linia, ',', 5);
					poz2 = linia.size();
					opis = linia.substr(poz1 + 1, poz2);
					opis.pop_back();
					cout << "opis: " << opis << endl;
				}
				else
				{
					poz1 = posStr(linia, ',', 5);
					poz2 = linia.size();
					stan = (int)linia.substr(poz1 + 1, poz2).c_str();
					
					cout << "stan: " << stan << endl;
				}
			}
		}

		fpDKal.close();
	}


	

}


void AplikacjaTerminarz::dodajKalendarz(string nazwa,string login){
	Kalendarz* kalendarz = new Kalendarz(nazwa,login);
	this->Kalendarze->push_back(kalendarz);

	fstream fpDKal;
	string path2 = "./Konta/" + login + "/" + nazwa + ".txt";//tworzenie kalendarza
	const char* pathKal = path2.c_str();
	fpDKal.open(pathKal, ios::app);
	fpDKal.close();
}


void AplikacjaTerminarz::usunKalendarz(Kalendarz* nazwa){
	//1.usuwa z listy
	//2.usuwa plik
}


Kalendarz* AplikacjaTerminarz::wybierzKalendarz(string nazwa){
	for (int i = 0; i < this->Kalendarze->size(); i++)
	{
		if (((*Kalendarze)[i])->dajNazwe() == nazwa) return (*Kalendarze)[i];
	}
	return  nullptr;
}


void AplikacjaTerminarz::wyswietlKalendarze(){
	cout << "KALENDARZE:\n";
	for (int i = 0; i < this->Kalendarze->size(); i++)
	{
		((*Kalendarze)[i])->wyswietlKalendarz();
	}
}


void AplikacjaTerminarz::wyswietlKonto(){
	cout << "KONTO:\n";
	cout <<"Login: " << this->login << "\n";
	cout << "Haslo: " << this->haslo << "\n";
	cout << "Kalendarze:\n";
	this->wyswietlKalendarze();
}

string AplikacjaTerminarz::getLogin()
{
	return login;
}