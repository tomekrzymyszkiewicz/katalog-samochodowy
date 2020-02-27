﻿#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "katalog-samochodowy.h"

class Pojazd
{
public:
		std::string marka;
		std::string model;
		int rocznik;
		float pojemnosc;
		int przebieg;
		char typSkrzyniBiegow;
		void Wypisz()
		{
			std::cout.width(12);
			std::cout << std::left << marka << " ";
			std::cout.width(12);
			std::cout << std::left << model << " ";
			std::cout.width(7);
			std::cout << std::left << rocznik << " ";
			std::cout.width(9);
			std::cout << std::left << pojemnosc << " ";
			std::cout.width(9);
			std::cout << std::left << przebieg << " ";
			std::cout.width(7);
			std::cout << std::left << typSkrzyniBiegow << std::endl;
			
		}
};

std::vector <Pojazd> rejestr;

void WypisanieListySamochodow()
{
	system("cls");
	printf("lp  Marka        Model        Rocznik Pojemnosc Przebieg  Skrzynia \n");
	for (int i = 0; i < rejestr.size(); i++)
	{
		std::cout.width(3);
		std::cout << std::left << i + 1 << " ";
		rejestr[i].Wypisz();
	}
	system("pause");
}

void WczytajZapisKataloguZPliku()
{
	std::ifstream plik;
	plik.open("katalog.txt", std::ios::in);
	if (plik.is_open() == true)
	{
		while (!plik.eof())
		{
			Pojazd nowyPojazd;
			plik >> nowyPojazd.marka;
			plik >> nowyPojazd.model;
			plik >> nowyPojazd.pojemnosc;
			plik >> nowyPojazd.przebieg;
			plik >> nowyPojazd.rocznik;
			plik >> nowyPojazd.typSkrzyniBiegow;
			if(nowyPojazd.marka != "" && nowyPojazd.model != "" && nowyPojazd.pojemnosc != NULL && nowyPojazd.przebieg != NULL && nowyPojazd.rocznik != NULL)
			rejestr.push_back(nowyPojazd);
		}
		std::cout << "Wczytano!" << std::endl;
	}
	plik.close();
	system("pause");
}

void ZapiszZapisKataloguZPliku()
{
	if (rejestr.size() == 0)
	{
		std::cout << "Nie wczytano danych do zapisu" << std::endl;
		system("pause");
		return;
	}
	std::ofstream plik;
	plik.open("katalog.txt", std::ios::trunc);
		if (plik.is_open() == true)
		{
			for(int i = 0; i < rejestr.size(); i++)
			{
				plik << rejestr[i].marka << " ";
				plik << rejestr[i].model << " ";
				plik << rejestr[i].pojemnosc << " ";
				plik << rejestr[i].przebieg << " ";
				plik << rejestr[i].rocznik << " ";
				plik << rejestr[i].typSkrzyniBiegow << std::endl;
			}
			rejestr.clear();
			std::cout << "Zapisano!" << std::endl;
		}
	plik.close();
	system("pause");

}

void WypisanieKonkretnegoSamochodu()
{
	int nrPojazdu;
	do {
		system("cls");
		std::cout << "Podaj nr pojazdu do wypisania: ";
		std::cin >> nrPojazdu;
		if (nrPojazdu > rejestr.size() || nrPojazdu <= 0)
		{
			std::cout << "Nie ma takiego pojazdu w rejestrze!";
			system("pause");
		}
	} while (nrPojazdu > rejestr.size() || nrPojazdu <= 0);
	system("cls");
	printf("lp  Marka        Model        Rocznik Pojemnosc Przebieg  Skrzynia \n");
	std::cout.width(3);
	std::cout << std::left << nrPojazdu << " ";
	rejestr[nrPojazdu-1].Wypisz();
	system("pause");
}

void UsuwanieSamochodu()
{
	int nrPojazdu;
	do {
		system("cls");
		std::cout << "Podaj nr pojazdu do usuniecia: ";
		std::cin >> nrPojazdu;
		if (nrPojazdu > rejestr.size() || nrPojazdu <= 0)
		{
			std::cout << "Nie ma takiego pojazdu w rejestrze!";
			system("pause");
		}
	} while (nrPojazdu > rejestr.size() || nrPojazdu <= 0);
	rejestr.erase(rejestr.begin()+nrPojazdu-1);
	std::cout << "Poprawnie usunieto pojazd nr " << nrPojazdu << std::endl;
	system("pause");
}

int main()
{
	bool on = true;
	do
	{
		system("CLS");
		std::cout << "KATALOG SAMOCHODOWY" << std::endl << "WYBIERZ OPERACJE" <<std::endl;
		std::cout << "1. Wczytaj baze danych z pliku" << std::endl;
		std::cout << "2. Zapisz baze danych do pliku" << std::endl;
		std::cout << "3. Wypisz zawartosc rejestru" << std::endl;
		std::cout << "4. Wypisz dane konkretnego pojazdu" << std::endl;
		std::cout << "5. Usun samochod z rejestru" << std::endl;
		std::cout << "ESC. Wyjscie" << std::endl;
		int numerOperacji = _getch();
		switch (numerOperacji)
		{
		case '1':
			WczytajZapisKataloguZPliku();
			break;
		case '2':
			ZapiszZapisKataloguZPliku();
			break;
		case '3':
			WypisanieListySamochodow();
			break;
		case '4':
			WypisanieKonkretnegoSamochodu();
			break;
		case '5':
			UsuwanieSamochodu();
			break;
		case 27:
			on = false;
			break;
		default:
			break;
		}
		
	} while (on);

	return 0;
}

