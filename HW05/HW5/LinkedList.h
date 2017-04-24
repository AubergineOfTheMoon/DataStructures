#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include<ctime>
#include<iostream>
using namespace std;


/*******************************************************************
*Student
********************************************************************/
class Student {
public:
	string firstName;
	string lastName;
	string mNumber;
	Student(string f, string l, int m);
	string getName();
	string getMNumber();
	bool operator>(Student s);
	bool operator<(Student s);
	bool operator==(Student s);
	string toString();
	Student* next;
};

inline Student::Student(string f, string l, int m) {
	firstName = f;
	lastName = l;
	mNumber = "M" + to_string(m);
	next = nullptr;
}

inline string Student::getName() {
	string fullName ="";
	fullName += firstName;
	fullName.append(" ");
	fullName += lastName;
	return fullName;
}

inline string Student::getMNumber() {
	return mNumber;
}

inline string Student::toString()
{
	return firstName + " " + lastName + " " + mNumber;
}


/*******************************************************************
*Linked List
********************************************************************/

template <class T>
class LinkedList {
private:
	int size;
	T* next;
	int pos;
	T* head;
	T* SeeAtSamePos(int index);
public:
	LinkedList(T* item);
	void AddItem(T* ptr);
	T* RemoveItem(T* ptr);
	bool IsInList(T* ptr);
	bool IsEmpty();
	int Size();
	T* SeeNext();
	T* SeeAt(int index);
	void Reset();
	void DisplayAll();
	class ItemNotFound {
	public:
		ItemNotFound() {};
	};
	class EmptyList {
	public:
		EmptyList() {};
	};
};

#endif 

template<class T>
inline LinkedList<T>::LinkedList(T * item = nullptr)
{
	size = 0;
	pos = 0;
	head = item;
	next = head;
}

template<class T>
inline void LinkedList<T>::AddItem(T * ptr)
{
	if (head == nullptr) {
		head = ptr;
		head->next = nullptr;
		next = head;
		size++;
	}
	else {
		int findPos = 0;
		while ((findPos < size) && (*SeeAtSamePos(findPos) < *ptr)) {
			findPos++;
		}
		if (findPos == 0) {
			T* nextTemp = head;
			head = ptr;
			next = head;
			size++;
			head->next = nextTemp;
		}
		else {
			T* nextTemp = SeeAtSamePos(findPos - 1)->next;
			SeeAtSamePos(findPos - 1)->next = ptr;
			size++;
			SeeAtSamePos(findPos)->next = nextTemp;
		}
	}
}

template<class T>
inline T * LinkedList<T>::RemoveItem(T * ptr)
{	
	T* retItem;
	int findPos;
	bool itemFound=false;
	for (int i = 0; i < size; i++) {
		if (*SeeAtSamePos(i) == *ptr){
			findPos = i;
			itemFound = true;
		}
	}
	if (itemFound) {
		retItem = SeeAtSamePos(findPos);
		// retItem->next = nullptr;
		if (findPos == 0) {
			T* newHead = head->next;
			head = newHead;
			// head = SeeAtSamePos(findPos)->next;
			/*if (head != nullptr) { 
				head->next = tempNext; 
			}*/
		}
		else {
			SeeAtSamePos(findPos - 1)->next = SeeAtSamePos(findPos)->next;
		}
		retItem->next = nullptr;
		size--;
		return retItem;
	}
	else {
		return nullptr;
	}
}

template<class T>
inline bool LinkedList<T>::IsInList(T * ptr)
{
	for (int i = 0; i < size; i++) {
		if ((*SeeAtSamePos(i)) == (*ptr)){
			return true;
		}
	}
	return false;
}

template<class T>
inline bool LinkedList<T>::IsEmpty()
{
	return size == 0;
}

template<class T>
inline int LinkedList<T>::Size()
{
	return size;
}

template<class T>
inline T * LinkedList<T>::SeeNext()
{	
	if (head == nullptr) {
		throw EmptyList();
		return nullptr;
	}
	T* nextTemp = next;
	if (next == nullptr) {
		return nullptr;
	}
	next = next->next;
	pos++;
	return nextTemp;
}

template<class T>
inline T * LinkedList<T>::SeeAt(int index)
{	
	if ((index >= size) || (index < 0)) {
		throw ItemNotFound();
		return nullptr;
	}
	else {
		T* retItem;
		retItem = head;
		for (int i = 0; i < index; i++) {
			retItem = retItem->next;
		}
		pos = index;
		if (size == 0) {
			next = nullptr;
		}
		else {
			next = retItem->next;
		}
		return retItem;
	}
}

template<class T>
inline T * LinkedList<T>::SeeAtSamePos(int index)
{
	if ((index >= size) || (index < 0)) {
		throw ItemNotFound();
		return nullptr;
	}
	else {
		T* retItem;
		retItem = head;
		for (int i = 0; i < index; i++) {
			retItem = retItem->next;
		}
		return retItem;
	}
}

template<class T>
inline void LinkedList<T>::Reset()
{
	pos = 0;
	next = head;
}

template<class Student>
inline void LinkedList<Student>::DisplayAll()
{
	int tPos = pos;
	pos = 0;
	Student* s;
	for (int i = 0; i < size; i++) {
		s = SeeNext();
		cout << (*s).toString();
	}
	pos = tPos;
}

void StudentSwap(Student *a, Student *b, Student *before) {
	Student *tNext = b->next;
	b->next = a;
	a->next = tNext;
	before->next = b;
}

void StudentSwapRoot(Student *a, Student *b, Student *root) {
	Student *tNext = b->next;
	b->next = a;
	a->next = tNext;
	root = b;
}

template<class Student>
inline void LinkedList<Student>::BubbleSort(int type, bool ascending)
{
	for (int i = 0; i < l.Size(); i++) {
		for (int k = 0; k < l.Size() - i - 1; k++) {
			if (l.SeeAt(k).firstName > l.SeeAt(k + 1).firstName) {
				if (k > 0) {
					StudentSwap(l.SeeAt(k), l.SeeAt(k + 1), l.SeeAt(k - 1))
				}
				else {
					StudentSwapRoot(l.SeeAt(k), l.SeeAt(k + 1), l.root)
				}
			}
		}
	}
}