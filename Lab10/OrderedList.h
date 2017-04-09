#pragma once
#ifndef STOrderedListCK_H
#define STOrderedListCK_H

#include <string>
#include <iostream>
using namespace std;

template <class T> class OrderedList {
protected:
	int max; // maximum number of items in the OrderedList
	int pos; // the next available spot in the OrderedList
	T* *list; // pointer array
	int numOps;
public:
	OrderedList();
	OrderedList(int);
	void AddItem(T *ptr);
	T* RemoveItem(T *ptr);
	void MakeEmpty();
	bool isEmpty();
	bool isFull();
	int length();
	T* getLastItem();
	T* peekItem(int a);
	int getNumOps();
	string getListContents();
	OrderedList operator<(OrderedList lst);
	OrderedList operator>(OrderedList lst);
	bool operator==(OrderedList lst);




	//OrderedListOverflow Class Definition
	class OrderedListOverflow {
	private:
		int index;
	public:
		OrderedListOverflow(int i) { index = i; }
		int getValue() { return index; }
	};


	//OrderedListUnderflow Class Definition
	class OrderedListUnderflow {
	public:
		OrderedListUnderflow() { }
	};

	//OrderedListItemNotFound Class Definition
	class OrderedListItemNotFound {
	public:
		OrderedListItemNotFound() { }
	};

	class OrderedListOutOfRangeIndex {
	public:
		OrderedListOutOfRangeIndex() { }
	};
};

#endif
#include <string>
template <class T>
inline OrderedList<T>::OrderedList() {
	pos = numOps = 0;
	max = 20;
	list = new T*[max];
	/*for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}*/
}

template <class T>
inline OrderedList<T>::OrderedList(int m) {
	pos = numOps = 0;
	max = m;
	list = new T*[max];
	/*for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}*/
}

template <class T>
inline int OrderedList<T>::getNumOps() {
	return numOps;
}

template <class T>
inline string OrderedList<T>::getListContents() {
	string output = "";
	int p = pos;
	for (int i = 0; i < pos; i++) {
		if (list[i] != nullptr) {
			output += to_string(*list[i]) + " ";
		}
		else {
			output += "- ";
		}
	}
	return output;
}

template <class T>
inline void OrderedList<T>::AddItem(T* ptr) {
	numOps++;
	if (pos >= max) {
		throw OrderedListOverflow(pos + 1);
	}
	else {
		int counter = 0;
		while ((counter < pos) && (*ptr > *list[counter])) {
			numOps++;
			counter++;
		}
		for (int i = pos; i > counter; i--) {
			list[i] = list[i-1];
			numOps++;
		}
		list[counter] = ptr;
		pos++;
	}

}

template <class T>
inline T* OrderedList<T>::RemoveItem(T* ptr) {
	numOps++;
	if (pos < 1) {
		throw OrderedListUnderflow();
	}
	else {
		int counter = 0;
		while ((*list[counter] != *ptr) && (counter < pos)) {
			numOps += 2;
			counter++;
		}
		if (counter != pos) {
			numOps++;
			T* retItem = list[counter];
			for (int i = counter; i < pos-1; i++) {
				list[i] = list[i+1];
				numOps++;
			}
			pos--;
			return retItem;
		}
		throw OrderedListItemNotFound();
	}
};


template <class T>
inline int OrderedList<T>::length() {
	return pos;
}

template <class T>
inline void OrderedList<T>::MakeEmpty() {
	// for (int i = 0; i < topOfList; i++) {
	// 	list[i] = nullptr;
	// }
	pos = 0;
}

/*template <class T>
inline T*  OrderedList<T>::returnOrderedListListItem(int index) {
if (index >= topOfList) { //if the OrderedList's top is less than the requested index, return a nullptr instead
return nullptr;
}
return list[index];
}*/

template <class T>
inline bool OrderedList<T>::isEmpty() {
	return pos == 0;
}

template <class T>
inline bool OrderedList<T>::isFull() {
	return pos  == max;
}

template<class T>
inline T* OrderedList<T>::getLastItem() {
	return list[pos-1];
}

template<class T>
inline T* OrderedList<T>::peekItem(int a) {
	if ((a < pos) && (a >= 0)) {
		return list[a];
	}
	else {
		throw OrderedListOutOfRangeIndex();
	}
}


template <class T>
inline OrderedList<T> OrderedList<T>::operator< (OrderedList lst) {
	if (pos < lst.length()) {
		return this;
	}
	else if (pos > lst.length()) {
		return lst;
	}
	else {
		if (list[pos - 1] > lst.getLastItem()) {
			return lst;
		}
		else {
			return this;
		}
	}
}

template<class T>
inline OrderedList<T> OrderedList<T>::operator>(OrderedList lst) {
	if (pos > lst.length()) {
		return this;
	}
	else if (pos < lst.length()) {
		return lst;
	}
	else {
		if (list[pos - 1] < lst.getLastItem()) {
			return lst;
		}
		else {
			return this;
		}
	}
}

template<class T>
inline bool OrderedList<T>::operator==(OrderedList lst) {
	if (pos == lst.length()) {
		bool flag = true; // flag for ordered lists not equal 
		for (int i = 0; i < max; i++) {
			if (list[i] != lst.peekItem(i)) {
				flag = false;
			}
		}
		return flag;
	}
	else {
		return false;
	}
}


// Derived Class With Back Linear Search

template <class T> class OrderedListBack : public OrderedList<T> {
public:
	OrderedListBack();
	OrderedListBack(int m);
	void AddItem(T*);
};

template<class T>
inline OrderedListBack<T>::OrderedListBack() {
	pos = 0;
	numOps = 0;
	max = 20;
	list = new T*[max];
	/*for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}*/
}

template<class T>
inline OrderedListBack<T>::OrderedListBack(int m) {
	pos = 0;
	max = m;
	list = new T*[max];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
}

template<class T>
inline void OrderedListBack<T>::AddItem(T* ptr) {
	numOps++;
	if (pos >= max) {
		throw OrderedListOverflow(pos + 1);
	}
	else {
		//int compCounter = pos-1;
		int counter = pos;
		if (pos == 0) { counter = 0; }
		while ((counter > 0) && (*ptr < *list[counter-1])) {
			numOps++;
			// compCounter--;
			counter--;
		}
		// if (counter < 0) { counter = 0; }
		for (int i = pos; i > counter; i--) { //TODO: Please check the code that Kyle and I wrote while we were sleepy @Evan
			list[i] = list[i-1];
			numOps++;
		}
		
		list[counter] = ptr;
		pos++;
	}
}
/*numOps++;
if (pos >= max) {
	throw OrderedListOverflow(pos + 1);
}
else {
	int counter = 0;
	while ((counter < pos) && (*ptr < *list[counter])) {
		numOps++;
		counter++;
	}
	for (int i = pos; i > counter; i--) {
		list[i] = list[i - 1];
		numOps++;
	}
	list[counter] = ptr;
	pos++;
}*/
// Task 3 Derived Class
template <class T> class OrderedListEmptySpace : public OrderedList<T> {
	// pos indicates the number of items in the array in the empty space ordered list
public:
	OrderedListEmptySpace();
	OrderedListEmptySpace(int m);
	void AddItem(T*);
	string getListContents();
	T* RemoveItem(int itemIndex);
};

//Derived class functions for empty space ordered list
template<class T>
inline OrderedListEmptySpace<T>::OrderedListEmptySpace() {
	pos = 0;
	max = 20;
	list = new T*[max];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
}

template<class T>
inline OrderedListEmptySpace<T>::OrderedListEmptySpace(int m) {
	pos = 0;
	numOps = 0;
	max = m;
	list = new T*[max];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
}

template<class T>
inline void OrderedListEmptySpace<T>::AddItem(T* ptr) {
	numOps++;
	if (pos >= max) { 
		throw OrderedListOverflow(pos + 1); 
	}

	int counterLow = 0;
	int counterHigh = max - 1;

	// Finds closest value from left to where the item should be inserted
	for (int i = 0; i < max; i++) {
		numOps++;
		if (list[i] != nullptr) { 
			if ((*list[i]) <= (*ptr)) { 
				numOps++;
				counterLow = i;
			} 
		}
	}

	// Finds closest value from right to where the item should be inserted		
	for (int i = (max - 1); i >= 0; i--) {
		numOps++;
		if (list[i] != nullptr) { 
			if ((*list[i]) >= (*ptr)) { 
				numOps++;
				counterHigh = i; 
			} 
		}
	}
	// Item should be inserted halfway between 2 items where it belongs
	int indexToInsert;
	if (list[counterLow] != nullptr && list[counterHigh] == nullptr) {
		indexToInsert = (counterHigh + counterLow) / 2 + 1;
	}
	else {
		indexToInsert = (counterHigh + counterLow) / 2;
	}
	// If there is no pointer at that position, insert the item.
	numOps++;
	if (list[indexToInsert] == nullptr) { 
		list[indexToInsert] = ptr; 
	}

	else {
		// Finds nearest null space to the right and left. 
		int closestNullIndexHigh = max * 2;
		int closestNullIndexLow = max * 2;

		for (int i = max - 1; i > counterHigh; i--) {
			numOps++;
			if (list[i] == nullptr) { 
				closestNullIndexHigh = i; 
			}
		}
		for (int i = 0; i < counterLow; i++) {
			numOps++;
			if (list[i] == nullptr) { 
				closestNullIndexLow = i; 
			}
		}

		// Determine closest null space and move items to the left or right
		int diffLow = abs(indexToInsert - closestNullIndexLow);
		int diffHigh = abs(indexToInsert - closestNullIndexHigh);
		if (diffHigh < diffLow) {//right
			//cout << "right ";
			numOps++;
			//for (int i = indexToInsert; i < closestNullIndexHigh; i++) { 
			for (int i = closestNullIndexHigh; i > indexToInsert; i--) {
				//numOps++;
				list[i] = list[i-1]; 
			}
			if (indexToInsert == 0) {
				list[1] = list[0];
			}
		}
		else {//left
			//cout << "left  ";
			for (int i = closestNullIndexLow; i < indexToInsert; i++) { 
				//numOps++;
				list[i] = list[i + 1];
			}
		}
		// Insert pointer at the required index
		list[indexToInsert] = ptr;
	}
	pos++;
}

template<class T>
inline T* OrderedListEmptySpace<T>::RemoveItem(int itemIndex) {
	numOps++;
	if (pos < 1) {
		throw OrderedListUnderflow();
	}
	else if ((itemIndex >= pos) || (itemIndex < 0)) {
		
		throw OrderedListOutOfRangeIndex();
	}
	else {
		numOps++;
		T* retVal = list[itemIndex];
		list[itemIndex] = nullptr;
		return retVal;
	}
}

template <class T>
inline string OrderedListEmptySpace<T>::getListContents() {
	string output = "";
	int p = pos;
	for (int i = 0; i < max; i++) {
		if (list[i] != nullptr) {
			output += to_string(*list[i]) + " ";
		}
	}
	return output;
}