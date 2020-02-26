#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

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
			std::cout << marka << " ";
			std::cout << model << " ";
			std::cout << rocznik << " ";
			std::cout << pojemnosc << " ";
			std::cout << przebieg << " ";
			std::cout << typSkrzyniBiegow << std::endl;
		}
};

std::vector <Pojazd> rejestr;

void WypisanieListySamochodow()
{
	system("cls");
	for (int i = 0; i < rejestr.size(); i++)
	{
		std::cout << i + 1 << " ";
		rejestr[i].Wypisz();
		//std::cout << rejestr[i].marka;
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
		std::cout << std::endl << "Wcztano!" << std::endl;
	}
	plik.close();
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
		std::cout << "2. Wypisz zawartosc rejestru" << std::endl;
		std::cout << "3." << std::endl;
		int numerOperacji = getchar();
		switch (numerOperacji)
		{
		case '1':
			WczytajZapisKataloguZPliku();
			break;
		case '2':
			WypisanieListySamochodow();
			break;
		default:
			break;
		}
		
	} while (on);

	return 0;
}








