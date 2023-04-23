#pragma once

class Klauzula {
	
private:
	bool czy_prawdziwa;
	int iPierwsza;
	int iDruga;
	int iTrzecia;
public:
	Klauzula();
	Klauzula(int liczba1, int liczba2, int liczba3);
	Klauzula* next;
	Klauzula* head = nullptr;
	bool get_czy_prawdziwe();
	void add(int liczba1, int liczba2, int liczba3);
	void set1(int liczba);
	void set2(int liczba);
	void set3(int liczba);
	int get1() { return iPierwsza; };
	int get2() { return iDruga; };
	int get3() { return iTrzecia; };
	void set_czy_prawdziwe(bool flag);
	void wyswietl();
	int suma();
	void usun_pierwszy();
	int size();

};