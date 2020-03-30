#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#define N 2
using namespace std;

typedef struct {
	string titolo;
	string autore;
	int anno_ed;
	int prezzo;
}
Tipolibro;

int main() {
	srand(time(NULL));
	Tipolibro libro[N];
	int tot_cost = 0;
	int older = 1000000;

	ofstream SaveFile("Libri.txt");

	for (int i = 0; i < N; i++)
	{
		SaveFile << "Libro numero " << i+1 << endl;

		cout << "Inserisci il titolo del libro: ";
		getline(cin, libro[i].titolo);
		SaveFile << "Titolo: " << libro[i].titolo << endl;

		cout << "Inserisci l'autore del libro: ";
		getline(cin, libro[i].autore);
		SaveFile << "Autore: " << libro[i].autore << endl;

		cout << "Inserisci l'anno di edizione: ";
		cin >> libro[i].anno_ed;
		SaveFile << "Anno edizione: " << libro[i].anno_ed << endl;

		libro[i].prezzo = rand() % 199;
		cout << "Il prezzo e' di " << libro[i].prezzo << " euro." << endl;
		SaveFile << "Prezzo: " << libro[i].prezzo << endl;
		tot_cost += libro[i].prezzo;

		if (libro[i].anno_ed < older)
		{
			older = i;
		}
	}
	cout << "Il prezzo medio e': " << tot_cost/N << endl;
	cout << "Il libro piu' vecchio e':" << endl << "-Titolo: " << libro[older].titolo << endl << "-Autore: " << libro[older].autore << endl << "-Anno: " << libro[older].anno_ed << endl << "-Prezzo: " << libro[older].prezzo << endl;

	return 0;
}