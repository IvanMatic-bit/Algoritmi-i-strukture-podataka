#include<iostream>
using namespace std;


typedef int Tip;
struct  Cvor
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

class ListaPov
{
	Cvor* prvi;
	int brojac = 0;
public:
	ListaPov()
	{
		prvi = nullptr;
		brojac = 0;

	}
	void Dodaj(Tip t)
	{
		Cvor* novi = new Cvor(t, prvi);
		prvi = novi;
		cout << "Dodaj: " << t << endl;
	}

	bool Ukloni(Tip tip)
	{
		Cvor* t = prvi;
		Cvor * pt = nullptr;
		while (t != nullptr)
		{
			if (t->info == tip)
				break;
			pt = t;
			t = t->next;
		}
		if (t == nullptr)
			return false;
		if (pt == nullptr)
			prvi = t->next;
		else
			pt->next = t->next;
		cout << "Uklonjen: " << t->info << endl;
		delete t;
		
		return true;
	}
};


class HesiranjeUlancavanjem
{
	ListaPov* Niz;
	int n;
	int IzracunajHash(Tip k)
	{
		return k % n;
	}
public:
	HesiranjeUlancavanjem(int n = 10)
	{
		Niz = new ListaPov[10];
		this->n = n;
	}
	void Dodaj(Tip t)
	{
		int i = IzracunajHash(t);
		ListaPov& lista = Niz[i];
		lista.Dodaj(t);
		
	}
	bool Ukloni(Tip t)
	{
		int i = IzracunajHash(t);
		ListaPov& lista = Niz[i];
		return lista.Ukloni(t);
	}
};

void main()
{
	HesiranjeUlancavanjem hesh(3);
	hesh.Dodaj(4);
	hesh.Dodaj(5);
	hesh.Dodaj(6);
	hesh.Ukloni(4);
	hesh.Dodaj(2);
	hesh.Dodaj(3);
	hesh.Ukloni(2);
	system("pause");
}