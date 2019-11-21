#include<iostream>
using namespace std;

class Tacka2D
{
public:
	int x,  y;

	Tacka2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Tacka2D(){}
	int GetX()
	{
		return x;
	}
	Tacka2D &operator=(const Tacka2D &t) 
	{
		if (this != &t)
		{
			this->x = t.x;
			this->y = t.y;
		}
		
		return *this;
	}
	int GetY()
	{
		return y;
	}
	bool operator==(const Tacka2D &t)const 
	{
		return x == t.x && y == t.y;
	}
	friend ostream &operator<<(ostream &o, Tacka2D &t)
	{
		o << t.x << "." << t.y;
		return o;
	}

};

struct  Cvor
{

	Tacka2D info;
	Cvor* next;
public:
	Cvor(Tacka2D info, Cvor* next)
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
	ListaPov(Tacka2D* niz, int max) :ListaPov() {}
	void Dodaj(Tacka2D t)
	{
		Cvor* novi = new Cvor(t, prvi);
		prvi = novi;
		cout << "Dodaj: " << t << endl;
		brojac++;
	}

	bool ukloni(const Tacka2D &tip)
	{
		Cvor* t = prvi;
		Cvor* pt = nullptr;

		while (t != nullptr)
		{
			if (tip == t->info)
				break;
			pt = t;
			t = t->next;
		}
		if (t == nullptr)
		{
			return false;
		}
		if (pt == nullptr)
		{
			prvi = t->next;
		}
		else
		{
			pt->next = t->next;
		}
		cout << "Uklonjen: " << t->info << endl;
		delete t;
		return true;
	}
	void IspisProvjera()
	{
		Cvor * temp = prvi;
		
		while (temp!=nullptr)
		{
			cout << temp->info << endl;
			temp = temp->next;
		}
	}
};


class HesiranjeUlancavanjem
{
	ListaPov* Niz;
	int n;
	int IzracunajHash(Tacka2D k)
	{
		int temp = sqrt(pow(k.GetX() + k.GetY(), 2) / 2) ;
		return temp % n;
	}
public:
	HesiranjeUlancavanjem(int n = 10)
	{
		Niz = new ListaPov[n];
		this->n = n;
	}
	void Dodaj(const Tacka2D &tacka)
	{
		int i = IzracunajHash(*const_cast<Tacka2D*>(&tacka));
		ListaPov& lista = Niz[i];
		lista.Dodaj(tacka);

	}
	bool Ukloni( const Tacka2D& tacka)
	{
		int i = IzracunajHash(*const_cast<Tacka2D*>(&tacka));
		ListaPov& lista = Niz[i];
		return lista.ukloni(tacka);
	}
	void Provjera()
	{
		for (size_t i = 0; i < n; i++)
		{
			cout << "----------------------------------------\nLista " << i << ":" << endl;
			Niz[i].IspisProvjera();
			cout << "----------------------------------------" << endl;
		}
		
	}
};

void main()
{
	HesiranjeUlancavanjem hesh(3);
	Tacka2D t1(2, 4);
	Tacka2D t2(3, 6);
	Tacka2D t3(7, 3);
	Tacka2D t4(5, 3);
	Tacka2D t5(4, 6);
	Tacka2D t6(3, 5);
	cout << t4 << endl;
	hesh.Dodaj(t1);
	hesh.Dodaj(t2);
	hesh.Dodaj(t5);
	hesh.Dodaj(t3);
	hesh.Dodaj(t4);
	hesh.Dodaj(t6);
	cout << "Provjera 1" << endl;
	hesh.Provjera();
	hesh.Ukloni(t1);
	hesh.Ukloni(t2);
	
	hesh.Ukloni(t3);
	hesh.Ukloni(t4);
	cout << "Provjera 3" << endl;
	hesh.Provjera();
	hesh.Ukloni(t5);
	hesh.Ukloni(t6);
	cout << "Provjera 4" << endl;
	hesh.Provjera();
	
	system("pause");
}