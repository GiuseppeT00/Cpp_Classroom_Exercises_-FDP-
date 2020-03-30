#include "ArrayBased_List.h"
#include "List_Functions.h"

int main() {
	AList<Item<int>> L1;
	int size;
	cout << "Insert the size of the list: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		L1.insert(Item<int>(i + 1));
	}
	listPrint(L1);
	L1.reverse();
	listPrint(L1);

	return 0;
}