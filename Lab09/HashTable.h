#pragma once

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include<ctime>
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
	int mIndex;
	float GPA;
	int birthday[3];
public:
	Student(string f, string l, int m, int bMonth, int bDay, int bYear, float g);
	string getName();
	string getMNumber();
	int getMIndex();
	int getAge();
	float getGPA();
	string getBirthday();
	bool operator>(Student s);
	bool operator<(Student s);
	bool operator==(Student s);
	string toString();
	Student* next;
};

inline Student::Student(string f, string l, int m, int bMonth, int bDay, int bYear, float g = 0.0) {
	firstName = f;
	lastName = l;
	mNumber = "M" + to_string(m);
	mIndex = m;
	birthday[0] = bMonth;
	birthday[1] = bDay;
	birthday[2] = bYear;
	GPA = g;
	next = nullptr;
}

inline string Student::getName() {
	string fullName = "";
	fullName += firstName;
	fullName.append(" ");
	fullName += lastName;
	return fullName;
}

inline string Student::getMNumber() {
	return mNumber;
}

inline int Student::getMIndex() {
	return mIndex;
}

inline int Student::getAge() {
	// Only get year
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int currentYear = timePtr->tm_year + 1900;
	int currentMonth = timePtr->tm_mon + 1;
	int currentDay = timePtr->tm_mday;
	int age = currentYear - birthday[2];
	/*cout << currentMonth << "/" << currentDay << "/" << currentYear << endl;
	bool b1 = currentMonth < birthday[0];
	bool b2 = (currentMonth == birthday[0]) && (currentDay < birthday[1]);
	cout << b1 << " " << b2 << endl;*/
	if ((currentMonth < birthday[0]) || ((currentMonth == birthday[0]) && (currentDay < birthday[1]))) {
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

	return mIndex > s.getMIndex();
}

inline bool Student::operator<(Student s) {
	return mIndex < s.getMIndex();
}

inline bool Student::operator==(Student s) {
	return mIndex == s.getMIndex();
}

inline string Student::toString()
{
	return mNumber;
}


/*******************************************************************
*Hash table
********************************************************************/

template <class T>
class HashTable {
protected:
	int max;
	int size;
	T* *dataTable;
	int Hash(string);
public:
	HashTable(int);
	void AddItem(T* ptr);
	T* RemoveItem(T* ptr);
	T* GetItem(T* ptr);
	int GetLength();
};

#endif 

template<class T>
inline int HashTable<T>::Hash(string s)
{
	int h = 0;
	const char *cArray = s.c_str();
	for (int i = 0; i < s.length(); i++) {
		h += (int)cArray[i];
	}
	
	return h % max;
}

template<class T>
inline HashTable<T>::HashTable(int length=100)
{
	max = length;
	size = 0;
	dataTable = new T*[max];
	for (int i = 0; i < max; i++) {
		dataTable[i] = nullptr;
	}
}

template<class T>
inline void HashTable<T>::AddItem(T * ptr)
{
	if (size == max) {
		// TODO Error checking
	}

	int h = Hash(ptr->toString());
	// bool spotOccupied;
	while (dataTable[h] != nullptr) {
		h = (h + 1) % max;
	} 
	dataTable[h] = ptr;
	size++;
}

template<class T>
inline T * HashTable<T>::RemoveItem(T * ptr)
{
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	// bool spotOccupied;
	int count = 0;
	// Check by value, not by pointer
	while ((dataTable[h] == nullptr || !(*dataTable[h] == *ptr)) && count < size) {
		h = (h + 1) % max;
		count++;
	}
	if (*dataTable[h] == *ptr) {
		T* retPtr = dataTable[h];
		dataTable[h] = nullptr;
		size--;
		return retPtr;
	}
	return nullptr;
}

template<class T>
inline T * HashTable<T>::GetItem(T * ptr)
{
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	// bool spotOccupied;
	int count = 0;
	// Check by value, not by pointer
	while ((dataTable[h] == nullptr || !(*dataTable[h] == *ptr)) && count < size) {
		h = (h + 1) % max;
		count++;
	}
	if (*dataTable[h] == *ptr && count != size) {
		T* retPtr = dataTable[h];
		return retPtr;
	}
	return nullptr;
}

template<class T>
inline int HashTable<T>::GetLength()
{
	return size;
}



/*********************************************************************
Derived Chain Hash
*********************************************************************/

template <class T>
class HashTableLinked : HashTable<T>{
protected:
	int max;
	int size;
	LinkedList<T>* *dataTable;
public:
	HashTableLinked(int);
	void AddItem(T* ptr);
	T* RemoveItem(T* ptr);
	T* GetItem(T* ptr);
	int GetLength();
};

template<class T>
inline HashTableLinked<T>::HashTableLinked(int length = 100)
{
	max = length;
	size = 0;
	dataTable = new LinkedList<T>*[max];
	for (int i = 0; i < max; i++) {
		dataTable[i] = nullptr;
	}
}

template<class T>
inline void HashTableLinked<T>::AddItem(T * ptr)
{
	if (size == max) {
		// TODO Error checking
	}
	int h = Hash(ptr->toString());
	dataTable[h].AddItem(ptr);
	size++;
}

template<class T>
inline T * HashTableLinked<T>::RemoveItem(T * ptr)
{
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	T* t = dataTable[h].RemoveItem(ptr);
	if (t != nullptr) {
		size--;
	}
	return t;
}

template<class T>
inline T * HashTableLinked<T>::GetItem(T * ptr)
{
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	T* t = dataTable[h].GetItem(ptr);
	return t;
}

template<class T>
inline int HashTableLinked<T>::GetLength()
{
	return size;
}


/*********************************************************************
Linked List
*********************************************************************/
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
	class ItemNotFound {
	public:
		ItemNotFound() {};
	};
	class EmptyList {
	public:
		EmptyList() {};
	};
};


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

template <class T> class ChainedHashTable : public HashTable<T> {
public:
	ChainedHashTable(int);
	void AddItem(T* ptr); //overload
	T* RemoveItem(T* ptr); //overload
	T* GetItem(T* ptr);// overload
					   // DO not need to change int GetLength();
};

template <class T>
inline ChainedHashTable<T>::ChainedHashTable(int length = 100) {
	max = length;
	size = 0;
	// LinkedList<Student> StudentDirectory(nullptr);
	dataTable = new LinkedList<T>[max];
	for (int i = 0; i < max; i++) {
		dataTable[i] = LinkedList(nullptr);
	}
}

template <class T>
inline void ChainedHashTable<T>::AddItem(T* ptr) {

	int h = Hash(ptr->toString());
	dataTable[h].AddItem(ptr);
	size++;
}

template <class T>
inline T* ChainedHashTable<T>::RemoveItem(T* ptr) {

	if (size == 0) {
		return nullptr;
	}

	int h = Hash(ptr->toString());
	retItem = dataTable[h].RemoveItem(ptr);
	if (retItem != nullptr)
	{
		size--;
	}
	return retItem;
}

template <class T>
inline T* ChainedHashTable<T>::GetItem(T* ptr) {

	int h = Hash(ptr->toString());
	T* retPtr = nullptr;
	for (int i = 0; i < dataTable[h].Size(); i++) {
		if (dataTable[h].SeeAt(i) == ptr) {
			retPtr = dataTable[h].SeeAt(i);
		}
	}
	return retPtr;
}