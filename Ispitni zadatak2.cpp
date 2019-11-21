//Zadatak: Prioritetni red pov
//Elementi prioritetnog reda predstavljaju tačke u koordinatnom sistemu(u 3D prostoru).
//Implementirajte kompletan Prioriteni red(povezana reprezentacija).Funkcija ukloni treba da ukloni tačku koja se nalazi najbliže tački A(0, 0, 0).


#include<iostream>
using namespace std;



class Tacka3D
{
	
public:
	int x, y, z;
	double IzracunajUdaljenost(Tacka3D t)
	{
		return sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2));
	}
	Tacka3D(){}
	Tacka3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;

	}
	bool operator==(const Tacka3D t)
	{
		return
			x == t.x
			&& y == t.y
			&& z == t.z;
	}
	friend ostream& operator <<(ostream& o, Tacka3D t)
	{
		o << t.x << "." << t.y << "." << t.z << endl;
		return o;
	}
	Tacka3D& operator =(const Tacka3D& t)
	{
		if (this != &t)
		{
			x = t.x;
			y = t.y;
			z = t.z;
		}
		return *this;
	}
	bool operator <(const Tacka3D t)
	{
		return IzracunajUdaljenost(*this) < IzracunajUdaljenost(t);
	}
};


struct Cvor
{
	Tacka3D info;
	Cvor* next;
public:
	Cvor(Tacka3D info, Cvor* next)
	{
		this->info = info;
		this->next = next;
	}
};


struct PrioritetRedPov
{
	Cvor* prvi;
public:
	PrioritetRedPov()
	{
		prvi = nullptr;
	}
	void Dodaj(Tacka3D t)
	{
		Cvor* novi = new Cvor(t, nullptr);
		Cvor* temp = prvi;
		Cvor* pt = nullptr;
		while (temp != nullptr)
		{
			if (novi->info < temp->info)
				break;
			pt = temp;
			temp = temp->next;
		}
		if (pt == nullptr)
			prvi = novi;
		else
			pt->next = novi;
		novi->next = temp;
	}
	Tacka3D Ukloni()
	{
		Cvor* temp = prvi;
		prvi = prvi->next;
		Tacka3D x = temp->info;
		delete temp;
		return x;
	}
};

void main()
{
	Tacka3D t1(1, 1, 2);
	Tacka3D t2(0, 1, 0);
	Tacka3D t3(5, 6, 7);
	Tacka3D t4(9, 9, 9);
	PrioritetRedPov red;
	red.Dodaj(t4);
	red.Dodaj(t1);
	red.Dodaj(t2);
	red.Dodaj(t3);
	cout << red.Ukloni() << endl;
	cout << red.Ukloni() << endl;
	cout << red.Ukloni() << endl;
	cout << red.Ukloni() << endl;
}
