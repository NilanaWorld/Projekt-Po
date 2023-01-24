///////////////////////////////////////////////////////////
//  Spotkanie.cpp
//  Implementation of the Class Spotkanie
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#include "Spotkanie.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


Spotkanie::~Spotkanie(){

}


Spotkanie::Spotkanie(string miejsce,string opis) : Termin::Termin(){
	this->miejsce = miejsce;
	this->opis = opis;
}


void Spotkanie::wyswietl(){
	cout << "Spotkanie: " << this->tytul << "\n";
	cout << "Data: " << this->data << "\n";
	cout << "Rodzaj: " << this->rodzaj << "\n";
	cout << "Miejsce: " << this->miejsce << "\n";
	cout << "Opis: " << this->opis << "\n";
}