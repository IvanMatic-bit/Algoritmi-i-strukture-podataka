#include<iostream>

using namespace std;

void BubbleSort(int* niz, int n)
{
	bool promjena = true;
	int pom;
	
	while (promjena)
	{
		promjena = false;
		
		for (size_t i = 0; i < n-1; i++)
		{
			if (niz[i] > niz[i + 1])
			{
				pom = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = pom;
				promjena = true;
			}
		}
	}
}





void InsertionSort(int *niz, int n)
{
	int i, j, pom;
	for (size_t i = 0; i < n; i++)
	{
		j = i;
		while (j>0 && niz[j-1]>niz[j])
		{
			pom = niz[j - 1];
			niz[j - 1] = niz[j];
			niz[j] = pom;
			j--;
		}
	}
}

void QuickSort(int* niz, int low, int high)
{
	if (low < high)
	{
		int pivotLoc = low;
		for (int i = pivotLoc+1; i <=high; i++)
		{
			if (niz[i] < niz[pivotLoc])
			{
				pivotLoc++;
				swap(niz[i], niz[pivotLoc]);
			}
		}
		swap(niz[low], niz[pivotLoc]);
		QuickSort(niz, 0, pivotLoc - 1);
		QuickSort(niz, pivotLoc+1, high);
	}
}

void Merge(int *niz, int* tempNiz, int pocetak1, int pocetak2, int size1, int size2)
{
	int i = pocetak1, j = pocetak2, k = pocetak1;
	while (i<pocetak1+size1 && j<pocetak2+size2)
	{
		if (niz[i] < niz[j])
		{
			tempNiz[k] = niz[i];
			i++;
		}
		else
		{
			tempNiz[k] = niz[j];
			j++;
		}
		k++;
	}
	while (i<pocetak1+size1)
	{
		tempNiz[k] = niz[i];
		k++; i++;
	}
	while (j<pocetak2+size2)
	{
		tempNiz[k] = niz[j];
		k++; j++;
	}
	for (size_t i = 0; i < pocetak1+size1+size2; i++)
	{
		niz[i] = tempNiz[i];
	}
}

void MergeSort(int* niz, int* tempNiz, int poc, int size)
{
	if (size > 1)
	{
		int pocetak2 = poc + size / 2;
		int size1 = pocetak2 - poc;
		int size2 = size - size1;
		int pocetak1 = poc;

		MergeSort(niz, tempNiz, pocetak1, size1);
		MergeSort(niz, tempNiz, pocetak2, size2);
		Merge(niz, tempNiz, pocetak1, pocetak2, size1, size2);
	}
}

void SelectionSort(int* niz, int max)
{
	int pom, minIndex;
	for (size_t i = 0; i < max-1; i++)
	{
		minIndex = i;
		for (size_t j = i+1; j < max; j++)
		{
			if (niz[j] < niz[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
		{
			swap(niz[i], niz[minIndex]);
		}
	}
}




void Ispis(int niz[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
}

void main()
{
	int niz[]{  1, 85, 21, 3, 33, 456, 18 , 70, 45,12, 321, 123 };
	int temp[]{ 1, 85, 21, 3, 33, 456, 18 , 70, 45,12, 321, 123 };
	int max = sizeof(niz) / sizeof(niz[0]);
	cout << "Ispis nesortiranog niza" << endl;
	Ispis(niz, max);
	//BubbleSort(niz, max);
	//InsertionSort(niz, max);
	//QuickSort(niz, 0, max-1);
	//MergeSort(niz, temp, 0, max);
	SelectionSort(niz, max);
	
	cout << "Ispis  sortiranog niza" << endl;
	Ispis(niz, max);
}