#pragma once
#ifndef STOrderedListCK_H
#define STOrderedListCK_H

#include <string>
using namespace std;

template <class T> class OrderedList {
protected:
	int max; // maximum number of items in the OrderedList
	int pos; // the next available spot in the OrderedList
	T* *list; // pointer array
public:
	OrderedList(int);
	void AddItem(T *ptr);
	T* RemoveItem(T *ptr);
	void MakeEmpty();
	bool isEmpty();
	bool isFull();
	int length();
	T* getLastItem();
	T* peekItem(int a);
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
inline OrderedList<T>::OrderedList(int m) {
	pos = 0;
	max = m;
	list = new T*[max];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
}

template <class T>
inline void OrderedList<T>::AddItem(T* ptr) {
	if (pos >= max) {
		throw OrderedListOverflow(topOfList + 1);
	}
	else {
		int counter = 0;
		while ((*ptr < *list[counter]) && (counter < max)) {
			counter++;
		}
		for (int i = pos; i > counter; i--) {
			list[i + 1] = list[i];
		}
		list[counter] = ptr;
	}
}

template <class T>
inline T* OrderedList<T>::RemoveItem(T* ptr) {
	if (pos < 1) {
		throw OrderedListUnderflow();
	}
	else {
		int counter = 0;
		while ((*list[counter] != *ptr) && (counter < pos)) {
			counter++;
		}
		if (counter != pos) {
			for (int i = counter; i < pos; i++) {
				list[i + 1] = list[i];
			}
		}
		else {
			throw OrderedListItemNotFound();
		}
		
		pos--;
		return list[counter];
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
	max = 20;
	list = new T*[max];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
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
inline void OrderedListBack<T>::AddItem(T*) {
	if (pos >= max) {
		throw OrderedListOverflow(topOfList + 1);
	}
	else {
		int counter = pos-1;
		while ((*ptr > *list[counter]) && (counter >= 0)) {
			counter--;
		}
		for (int i = pos; i > counter; i--) { //TODO: Please check the code that Kyle and I wrote while we were sleepy @Evan
			list[i] = list[i + 1];
		}
		list[counter] = ptr;
	}
}

// Task 3 Derived Class
template <class T> class OrderedListEmptySpace : public OrderedList<T> {
	// pos indicates the number of items in the array in the empty space ordered list
public:
	OrderedListEmptySpace();
	OrderedListEmptySpace(int m);
	void AddItem(T*);
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
	max = m;
	list = new T*[max];
	for (int i = 0; i < max; i++) {
		list[i] = nullptr;
	}
}

template<class T>
inline void OrderedListEmptySpace<T>::AddItem(T* ptr) {
	if (pos >= max) { throw OrderedListOverflow(pos + 1); }

	int counterLow = 0;
	int counterHigh = max - 1;

	// Finds closest value from left to where the item should be inserted
	for (int i = 0; i < max; i++) {
		if (list[i] != nullptr) { if ((*list[i]) <= (*ptr)) { counterLow = i; } }
	}

	// Finds closest value from right to where the item should be inserted		
	for (int i = (max - 1); i >= 0; i--) {
		if (list[i] != nullptr) { if ((*list[i]) >= (*ptr)) { counterHigh = i; } }
	}
	// Item should be inserted halfway between 2 items where it belongs
	int indexToInsert = (counterHigh + counterLow) / 2;

	// If there is no pointer at that position, insert the item.
	if (list[indexToInsert] == nullptr) { list[indexToInsert] = ptr; }

	else {
		// Finds nearest null space to the right and left. 
		int closestNullIndexHigh = max * 2;
		int closestNullIndexLow = max * 2;

		for (int i = max - 1; i > counterHigh; i--) {
			if (list[i] == nullptr) { closestNullIndexHigh = i; }
		}
		for (int i = 0; i < counterLow; i++) {
			if (list[i] == nullptr) { closestNullIndexLow = i; }
		}

		// Determine closest null space and move items to the left or right
		int diffLow = abs(indexToInsert - closestNullIndexLow);
		int diffHigh = abs(indexToInsert - closestNullIndexHigh);
		if (diffHigh < diffLow) {
			for (int i = indexToInsert; i < closestNullIndexHigh; i++) { list[i + 1] = list[i]; }
		}
		else {
			for (int i = closestNullIndexLow; i < indexToInsert; i++) { list[i] = list[i + 1]; }
		}
		// Insert pointer at the required index
		list[indexToInsert] = ptr;
	}
}

template<class T>
inline T* OrderedListEmptySpace<T>::RemoveItem(int itemIndex) {
	if (pos < 1) {
		throw OrderedListUnderflow();
	}
	else if ((itemIndex >= pos) || (itemIndex < 0)) {
		throw OrderedListOutOfRangeIndex();
	}
	else {
		T* retVal = list[itemIndex];
		listItemIndex = nullptr;
		return retVal;
	}
}