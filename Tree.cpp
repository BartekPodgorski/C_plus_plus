#include <iostream>
#include<string>
#define LITERY 26
using namespace std;

struct Trie
{
	struct Trie *litery[LITERY];
	bool koniecSlowa;
	string tlumacznie;
};

struct Trie *getWezel(void)
{
	struct Trie *wezel = new Trie;
	wezel->koniecSlowa = false;
	wezel->tlumacznie = "NULL";
	for (int i = 0; i < LITERY; i++)
		wezel->litery[i] = NULL;
	return wezel;
}

void dodaj(struct Trie *korzen, string slowo, string tlumaczenie)
{
	struct Trie *wezel = korzen;
	for (int i = 0; i < (int)slowo.length(); i++)
	{
		int index = slowo[i] - 'a';
		if (!wezel->litery[index])
			wezel->litery[index] = getWezel();

		wezel = wezel->litery[index];
	}
	wezel->koniecSlowa = true;
	wezel->tlumacznie = tlumaczenie;
}

void szukaj(struct Trie *korzen, string slowo)
{
	struct Trie *wezel = korzen;
	for (int i = 0; i < (int)slowo.length(); i++)
	{
		int index = slowo[i] - 'a';
		if (!wezel->litery[index]) {
			cout << "-" << endl;
			return;
		}
		wezel = wezel->litery[index];
	}
	if (wezel != NULL && wezel->koniecSlowa) {
		cout << wezel->tlumacznie << endl;
		return;
	}
	else {
		cout << "-" << endl;
		return;
	}
}

void szukajAll(struct Trie *wezel) {
	for (int i = 0; i < LITERY; i++) {
		if (wezel->litery[i]) {
			if (wezel->litery[i]->koniecSlowa)
				cout << wezel->litery[i]->tlumacznie << endl;
			szukajAll(wezel->litery[i]);
		}
	}
}

void prefix(struct Trie *korzen, string slowo) {
	struct Trie *wezel = korzen;
	for (int i = 0; i < (int)slowo.length(); i++)
	{
		int index = slowo[i] - 'a';
		if (!wezel->litery[index]) {
			cout << "-" << endl;
			return;
		}
		wezel = wezel->litery[index];
	}
	if (wezel->tlumacznie != "NULL")
		cout << wezel->tlumacznie << endl;
	szukajAll(wezel);
	return;

}

int main() {
	struct Trie *korzen = getWezel();
	char znak = 'a';
	string slowo, tlumaczenie;
	while (cin >> znak) {
		switch (znak)
		{
		case '+':
			cin >> slowo >> tlumaczenie;
			dodaj(korzen, slowo, tlumaczenie);
			break;

		case '?':
			cin >> slowo;
			szukaj(korzen, slowo);
			break;
		case '*':
			cin >> slowo;
			prefix(korzen, slowo);
			break;
		}
	}
	return 0;
}