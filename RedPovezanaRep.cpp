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

struct RedPovezanaPrez
{
	Cvor* pocetak;
	Cvor* kraj;
public:
	RedPovezanaPrez()
	{
		pocetak = nullptr;
		kraj = nullptr;
	}
	void Dodaj(Tip t)
	{
		Cvor* novi = new Cvor(t, nullptr);

		if (kraj != nullptr)
			kraj->next = novi;
		else
			pocetak = novi;

		kraj = novi;
		cout << "Element " << kraj->info << " uspsjeno dodat" << endl;

	}

	Tip Ukloni()
	{
		Cvor* temp = pocetak;
		pocetak = pocetak->next;
		Tip t = temp->info;
		delete temp;
		if (pocetak == nullptr)
			kraj = nullptr;
		return t;
	}

	void info()
	{
		Cvor* temp = pocetak;
		while (temp!=nullptr)
		{
			cout <<  temp->info << endl;
			temp = temp->next;
		}
	}
};


void main()
{
	RedPovezanaPrez red;
	red.Dodaj(3);
	red.Dodaj(6);
	red.Ukloni();
	red.Dodaj(7);
	red.Dodaj(2);
	red.info();
	red.Ukloni();
	red.Ukloni();
	red.Ukloni();
	red.info();
}