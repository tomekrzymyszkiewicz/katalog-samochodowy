#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
			std::cout << typSkrzyniBiegow << " ";
		}
};

std::vector <Pojazd> rejestr;

void WypisanieListySamochodow()
{
	for (int i = 0; i < rejestr.size(); i++)
	{
		std::cout << rejestr[i].marka << " ";
		std::cout << rejestr[i].model << " ";
		std::cout << rejestr[i].pojemnosc << " ";
		std::cout << rejestr[i].przebieg << " ";
		std::cout << rejestr[i].rocznik << " ";
		std::cout << rejestr[i].typSkrzyniBiegow << std::endl;
	}
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
	}
	plik.close();

}

int main()
{
	
	WczytajZapisKataloguZPliku();
	WypisanieListySamochodow();
	return 0;
}








