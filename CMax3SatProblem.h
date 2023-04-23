#pragma once
#include "Klauzula.h"
#include "CGAIndividual.h"


class CMax3SatProblem
{
public:
	bool Load();
	int Compute(CGAIndividual rozwiazanie);
	Klauzula lista = Klauzula();
	CGAIndividual BestResultatosobnik;
	int IleKlauzul = 0;
	void wyswietl_najlepszy_rezultat();
private:
	
};