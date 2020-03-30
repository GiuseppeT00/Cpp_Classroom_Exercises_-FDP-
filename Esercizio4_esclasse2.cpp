#include "LinkedBased_List.h"
#include "List_Functions.h"

int main() {
	LList<int> L1, L2;
	int item;

	cout << "Insert items to append in the list (0 to stop): " << endl;
	while (cin >> item && item != 0) {
		insertOrdered(L1, item, "asc");
	}
	listPrint(L1);
	fillList(L1);
	listPrint(L1);

	return 0;
}