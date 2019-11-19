#pragma once


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
	Cvor()
	{
		
	}
};


class ListaPov
{
private:
	Cvor* prvi;
	int brojac = 0;

public:
	ListaPov()
	{
		brojac = 0;
		prvi = nullptr;
	}
	ListaPov(Tip *niz, int max):ListaPov(){}

	void Dodaj(Tip tip)
	{
		Cvor* t = new Cvor(tip, prvi);
		prvi = t;
		brojac++;
	}

	Tip Ukloni()
	{
		if (brojac == 0)
			return 0;
		brojac--;
		Cvor * t = prvi;
		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}

	bool Ukloni(Tip tip)
	{
		Cvor* t = prvi;
		Cvor  * pt = nullptr;
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
		delete t;
		return true;
	}

};


