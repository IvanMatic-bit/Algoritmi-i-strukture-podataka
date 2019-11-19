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


struct PrioritetRedPov
{
	Cvor* prvi;
public:
	PrioritetRedPov()
	{
		prvi = nullptr;
	}
	void Dodaj(Tip t)
	{
		Cvor* novi = new Cvor(t, nullptr);
		Cvor* temp = prvi;
		Cvor* pt = nullptr;
		while (temp!=nullptr)
		{
			if (novi->info > temp->info)
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
	Tip Ukloni()
	{
		Cvor* temp = prvi;
		prvi = prvi->next;
		Tip x = temp->info;
		delete temp;
		return x;
	}
};

void main()
{
	PrioritetRedPov red;
	red.Dodaj(4);
	red.Dodaj(2);
	red.Dodaj(5);
	red.Dodaj(6);
	cout << red.Ukloni() << endl;
	cout << red.Ukloni() << endl;
	cout << red.Ukloni() << endl;
	cout << red.Ukloni() << endl;
}