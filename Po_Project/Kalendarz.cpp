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

}



Kalendarz::~Kalendarz(){

}





Kalendarz::Kalendarz(string nazwa){
	this->nazwa = nazwa;
	this->Terminy = new vector<Termin*>();
}


void Kalendarz::dodajTermin(string opis, string data, string tytul, string miejsce){

}


void Kalendarz::dodajTermin(string data, string opis, string tytul){

}


void Kalendarz::usunTermin(){

}


Termin* Kalendarz::wybierzTermin(string nazwa){

	return  NULL;
}


void Kalendarz::wyswietlKalendarz(){
	cout << this->nazwa << "\n";
}


void Kalendarz::wyswietlTerminy(){

}