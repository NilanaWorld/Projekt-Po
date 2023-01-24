///////////////////////////////////////////////////////////
//  Kalendarz.h
//  Implementation of the Class Kalendarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#if !defined(EA_20A53B12_0336_465a_B15E_02961E3D4FD6__INCLUDED_)
#define EA_20A53B12_0336_465a_B15E_02961E3D4FD6__INCLUDED_

#include "Termin.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Kalendarz
{
public:
	Kalendarz();
	virtual ~Kalendarz();
	Termin *m_Termin;

	Kalendarz(string nazwa,string login);
	void dodajTermin(Termin* termin);
	void dodajTermin();
	void usunTermin();
	Termin* wybierzTermin(string nazwa);
	void wyswietlKalendarz();
	void wyswietlTerminy();
	string dajNazwe();
	string getLogin();

private:
	string nazwa;
	vector <Termin*> *Terminy;
	string login;
};
#endif // !defined(EA_20A53B12_0336_465a_B15E_02961E3D4FD6__INCLUDED_)
