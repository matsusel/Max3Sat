#include "CGAIndividual.h"
#include "Klauzula.h"
#include <random>
#include <time.h>
#include <iostream>
#include <string>

CGAIndividual::CGAIndividual()
{
}

void CGAIndividual::Crossover( CGAIndividual rodzic2, CGAIndividual dziecko1, CGAIndividual dziecko2)
{
	for (int i = 0; i < rozwiazanie.size(); i++)
	{
		int Rand = rand() % 2;
		//std::cout << Rand << std::endl;
		if (Rand == 1)
		{
			dziecko1.rozwiazanie += rozwiazanie.at(i);
			dziecko2.rozwiazanie += rodzic2.rozwiazanie.at(i);
		}
		else
		{
			dziecko1.rozwiazanie += rodzic2.rozwiazanie.at(i);
			dziecko2.rozwiazanie += rozwiazanie.at(i);
		}
	}
}

void CGAIndividual::Mutation(double prawdopodobienstwomutacji)
{
	std::mt19937;
	std::string zmutowane = "";
	for (int i = 0; i < rozwiazanie.size(); i++)
	{
		double dRand = ((double)rand() / (double)RAND_MAX);
		//std::cout << dRand << " " << prawdopodobienstwomutacji << "ddd" << (prawdopodobienstwomutacji < dRand) << std::endl;
		if (prawdopodobienstwomutacji < dRand)
		{
			if (rozwiazanie.at(i) == '1')
			{
				zmutowane += "0";
			}
			else
			{
				zmutowane += "1";
			}

		}
		else
		{
			zmutowane += rozwiazanie.at(i);
		}
	}
	rozwiazanie = zmutowane;
}

int CGAIndividual::Fitness(int ktoryosobnik, Klauzula lista, CGAIndividual populacja[])
{
	Klauzula tmp = *lista.head;

	while (tmp.next != nullptr)
	{
		tmp.set_czy_prawdziwe(false);
		if (tmp.get1() > 0)
		{
			if (populacja[ktoryosobnik].rozwiazanie.at(tmp.get1()) == '1')
			{
				tmp.set_czy_prawdziwe(true);
			}
		}
		else
		{
			if (populacja[ktoryosobnik].rozwiazanie.at(abs(tmp.get1())) == '0')
			{
				tmp.set_czy_prawdziwe(true);
			}
		}

		if (tmp.get2() > 0)
		{
			if (populacja[ktoryosobnik].rozwiazanie.at(tmp.get2()) == '1')
			{
				tmp.set_czy_prawdziwe(true);
			}
		}
		else
		{
			if (populacja[ktoryosobnik].rozwiazanie.at(abs(tmp.get2())) == '0')
			{
				tmp.set_czy_prawdziwe(true);
			}
		}

		if (tmp.get3() > 0)
		{
			if (populacja[ktoryosobnik].rozwiazanie.at(tmp.get3()) == '1')
			{
				tmp.set_czy_prawdziwe(true);
			}
		}
		else
		{
			if (populacja[ktoryosobnik].rozwiazanie.at(abs(tmp.get3())) == '0')
			{
				tmp.set_czy_prawdziwe(true);
			}
		}
		tmp = *tmp.next;
	}

	return lista.suma();
}
