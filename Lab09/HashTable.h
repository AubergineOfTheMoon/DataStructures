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
private:
	int max;
	int size;
	T* *dataTable;
	int Hash(string);
public:
	HashTable(int size);
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
