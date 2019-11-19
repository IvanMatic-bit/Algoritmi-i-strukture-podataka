#include<iostream>
using namespace std;

struct Tacka3D
{

public:
	int x, y, z;
	Tacka3D()
	{

	}
	Tacka3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}



	bool operator==(Tacka3D t)
	{
		return this->x == t.x && this->y == t.y && this->z == t.z;
	}
};

typedef Tacka3D Tip;

class HashingOtvorenoAdresiranje
{
private:
	Tip* niz;
	bool* zauzeto;
	int brojac;
	int max_vel;
	int hash1(Tip t)
	{
		return sqrt(pow(t.x, 2) / 3 + pow(t.y, 2) / 3 + pow(t.z, 2) / 3);

	}

	int hash2(Tip t)
	{
		return sqrt(pow(t.x + t.y + t.z, 2));
	}
	int hashFunkcija(Tip t, int pokusaj)
	{
		return (hash1(t) + pokusaj * hash2(t)) % max_vel;
	}
public:
	HashingOtvorenoAdresiranje() {}
	HashingOtvorenoAdresiranje(int max)
	{
		brojac = 0;
		max_vel = max;
		zauzeto = new bool[max] {false};
		niz = new Tip[max];
	}


	void Dodaj(Tip t)
	{
		if (brojac == max_vel)
			throw exception("Greska. Hash tabela je puna");
		int brPokusaja = 0;
		int p;
		while (true)
		{
			brPokusaja++;
			p = hashFunkcija(t, brPokusaja);
			if (!zauzeto[p])
				break;
		}
		zauzeto[p] = true;
		niz[p] = t;
		brojac++;
		cout << "Tacka " << t.x << "." << t.y << "." << t.z << "je uspesno dodata" << endl;

	}

	bool Ukloni(Tip t)
	{
		if (brojac == 0)
			throw exception("Greska. Hash tabela je prazna");

		int pokusaj = 0;
		int p;
		while (pokusaj <= brojac)
		{
			pokusaj++;
			p = hashFunkcija(t, pokusaj);
			if (zauzeto[p] && niz[p] == t)
			{
				zauzeto[p] = false;
				brojac--;
				cout << "Tacka " << t.x << "." << t.y << "." << t.z << "je uspesno uklonjena" << endl;
				return true;
			}
		}
		cout << "Trazeni element " << t.x << "." << t.y << "." << t.z << " nije pronadjen" << endl;
		return false;
	}
};


void main()
{
	Tacka3D t1(1, 2, 3);
	Tacka3D t2(5, 4, 6);
	Tacka3D t3(3, 5, 7);
	Tacka3D t4(6, 7, 1);
	Tacka3D t5(4, 3, 8);

	HashingOtvorenoAdresiranje hash(3);
	/*try
	{
		hash.Ukloni(t2);
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}*/

	try
	{
		hash.Dodaj(t1);

	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	hash.Ukloni(t1);
	hash.Dodaj(t2);
	hash.Dodaj(t4);
	hash.Ukloni(t4);
	hash.Ukloni(t2);
	try
	{
		hash.Ukloni(t1);
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}


	system("pause");
}