#pragma once
#ifndef STOrderedListCK_H
#define STOrderedListCK_H

#include <string>
using namespace std;

template <class T> class OrderedList {
protected:
	int max = 20; // maximum number of items in the OrderedList
	int pos; // the next available spot in the OrderedList
	T* *list[max]; // pointer array
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
	topOfList = 0;
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
		throw OrderedListOutOfRangeIndex;
	}
}


template <class T>
inline OrderedList OrderedList<T>::operator<(OrderedList lst) {
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

template<class T>
template <class OrderedList> class OrderedListBack{
	void AddItem(T*);
};

template<class T>
template<class OrderedList>
inline void OrderedListBack<OrderedList>::AddItem(T*) {
	if (pos >= max) {
		throw OrderedListOverflow(topOfList + 1);
	}
	else {
		int counter = pos-1;
		while ((*ptr > *list[counter]) && (counter >= 0)) {
			counter--;
		}
		for (int i = pos; i > counter; i--) { //TODO: Please check the code that Kyle and I wrote while we were sleepy @Evan
			list[i + 1] = list[i];
		}
		list[counter] = ptr;
	}
}

// Task 3 Derived Class

template<class T>
template <class OrderedList> class OrderedListBack {
	void AddItem(T*);
};

template<class T>
template<class OrderedList>
inline void OrderedListBack<OrderedList>::AddItem(T*) {
	if (pos >= max) {
		throw OrderedListOverflow(topOfList + 1);
	}
	else {
		int counter = pos - 1;
		while ((*ptr > *list[counter]) && (counter >= 0)) {
			counter--;
		}
		for (int i = pos; i > counter; i--) { //TODO: Please check the code that Kyle and I wrote while we were sleepy @Evan
			list[i + 1] = list[i];
		}
		list[counter] = ptr;
	}
}