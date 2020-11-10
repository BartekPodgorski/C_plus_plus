#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int f(int n)
{
	if (n == 0) return 3;//przypadek podstawowy
	else return f(n - 1) + 2;//przypadek z³o¿ony
}
long int potega(int p, int w)
{
	if (w == 0) return 1;
	else return  p * potega(p,w - 1);
}
long int fib(int n)
{
	if (n == 1 || n == 2) return 1;
	else  return fib(n - 1) + fib(n - 2);
}
long int silnia(int n)
{
	if (n == 0) return 1;
	else return n*silnia(n-1);//¿eby wiedzia³o z czego wywo³aæ to n
}
int main()
{
	//cout << f(4)<<endl;
	//cout << potega(3, 4) << endl;
	//cout << fib(6) << endl;
	cout << silnia(5) << endl;
	system("pause");
	return 0;
}