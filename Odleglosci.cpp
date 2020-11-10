#include <iostream>
#include<math.h>
using namespace std;

int tower(double l, int d, int k);
int bishop(double l, int d, int k);
int king(double l, int d, int k);

int main() 
{
	int k, h, d, test;
	double l;
	cin >> test;
	for (int i = 0; i < test; i++) 
	{
		cin >> d >> l >> k >> h;
		if (h == 1)printf("%d\n", int(tower(l, d, k)));
		if (h == 2) 
		{
			int p = l;
			if (d < 2 || k == 0 || p % 2 == 0) printf("%s\n", "Inf");
			else printf("%d\n", int(bishop(l, d, k) / (l*l - 1)));
		}
		if (h == 0)
			printf("%d\n", int(king(l, d, k) / (l*l - 1)));
	}
	return 0;
}

int tower(double l, int d, int k)
{
	int i = l;
	double ans = 0;
	if (k == 0)
	{
		int a1 = 2;	
		int a2 = 0;
		for (int c = 0; c < l; c++)
		{
			ans += a2;
			a2 += a1;
			a1 += 2;
		}
		return int((d*ans) / ((l*l) - 1));
	}
	if (k == 1)
	{
		double ans2;
		if (i % 2 == 0)ans2 = (((l + 2) / 2)*(l - 1) - (l - 2) / 2) / 2;
		else ans2 = ((l + 1) / 2)*(l - 1) / 2;
		double ans3 = ans2;
		for (int h = 0; h < l - 1; h++)
		{
			ans3 += l;
			ans2 += ans3;
		}
		ans += 2 * ans2 / l;
		int sum = l * (l - 2);
		int minus = 2 * l;
		if (i % 2 == 0)
		{
			for (int c = (l - 2) / 2; c > 0; c--)
			{
				ans2 -= sum;
				sum -= minus;
				ans += 2 * ans2 / l;
			}
		}
		else
			for (int c = (l - 1) / 2; c > 0; c--)
			{
				ans2 -= sum;
				sum -= minus;
				if (c == 1)ans += ans2 / l;
				else ans += 2 * ans2 / l;
			}
		return int(ans / (l*l - 1));
	}
	else
	{
		if (i % 2 == 0)
		{
			ans += l;
			int q = 0;
			int j = 1;
			for (int n = (l / 2) - 1; n > 0; n--)
			{
				q += 4;
				ans = ans + (q*j);
				j++;
			}
			ans = ans + (q + 2)*j; j++;
			ans = ans + (q * j); j++;
			for (int m = (l / 2) - 2; m > 0; m--)
			{
				q -= 4;
				ans = ans + (q * j);
				j++;
			}
			return int(ans / (l*l - 1));
		}
		else
		{
			int q = 0;
			int j = 1;
			for (int n = (i / 2); n > 0; n--)
			{
				q += 4;
				ans = ans + (j*q);
				j++;
			}
			ans += q * j; j++;
			for (int m = (i / 2) - 1; m > 0; m--)
			{
				q -= 4;
				ans = ans + (q*j); j++;
			}
			return int(ans / (l*l - 1));
		}
	}
}

int bishop(double l, int d, int k) 
{
	int i = l;
	double ans = 0;
	if (d == 2 && k == 1) 
	{
		int ans2 = bishop(l, d, 2);
		int f = (l - 1) / 2;
		int w = 0;
		if (f % 2 == 0) {
			w = 3; f--;
		}
		else  w = 1;
		for (int m = (f + 1) / 2; m > 0; m--) 
		{
			ans2 += 2 * w * f;
			w += 4;
			f -= 2;
		}
		ans += ans2 / l;
		int ans3 = (l - 1) / 2;
		if (ans3 % 2 == 0)ans3 += 1;
		for (int n = (l - 1) / 2; n > 0; n--) 
		{
			ans2 += ans3;
			ans3 += (l + 1);
			ans += 2 * ans2 / l;
			if (n % 2 == 0)ans3 -= 2;
		}
		return int(ans);
	}
	else if (d == 2 && k == 2 && i % 2 != 0) 
	{
		ans = (2 * (l + 1)*(l - 1) / 4 * l);
		return int(ans);
	}
	else return d;
}

int king(double l, int d, int k)
{
	double ans = 0;
	int i = l;
	if (k == 0)
	{
		double ans2 = 0;
		int w = 3;
		for (int s = 1; s < l; s++)
		{
			ans2 += w * s;
			w += 2;
		}
		ans += 4 * ans2 / l;
		int o = 0;
		if (i % 2 == 0)
		{
			for (int s = 2; s <= (l - 1); s += 2)
			{
				ans2 -= (l + 1)*(l - s) / 2;
				ans += 8 * ans2 / l;
				double ans3 = ans2;
				o += s / 2;
				int sum = (l + 1)*(l - 2) / 2 - o * 2 + (s / 2)*l;
				int minus = l + 3;
				for (int y = 2; y <= (l - 1); y += 2)
				{
					ans3 -= sum;
					if (y == (l - 1))ans += 2 * ans3 / l;
					else ans += 4 * ans3 / l;
					if (y > 2 && y <= s)minus += 2;
					sum -= minus;
				}
			}
			return int(ans / l);
		}
		else
		{
			for (int s = 2; s <= (l - 1); s += 2)
			{
				ans2 -= (l + 1)*(l - s) / 2;
				if (s == (l - 1))ans += 4 * ans2 / l;
				else ans += 8 * ans2 / l;
				double ans3 = ans2;
				o += s / 2;
				int sum = (l + 1)*(l - 2) / 2 - o * 2 + (s / 2)*l;
				int minus = l + 3;
				for (int y = 2; y <= (l - 1); y += 2)
				{
					ans3 -= sum;
					if (y == s && y == (l - 1))ans += ans3 / l;
					else if (y == (l - 1) || s == (l - 1))ans += 2 * ans3 / l;
					else ans += 4 * ans3 / l;
					if (y > 2 && y <= s)minus += 2;
					sum -= minus;
				}
			}
			return int(ans / l);
		}
	}
	else if (k == 1)
	{
		if (i % 2 == 0)
		{
			double *table = new double[l / 2];
			double ans3 = 0;
			double ans2 = king(l, d, 2);
			ans += 2 * ans2 / l;
			int j = 1;
			for (int m = (l - 2) / 2; m > 0; m--)
			{
				ans3 = (l - j)*l - ((l / 2 + j)*(l - (2 * j - 2)) / 2 - l / 2 + (2 * j - 1)*j);
				table[j - 1] = ans3;
				j++;
			}
			for (int n = (l - 2) / 2; n > 0; n--)
			{
				ans2 += table[n - 1];
				ans += 2 * ans2 / l;
			}
			delete[] table;
			return int(ans);
		}
		else
		{
			double *table = new double[(l - 1) / 2];
			double ans3 = 0;
			double ans2 = king(l, d, 2);
			ans += ans2 / l;
			int j = 1;
			for (int m = (l - 1) / 2; m > 0; m--)
			{
				ans3 = ((l - j)*l) - ((((l - 1) / 2 + j)*(l - (j * 2 - 1))) / 2 + (j * 2 - 1)* j);
				table[j - 1] = ans3;
				j++;
			}
			for (int n = (l - 1) / 2; n > 0; n--)
			{
				ans2 += table[n - 1];
				ans += 2 * ans2 / l;
			}
			delete[] table;
			return int(ans);
		}
	}
	else if (k == 2)
	{
		if (i % 2 == 0)
		{
			int q = 0;
			int j = 1;
			for (int n = (l / 2) - 1; n > 0; n--)
			{
				q += 8;
				ans += j * q;
				j++;
			}
			ans = ans + ((l + l - 1)*j);
			return ans;
		}
		else
		{
			int q = 0;
			int j = 1;
			for (int m = l / 2; m > 0; m--)
			{
				q += 8;
				ans += j * q;
				j++;
			}
			return ans;
		}
	}
	else return 1;
}