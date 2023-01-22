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
	this->tytul = zadanie;
	this->kolor = 1;
	this->rodzaj = zadanie;
}



Termin::~Termin(){

}





Termin::Termin(string data, string tytul, typTerm rodzaj){
	this->data = data;
	this->tytul = tytul;
	this->rodzaj = rodzaj;
	this->kolor = kolor;
}


void Termin::edytujDate(string nowaData){

}


void Termin::wyswietl(){

	return;
}