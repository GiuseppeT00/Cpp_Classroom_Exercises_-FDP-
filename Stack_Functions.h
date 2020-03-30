// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Some interesting template functions for Stacks Data Structures
// that you can use to test a stack, and make some programs



#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Linked_Stack.h"
#include "Array_Stack.h"

inline void Assert(bool exp, string s) {
	if (!exp)
	{
		cout << "Assertion failed...! " << s << endl;
		exit(-1);
	}
}

class Item {
private:
	int val;
public:
	Item(int v = 0) { val = v; }
	int key() const { return val; }
};

inline ostream& operator<<(ostream& os, Item it) {
	return os << it.key();
}

template <typename E> void stackPrint(Stack<E>& S) {
	E* v;
	int i = 0, size = S.length();
	v = new E[size];
	cout << "Format: last in <- ... <- first in ;" << endl;
	if (S.length() > 0)
	{
		while (S.length() > 0)
		{
			v[i] = S.pop();
			cout << v[i];
			if (S.length() > 0) cout << " <- ";
			i++;
		}
		cout << endl;
	}
	else cout << "Stack empty...!" << endl;
	for (i = 0; i < size; i++) S.push(v[size - 1 - i]); //Refill stack after print it
}

template <typename E> void stackTransfer(Stack<E>& S1, Stack<E>& S2) {
	LStack<E> Stemp;
	E it;
	while (S1.length() > 0) Stemp.push(S1.pop());
	while (Stemp.length() > 0) {
		it = Stemp.pop();
		S1.push(it);
		S2.push(it);
	}
}

template <typename E> void stackReverse(Stack<E>& S) {
	LStack<E> Stemp;
	stackTransfer(S, Stemp);
	S.clear();
	while (Stemp.length() > 0) S.push(Stemp.pop());
}


#endif // !FUNCTIONS_H