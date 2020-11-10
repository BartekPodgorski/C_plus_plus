#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

clock_t start, stop;
double czas;
using namespace std;

int main()
{
	int ile;
	cout << "Ile liczb w tablicy: ";
	cin >> ile;
	int *w;
	w = new int[ile];
	start = clock();
	for (int i = 0; i < ile; i++)
	{
		w[i] = i;
		w[i] += 50;
	}
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "Czas zapisu bez wskaznika:" << czas << endl;
	delete[] w;

	int *wskaznik = w;
	w = new int[ile];
	start = clock();
	for (int i = 0; i < ile; i++)
	{
		*wskaznik =i;
		*wskaznik += 50;
		wskaznik++;
	}
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;
	cout << "Czas zapisu ze skaznika:" << czas << endl; 

	system("pause");
	return 0;
}


//Tworzenie dynamicznej tablicy wkleiæ do maina
/*int ile;
	cout << "Ile liczb w tablicy: ";
	cin >> ile;
	int *w;
	w = new int[ile];
	for (int i=0; i < ile; i++)
	{
		cout <<(int)w<<"," ;
		w++;
	}
	delete [] w;*/