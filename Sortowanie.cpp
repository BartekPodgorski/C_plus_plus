#include <windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

clock_t start, stop;
double czas;

void quicksort(int *tablica, int lewy, int prawy)
{
	int v = tablica[(lewy + prawy) / 2];
	int i, j, x;
	i = lewy;
	j = prawy;
	do
	{
		while (tablica[i] < v) i++;
		while (tablica[j] > v) j--;
		if (i <= j)
		{
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > lewy) quicksort(tablica, lewy, j);
	if (i < prawy) quicksort(tablica, i, prawy);
}

void sortowanie_babelkowe(int *tab, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= 1; j--)
		{
			if (tab[j] < tab[j - 1])
			{
				int bufor;
				bufor = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = bufor;
			}
		}
	}
}

int main()
{
	int ile;
	cout << "Porównanie czasów sortowanie v.1" << endl;
	cout << "Ile losowych liczb w tablicy: ";
	cin >> ile;

	//dynamicznie alokuje tablice
	int *tablica;
	tablica = new int[ile];
	int *tablica2;
	tablica2 = new int[ile];

	//inicjuje generator liczb (pseudo)losowych
	srand(time(NULL));

	//wczytywanie losowych liczb do tablicy
	for (int i = 0; i < ile; i++)
	{
		tablica[i] = rand() % 100000 + 1;
		//cout << tablica[i] << " , ";//sprawdzenie czy dzia³a tablica losowych liczb
	}

	//przepisanie tablicy do tablicy2
	for (int i = 0; i < ile; i++)
	{
		tablica2[i] = rand() % 100000 + 1;
	}

	//babelkowe

	/*cout << "Przed posortowaniem babelkowym: " << endl;
	for (int i = 0; i < ile; i++)
	{
		cout << tablica[i] << " , ";
	}
	*/
	cout << "Sortuje babelkowo, prosze czekac!"<<endl;

	start = clock();
	sortowanie_babelkowe(tablica, ile);
	stop = clock();
	czas = (double)(stop - start)/ CLOCKS_PER_SEC;//tego to nawet szatan nie wie
	/*cout << "Po sortowaniu: " << endl;
	for (int i = 0; i < ile; i++)
	{
		cout << tablica[i] << " , ";
	}
	*/
	cout << endl << "Czas sortowania babelkowego:" << czas<<"s"<< endl;
	

	//guicksort

	/*cout << "Przed posortowaniem quicksort: " << endl;
	for (int i = 0; i < ile; i++)
	{
		cout << tablica2[i] << " , ";
	}
	*/
	cout << "Sortuje quicksort, prosze czekac!" << endl;

	start = clock();
	quicksort(tablica2, 0,ile-1);
	stop = clock();
	czas = (double)(stop - start) / CLOCKS_PER_SEC;//tego to nawet szatan nie wie
	/*cout << "Po sortowaniu: " << endl;
	for (int i = 0; i < ile; i++)
	{
		cout << tablica2[i] << " , ";
	}
	*/
	cout << endl << "Czas sortowania quicksort:" << czas << "s" << endl;
	
	delete[] tablica;
	delete[] tablica2;
	
	system("pause");
	return 0;
}
