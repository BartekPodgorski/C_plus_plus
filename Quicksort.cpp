#include<string>
#include<iostream>

using namespace std;

void swap(string *xp, string *yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}

bool isLarger(string xp, string yp) 
{
	if (xp.length() > yp.length()) return true;
	else if (xp.length() < yp.length()) return false;
	else for (int i = 0; i < xp.length(); i++)
	{
		if (xp[i] > yp[i]) 
		{ 
			return true; 
		}
		else if (xp[i] < yp[i]) 
		{ 
			return false; 
		}
		else continue;
	}
	return false;
}

void quick_sort(string *arr, int left, int right)
{
	if (right <= left) return;

	int i = left, j = right;
	string pivot = arr[(left + right) / 2];

	while (1)
	{
		while (isLarger(pivot, arr[i])) 
		{ 
			i++; 
		}
		while (isLarger(arr[j], pivot)) 
		{ 
			j--; 
		}
		if (i <= j) 
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else
			break;
	}

	if (j > left)
		quick_sort(arr, left, j);
	if (i < right)
		quick_sort(arr, i, right);
}

int main() {
	int N;
	cin >> N;
	string* array = new string[N];
	for (int i = 0; i < N; i++) 
		cin >> array[i];
	quick_sort(array, 0, N - 1);
	for (int i = 0; i < N; i++) 
		cout << array[i] << endl;
	return 0;
}