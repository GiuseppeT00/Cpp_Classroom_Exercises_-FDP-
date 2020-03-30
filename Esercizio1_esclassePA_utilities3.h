#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "LLinkedBased_List.h"

inline void Assert(bool exp, string s) {
	if (!exp) {
		cout << "Assertion failed...!" << s << endl;
		exit(-1);
	}
}

class Product {
private:
	string id;
	string name;
	int qnt;

public:
	Product(string cod = "/", string descr = "/", int num = 0) {
		id = cod;
		name = descr;
		qnt = num;
	}

	Product(string cod, int num) {
		id = cod;
		name = "/";
		qnt = num;
	}

	string id_key() const { return id; }

	string name_key() const { return name; }

	int qnt_key() const { return qnt; }

	void set_qnt(int q) { qnt = q; }

};

inline ostream& operator<<(ostream& os, const Product& it) {
	return os << "(" << it.id_key() << " " << it.name_key() << " " << it.qnt_key() << ")";
}

inline bool operator==(const Product& it1, const Product& it2) {
	if (it1.id_key() == it2.id_key()) return true;
	else return false;
}

Product operator+(const Product& it1, const Product& it2) { return Product(it1.id_key(), it1.name_key(), it1.qnt_key() + it2.qnt_key()); }

Product operator-(const Product& it1, const Product& it2) { return Product(it1.id_key(), it1.name_key(), it1.qnt_key() - it2.qnt_key()); }

class Dish {
private:
	int id;
	string name;
	Product ingr1;
	Product ingr2;
public:
	Dish(int cod = 0, string descr = "/", Product it1 = Product(), Product it2 = Product()) {
		id = cod;
		name = descr;
		ingr1 = it1;
		ingr2 = it2;
	}
	int cod_key() const { return id; }
	string name_key() const { return name; }
	Product ingr1_key() const { return ingr1; }
	Product ingr2_key() const { return ingr2; }
};

inline ostream& operator<<(ostream& os, const Dish& it) {
	return os << "(" << it.cod_key() << " " << it.name_key() << " " << it.ingr1_key() << " " << it.ingr2_key() << ")";
}

inline bool operator<=(const Dish& it1, const Dish& it2) {
	if (it1.cod_key() <= it2.cod_key()) return true;
	else return false;
}

template <typename E> void listPrint(List<E>& L) {
	int c_pos = L.currPos();
	cout << "< ";
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
	{
		if (L.currPos() == c_pos) cout << "| ";
		cout << L.getValue() << " ";
	}
	cout << " >" << endl;
	L.setPos(c_pos);
}

template <typename E> void insertOrdered(List<E>& L, E item) {
	int c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
		if (item <= L.getValue()) {
			L.insert(item);
			return;
		}
	L.insert(item);
	L.setPos(c_pos);
}

void insertUnique(List<Product>& L, Product item) {
	int c_pos = L.currPos();
	for (L.moveToStart(); L.currPos() < L.length(); L.next())
		if (item == L.getValue()) {
			Product update = L.remove();
			update.set_qnt(update.qnt_key() + item.qnt_key());
			L.insert(update);
			return;
		}
	L.append(item);
	L.setPos(c_pos);
}





#endif // !FUNCTIONS_H