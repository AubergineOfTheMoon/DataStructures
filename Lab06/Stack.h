#pragma once
#ifndef STStackCK_H
#define STStackCK_H

#include <string>
using namespace std;

template<class T>
class Stack;

template<class T>
T* getItem(Stack<T>& a, int index);

template <class T> class Stack {
private:
	int max; // the last available spot + 1
	int topOfList; // the top of the stack
	T* *list; // pointer array
public:
	Stack(int);
	void push(T *ptr);
	T* pop();
	T* top();
	int length();
	void empty();
	//T* returnStackListItem(int);
	bool isEmpty();
	bool isFull();


	friend T* getItem<T>(Stack& a, int index);


	//FullStable Class Definition
	class StackOverflow {
	private:
		int index;
	public:
		StackOverflow(int i) { index = i; }
		int getValue() { return index; }
	};


	//StackUnderflow Class Definition
	class StackUnderflow {
	public:
		StackUnderflow() { }
	};
};

#endif
#include <string>

template <class T>
inline Stack<T>::Stack(int m) {
	topOfList = 0;
	max = m;
	list = new T*[m];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
}

template <class T>
inline void Stack<T>::push(T* ptr) {
	if (topOfList == max) {
		throw StackOverflow(topOfList + 1);
	}
	else {
		list[topOfList] = ptr;
		topOfList++;
	}
};

template <class T>
inline T* Stack<T>::pop() {
	if (topOfList < 1) {
		throw StackUnderflow();
	}else{
		topOfList--;
		return list[topOfList];
	}
}; 

template <class T>
inline T* Stack<T>::top() {
	if (topOfList < 1) {
		throw StackUnderflow();
	}
	else {
		return list[topOfList - 1];
	}
}; 

template <class T>
inline int Stack<T>::length() {
	return topOfList;
};

template <class T>
inline void Stack<T>::empty() {
	for (int i = 0; i < topOfList; i++) {
		list[i] = nullptr;
	}
	topOfList = 0;
};

/*template <class T>
inline T*  Stack<T>::returnStackListItem(int index) {
	if (index >= topOfList) { //if the stack's top is less than the requested index, return a nullptr instead
		return nullptr;
	}
	return list[index];
}*/

template <class T>
inline bool Stack<T>::isEmpty() {
	return topOfList == 0;
}

template <class T>
inline bool Stack<T>::isFull() {
	return topOfList == max;
}

template<class T>
T* getItem(Stack<T>& a, int index)
{
	if (index >= a.topOfList) { //if the stack's top is less than the requested index, return a nullptr instead
		return nullptr;
	}
	return a.list[index];
}

