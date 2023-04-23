#include "CGAOptimizer.h"
#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include "Klauzula.h"
#include "CGAIndividual.h"

CGAOptimizer::CGAOptimizer()
{
	for (int i = 0; i < wielkosc_populacji; i++)
		populacja[i].rozwiazanie = "";

}

void CGAOptimizer::Initialize(int rozmiar_populacji, double prawdopodobienstwo_k, double prawdopodobienstwo_m)
{
	std::mt19937;
	for (int i = 0; i < wielkosc_populacji; i++)
	{
		for (int j = 0; j < rozmiar_populacji; j++)
		{
			int iRand = rand() % 2;
			if (iRand == 1)
				populacja[i].rozwiazanie += "1";
			else
				populacja[i].rozwiazanie += "0";

		}
		//std::cout << "Numer: " << i << " " << populacja[i].rozwiazanie << std::endl;
	}

}

void CGAOptimizer::RunIteration(Klauzula lista)
{
	std::mt19937;
	for (int i = 0; i < wielkosc_populacji; i++) 
	{
		//std::cout << "Numer: " << i << " " << populacja[i].rozwiazanie << std::endl;
	}
	

	CGAIndividual nowapopulacja[10];
	int ilejestwnowejosobnikow = 0;
	for (int i = 0; i < 10; i++)
	{
		nowapopulacja[i].rozwiazanie = "";
	}
	while (ilejestwnowejosobnikow != populacja[9].rozwiazanie.size())
	{
		CGAIndividual rodzic1, rodzic2, dziecko1, dziecko2;
		rodzic1 = wybierzRodzica(lista);
		rodzic2 = wybierzRodzica(lista);
		//std::cout << "Numer: 1 "<< rodzic1.rozwiazanie << " Numer: 2 " << rodzic2.rozwiazanie << std::endl;
		double dRand = ((double)rand() / (double)RAND_MAX);
		//std::cout << dRand << std::endl;
		if (dRand < Prawdopodobienstwo_krzyzowania)
		{
			rodzic1.Crossover(rodzic2, dziecko1, dziecko2);
		}
		else
		{
			dziecko1 = rodzic1;
			dziecko2 = rodzic2;
		}
		//std::cout << "dziecko: 1 " << dziecko1.rozwiazanie << " dziecko: 2 " << dziecko2.rozwiazanie << std::endl;
		dziecko1.Mutation(Prawdopodobienstwo_mutacji);
		dziecko2.Mutation(Prawdopodobienstwo_mutacji);
		//std::cout << "MUTACJA dziecko: 1 " << dziecko1.rozwiazanie << " dziecko: 2 " << dziecko2.rozwiazanie << std::endl;

		nowapopulacja[ilejestwnowejosobnikow] = dziecko1;
		ilejestwnowejosobnikow++;
		nowapopulacja[ilejestwnowejosobnikow] = dziecko2;
		ilejestwnowejosobnikow++;
		std::cout << ilejestwnowejosobnikow << std::endl;
	}
	for (int i = 0; i < wielkosc_populacji; i++)
	{
		//std::cout << "NumerNoa: " << i << " " << nowapopulacja[i].rozwiazanie << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		populacja[i] = nowapopulacja[i];
	}
	for (int i = 0; i < wielkosc_populacji; i++)
	{
		//std::cout << "NumerKoniec: " << i << " " << populacja[i].rozwiazanie << std::endl;
	}
}

CGAIndividual CGAOptimizer::wybierzRodzica(Klauzula lista)
{
	std::mt19937;
	int iRand1 = rand() % 10;
	int iRand2;
	int wynik1 = -1;
	int wynik2 = -1;
	do
	{
		iRand2 = rand() % 10;
	} while (iRand2 == iRand1);

	wynik1 = populacja->Fitness(iRand1, lista, populacja);

	wynik2 = populacja->Fitness(iRand2, lista, populacja);

	if (wynik1 >= wynik2)
		return populacja[iRand1];
	else
		return populacja[iRand2];

}


