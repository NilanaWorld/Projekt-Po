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
	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1 = new Kalendarz("podstawowy");
	this->Kalendarze->push_back(k1);
}



AplikacjaTerminarz::~AplikacjaTerminarz(){

}





AplikacjaTerminarz::AplikacjaTerminarz(string login, string haslo){

}


void AplikacjaTerminarz::dodajKalendarz(Kalendarz* nazwa){
	this->Kalendarze->push_back(nazwa);
}


void AplikacjaTerminarz::usunKalendarz(Kalendarz* nazwa){

}


Kalendarz* AplikacjaTerminarz::wybierzKalendarz(string nazwa){

	return  nullptr;
}


void AplikacjaTerminarz::wyswietlKalendarze(){
	for (int i = 0; i < Kalendarze->size(); i++)
	{
		((*Kalendarze)[i])->wyswietlKalendarz();
	}
}


void AplikacjaTerminarz::wyswietlKonto(){

}