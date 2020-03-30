#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "llist.h"

struct cost {
	int start;
	int end;
	int amount;
};

class Item_2 {
	int month;
	int euros;

public:
	Item_2(int m = 0, int e = 0) {
		month = m;
		euros = e;
	}
	int get_month() const { return month; }
	int get_euros() const { return euros; }
	void set_euros(int e) { euros = e; }
};

inline ostream& operator<<(ostream& os, const Item_2& it) {
	return os << "(" << it.get_month() << " " << it.get_euros() << ")";
}

class Item_1 {
	cost spesa;

public:
	Item_1() { }
	Item_1(cost exp) { spesa = exp; }
	int get_start() const { return spesa.start; }
	int get_amount() const { return spesa.amount; }
	int get_end() const { return spesa.end; }
};

inline ostream& operator<<(ostream& os, const Item_1& it) {
	return os << "(" << it.get_start() << " " << it.get_end() << " " << it.get_amount() << ")";
}

template <typename E> void listPrint(List<E>& L) {
	int curr = L.currPos();
	cout << "< ";
	for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
		if (L.currPos() == curr) cout << "| ";
		cout << L.getValue() << " ";
	}
	cout << ">" << endl;
	L.moveToPos(curr);
}


#endif // !FUNCTIONS_H