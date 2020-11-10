#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int test; 
	int vertice;
	int sum;
	int pair = 0;
	bool cycle = true;
	string sequence;
	cin >> test;
	for (int i = 0; i <test; i++) 
	{
		cin >> vertice;
		cin >> sequence;
		sum = 0;
		for (int j = 0; j < vertice; j++)
		{
			for (int m = 0; m < vertice; m++)
			{
				if (sequence[vertice*j + m] == '1')
				{
					sum++;
					pair++;
				}
			}
			if (pair != 2) cycle = false;
			pair = 0;
		}
		if (vertice * (vertice - 1) == sum || (cycle && vertice % 2))
			cout << "True" << endl;
		else 
			cout << "False" << endl;
		cycle = true;
	}

	return 0;
}