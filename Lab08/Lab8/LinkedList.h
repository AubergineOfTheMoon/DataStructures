#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include<ctime>
#include<sstream>
#include<iostream>
using namespace std;


/*******************************************************************
*Student
********************************************************************/
class Student {
private:
	string firstName;
	string lastName;
	string mNumber;
	float GPA;
	int birthday[3];
public:
	Student(string f, string l, string m, int bMonth, int bDay, int bYear, float g);
	string getName();
	string getMNumber();
	int getAge();
	float getGPA();
	string getBirthday();
	bool operator>(Student s);
	bool operator<(Student s);
	bool operator==(Student s);
	Student* next;
};

inline Student::Student(string f, string l, string m, int bMonth, int bDay, int bYear, float g = 0.0) {
	firstName = f;
	lastName = l;
	mNumber = m;
	birthday[0] = bMonth;
	birthday[1] = bDay;
	birthday[0] = bYear;
	GPA = g;
	next = nullptr;
}

inline string Student::getName() {
	string fullName ="";
	cout << firstName;
	/*fullName += firstName;
	fullName.append(" ");
	fullName += lastName;*/
	return fullName;
}

inline string Student::getMNumber() {
	return mNumber;
}

inline int Student::getAge() {
	// Only get year
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int currentYear = timePtr->tm_year + 1900;
	int currentMonth = timePtr->tm_mon;
	int currentDay = timePtr->tm_mday;
	int age = currentYear - birthday[2];
	if ((currentMonth < birthday[0]) || ((currentMonth==birthday[0]) && (currentDay < birthday[1]))) {
		age--;
	}
	return age;
}

float Student::getGPA() {
	return GPA;
}

string Student::getBirthday() {
	return to_string(birthday[0]) + "/" + to_string(birthday[1]) + "/" + to_string(birthday[2]);
}

inline bool Student::operator>(Student s) {
	int numSame, numOther;
	istringstream (mNumber.substr(1)) >> numSame;
	istringstream(s.getMNumber().substr(1)) >> numOther;
	return numSame > numOther;
}

inline bool Student::operator<(Student s) {
	int numSame, numOther;
	istringstream(mNumber.substr(1)) >> numSame;
	istringstream(s.getMNumber().substr(1)) >> numOther;
	return numSame < numOther;
}

inline bool Student::operator==(Student s) {
	int numSame, numOther;
	istringstream(mNumber.substr(1)) >> numSame;
	istringstream(s.getMNumber().substr(1)) >> numOther;
	return numSame == numOther;
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
	class ItemNotFound {
	public:
		ItemNotFound() {};
	};
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
		head->next = nullptr;
	}
	else {
		int findPos = 0;
		while ((SeeAt(findPos) < ptr) && (findPos < size)) {
			findPos++;
		}
		T* nextTemp = SeeAt(findPos - 1)->next;
		SeeAt(findPos - 1)->next = ptr;
		SeeAt(findPos)->next = nextTemp;
	}
	size++;
}

template<class T>
inline T * LinkedList<T>::RemoveItem(T * ptr)
{	
	T* retItem;
	int findPos;
	bool itemFound=false;
	for (int i = 0; i < size; i++) {
		if (SeeAt(i) == ptr){
			findPos = i;
			itemFound = true;
		}
	}
	if (itemFound) {
		retItem = SeeAt(findPos);
		retItem->next = nullptr;
		SeeAt(findPos - 1)->next = SeeAt(findPos)->next;
		size--;
		return retItem;
	}
	else {
		return NULL;
	}
}

template<class T>
inline bool LinkedList<T>::IsInList(T * ptr)
{
	for (int i = 0; i < size; i++) {
		if (SeeAt(i) == ptr){
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
	T* nextTemp = next;
	next = next->next;
	pos++;
	return nextTemp;
}

template<class T>
inline T * LinkedList<T>::SeeAt(int index)
{	
	if ((index >= size) || (index < 0)) {
		throw ItemNotFound();
	}
	T* retItem;
	retItem = head;
	for (int i = 0; i <=index; i++) {
		retItem = retItem->next;
	}
	pos = index;
	if (pos == 0) {
		next = nullptr;
	}
	else {
		next = retItem->next;
	}
	return retItem;
}

template<class T>
inline void LinkedList<T>::Reset()
{
	pos = 0;
	next = head;
}

