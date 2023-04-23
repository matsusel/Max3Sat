#include <iostream>
#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"

int main()
{
	CMax3SatProblem problem;
	CGAOptimizer opt;
	problem.Load();
	//problem.lista.wyswietl();
	opt.Initialize(50,0.7,0.3);
	//problem.lista.wyswietl();
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << "///////////////////////////" << std::endl;
		opt.RunIteration(problem.lista);
		for (int j = 0; j < 10; j++)
		{
			//problem.lista.wyswietl();
			problem.Compute(opt.populacja[j]);
		}
		//problem.wyswietl_najlepszy_rezultat();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	problem.wyswietl_najlepszy_rezultat();
}