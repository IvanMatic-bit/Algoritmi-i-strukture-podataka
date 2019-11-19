#include<iostream>
using namespace std;

typedef int Tip;

class StekSekvRep
{
	Tip* niz;
	int max;
	int brojac;
public:
	StekSekvRep(int max)
	{
		this->max = max;
		brojac = 0;
		niz = new Tip[max];
	}
	bool jePun()
	{
		return brojac == max;

	}
	bool jePrazan()
	{
		return brojac == 0;
	}
	void ProsiriNiz()
	{
		int noviMax = max * 2;
		Tip* noviNiz = new Tip[noviMax];
		for (size_t i = 0; i < max; i++)
		{
			noviNiz[i] = niz[i];
		}
		delete[]niz;
		niz = noviNiz;
		max = noviMax;
	}

	void DodajNaVrhSteka(Tip t)
	{
		if (jePun())
			ProsiriNiz();
		niz[brojac] = t;
		brojac++;
	}
	Tip UkloniSaSteka()
	{
		if (jePrazan())
		{
			cout << "Stek je prazan" << endl;
			return false;
		}
		Tip x = niz[--brojac];
		
		return x;
	}

};

void main()
{
	StekSekvRep stek(5);
	stek.UkloniSaSteka();
	stek.DodajNaVrhSteka(2);
	stek.DodajNaVrhSteka(6);
	stek.DodajNaVrhSteka(2);
	stek.DodajNaVrhSteka(1);
	stek.DodajNaVrhSteka(7);
	stek.DodajNaVrhSteka(8);
	cout << stek.UkloniSaSteka() << endl;
	cout << stek.UkloniSaSteka() << endl;
	cout << stek.UkloniSaSteka() << endl;
}