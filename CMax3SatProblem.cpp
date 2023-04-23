#include "CMax3SatProblem.h"
#include <fstream>
#include <iostream>
#include <string>

bool CMax3SatProblem::Load()
{
	std::fstream plik;
	bool bflag = false;

	plik.open("m3s_50_0.txt", std::ios::in);
	if (plik.is_open()) {
		while (!plik.eof())
		{
			char pierwszychar;
			char ostatnichar;
			int pierwszaliczba;
			int drugaliczba;
			int trzecialiczba;
			plik >> pierwszychar;
			plik >> pierwszaliczba;
			plik >> drugaliczba;
			plik >> trzecialiczba;
			plik >> ostatnichar;
			//std::cout << pierwszaliczba << " " << drugaliczba << " " << trzecialiczba << std::endl;
			lista.add(pierwszaliczba, drugaliczba, trzecialiczba);
		}
		bflag = true;
		lista.usun_pierwszy();
	}
	plik.close();

	return bflag;
}

int CMax3SatProblem::Compute(CGAIndividual populacja)
{
	int licznik = 0;
	Klauzula tmp = *lista.head;

	while (tmp.next != nullptr)
	{
		bool flag = false;
		tmp.set_czy_prawdziwe(false);
		if (tmp.get1() > 0)
		{
			if (populacja.rozwiazanie.at(tmp.get1()) == '1')
			{
				tmp.set_czy_prawdziwe(true);
				licznik++;
				flag = true;
			}
		}
		else
		{
			if (populacja.rozwiazanie.at(abs(tmp.get1())) == '0')
			{
				tmp.set_czy_prawdziwe(true);
				licznik++;
				flag = true;
			}
		}

		if (tmp.get2() > 0)
		{
			if (populacja.rozwiazanie.at(tmp.get2()) == '1')
			{
				tmp.set_czy_prawdziwe(true);
				if (flag == false)
				{
					licznik++;
					flag = true;
				}
				
			}
		}
		else
		{
			if (populacja.rozwiazanie.at(abs(tmp.get2())) == '0')
			{
				tmp.set_czy_prawdziwe(true);
				if (flag == false)
				{
					licznik++;
					flag = true;
				}
			}
		}

		if (tmp.get3() > 0)
		{
			if (populacja.rozwiazanie.at(tmp.get3()) == '1')
			{
				tmp.set_czy_prawdziwe(true);
				if (flag == false)
				{
					licznik++;
					flag = true;
				}
			}
		}
		else
		{
			if (populacja.rozwiazanie.at(abs(tmp.get3())) == '0')
			{
				tmp.set_czy_prawdziwe(true);
				if (flag == false)
				{
					licznik++;
					flag = true;
				}
			}
		}
		tmp = *tmp.next;
	}

	//std::cout << "Ile klauzul spelnionych: " << ilicznik << " " << populacja.rozwiazanie << std::endl;
	if (licznik > IleKlauzul)
	{
		IleKlauzul = licznik;
		BestResultatosobnik = populacja;
	}

	return licznik;


}

void CMax3SatProblem::wyswietl_najlepszy_rezultat()
{
	std::cout << "Ile klauzul spelnionych: " << IleKlauzul << " " << BestResultatosobnik.rozwiazanie << std::endl;
}
