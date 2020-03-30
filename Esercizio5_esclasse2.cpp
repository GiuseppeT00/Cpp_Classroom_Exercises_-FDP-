#include "DLinkedBased_Class.h"
#include "List_Functions.h"

#include <cstdlib>
#include <time.h>

int main() {
	DList<int> L;
	int size;

	/*cout << "Insert the size of the list: ";
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		L.insert(1 + rand() % 50);
	}
	listPrint(L);*/
	while (cin >> size && size != 0) {
		L.append(size);
	}
	L.moveToEnd();
	listPrint(L);

	cout << "List without duplicates: " << endl;
	removeDouble(L);
	listPrint(L);

	return 0;
};