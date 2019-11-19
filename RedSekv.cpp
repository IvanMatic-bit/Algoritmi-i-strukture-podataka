#include<iostream>
using namespace std;

typedef int Tip;

struct RedSekvPrez
{
	int pocetak;
	int kraj;
	Tip* niz;
	int brojac;
	int max;
public:
	RedSekvPrez(int max = 0)
	{
		pocetak = 0;
		kraj = 0;
		brojac = 0;
		this->max = max;
		niz = new Tip[max];
	}
	void Dodaj(Tip t)
	{
		if (brojac == max)
		{
			cout << "Red je pun" << endl;
			return;
		}
		niz[kraj] = t;
		kraj++;
		if (kraj == max)
			kraj = 0;
		brojac++;
	}

	Tip Ukloni()
	{
		if (brojac == 0)
			return 0;
		Tip x = niz[pocetak];
		pocetak++;
		brojac--;
		if (pocetak == 0)
			pocetak = 0;
		return x;

	}

};

void main()
{
	RedSekvPrez red(4);
	cout << "Ukloni " << red.Ukloni() << endl;
	red.Dodaj(2);
	red.Dodaj(5);
	red.Dodaj(7);
	red.Dodaj(1);
	red.Dodaj(9);
	cout << "Ukloni " << red.Ukloni() << endl;
	cout << "Ukloni " << red.Ukloni() << endl;
	cout << "Ukloni " << red.Ukloni() << endl;


}