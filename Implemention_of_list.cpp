#include <iostream>
using namespace std;
struct List {
	int key;
	List *next;
	List *prev;
};
void add(List **root, List **begin, int key2) {
	List *nowa = new List;
	nowa->key = key2;
	nowa->next = NULL;
	if ((*begin) == NULL) {
		(*begin) = nowa;
		(*root) = nowa;
		nowa->prev = NULL;
	}
	else {
		nowa->prev = (*root);
		(*root)->next = nowa;
		(*root) = nowa;
		nowa->next = NULL;
	}
}
int get(List *begin, int key2) {
	if (key2 == 0) return begin->key;
	else {
		for (int num = 0; num < key2; num++) {
			begin = begin->next;
		}
		return begin->key;
	}
}

int del(List **root) {
	List *n = (*root);
	(*root) = (*root)->prev;
	return n->key;
}

int main() {
	List *beg = NULL;
	List *head = NULL;
	List *begin = NULL;
	List *root = NULL;
	int key = 0;

	char option;
	cin >> option;
	while (option != 'q') {
		if (option == 'i') {
			cin >> key;
			add(&root, &begin, key);
		}
		else if (option == 'd') {
			add(&head, &beg, del(&root));
		}
		else if (option == 'g') {
			cin >> key;
			add(&head, &beg, get(begin, key));
		}
		else cout << "error" << endl;
		cin >> option;
	}
	for (beg; beg != NULL; beg = beg->next) {
		cout << beg->key << endl;
	}
	return 0;
}