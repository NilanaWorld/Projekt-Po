///////////////////////////////////////////////////////////
//  Termin.cpp
//  Implementation of the Class Termin
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#include "Termin.h"
#include "typTerm.h"

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;


Termin::Termin(){
	this->data = "12.12.2012";
	this->tytul = "kartkowka";
	this->kolor = 0;
	this->rodzaj = zadanie;
}



Termin::~Termin(){

}




Termin::Termin(string data, string tytul, typTerm rodzaj){
	this->data = data;
	this->tytul = tytul;
	this->rodzaj = rodzaj;
	this->kolor = 0;
}

string Termin::dajTytul(){
	return this->tytul;
}

void Termin::edytujDate(string nowaData){
	this->data = nowaData;
}

 void Termin::wyswietl(){
	cout <<"Termin: " << this->tytul << "\n";
	cout <<"data: " << this->data << "\n";
	cout <<"rodzaj: " << this->rodzaj<< "\n";
}