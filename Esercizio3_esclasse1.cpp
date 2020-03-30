#include <iostream>
#include <cmath>
#define N 2
using namespace std;

int main()
{
	float radice[N], num, x1, xi;

	cout << "Bisogna inserire 3 numeri di cui calcolarne la radice." << endl;
	for (int i = 0; i < N + 1; i++)
	{
		cout << "Inserisci il numero " << i+1 << " : ";
		cin >> num;
		if (num >= 0)
		{
			radice[i] = num;
			x1 = 1;
			do
			{
				xi = x1;
				x1 = 0.5 * ( xi + ( radice[i] / xi ) );
			} while (abs(sqrt(radice[i])-x1) > 0.001);
			cout << "La radice di " << radice[i] << " con errore <0.001 e': " << x1 << endl;
		}
		else
		{
			cout << "Hai inserito un numero negativo!" << endl;
		}
	}
	return 0;
}