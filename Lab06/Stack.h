#pragma once
#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

template <class T> class Stack {
private:
	int max = 4;
	int topOfList;
	T** list = new T*[4];

public:
	Stack(int);
	void push(T *ptr);
	T* pop();
	T* top();
	int length();
	void empty();
	string returnStackString();


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
	//max = m;
	//list = new T*[m];
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



