///////////////////////////////////////////////////////////
//  AplikacjaTerminarz.cpp
//  Implementation of the Class AplikacjaTerminarz
//  Created on:      17-sty-2023 20:06:39
//  Original author: user
///////////////////////////////////////////////////////////

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "AplikacjaTerminarz.h"
#include "Konto.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <filesystem>
#include <tchar.h>
#include <experimental/filesystem>
#include <stdio.h>
#include <direct.h>
using namespace std;

using namespace std::experimental::filesystem;
using namespace std::experimental::filesystem::v1;


AplikacjaTerminarz::AplikacjaTerminarz(){
	this->login = "niewiem";
	this->haslo = "niewiem";
	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1 = new Kalendarz("Default",login);
	this->Kalendarze->push_back(k1);
}



AplikacjaTerminarz::~AplikacjaTerminarz(){

}

void AplikacjaTerminarz::wczytywanieDanych()
{
	//ladowanie danych
	//lista plikow w folderze
	string path2 = "./Konta/" + login + "/";
	string nazwa;
	string linia, tytul, data, opis, miejsce;
	int typ, stan;
	int poz1, poz2;

	//lista kalendarzy
	for (const auto& entry : directory_iterator(path2))
	{
		nazwa = entry.path().generic_string();
		string path2 = entry.path().generic_string();
		const char* pathKal = path2.c_str();

		//cout << entry.path().generic_string() << endl;
		nazwa = nazwa.substr(nazwa.rfind("/") + 1, nazwa.size());
		nazwa.pop_back();
		nazwa.pop_back();
		nazwa.pop_back();
		nazwa.pop_back();

		//cout << "nazwa: " << nazwa << endl;

		Kalendarz* k1 = new Kalendarz(nazwa, login);
		this->Kalendarze->push_back(k1);

		//lista terminow
		fstream fpDKal;
		fpDKal.open(pathKal, ios::in);//otwieranie kalendarza i pobieranie tresci z niego
		if (fpDKal.good())
		{
			while (getline(fpDKal, linia))
			{
				typ = (int)linia[0] - 48;
				//cout << "typ: " << typ << endl;
				poz1 = posStr(linia, ',', 1);
				poz2 = posStr(linia, ',', 2);
				tytul = linia.substr(poz1 + 1, poz2 - poz1 - 1);
				//cout << "tytul: " << tytul << endl;
				poz1 = posStr(linia, ',', 2);
				poz2 = posStr(linia, ',', 3);
				data = linia.substr(poz1 + 1, poz2 - poz1 - 1);
				//cout << "data: " << data << endl;
				poz1 = posStr(linia, ',', 3);
				poz2 = posStr(linia, ',', 4);
				opis = linia.substr(poz1 + 1, poz2 - poz1 - 1);
				//cout << "opis: " << opis << endl;


				if (typ == 0)
				{
					poz1 = posStr(linia, ',', 4);
					poz2 = linia.size();
					miejsce = linia.substr(poz1 + 1, poz2);
					//cout << "miejsce: " << miejsce << endl;
					k1->dodajTermin(typ, tytul, data, opis, miejsce);
				}
				else
				{
					poz1 = posStr(linia, ',', 4);
					stan = (int)((linia.substr(poz1 + 1, 1)).c_str()[0]) - 48;
					//cout << "stan: " << stan << endl;
					k1->dodajTermin(typ, tytul, data, opis, (typStanu)stan);
				}
			}
		}

		fpDKal.close();
	}
	//system("pause");
}



AplikacjaTerminarz::AplikacjaTerminarz(string login, string haslo){
	this->login = login;
	this->haslo = haslo;

	this->Kalendarze = new vector <Kalendarz*>();
	Kalendarz* k1;

	fstream fpDKal;
	string path2 = "./Konta/" + login + "/Default.txt";
	const char* pathKal = path2.c_str();
	fpDKal.open(pathKal, ios::app);//tworzenie domyslnego kalendarza jeœli nie istnieje
	fpDKal.close();

	wczytywanieDanych();
}

void AplikacjaTerminarz::dodajKalendarz(string nazwa,string login){
	Kalendarz* kalendarz = new Kalendarz(nazwa,login);
	this->Kalendarze->push_back(kalendarz);

	fstream fpDKal;
	string path2 = "./Konta/" + login + "/" + nazwa + ".txt";//tworzenie kalendarza
	const char* pathKal = path2.c_str();
	fpDKal.open(pathKal, ios::app);
	fpDKal.close();
}


void AplikacjaTerminarz::usunKalendarz(string nazwa) {
	//1.usuwa z listy
	bool flag=false;
	Kalendarz* r = nullptr;
	auto it = find_if(Kalendarze->begin(), Kalendarze->end(), [&](Kalendarz* p)
		{
			if (nazwa == p->dajNazwe())
			{
				flag = true;
				r = p;
				return true;
			}
			return false; });
	Kalendarze->erase(it);			//	erase sie psuje gdy nie ma kalendarza

	if (flag == false)
	{
		cout << "Kalendarz nie istnieje\n";
	}
	else
	{
		//2.usuwa plik

		string path2 = "./Konta/" + login + "/" + nazwa + ".txt";
		const char* pathKal = path2.c_str();

		if (remove(pathKal) != 0)
			cout << "Error deleting file";
		else
			cout << "File successfully deleted\n";
	}
}


Kalendarz* AplikacjaTerminarz::wybierzKalendarz(string nazwa){
	for (int i = 0; i < this->Kalendarze->size(); i++)
	{
		if (((*Kalendarze)[i])->dajNazwe() == nazwa) return (*Kalendarze)[i];
	}
	return  nullptr;
}


void AplikacjaTerminarz::wyswietlKalendarze(){
	cout << "KALENDARZE:\n";
	for (int i = 0; i < this->Kalendarze->size(); i++)
	{
		((*Kalendarze)[i])->wyswietlKalendarz();
	}
}


void AplikacjaTerminarz::wyswietlKonto(){
	cout << "KONTO:\n";
	cout <<"Login: " << this->login << "\n";
	cout << "Haslo: " << this->haslo << "\n";
	cout << "Kalendarze:\n";
	this->wyswietlKalendarze();
}

string AplikacjaTerminarz::getLogin()
{
	return login;
}

void  AplikacjaTerminarz::usunKonto()
{

	//std::experimental::filesystem::_Remove_dir();
	
	fstream fp, tmp;
	string line,nazwa2;
	int n = login.length();
	fp.open("konta.txt", ios::in);
	tmp.open("tmp.txt", ios::app);
	int poz1;
	if (fp.good()) {
		while (getline(fp, line))
		{
			poz1 = posStr(line, ',', 1);
			nazwa2 = line.substr(0, poz1 );
			//cout << "N: " << nazwa2 << endl;
			if (strncmp(nazwa2.c_str(), login.c_str(), n) != 0)
			{
				//cout << nazwa2 << " " << login << endl;
				tmp << line << "\n";
			}
		}
		string core = ws2s(ExePath());
		string coreFinal;
		core.pop_back(); core.pop_back();
		core.pop_back(); core.pop_back();
		core.pop_back(); core.pop_back();
		for (int i = 0; i < core.length(); i++)
		{
			if (core[i] == '/') {
				coreFinal.push_back('\\');
				coreFinal.push_back('\\');
			}
			else {
				coreFinal.push_back(core[i]);
			}

		}
		//cout << "coreF: " << coreFinal << endl;

		string KalPath = coreFinal + "\\konta.txt";
		string TmpPath = coreFinal + "\\tmp.txt";
		const char* KalPath1 = KalPath.c_str();
		const char* TmpPath1 = TmpPath.c_str();

		fp.close();
		tmp.close();

		if (remove(KalPath1) != 0)
			perror("Error removing file\n");
		else
			cout << "File removed successfully\n";

		if (rename(TmpPath1, KalPath1) != 0)
			perror("Error rename file");
		else
			cout << "File rename successfully\n";

		string UPath = coreFinal + "\\Konta\\" + login;
		const char* UPath1 = UPath.c_str();

		remove_all(UPath);

		if (rmdir(UPath1) == -1)						//usuwanie pustego folderu, z jakiegos powodu wyskakuje blad ale dziala O_o
		{
			//perror("Error deleting folder\n");
		}
		else
		{
			//cout << "Pomyslnie usunieto konto\n";
		}

		exit(0);
	}
}