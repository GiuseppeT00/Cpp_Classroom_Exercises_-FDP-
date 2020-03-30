#ifndef QUEUE_H
#define QUEUE_H

template <typename E> class Queue { //ADT class for queues
private:
	Queue(const Queue&) { } //Protect copy constructor

	void operator=(const Queue&) { } //Protect assignment operator

public:
	Queue() { } //Default costructor

	virtual ~Queue() { } //Base destructor

	virtual void clear() = 0; //Reinitialize queue (doesn't clear the storage used by it)

	virtual void enqueue(const E&) = 0; //Insert an item to the rear of the queue

	virtual E dequeue() = 0; //Remove and return the item at front of the queue

	virtual const E& frontValue() const = 0 ; //Return the item at front of the queue

	virtual int length() const = 0 ; //Return the size of the queue

};


#endif // !QUEUE_H
