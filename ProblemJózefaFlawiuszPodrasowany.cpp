#include <iostream>
#include <math.h>
using namespace std;

long long int ostatni(long long int n);
long long int dowolna(long long int n, long long int k);

int main()
{
	int test;
	cin >> test;
	long long int *tablica = new long long int[test];
	for (int i = 0; i < test; ++i)
	{
		long long int n = 0;
		long long int k = 0;
		scanf_s("%lld", &n);
		scanf_s("%lld", &k);
		if (k < 0) k = k + n + 1;
		if (k <= (n / 2))tablica[i] = 2 * k;
		else if (k == n)tablica[i] = ostatni(n);
		else tablica[i] = dowolna(n, k);
	}
	for (long long int j = 0; j < test; j++)
	{
		printf("%lld\n", tablica[j]);
	}
	delete[] tablica;
	return 0;
}

long long int ostatni(long long int n)
{
	for (long long int a = 1; a < n; a *= 2) 
	{
		n -= a;
	}
	return  (n * 2) - 1;
}

long long int dowolna(long long int n, long long int k)
{
	k = n - k + 1;
	n = n - (2 * k - 1);
	for (long long int i = (2 * k) - 1; i <= n; i *= 2) 
	{
		n -= i;
	}
	return n * 2 + 1;
}