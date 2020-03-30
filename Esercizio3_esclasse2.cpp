#include "LinkedBased_List.h"
#include "List_Functions.h"
#include <fstream>

int main() {
	ifstream myfile("numeri-float.txt");
	LList<float> L1, L2;
	int size;
	float it, avg = 0;

	myfile >> size;
	for (int i = 0; i < size; i++)
	{
		myfile >> it;
		avg += it;
		L1.append(it);
	}
	listPrint(L1);

	avg /= size;
	cout << "Average: " << avg << endl;
	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next())
		if (L1.getValue() > avg) L2.append(L1.getValue());

	listPrint(L2);

	return 0;
}