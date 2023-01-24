///////////////////////////////////////////////////////////
//  Zadanie.cpp
//  Implementation of the Class Zadanie
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#include "Zadanie.h"
#include "typStanu.h"

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


Zadanie::Zadanie() : Termin::Termin(){
	this->opis = "default";
	this->stan = zaplanowany;
}



Zadanie::~Zadanie(){

}





Zadanie::Zadanie(string opis) : Termin::Termin(){
	this->stan = zaplanowany;
	this->opis = opis;
}


void Zadanie::wyswietl(){
	cout << "Zadanie: " << this->tytul << "\n";
	cout << "Data: " << this->data << "\n";
	cout << "Rodzaj: " << this->rodzaj << "\n";
	cout << "Stan: " << this->stan << "\n";
	cout << "Opis: " << this->opis << "\n";
}


void Zadanie::zmienStan(typStanu stan){
	this->stan = stan;
}