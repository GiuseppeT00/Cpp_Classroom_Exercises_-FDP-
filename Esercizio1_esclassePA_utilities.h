#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "llist.h"

class Item {
private:
	int val;

public:
	Item(int v = 0) { val = v; }

	int get_val() const { return val; }

	bool operator<(const Item& other) {
		if (val < other.get_val()) return true;
		else return false;
	}
};

inline ostream& operator<<(ostream& os, const Item& it) { return os << it.get_val(); }

template <typename E> void listPrint(List<E>& L) {
	int curr = L.currPos();
	cout << "< ";
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		if (L.currPos() == curr) cout << "| ";
		cout << L.getValue() << " ";
	}
	cout << ">" << endl;
	L.moveToPos(curr);
}

template <typename E> void exch(E& A, E& B) {
	E temp = A;
	A = B;
	B = temp;
}

template <typename E> bool comp(E& A, E& B) {
	if (B < A) return true;
	else return false;
}

template <typename E> void compexch(E& A, E& B) {
	if (B < A) {
		E temp = A;
		A = B;
		B = temp;
	}
}

template <typename E> void insertionSort(List<E>& L, int l, int r) {
	int curr = L.currPos();
	E it1, it2;
	for (int i = l + 1; i < r; i++)
		for (int j = i; j > 0; j--)
		{
			L.moveToPos(j);
			it1 = L.remove();
			L.prev();
			it2 = L.remove();
			compexch(it2, it1);
			L.insert(it2);
			L.next();
			L.insert(it1);
		}
	L.moveToPos(curr);
}

/*template <typename E> void mergeSort(List<E>& L, int l, int r) {
	if (l >= r) return;
	
	int mid = L.length() / 2;

	mergeSort(L, l, mid);
	mergeSort(L, mid + 1, r);
}*/

/*template <typename E> void merge(List<E>& L, int l, int mid, int r) {
	LList<E> Ltemp;
	for (int i = l; i < mid; i++)
	{

	}
}*/


#endif // !FUNCTIONS_H