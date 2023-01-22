///////////////////////////////////////////////////////////
//  Kalendarz.cpp
//  Implementation of the Class Kalendarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#include "Kalendarz.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;


Kalendarz::Kalendarz(){
	this->nazwa = "Podstawowy";
	this->Terminy = new vector<Termin*>();
}



Kalendarz::~Kalendarz(){

}





Kalendarz::Kalendarz(string nazwa){
	this->nazwa = nazwa;
	this->Terminy = new vector<Termin*>();
}


void Kalendarz::dodajTermin(Termin* termin){
	this->Terminy->push_back(termin);
}

void Kalendarz::dodajTermin(string nazwa,Termin* termin) {
	this->Terminy->push_back(termin);
}


void Kalendarz::usunTermin(){

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