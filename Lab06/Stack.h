#pragma once
#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

template <class T> class Stack {
public:
	Stack(int);
	void push(T *ptr);
	T* pop();
	T* top();
	int length();
	void empty();
	string returnStackString();
private:
	int max;
	int topOfList;
	T** list = new T*[4];
};

#endif
#include <string>

template <class T>
inline Stack<T>::Stack(int m) {
	topOfList = 0;
	max = m;
	//list = new T*[m];
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
		list[i] = nullptr;
	}
	topOfList = 0;
};

template <class T>
inline string Stack<T>::returnStackString() {
	string rtn = "";
	for (int i = 0; i < topOfList; i++) {
		rtn += to_string(*list[i]) + " ";
	}
	return rtn;
}

inline string Stack<string>::returnStackString() {
	string rtn = "";
	for (int i = 0; i < topOfList; i++) {
		rtn += *list[i] + " ";
	}
	return rtn;
}