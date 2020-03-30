#include "Functions.h"
#include <fstream>

void insertUnique(List<Item_2>& L, Item_2 it);

void compexch(Item_2& A, Item_2& B);

void insertionSort(LList<Item_2>& L, int l, int r);

int main() {
	ifstream spese("spese.txt");
	LList<Item_1> L1;
	LList<Item_2> L2;

	cost c1;
	float monthly_cost;

	if (spese.is_open())
		while (spese >> c1.start >> c1.end >> c1.amount) 
			L1.append(Item_1(c1));
	else {
		cout << "Unable to open the file...!" << endl;
		exit(-1);
	}
	cout << "List created by 'spese.txt': " << endl;
	listPrint(L1);

	for (L1.moveToStart(); L1.currPos() < L1.length(); L1.next())
	{
		c1.start = L1.getValue().get_start();
		c1.end = L1.getValue().get_end();
		monthly_cost = L1.getValue().get_amount() / (c1.end - c1.start + 1);

		for (c1.start; c1.start <= c1.end; c1.start++)
		{
			if (L2.length() > 0) insertUnique(L2, Item_2(c1.start, monthly_cost));

			else L2.insert(Item_2(c1.start, monthly_cost));
		}
	}

	L2.moveToStart();
	cout << "Unordered list of monthly expense: " << endl;
	listPrint(L2);

	cout << "Ordered list of monthly expense: " << endl;
	insertionSort(L2, 0, L2.length());
	listPrint(L2);


	return 0;
}

void insertUnique(List<Item_2>& L, Item_2 it) {
	int c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
		if (L.getValue().get_month() == it.get_month()) {
			Item_2 it_temp = L.remove();
			it_temp.set_euros(it_temp.get_euros() + it.get_euros());
			L.insert(it_temp);
			return;
		}
	L.moveToPos(c_pos); L.append(it);
}

void compexch(Item_2& A, Item_2& B) {
	if (B.get_euros() > A.get_euros()) {
		Item_2 temp = A;
		A = B;
		B = temp;
	}
}

void insertionSort(LList<Item_2>& L, int l, int r) {
	int curr = L.currPos();
	for (int i = 1; i < r; i++)
		for (int j = i; j > 0; j--)
		{
			L.moveToPos(j);
			Item_2 it1 = L.remove();
			L.prev(); 
			Item_2 it2 = L.remove();
			compexch(it2, it1);
			L.insert(it2);
			L.next(); L.insert(it1);
		}
	L.moveToPos(curr);
}