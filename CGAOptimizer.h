#pragma once
#include <string>
#include "Klauzula.h"
#include "CGAIndividual.h"

class CGAOptimizer
{
public:
	CGAOptimizer();
	void Initialize(int rozmiar_populacji, double prawdopodobienstwo_k, double prawdopodobienstwo_m);
	void RunIteration(Klauzula lista);
	CGAIndividual wybierzRodzica(Klauzula lista);
	CGAIndividual populacja[10];

private:
	int rozwiazania;
	int rozmiar_rozwiazan;
	double Prawdopodobienstwo_krzyzowania;
	double Prawdopodobienstwo_mutacji;
	const int wielkosc_populacji = 10;//chodzi o liczbe osobników
};