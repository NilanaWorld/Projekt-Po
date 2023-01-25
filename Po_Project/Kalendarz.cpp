///////////////////////////////////////////////////////////
//  Kalendarz.cpp
//  Implementation of the Class Kalendarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#include "Kalendarz.h"
#include "Spotkanie.h"
#include "Termin.h"
#include "Zadanie.h"
#include "typStanu.h"
#include "Konto.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;


Kalendarz::Kalendarz(){
	this->nazwa = "Podstawowy";
	this->Terminy = new vector<Termin*>();
}


Kalendarz::~Kalendarz(){

}


Kalendarz::Kalendarz(string nazwa,string login){
	this->nazwa = nazwa;
	this->Terminy = new vector<Termin*>();
	this->login=login;
}


void Kalendarz::dodajTermin(int typ,string tytul,string data,string opis,string miejsce){//Spotkanie
	Termin* termin = new Spotkanie(tytul, data, opis, miejsce);
	this->Terminy->push_back(termin);
}

void Kalendarz::dodajTermin(int typ, string tytul, string data, string opis, typStanu stan) {//Zadanie
	Termin* termin=new Zadanie(tytul, data, opis);
	((Zadanie*)termin)->zmienStan(stan);
	this->Terminy->push_back(termin);
}

void Kalendarz::dodajTermin() {
	int typ;
	string data;
	string tytul;
	string miejsce;
	string opis;
	Termin* termin;

	cout << "\n0-Spotkanie\n1-Zadanie\n"; cin >> typ;
	cout << "Tytul: "; cin >> tytul;
	cout << "Data: "; cin >> data;
	cout << "Opis: "; cin >> opis;

	switch (typ)
	{
	case 0://Spotkanie
	{
		cout << "Miejsce: "; cin >> miejsce;
		termin = new Spotkanie(tytul,data,opis,miejsce);
		break;
	}
	case 1://Zadanie
	{
		termin = new Zadanie(tytul,data,opis);
		break;
	}
	default:
		cout << "Bledny typ\n";
		exit(2);
		break;
	}
	this->Terminy->push_back(termin);

	fstream fp;
	string path2 = "./Konta/" + login + "/" + nazwa + ".txt";//sciezka kalendarza
	cout << "sciezka: " << path2 << endl;
	const char* pathKal = path2.c_str();
	fp.open(pathKal, ios::app);

	if (typ == 0)
		fp << typ << "," << tytul << "," << data << "," << opis << "," << miejsce << "\n";
	else
		fp << typ << "," << tytul << "," << data << "," << opis << "," << zaplanowany <<"\n";
	fp.close();
}


void Kalendarz::usunTermin(string nazwa1) {
	//1.usuwa z listy
	bool flag = false;
	Termin* r = nullptr;
	auto it = find_if(Terminy->begin(), Terminy->end(), [&](Termin* p)
		{
			if (nazwa1 == p->dajTytul())
			{
				r = p;
				flag = true;
				return true;
			}
			return false; });
	Terminy->erase(it);
	if (flag == false)
	{
		cout << "Plik nie istnieje\n";
	}
	else
	{
		fstream fp, tmp;
		string line, nazwa2;
		int n = nazwa1.length();
		string KalPath = "./Konta/" + login + "/" + nazwa + ".txt";
		string TmpPath = "./Konta/" + login + "/tmp.txt";
		const char* KalPath1 = KalPath.c_str();
		const char* TmpPath1 = TmpPath.c_str();
		fp.open(KalPath1, ios::in);
		tmp.open(TmpPath1, ios::app);
		int poz1, poz2;

		if (fp.good()) {
			while (getline(fp, line))
			{
				poz1 = posStr(line, ',', 1);
				poz2 = posStr(line, ',', 2);
				nazwa2 = line.substr(poz1 + 1, poz2 - poz1 - 1);
				if (strncmp(nazwa2.c_str(), nazwa1.c_str(), n) != 0)
				{
					tmp << line << "\n";
				}
			}
			string core = ws2s(ExePath());
			string coreFinal;
			core.pop_back(); core.pop_back();
			core.pop_back(); core.pop_back();
			core.pop_back(); core.pop_back();
			for (int i = 0; i < core.length(); i++)
			{
				if (core[i] == '/') {
					coreFinal.push_back('\\');
					coreFinal.push_back('\\');
				}
				else {
					coreFinal.push_back(core[i]);
				}

			}
			cout << "coreF: " << coreFinal << endl;

			KalPath = coreFinal + ".\\Konta\\" + login + "\\" + nazwa + ".txt";
			TmpPath = coreFinal + ".\\Konta\\" + login + "\\tmp.txt";
			KalPath1 = KalPath.c_str();
			TmpPath1 = TmpPath.c_str();

			fp.close();
			tmp.close();

			if (remove(KalPath1) != 0)
				perror("Error removing file\n");
			else
				cout << "File removed successfully\n";

			if (rename(TmpPath1, KalPath1) != 0)
				perror("Error rename file");
			else
				cout << "File rename successfully\n";

		}
		else
		{
			cout << "Blad otwarcia pliku\n";
		}
	}
}


Termin* Kalendarz::wybierzTermin(string nazwa){
	for (int i = 0; i < this->Terminy->size(); i++)
	{
		if (((*Terminy)[i])->dajTytul() == nazwa) return (*Terminy)[i];
	}
	return  nullptr;
}


void Kalendarz::wyswietlKalendarz(){
	cout << this->nazwa << "\n";
}


void Kalendarz::wyswietlTerminy(){
	for (int i = 0; i < this->Terminy->size(); i++)
	{
		((*Terminy)[i])->wyswietl();
	}
}

string Kalendarz::dajNazwe() {
	return this->nazwa;
}

string Kalendarz::getLogin()
{
	return this->login;
}