#include <iostream>
#define N 31
using namespace std;

int main()
{
	int ar1[N] = { 0 }, ar2[N] = { 0 } ;
	int day;

	cout << "Inserisci 0 per terminare." << endl;
	cout << "Collega 1: " << endl;
	do
	{
		cout << "\nGiorno libero (tra 1 e 31): ";
		cin >> day;
		if (day > 0 && day < 32)
		{
			ar1[day-1] = 1;
			cout << "Valore aggiunto." << endl;
		}
		else
		{
			cout << "Valore non aggiunto." << endl;
		}
	} while (day != 0);

	cout << "Collega 2: " << endl;
	do
	{
		cout << "\nGiorno libero (tra 1 e 31): ";
		cin >> day;
		if (day > 0 && day < 32)
		{
			ar2[day - 1] = 1;
			cout << "Valore aggiunto." << endl;
		}
		else
		{
			cout << "Valore non aggiunto." << endl;
		}
	} while (day != 0);

	for (int i = 0; i < N; i++)
	{
		if (ar1[i] == ar2[i] && ar1[i] == 1) {
			cout << "\nGiorno " << i + 1 << " libero in comune!" << endl;
		}
	}
	return 0;
}