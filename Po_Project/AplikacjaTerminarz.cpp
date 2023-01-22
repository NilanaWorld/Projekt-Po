///////////////////////////////////////////////////////////
//  AplikacjaTerminarz.cpp
//  Implementation of the Class AplikacjaTerminarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#include "AplikacjaTerminarz.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;


AplikacjaTerminarz::AplikacjaTerminarz(){
	this->login = "niewiem";
	this->haslo = "niewiem";
	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1 = new Kalendarz("podstawowy");
	this->Kalendarze->push_back(k1);
}



AplikacjaTerminarz::~AplikacjaTerminarz(){

}





AplikacjaTerminarz::AplikacjaTerminarz(string login, string haslo){
	this->login = login;
	this->haslo = haslo;

	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1 = new Kalendarz("podstawowy");
	this->Kalendarze->push_back(k1);
}


void AplikacjaTerminarz::dodajKalendarz(Kalendarz* nazwa){
	this->Kalendarze->push_back(nazwa);
}


void AplikacjaTerminarz::usunKalendarz(Kalendarz* nazwa){

}


Kalendarz* AplikacjaTerminarz::wybierzKalendarz(string nazwa){
	for (int i = 0; i < this->Kalendarze->size(); i++)
	{
		if (((*Kalendarze)[i])->dajNazwe() == nazwa) return (*Kalendarze)[i];
	}
	return  nullptr;
}


void AplikacjaTerminarz::wyswietlKalendarze(){
	for (int i = 0; i < this->Kalendarze->size(); i++)
	{
		((*Kalendarze)[i])->wyswietlKalendarz();
	}
}


void AplikacjaTerminarz::wyswietlKonto(){
	cout <<"Login: " << this->login << "\n";
	cout << "Haslo: " << this->haslo << "\n";
	cout << "Kalendarze:\n";
	this->wyswietlKalendarze();
}