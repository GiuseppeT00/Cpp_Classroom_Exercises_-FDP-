#include "LinkedBased_List.h"
#include "List_Functions.h"

int main() {
	LList<Item<int>> L;
	int size;

	cout << "Insert the size of the list: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		L.append(Item<int>(i + 1));
	}
	listPrint(L);

	int c_pos = L.currPos();

	Item<int> it1, it2;
	for (L.moveToStart(); L.currPos() < L.length() / 2; L.next())
	{
		int curr = L.currPos();
		it1 = L.remove();
		L.setPos(L.length() - L.currPos() - 1);
		it2 = L.remove();
		L.insert(it1);
		L.setPos(curr);
		L.insert(it2);
	}
	L.setPos(c_pos);
	listPrint(L);




	return 0;
}