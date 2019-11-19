#include<iostream>
using namespace std;


template<class Tip>
class ListaSekv
{
private:
	Tip* N;
	int brojac;
	int max;

	void ProsiriListu()
	{
		int noviMax = max * 2;
		Tip* noviNiz = new Tip[noviMax];
		for (size_t i = 0; i < max; i++)
		{
			noviNiz[i] = N[i];
		}
		delete[]N;
		N = noviNiz;
		max = noviMax;
	}
	bool jePrazan()
	{
		return brojac == 0;
	}

public:
	ListaSekv(int max = 10)
	{
		this->max = max;
		N = new Tip[max];
		brojac = 0;
	}
	ListaSekv(Tip* niz, int velicina, int max = 10)
	{
		for (size_t i = 0; i < velicina; i++)
		{
			N[i] = niz[i];
		}
	}
	void Dodaj(Tip t)
	{
		if (brojac == max)
		{
			ProsiriListu();
		}
		N[brojac] = t;
		brojac++;
	}
	Tip Ukloni()
	{
		if (jePrazan())
			throw exception("Greska. Lista je prazna");
		brojac--;
		Tip x = N[brojac];
		return x;
	}
};


void main()
{
	ListaSekv<int> lista;
	lista.Dodaj(2);
	lista.Dodaj(5);
	lista.Dodaj(1);
	lista.Dodaj(3);
	cout << lista.Ukloni() << endl;
	cout << lista.Ukloni() << endl;
	cout << lista.Ukloni() << endl;
	cout << lista.Ukloni() << endl;
	try
	{
		cout << lista.Ukloni() << endl;
	}
	catch (exception&ex)
	{
		cout << ex.what() << endl;
	}
	
}