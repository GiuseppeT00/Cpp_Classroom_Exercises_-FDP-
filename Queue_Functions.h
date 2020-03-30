// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Some interesting template functions for Queues Data Structures
// that you can use to test a queue, and make some programs


#ifndef FUNCTION
#define FUNCTION

#include "Linked_Queue.h"
#include "Array_Queue.h"

class Item {
private:
	int val;
public:
	Item(int v = 0) { val = v; }
	int key() const { return val; }
	Item operator+(const Item& other) { return Item(val + other.key()); }
	Item operator-(const Item& other) { return Item(val - other.key()); }
	Item operator*(const Item& other) { return Item(val * other.key()); }
	Item operator/(const Item& other) { return Item(val / other.key()); }
};

inline ostream& operator<<(ostream& os, Item it) {
	return os << it.key();
}

inline int halve(int num) {
	if ((num % 2) != 0) return (num / 2) + 1;
	else return num / 2;
}

template <typename E> void queuePrint(Queue<E>& Q) {
	LQueue<E> Qt;
	E it;
	if (Q.length() > 0)
	{
		cout << "Format: first in <- ... <- last in ;" << endl;
		while (Q.length() > 0)
		{
			it = Q.dequeue();
			Qt.enqueue(it);
			cout << it;
			if (Q.length() > 0) cout << " <- ";
		}
		cout << endl;
		while (Qt.length() > 0) Q.enqueue(Qt.dequeue());
	}
	else cout << "Queue is empty...!" << endl;
}

//PER ESERCIZIO 6 ES.LABORATORIO 4;
template <typename E> void TwoByTwo_sum(Queue<E>& Q) {
	E it1, it2;
	int bef_size = Q.length();
	int act_size = halve(bef_size);
	for (int i = 0; i < act_size; i++)
	{
		if (bef_size % 2 != 0 && i == act_size - 1) Q.enqueue(Q.dequeue());
		else {
			it1 = Q.dequeue();
			it2 = Q.dequeue();
			Q.enqueue(it1 + it2);
		}
	}
}

template <typename E> void TwoByTwo_difference(Queue<E>& Q) {
	E it1, it2;
	int bef_size = Q.length();
	int act_size = halve(bef_size);
	for (int i = 0; i < act_size; i++)
	{
		if (bef_size % 2 != 0 && i == act_size - 1) Q.enqueue(Q.dequeue());
		else {
			it1 = Q.dequeue();
			it2 = Q.dequeue();
			Q.enqueue(it1 - it2);
		}
	}
}

template <typename E> void TwoByTwo_multiplication(Queue<E>& Q) {
	E it1, it2;
	int bef_size = Q.length();
	int act_size = halve(bef_size);
	for (int i = 0; i < act_size; i++)
	{
		if (bef_size % 2 != 0 && i == act_size - 1) Q.enqueue(Q.dequeue());
		else {
			it1 = Q.dequeue();
			it2 = Q.dequeue();
			Q.enqueue(it1 * it2);
		}
	}
}

template <typename E> void TwoByTwo_division(Queue<E>& Q) {
	E it1, it2;
	int bef_size = Q.length();
	int act_size = halve(bef_size);
	for (int i = 0; i < act_size; i++)
	{
		if (bef_size % 2 != 0 && i == act_size - 1) Q.enqueue(Q.dequeue());
		else {
			it1 = Q.dequeue();
			it2 = Q.dequeue();
			Q.enqueue(it1 / it2);
		}
	}
}

#endif // !FUNCTION