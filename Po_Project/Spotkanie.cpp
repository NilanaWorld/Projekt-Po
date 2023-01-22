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





Spotkanie::Spotkanie() : Termin::Termin(){
	this->miejsce = "default";
	this->opis = "default";
}


void Spotkanie::wyswietl(){
	cout << "Spotkanie: " << this->tytul << "\n";
	cout << "data: " << this->data << "\n";
	cout << "rodzaj: " << this->rodzaj << "\n";
	cout << "miejsce: " << this->miejsce << "\n";
	cout << "opis: " << this->opis << "\n";
}