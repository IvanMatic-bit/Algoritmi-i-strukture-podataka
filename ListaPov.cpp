#include<iostream>
#include"ListaPovezana.h"
using namespace std;



void main()
{
	ListaPov lista1;
	lista1.Dodaj(3);
	lista1.Dodaj(2);
	lista1.Dodaj(5);
	lista1.Dodaj(6);
	lista1.Dodaj(11);
	cout << lista1.Ukloni() << endl;
	cout << lista1.Ukloni() << endl;
	if (lista1.Ukloni(2))
		cout << "Uklonjen 2" << endl;
	if (lista1.Ukloni(11))
		cout << "Uklonjen 11" << endl;
	lista1.Dodaj(9);
	cout << lista1.Ukloni() << endl;
	cout << lista1.Ukloni() << endl;
}