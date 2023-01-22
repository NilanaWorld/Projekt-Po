///////////////////////////////////////////////////////////
//  AplikacjaTerminarz.h
//  Implementation of the Class AplikacjaTerminarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#if !defined(EA_1D566332_0583_4efe_A3E6_AD37CB2E40F1__INCLUDED_)
#define EA_1D566332_0583_4efe_A3E6_AD37CB2E40F1__INCLUDED_

#include "Kalendarz.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class AplikacjaTerminarz
{

public:
	AplikacjaTerminarz();
	virtual ~AplikacjaTerminarz();
	//Kalendarz *m_Kalendarz;

	AplikacjaTerminarz(string login, string haslo);
	void dodajKalendarz(Kalendarz* nazwa);
	void usunKalendarz(Kalendarz* nazwa);
	Kalendarz* wybierzKalendarz(string nazwa);
	void wyswietlKalendarze();
	void wyswietlKonto();

private:
	string haslo;
	vector <Kalendarz*> *Kalendarze;
	string login;

};
#endif // !defined(EA_1D566332_0583_4efe_A3E6_AD37CB2E40F1__INCLUDED_)
