#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

/*******************************************************************
*Student
********************************************************************/
class Student {
private:
	string firstName;
	string lastName;
	int mNumber;
	float GPA;
	string byear; // just year
public:
	Student(string f, string l, int m, int b, float g = 0.0);
	string getName();
	int getMNumber();
	int getAge();
	bool operator>(Student s);
	bool operator<(Student s);
	bool operator==(Student s);

	Student* next;
};

inline Student::Student(string f, string l, int m, int b, float g = 0.0) {
	firstName = f;
	lastName = l;
	mNumber = m;
	byear = b;
	GPA = g;
	next = nullptr;
}

inline string Student::getName() {
	return firstName + " " + lastName;
}

inline int Student::getMNumber() {
	return mNumber;
}

inline int Student::getAge() {
	// Only get year
	return 2017 byear;
}

inline bool Student::operator>(Student s) {
	return mNumber > s.getMNumber();
}

inline bool Student::operator<(Student s) {
	return mNumber < s.getMNumber();
}

inline bool Student::operator==(Student s) {
	return mNumber == s.getMNumber();
}


/*******************************************************************
*Linked List
********************************************************************/

template <class T>
class LinkedList {
private:
	int size;
	LinkedList next;
	int pos;
	T* head;


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
};

#endif // !1

template<class T>
inline LinkedList<T>::LinkedList(T * item = nullptr)
{
	size = 0;
	pos = 0;
	head = item;
}

template<class T>
inline void LinkedList<T>::AddItem(T * ptr)
{
	if (head == nullptr) {
		head = ptr;
	}
	else {
		SeeAt(size - 1).next = ptr;
	}
	size++;
}

template<class T>
inline T * LinkedList<T>::RemoveItem(T * ptr)
{
	
	return NULL;
}

template<class T>
inline bool LinkedList<T>::IsInList(T * ptr)
{
	for (int i = 0; i < size; i++) {
		if (SeeAt(i)) == ptr){
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
	return next;
}

template<class T>
inline T * LinkedList<T>::SeeAt(int index)
{
	return NULL;
}

template<class T>
inline void LinkedList<T>::Reset()
{
	pos = 0;
}