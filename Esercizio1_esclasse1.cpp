#include <iostream>
#define N 5
using namespace std;

int main()
{
	int a[N] = { 1, -5, 7, -10, 13 };
	int b[N] = { 0, -3, 6, -9, 12 };
	int c[N], d[N];

	cout << "Somma incrociata"<< endl;

	for (int i = 0; i < N; i++)
	{
		cout<<"\nSommo a["<<i<<"] e b["<<N-1-i<<"] -> "<<a[i]<<" + "<<b[N-1-i];
		c[i] = a[i] + b[N - 1 - i];
		if (a[i] > b[i])
		{
			d[i] = 1;
		}
		else if (a[i] == b[i])
		{
			d[i] = 0;
		}
		else
		{
			d[i] = -1;
		};
		cout << "\nVettore a[" << i << "] = " << a[i];
		cout << "\nVettore b[" << i << "] = " << b[i];
		cout << "\nVettore c[" << i << "] = " << c[i];
		cout << "\nVettore d[" << i << "] = " << d[i];
	};

	system("PAUSE");
	return 0;
};