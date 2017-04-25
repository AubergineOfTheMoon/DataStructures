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
	int mNumber;
	Student(string f, string l, int m);
	string getName();
	int getMNumber();
	string toString();
	Student* next;
	
};

inline Student::Student(string f, string l, int m) {
	firstName = f;
	lastName = l;
	mNumber = m;
	next = nullptr;
}

inline string Student::getName() {
	string fullName ="";
	fullName += firstName;
	fullName.append(" ");
	fullName += lastName;
	return fullName;
}

inline int Student::getMNumber() {
	return mNumber;
}

inline string Student::toString()
{
	return firstName + " " + lastName + " " + to_string(mNumber);
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
	void BubbleSort(bool);
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
		int findPos = size - 1;
		if (size == 1) {
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
	bool itemFound = false;
	for (int i = 0; i < size; i++) {
		if (*SeeAtSamePos(i) == *ptr) {
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
		if ((*SeeAtSamePos(i)) == (*ptr)) {
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
		s = SeeAt(i);
		if (s != nullptr) 

			cout << (*s).toString() << " | ";
		
		else
			cout << i << " was empty ";
	}
	pos = tPos;
}

template<class Student>
inline void LinkedList<Student>::BubbleSort(bool ascending)
{
	if (ascending) {
		for (int i = 0; i < Size(); i++) {
			for (int k = 0; k < Size() - i - 1; k++) {
				if (SeeAt(k)->firstName > SeeAt(k + 1)->firstName) {
					Student* one = SeeAt(k);
					Student* two = SeeAt(k + 1);

					if (k > 0) {
						SeeAt(k - 1)->next = two;
					}
					else if (k == 0)
					{
						head = two;
					}

					one->next = two->next;
					two->next = one;
					
				}
			}
		}
	}
	else {
		for (int i = 0; i < Size(); i++) {
			for (int k = 0; k < Size() - i - 1; k++) {
				if (SeeAt(k)->firstName < SeeAt(k + 1)->firstName) {
					Student* one = SeeAt(k);
					Student* two = SeeAt(k + 1);
					if (k > 0) {
						SeeAt(k - 1)->next = two;

					}
					else if (k == 0)
					{
						head = two;
					}
					one->next = two->next;
					two->next = one;
				}
			}
		}
	}
	//Student *test = SeeAt(48);
}