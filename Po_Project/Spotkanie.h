///////////////////////////////////////////////////////////
//  Spotkanie.h
//  Implementation of the Class Spotkanie
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#if !defined(EA_9AB01F80_C545_4742_B3EC_F510B8818FF1__INCLUDED_)
#define EA_9AB01F80_C545_4742_B3EC_F510B8818FF1__INCLUDED_

#include "Termin.h"
#include <iostream>
#include <string>

using namespace std;

class Spotkanie : public Termin
{

public:
	virtual ~Spotkanie();

	Spotkanie();
	void wyswietl();

private:
	string miejsce;
	string opis;

};
#endif // !defined(EA_9AB01F80_C545_4742_B3EC_F510B8818FF1__INCLUDED_)
