#pragma once
#include <string>
#include "CGAIndividual.h";
#include "Klauzula.h";

class CGAIndividual
{
public:
	CGAIndividual();
	std::string rozwiazanie;
	void Crossover(CGAIndividual rodzic2, CGAIndividual dziecko1, CGAIndividual dziecko2);
	void Mutation(double prawdopodobienstwomutacji);
	int Fitness(int ktoryosobnik, Klauzula lista, CGAIndividual populacja[]);
	
private:
};
