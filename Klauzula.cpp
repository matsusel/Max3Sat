#include "Klauzula.h"
#include <iostream>


Klauzula::Klauzula()
{
	next = nullptr;
	iPierwsza = 0;
	iDruga = 0;
	iTrzecia = 0;
	czy_prawdziwa = false;
}

Klauzula::Klauzula(int liczba1, int liczba2, int liczba3)
{
	iPierwsza = liczba1;
	iDruga = liczba2;
	iTrzecia = liczba3;
	czy_prawdziwa = false;
	//next = nullptr;

}

void Klauzula::set1(int liczba)
{
	iPierwsza = liczba;
}

void Klauzula::set2(int liczba)
{
	iDruga = liczba;
}

void Klauzula::set3(int liczba)
{
	iTrzecia = liczba;
}

void Klauzula::add(int liczba1, int liczba2, int liczba3)
{
	Klauzula* tmp = new Klauzula(liczba1, liczba2, liczba3);
	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}

void Klauzula::set_czy_prawdziwe(bool flag)
{
	czy_prawdziwa = flag;
}

void Klauzula::wyswietl()
{
	Klauzula* tmp = head;
	int i = 0;
	while (tmp->next != nullptr)
	{
		std::cout << tmp->iPierwsza << " " << tmp->iDruga << " " << tmp->iTrzecia << " " << ++i << std::endl;
		tmp = tmp->next;
	}
}

int Klauzula::suma()
{
	Klauzula* tmp = head;
	int licznik = 0;
	while (tmp->next != nullptr)
	{
		if (tmp->get_czy_prawdziwe() == true)
		{
			licznik++;
		}
		tmp = tmp->next;
	}
	return licznik;
}

void Klauzula::usun_pierwszy()
{
	head = head->next;
}

int Klauzula::size()
{
	Klauzula* tmp = head;
	int licznik = 0;
	while (tmp->next != nullptr)
	{
		licznik++;
		tmp = tmp->next;
	}
	return licznik;
}

bool Klauzula::get_czy_prawdziwe()
{
	return czy_prawdziwa;
}