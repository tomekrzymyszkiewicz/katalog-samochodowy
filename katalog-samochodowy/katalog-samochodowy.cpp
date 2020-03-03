#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include <sstream>

class Pojazd
{
public:
		std::string marka;
		std::string model;
		int rocznik;
		float pojemnosc;
		int przebieg;
		char typSkrzyniBiegow;
		Pojazd() 
		{
			marka = "Marka";
			model = "Model";
			rocznik = 0000;
			pojemnosc = 0;
			przebieg = 0;
			typSkrzyniBiegow = 'B';
		}
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
		const Pojazd& operator=(const Pojazd& pojazd)
		{
			this->marka = pojazd.marka;
			this->model = pojazd.model;
			this->rocznik = pojazd.rocznik;
			this->pojemnosc = pojazd.pojemnosc;
			this->przebieg = pojazd.przebieg;
			this->typSkrzyniBiegow = pojazd.typSkrzyniBiegow;
			return *this;
		}
		//DEFINICJE SORTOWANIA
		static bool poMarce (Pojazd& A, Pojazd& B) 
		{
			return A.marka < B.marka;
		}
		static bool poModelu(Pojazd& A, Pojazd& B)
		{
			return A.model < B.model;
		}
		static bool poRoczniku(Pojazd& A, Pojazd& B)
		{
			return A.rocznik < B.rocznik;
		}
		static bool poPojemnosci(Pojazd& A, Pojazd& B)
		{
			return A.pojemnosc < B.pojemnosc;
		}
		static bool poPrzebiegu(Pojazd& A, Pojazd& B)
		{
			return A.przebieg < B.przebieg;
		}
		static bool poSkrzyni(Pojazd& A, Pojazd& B)
		{
			return A.typSkrzyniBiegow < B.typSkrzyniBiegow;
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
			Pojazd *nowyPojazd = new Pojazd;
			plik >> (*nowyPojazd).marka;
			plik >> (*nowyPojazd).model;
			plik >> (*nowyPojazd).pojemnosc;
			plik >> (*nowyPojazd).przebieg;
			plik >> (*nowyPojazd).rocznik;
			plik >> (*nowyPojazd).typSkrzyniBiegow;
			if((*nowyPojazd).marka != "" && (*nowyPojazd).model != "" && (*nowyPojazd).pojemnosc != NULL && (*nowyPojazd).przebieg != NULL && (*nowyPojazd).rocznik != NULL && (*nowyPojazd).typSkrzyniBiegow == 'A' || (*nowyPojazd).typSkrzyniBiegow == 'M')
			rejestr.push_back(*nowyPojazd);
			delete nowyPojazd;
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
				Pojazd *doZapisania = new Pojazd;
				*doZapisania = rejestr[i];
				plik << (*doZapisania).marka << " ";
				plik << (*doZapisania).model << " ";
				plik << (*doZapisania).pojemnosc << " ";
				plik << (*doZapisania).przebieg << " ";
				plik << (*doZapisania).rocznik << " ";
				plik << (*doZapisania).typSkrzyniBiegow << std::endl;
				delete doZapisania;
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

void DodajNowySamochod()
{
	Pojazd nowyPojazd;
	system("cls");
	std::cout << "Dodwanie nowego samochodu" << std::endl;
	std::cout << "Marka: ";
	std::cin >> nowyPojazd.marka;
	std::cout << "Model: ";
	std::cin >> nowyPojazd.model;
	std::cout << "Pojemnosc: ";
	std::cin >> nowyPojazd.pojemnosc;
	std::cout << "Przebieg: ";
	std::cin >> nowyPojazd.przebieg;
	std::cout << "Rocznik: ";
	std::cin >> nowyPojazd.rocznik;
	std::cout << "Typ skrzyni biegow (A/M): ";
	std::cin >> nowyPojazd.typSkrzyniBiegow;
	rejestr.push_back(nowyPojazd);
	std::cout << "Wczytano prawidlowo pojazd" << std::endl;
	system("pause");
}

void SortowaniePoWybranymElemencie() 
{
	system("cls");
	std::cout << "Wybierz parametr wedlug ktorego chcesz posortowac dane:" << std::endl;
	std::cout << "1. Marka" << std::endl;
	std::cout << "2. Model" << std::endl;
	std::cout << "3. Rocznik" << std::endl;
	std::cout << "4. Pojemnosc" << std::endl;
	std::cout << "5. Przebieg" << std::endl;
	std::cout << "6. Typ skrzyni biegow" << std::endl;
	int parametr;
	parametr = _getch();
	switch (parametr)
	{
	case '1':
		std::sort(rejestr.begin(), rejestr.end(), Pojazd::poMarce);
		std::cout << "Posortowano" << std::endl;
		break;
	case '2':
		std::sort(rejestr.begin(), rejestr.end(), Pojazd::poModelu);
		std::cout << "Posortowano" << std::endl;
		break;
	case '3':
		std::sort(rejestr.begin(), rejestr.end(), Pojazd::poRoczniku);
		std::cout << "Posortowano" << std::endl;
		break;
	case '4':
		std::sort(rejestr.begin(), rejestr.end(), Pojazd::poPojemnosci);
		std::cout << "Posortowano" << std::endl;
		break;
	case '5':
		std::sort(rejestr.begin(), rejestr.end(), Pojazd::poPrzebiegu);
		std::cout << "Posortowano" << std::endl;
		break;
	case '6':
		std::sort(rejestr.begin(), rejestr.end(), Pojazd::poSkrzyni);
		std::cout << "Posortowano" << std::endl;
		break;
	default:
		std::cout << "Nieprawidlowo wybrano parametr";
		break;
	}
	system("pause");
}

void WyswietlanieWarunkowe()
{
	system("cls");
	std::cout << "Wybierz parametr wedlug ktorego chcesz wyswietlac:" << std::endl;
	std::cout << "1. Marka" << std::endl;
	std::cout << "2. Model" << std::endl;
	std::cout << "3. Rocznik" << std::endl;
	std::cout << "4. Pojemnosc" << std::endl;
	std::cout << "5. Przebieg" << std::endl;
	std::cout << "6. Typ skrzyni biegow" << std::endl;
	int parametr;
	parametr = _getch();
	std::cout << "Wybierz rodzaj warunku: " << std::endl;
	std::cout << "1. Zawiera" << std::endl;
	std::cout << "2. Wieksze lub rowne niz" << std::endl;
	std::cout << "3. Mniejsze niz" << std::endl;
	int warunek;
	warunek = _getch();
	std::string tresc;
	std::cout << "Podaj tresc warunku: ";
	std::cin >> tresc;
	std::stringstream strumienZLiczba(tresc);
	float liczba;
	strumienZLiczba >> liczba;
	char skrzynia;
	tresc.copy(&skrzynia,1);
	int licznik = 0;
	printf("lp  Marka        Model        Rocznik Pojemnosc Przebieg  Skrzynia \n");
	switch (parametr)
	{
	case '1':
		switch (warunek)
		{
		case '1':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].marka.compare(tresc) == 0)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '2':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].marka.compare(tresc) > 0)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '3':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].marka.compare(tresc) < 0)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		default:
			std::cout << "Podano nieprawidlowy warunek" << std::endl;
			system("pause");
			break;
		}
		break;
	case '2':
		switch (warunek)
		{
		case '1':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].model.compare(tresc) == 0)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '2':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].model.compare(tresc) > 0)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '3':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].model.compare(tresc) < 0)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		default:
			std::cout << "Podano nieprawidlowy warunek" << std::endl;
			system("pause");
			break;
		}
		break;
	case '3':
		switch (warunek)
		{
		case '1':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].rocznik == liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '2':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].rocznik >= liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '3':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].rocznik < liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		default:
			std::cout << "Podano nieprawidlowy warunek" << std::endl;
			system("pause");
			break;
		}
		break;
	case '4':
		switch (warunek)
		{
		case '1':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].pojemnosc == liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '2':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].pojemnosc >= liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '3':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].pojemnosc < liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		default:
			std::cout << "Podano nieprawidlowy warunek" << std::endl;
			system("pause");
			break;
		}
		break;
	case '5':
		switch (warunek)
		{
		case '1':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].przebieg == liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '2':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].przebieg >= liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '3':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].przebieg < liczba)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		default:
			std::cout << "Podano nieprawidlowy warunek" << std::endl;
			system("pause");
			break;
		}
		break;
	case '6':
		switch (warunek)
		{
		case '1':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].typSkrzyniBiegow == skrzynia)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '2':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].typSkrzyniBiegow >= skrzynia)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		case '3':
			for (int i = 0; i < rejestr.size(); i++)
			{
				if (rejestr[i].typSkrzyniBiegow < skrzynia)
				{
					std::cout.width(3);
					std::cout << std::left << licznik + 1 << " ";
					rejestr[i].Wypisz();
					licznik++;
				}
			}
			system("pause");
			break;
		default:
			std::cout << "Podano nieprawidlowy warunek" << std::endl;
			system("pause");
			break;
		}
		break;
	default:
		std::cout << "Podano nieprawidlowy parametr" << std::endl;
		system("pause");
		break;
	}
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
		std::cout << "6. Dodaj samochod do rejestru" << std::endl;
		std::cout << "7. Sortuj wedlug wybranego parametru" << std::endl;
		std::cout << "8. Wyswietlanie wedlug warunku" << std::endl;
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
		case '6':
			DodajNowySamochod();
			break;
		case '7':
			SortowaniePoWybranymElemencie();
			break;
		case '8':
			WyswietlanieWarunkowe();
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