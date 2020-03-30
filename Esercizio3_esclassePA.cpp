#include "Functions.h"
#define N 100

#include <fstream>

void sequence(LList<Item>& L, int n0);

int main() {
	ofstream output("sequence.txt");
	LList<Item> L[N];
	int longest_seq = 0;
	 
	for (int i = 0; i < N; i++)
	{
		L[i].append(Item(i + 1));
		sequence(L[i], i + 1);
		if (L[i].length() > L[longest_seq].length()) longest_seq = i;
	}
	cout << "The longest sequence was created by n0 = " << longest_seq + 1 << " and it is :" << endl;
	listPrint(L[longest_seq]);

	for (L[longest_seq].moveToStart(); L[longest_seq].currPos() < L[longest_seq].length(); L[longest_seq].next())
		output << L[longest_seq].getValue() << endl;

	for (int i = 0; i < N; i++)
		insertionSort(L[i], 0, L[i].length());
	
	listPrint(L[longest_seq]);

	return 0;
}

void sequence(LList<Item>& L, int n0) {
	while (n0 > 1) {
		if (n0 % 2 == 0) n0 /= 2;
		else n0 = n0 * 3 + 1;
		L.append(Item(n0));
	}
}