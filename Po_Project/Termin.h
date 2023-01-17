///////////////////////////////////////////////////////////
//  Termin.h
//  Implementation of the Class Termin
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#if !defined(EA_F85C05B0_EB58_46b7_AE12_36625D3ED35D__INCLUDED_)
#define EA_F85C05B0_EB58_46b7_AE12_36625D3ED35D__INCLUDED_

#include "typTerm.h"
#include <iostream>
#include <string>

using namespace std;

class Termin
{

public:
	Termin();
	virtual ~Termin();

	Termin(string data, string tytul, typTerm rodzaj);
	void edytujDate(string nowaData);
	virtual void wyswietl();

protected:
	string data;
	typTerm rodzaj;
	string tytul;

};
#endif // !defined(EA_F85C05B0_EB58_46b7_AE12_36625D3ED35D__INCLUDED_)
