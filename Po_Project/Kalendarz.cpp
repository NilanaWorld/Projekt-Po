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


void Kalendarz::dodajTermin(Termin* termin){
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
		termin = new Spotkanie(miejsce, opis);
		break;
	}
	case 1://Zadanie
	{
		termin = new Zadanie(opis);
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


void Kalendarz::usunTermin(string nazwa){
	Termin* r = nullptr;
	auto it = find_if(Terminy->begin(), Terminy->end(), [&](Termin* p)
		{
			if (nazwa == p->dajTytul())
			{
				r = p;
				return true;
			}
		return false; });
	Terminy->erase(it);
		
	//1.usuwa z listy
	//2. ios::out powinno go usunac z pliku
	//3. potrzeba funkcji zapisz
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