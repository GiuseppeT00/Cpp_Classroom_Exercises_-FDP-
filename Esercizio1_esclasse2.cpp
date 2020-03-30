#include "LinkedBased_List.h"
#include "List_Functions.h"
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	LList<int> L1, L2, L3;
	int s1, s2;

	cout << "Insert the size of the list L1: ";
	cin >> s1;
	for (int i = 0; i < s1; i++)
	{
		insertOrdered(L1, 1 + rand() % 99, "desc");
	}
	listPrint(L1);

	cout << "Insert the size of the list L2: ";
	cin >> s2;
	for (int i = 0; i < s2; i++)
	{
		insertOrdered(L2, 1 + rand() % 99, "desc");
	}
	listPrint(L2);

	cout << "This is the L3 list (L1 merged with L2): " << endl;
	desc_mergeLists(L1, L2, L3);
	listPrint(L3);

	cout << "These are L1 list and L2 list: "<< endl;
	listPrint(L1);
	listPrint(L2);


	return 0;
}