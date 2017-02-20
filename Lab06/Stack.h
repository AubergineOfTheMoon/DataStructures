#pragma once
#ifndef STACK_H
#define STACK_H

template <class T> class Stack {

private:
	int max;
	T** list;
	int topOfList;
	
public:
	Stack(int);
	void push(T *ptr);
	T* pop();
	T* top();
	int length();
	void empty();
	// friend string returnStackValues();
	// TODO: friend friendFunction();
};

#endif

template <class T>
inline Stack<T>::Stack(int m) {
	topOfList = 0;
	max = m;
	list = new T*[max];
}

template <class T>
inline void Stack<T>::push(T* ptr) {
	list[topOfList] = ptr;
	topOfList++;
}; // TODO: Check for stack overflow

template <class T>
inline T* Stack<T>::pop() {
	topOfList--;
	return list[topOfList];
}; //TODO: Check for stack underflow

template <class T>
inline T* Stack<T>::top() {
	return list[topOfList - 1];
}; // TODO: Error checking i.e. Empty

template <class T>
inline int Stack<T>::length() {
	return topOfList;
};

template <class T>
inline void Stack<T>::empty() {
	for (int i = 0; i < topOfList; i++) {
		delete list[i];
		list[i] = nullptr;
	}
	topOfList = 0;
};

