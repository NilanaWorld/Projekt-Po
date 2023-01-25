///////////////////////////////////////////////////////////
//  Zadanie.h
//  Implementation of the Class Zadanie
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#if !defined(EA_C34DDF94_69B5_46c8_9FD5_9962B765CF62__INCLUDED_)
#define EA_C34DDF94_69B5_46c8_9FD5_9962B765CF62__INCLUDED_

#include "Termin.h"
#include "typStanu.h"
#include <iostream>
#include <string>

using namespace std;

class Zadanie : public Termin
{

public:
	Zadanie();
	virtual ~Zadanie();

	Zadanie(string tytul, string data, string opis);
	void wyswietl();
	void zmienStan(typStanu stan);

private:
	string opis;
	typStanu stan;

};
#endif // !defined(EA_C34DDF94_69B5_46c8_9FD5_9962B765CF62__INCLUDED_)
