#include<iostream>
using namespace std;

typedef int Tip;
struct Cvor
{
	Tip info;
	Cvor* next;
public:
	Cvor(Tip info, Cvor* next)
	{
		this->info = info;
		this->next = next;
	}
};

class StekPovezanaRep
{
	Cvor* prvi;
	bool jePrazno()
	{
		return prvi == nullptr;
	}
public:
	StekPovezanaRep()
	{
		prvi = nullptr;
	}
	void DodajNaVrhSteka(Tip t)
	{
		Cvor* novi = new Cvor(t, prvi);
		prvi = novi;
	}

	Tip UkloniSaSteka()
	{
		if (jePrazno())
			return false;
		Cvor* t = prvi;
		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}
};

void main()
{
	StekPovezanaRep stek;
	stek.DodajNaVrhSteka(3);
	stek.DodajNaVrhSteka(4);
	stek.DodajNaVrhSteka(2);
	stek.DodajNaVrhSteka(9);
	cout << stek.UkloniSaSteka() << endl;
	cout << stek.UkloniSaSteka() << endl;
	cout << stek.UkloniSaSteka() << endl;
	cout << stek.UkloniSaSteka() << endl;
	cout << stek.UkloniSaSteka() << endl;
	
}