#include <iostream>
#include <string>
#include <ctime>
#define SIZE 100000
using namespace std;

struct LIST {
	string word = "";
	int value = 0;
	bool flag = false;
	LIST *ptr= NULL;
};

int hashing(string name)
{
	int hash = 19;
	for (int i = 0; i < name.length(); i++)
		hash = (hash * 31 + name[i]) % SIZE;
	return hash;
}

int search(string name, LIST table[])
{
	int i = hashing(name);
	int k = i;
	while (true)
	{
		if (table[i].word == name)
			break;
		else if (i == k - 1)
		{
			i = -1;
			break;
		}
		else if (i == SIZE - 1)
			i = 0;
		else
			i++;
	}
	return i;
}

int main()
{
	LIST* table = new LIST[SIZE];
	string key;
	int place;
	cin >> key;
	while (key != "q")
	{
		if (key[0] == '?')
		{
			key.erase(0, 1);
			int k = search(key, table);
			if (k == -1)
				cout << "0 ";
			else
				cout << table[k].value << endl;


		}
		else if (key[0] == '-')
		{
			key.erase(0, 1);
			int k = search(key, table);
			if (k != -1)
			{
				table[k].flag = false;
				table[k].value = 0;
			}
		}
		else
		{
			place = hashing(key);
			while (true)
			{
				if (table[place].flag == false || table[place].word == key)
				{
					table[place].flag = true;
					table[place].word = key;
					table[place].value++;
					break;
				}
				else
				{
					LIST *tr = new LIST;
					tr->value = 0;
					tr->flag = true;
					tr->word = key;
					tr->ptr = NULL;
					LIST *it = table[place].ptr;
					if (it == NULL)table[place].ptr = tr;
					while (it->ptr == NULL)
					{
						it = it->ptr;
					}
					it->ptr = tr;
					delete tr;
				}
			}
		}
		cin >> key;
	}
	delete[] table;
	return 0;
}