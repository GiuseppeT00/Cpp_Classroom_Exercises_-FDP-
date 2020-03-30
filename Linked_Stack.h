// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Linked Stack Data Structure, a template class derived from Stack

// This is the file to include in your code if you want access to the
// complete LStack template class

#ifndef LSTACK_H
#define LSTACK_H

#include <string>
using namespace std;

inline void Assert(bool val, string s);

// Include the link class
#include "Link_Class.h"

// First, get the declaration for the base stack class
#include "Stack_BaseClass.h"

// This is the declaration for LStack.
// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
private:
  Link<E>* top;            // Pointer to first element
  int size;                   // Number of elements

public:
  LStack()                        // Constructor
    { top = NULL; size = 0; }

  ~LStack() { clear(); }          // Destructor

  void clear() {                  // Reinitialize
    while (top != NULL) {         // Delete link nodes
      Link<E>* temp = top;
      top = top->next;
      delete temp;
    }
    size = 0;
  }

  void push(const E& it) { // Put "it" on stack
    top = new Link<E>(it, top);
    size++;
  }

  E pop() {                // Remove "it" from stack
    Assert(top != NULL, "Stack is empty");
    E it = top->element;
    Link<E>* ltemp = top->next;
    delete top;
    top = ltemp;
    size--;
    return it;
  }

  const E& topValue() const { // Return top value
    Assert(top != 0, "Stack is empty");
    return top->element;
  }

  int length() const { return size; } // Return length
};

#endif