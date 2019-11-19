#include<iostream>
using namespace std;



typedef int Tip;
struct PrioritetSekvRed
{
	Tip* niz;
	int brojac;
	int max;

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
	bool jePrazan()
	{
		return brojac == 0;
	}
	bool jePun()
	{
		return brojac == max;
	}
public:
	PrioritetSekvRed(int max = 0)
	{
		brojac = 0;
		this->max = max;
		niz = new Tip[max];
	}

	void Dodaj(Tip t)
	{
		if (jePun())
			ProsiriNiz();
		niz[brojac] = t;
		brojac++;
	}
	Tip Ukloni()
	{
		int maxl = 0;
		Tip maxV = niz[0];
		for (size_t i = 0; i < brojac; i++)
		{
			if (maxV < niz[i])
			{
				maxl = i;
				maxV = niz[i];
			}
		}
		brojac--;
		Tip info = niz[maxl];
		niz[maxl] = niz[brojac];
		return info;
	}
	void info()
	{
		for (size_t i = 0; i < brojac; i++)
		{
			cout << niz[i] << " ";
		}
		cout << endl;
	}
};

void main()
{
	PrioritetSekvRed red(3);
	red.Dodaj(5);
	red.Dodaj(1);
	red.Dodaj(8);
	red.Dodaj(6);
	red.info();
	cout <<"Ukloni: "<< red.Ukloni() << endl;
	cout << "Ukloni: " << red.Ukloni() << endl;
	cout << "Ukloni: " << red.Ukloni() << endl;
	red.info();
}