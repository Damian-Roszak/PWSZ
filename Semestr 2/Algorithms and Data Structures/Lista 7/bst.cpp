#include <iostream>
#include <fstream>
//#include <Windows.h>
#include <string>

using namespace std;

struct node {
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
};

//Wskaznik na korzen
struct node *root = NULL;

/*
Funkcja dodawania wezla - funkcja ta przechodzi przez drzewo
w poszukiwaniu wolnego miejsca na wezel. Jesli wartosc nowego wezla
jest mniejsza od aktualnego, przechodzi w lewo, w przeciwnym przypadku
przechodzimy w prawo. Gdy natkniemy sie na wartosc null wstawiamy tam
nowy wezel pamietajac o przypisaniu wskaznikow.
*/
void add_node(int val) {
	//tworzymy wskazniki wskazujace na aktualnie rozpatrywany wezel i nowy wezel
	struct node *now = root;
	struct node *addedNode = new node;

	//Przypisujemy wartosci do wezla
	addedNode->key = val;
	addedNode->left = NULL;
	addedNode->right = NULL;

	//Jesli korzen ma wartosc null, nowy wezel staje sie korzeniem
	if (root == NULL) {
		addedNode->parent = NULL;
		root = addedNode;
		return;
	}
	else {

		while (now!= NULL) {
			//wartosc nowego wezla jest wieksza badz rowna od wskazywanego
			if (now->key <= addedNode->key) {
				//jesli po prawej jest wolne miejsce dodajemy w nie wezel
				if (now->right == NULL) {
					addedNode->parent = now;
					now->right = addedNode;
					return;
				}
				//w innym przypadku przechodzimy w glab drzewa
				else {
					now = now->right;
				}
			}
			//wartosc nowego wezla jest mniejsza od wskazywanego
			if (now->key > addedNode->key) {
				//jesli po lewej jest wolne miejsce dodajemy w nie wezel
				if (now->left == NULL) {
					addedNode->parent = now;
					now->left = addedNode;
					return;
				} 
				//w innym przypadku przechodzimy w glab drzewa
				else {
					now = now->left;
				}
			}
		}
	}
}

/*
Funkcja usuwania wezla - funkcja przechodzi po drzewie w poszukiwaniu
wezla o zadanej wartosci. Jesli szukana wartosc jest mniejsza od wartosci 
aktualnie wskazywanego wezla, przechodzi w lewo, w przeciwnym przypadku
przechodzimy w prawo. Jesli znajdziemy wezel o zadanej wartosci, usuwamy go.
W przypadku gdy posiadal jakiekolwiek dzieci, wstawiamy je w wolne miejsce.
Jesli zadana wartosc nie znajduje sie w drzewie, zwracamy NULL.
*/
struct node* del_node_key(struct node* node, int find) {

	if (node == NULL) 
		return node;

	if (find < node->key) {
		return node->left = del_node_key(node->left, find);		//Rekurencyjne przejście do szukanej wartości
	}

	else if (find > node->key) {
		return node->right = del_node_key(node->right, find);
	}

	if (find == node->key) {
		//Jeśli drzewo składa sie z samego korzenia
		if (root->left == NULL && root->right == NULL) {
			delete(root);
			root = NULL;
			return NULL;
		}
		//Wsunięcie prawego syna na miejsce aktualnie wskazywanego
		if (node->left == NULL) {								
			struct node *tmp = node->right;
			delete(node);
			return tmp;
		}
		//Wsunięcie lewego syna na miejsce aktualnie wskazywanego
		else if (node->right == NULL) {
			struct node *tmp = node->left;
			delete(node);
			return tmp;
		}

		//Przypadek gdy wskazywany węzeł ma dwóch synów	
		struct node* tmp = node->right;							

		node->key = tmp->key;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}

		//Znalezienie następcy
		node->right = del_node_key(node->right, tmp->key);		
	}
	return node;
}

//Szukanie najwiekszej wartosci w drzewie - skrajny prawy wezel
int find_max() {
	struct node *now = root;
	//przejście do ostatniego elementu po prawej
	while (now->right != NULL) {
		now = now->right;
	}
	return now->key;
}

//Szukanie najmniejszej wartosci w drzewie - skrajny lewy wezel
int find_min() {
	struct node *now = root;
	//przejście do ostatniego elementu po lewej
	while (now->left != NULL) {
		now = now->left;
	}
	return now->key;
}

int main()
{
	bool isRunning = true;
	int answ, inpu;
	while (isRunning) {
		
		cout << endl;

		cout << "###########MENU###########" << endl;
		cout << "[1] Dodaj wezel" << endl;
		cout << "[2] Usun wezel" << endl;
		cout << "[3] Znajdz najmniejsza wartosc" << endl;
		cout << "[4] Znajdz najwieksza wartosc" << endl;
		cout << "[5] Wyjdz" << endl;
		cout << "##########################" << endl;

		cin >> answ;
		cout << endl;

		switch (answ) {
		case 1: {
			cout << "Wporwadz wartosc wezla: ";
			cin >> inpu;
			add_node(inpu);
			break;
		}
		case 2: {
			cout << "Wprowadz wartosc do usuniecia: ";
			cin >> inpu;
			if (root == NULL) {
				cout << "Brak korzenia - drzewo jest puste" << endl;
			}
			
			break;
		}
		case 3: {
			cout << "Najmniejsza wartosc = " << find_min() << endl;
			
			break;
		}
		case 4: {
			cout << "Najwieksza wartosc = " << find_max() << endl;
			
			break;
		}
		case 5: {
			isRunning = false;
			break;
		}
		default: {
			cout << "Zly wybor!" << endl;
			
			break;
		}
		}
	}

	return 0;
}
