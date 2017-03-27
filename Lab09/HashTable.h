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
	LinkedList();
	LinkedList(T* item);
	void AddItem(T* ptr);
	T* RemoveItem(T* ptr);
	bool IsInList(T* ptr);
	bool IsEmpty();
	int Size();
	T* SeeNext();
	T* SeeAt(int index);
	void Reset();
	string toString(); // For testing, should only used for linked lists with students
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
inline LinkedList<T>::LinkedList()
{
	// Default constructor for linked list.
	size = 0;
	pos = 0;
	head = nullptr;
	next = head;
}

template<class T>
inline LinkedList<T>::LinkedList(T * item = nullptr)
{
	// Constructor for linked list.
	size = 0;
	pos = 0;
	head = item;
	next = head;
}

template<class T>
inline void LinkedList<T>::AddItem(T * ptr)
{
	// Add item to linked list
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
	// Remove item from linked list
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
	// Returns whether item is in the list or not
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
	// Returns whether linked list is empty
	return size == 0;
}

template<class T>
inline int LinkedList<T>::Size()
{
	// Returns size of linked list
	return size;
}

template<class T>
inline T * LinkedList<T>::SeeNext()
{
	// Returns the next item in the linked list
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
	// Returns the item at a specific index in the linked list
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
	// Returns the item at a specific index in the linked list without changing the internal variable pos.
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
	// Resets pos and next.
	pos = 0;
	next = head;
}

template<class T>
inline string LinkedList<T>::toString() // For testing
{
	// Returns a string with the information of the students (M numbers) in the linked list
	string retString = "";
	int tPos = pos;
	pos = 0;
	Student* s;
	for (int i = 0; i < size; i++) {
		s = SeeAtSamePos(i);
		retString += (*s).toString()+ ", ";
	}
	pos = tPos;
	return retString;
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
	HashTable();
	HashTable(int);
	void AddItem(T* ptr);
	T* RemoveItem(T* ptr);
	T* GetItem(T* ptr);
	int GetLength();
	class ListFull {
	public:
		ListFull() {};
	};
};

#endif 

template<class T>
inline int HashTable<T>::Hash(string s)
{
	// Hash function: Returns sum of the ASCII values in string argument modulo the max items in the hash table
	int h = 0;
	const char *cArray = s.c_str();
	for (int i = 0; i < s.length(); i++) {
		h += (int)cArray[i];
	}
	
	return h % max;
}

template<class T>
inline HashTable<T>::HashTable()
{
	// Default constructor for Hash Table
	max = 100;
	size = 0;
	dataTable = new T*[max];
	for (int i = 0; i < max; i++) {
		dataTable[i] = nullptr;
	}
}

template<class T>
inline HashTable<T>::HashTable(int length=100)
{
	// Constructor for Hash Table
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
	// Add item to the Hash Table
	if (size == max) {
		throw ListFull();
	}

	int h = Hash(ptr->toString());
	while (dataTable[h] != nullptr) {
		h = (h + 1) % max;
	} 
	dataTable[h] = ptr;
	size++;
}

template<class T>
inline T * HashTable<T>::RemoveItem(T * ptr)
{
	// Removes item from the Hash Table
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	int count = 0;
	// Iterate throught the Hash Table starting at the hash value checking every position after in the Hash Table 
	// until the desired item is found or all values in Hash Table have been checked.  
	// The item is found by comparing values not memory locations.
	while ((dataTable[h] == nullptr || !(*dataTable[h] == *ptr)) && count < size) {
		h = (h + 1) % max;
		count++;
	}
	if (dataTable[h] != nullptr){
		if (*dataTable[h] == *ptr) {
			T* retPtr = dataTable[h];
			dataTable[h] = nullptr;
			size--;
			return retPtr;
		}
	}
	return nullptr;
}

template<class T>
inline T * HashTable<T>::GetItem(T * ptr)
{
	// Return an item in the Hash Table without removing it from the Hash Table
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	int count = 0;
	// Iterate throught the Hash Table starting at the hash value checking every position after in the Hash Table 
	// until the desired item is found or all values in Hash Table have been checked.  
	// The item is found by comparing values not memory locations.
	while ((dataTable[h] == nullptr || !(*dataTable[h] == *ptr)) && count < size) {
		h = (h + 1) % max;
		count++;
	}
	if (dataTable[h] != nullptr) {
		if (*dataTable[h] == *ptr && count != size) {
			T* retPtr = dataTable[h];
			return retPtr;
		}
	}
	return nullptr;
}

template<class T>
inline int HashTable<T>::GetLength()
{
	// Returns number of items in the Hash Table
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
	LinkedList<T>* dataTable;
	int Hash(string);
public:
	//HashTableLinked();
	HashTableLinked(int);
	void AddItem(T* ptr);
	T* RemoveItem(T* ptr);
	T* GetItem(T* ptr);
	int GetLength();
	string toString();
	/*class HashTableLinkedFull {
	public:
		HashTableLinkedFull() {};
	};*/
};
template<class T>
inline int HashTableLinked<T>::Hash(string s)
{
	// Hash function for Hash Table Linked
	int h = 0;
	const char *cArray = s.c_str();
	for (int i = 0; i < s.length(); i++) {
		h += (int)cArray[i];
	}

	return h % max;
}
/*template<class T>
inline HashTableLinked<T>::HashTableLinked()
{
	max = 100;
	size = 0;
	dataTable = new LinkedList<T>[max];
	for (int i = 0; i < max; i++) {
		dataTable[i] = LinkedList<T>();
	}
}*/

template<class T>
inline HashTableLinked<T>::HashTableLinked(int length = 100)
{
	// Constructor for Hash Table Linked
	max = length;
	size = 0;
	dataTable = new LinkedList<T>[max];
	for (int i = 0; i < max; i++) {
		dataTable[i] = LinkedList<T>(nullptr);
	}
}

template<class T>
inline void HashTableLinked<T>::AddItem(T * ptr)
{
	// Add item to the Hash Table Linked
	int h = Hash(ptr->toString());
	dataTable[h].AddItem(ptr); // Add item to the linked list at hash value position in the Hash Table Linked
	size++;
}

template<class T>
inline T * HashTableLinked<T>::RemoveItem(T * ptr)
{
	// Remove Item from the Hash Table Linked
	if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	T* t = dataTable[h].RemoveItem(ptr); // Remove item from the linked list at hash value position in the Hash Table
	// If the item is not in the linked list, a null pointer is returned.
	if (t != nullptr) { 
		size--;
	}
	return t;
}

template<class T>
inline T * HashTableLinked<T>::GetItem(T * ptr)
{
	// Return item in the Hash Tabled Linked without removing it.
	/*if (size == 0) {
		// TODO Maybe error checking
		return nullptr;
	}
	int h = Hash(ptr->toString());
	T* t = dataTable[h].GetItem(ptr); // Removed this code because the Linked List has no GetItem function
	return t;*/
	int h = Hash(ptr->toString());
	T* retPtr = nullptr;
	for (int i = 0; i < dataTable[h].Size(); i++) {
		retPtr = dataTable[h].SeeAt(i);
		if (*retPtr == *ptr) {
			return retPtr;
		}
	}
	return nullptr;
}

template<class T>
inline int HashTableLinked<T>::GetLength()
{
	// Returns the number of items in the Hash Table Linked
	return size;
}

template<class T>
inline string HashTableLinked<T>::toString() {
	// Function for testing purposes only, returns a string representing the Hash Table Linked
	string retString = "";
	for (int i = 0; i < max; i++) {
		retString += to_string(i) + ": " + dataTable[i].toString() + "\n";
	}
	return retString;
}
/*
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
}*/