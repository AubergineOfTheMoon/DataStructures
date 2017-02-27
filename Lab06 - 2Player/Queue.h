#pragma once
#ifndef QUEUE_H

#include<vector>
#include <string>
using namespace std;

template<class T>
class Queue;

template <class T> class Queue {
private:
	int back; // the next available spot in the Queue
	vector<T> list; // Vector list of items in Queue

public:
	Queue();
	void enqueue(T val);
	T dequeue();
	T peek();
	int length();
	void makeEmpty();
	bool isEmpty();

	// Exception Class for Stack underflow of queue
	class StackUnderflow {
	public:
		StackUnderflow() { }
	};
};

template <class T>
inline Queue<T>::Queue() {
// Initialize class Queue.
	back = 0;
}

template <class T>
inline void Queue<T>::enqueue(T val) {
// Add item to queue.
	list.push_back(val);
	back++;

}

template <class T>
inline T Queue<T>::dequeue() {
// Remove and return first item in queue
	if (back < 1) {
		throw StackUnderflow();
	}
	else {
		T retVal= list[0];
		for (int i = 0; i < back - 1; i++) {
		// Reset Queue after removing item by moving each item one position back.
			list[i] = list[i + 1];
		}
		back--;
		return retVal;
	}
}

template <class T>
inline T Queue<T>::peek() {
// Return first item in queue.
	if (back < 1) {
		throw StackUnderflow();
	}
	else {
		return list[0];
	}
}

template <class T>
inline int Queue<T>::length() {
	// Return number of items in Queue
	return back;
}

template <class T>
inline void Queue<T>::makeEmpty() {
	// Make the Queue empty.
	list.clear();
	back = 0;
}


template <class T>
inline bool Queue<T>::isEmpty() {
	// Return whether the Queue is empty or not.
	return back == 0;
}


#endif