#pragma once
#ifndef BTREE_H
#define BTREE_H

#include"OrderedList.h"

/*******************************************************
					Node Class
********************************************************/

template<class T> class Node {
private:
	OrderedList<T> keyList;
	Node* children[];
	int max;
	// int pos;
public:
	Node(int);
	void addKey(int*);
	int* removeKey(int*);
	void addChild(Node*);
	Node* removeChild(Node*);
	bool isFull();
	bool isEmpty();
};

template<class T>
inline Node::Node(int m = 3) {
	max = m;
	// pos = 0;
	keyList = OrderedList<T>(max);
}

template<class T>
inline void Node<T>::addKey(int *k)
{
	/*	int counter = 0;
	while ((counter < pos) && (*k > *keyList[counter])) {
		counter++;
	}
	for (int i = pos; i > counter; i--) {
		keyList[i] = keyList[i - 1];
	}*/
	try {
		keyList.AddItem(k);
	}
	catch (OrderedListOverflow) {
		cout << "Your program sucks right now. This means you aren't even splitting the nodes properly" << endl;
	}
	// pos++;
	// if (isFull()) {
		// TODO Throw Error for splitting
	// }
}

template<class T>
inline int* Node<T>::removeKey(int *k)
{
	try {
		int* retItem = keyList.RemoveItem(k);
	}
	catch (OrderedListItemNotFound) {
		cout<<"Add checking for item before trying to remove it."
	}
	catch (OrderedListUnderflow) {
		cout << "Your program should not get tot this point, but if it has :( here is something to catch it." << endl;
	}
	return retItem;
	/*int* retItem = nullptr;
	int counter = 0;
	for (int i = 0; i < pos; i++) {
		if (*k == *keyList[i]) {
			retItem = keyList[i];
			counter = i;
		}
	}
	for (int i = counter; i < pos - 1; i++) {
		keyList[i] = keyList[i + 1];
	}
	pos--;
	return retItem;*/

	// TODO if node is empty delete/merge things
}
template<class T>
inline void Node<T>::addChild(Node*) {
	//TODO: Add code for adding child	

}

template<class T>
inline Node* Node<T>::removeChild(Node*) {
	///TODO Add code for removing child
}

template<class T>
inline bool Node<T>::isFull()
{
	return keyList.isFull();
}

template<class T>
inline bool Node<T>::isEmpty()
{
	return keyList.isEmpty();
}

/*******************************************************
					BTree Class
********************************************************/

template<class T> class BTree {
private:
	int treeSize;

public:
	BTree();
	void insertItem(int*);
	void splitChild(nodeToSplit, parent, child);
	void removeItem();
	void findItem();
	int getTreeSize();
	int getTreeHeight();
	void PrintTree();

};

#endif

template<class T> 
inline BTree<T>::BTree() {
	treeSize = 0;
}

template<class T>
inline void BTree<T>::insertItem(int*)
{
	if()
}

template<class T>
inline void BTree<T>::removeItem()
{
}

template<class T>
inline void BTree<T>::findItem()
{
}

template<class T>
inline int BTree<T>::getTreeSize()
{
	return 0;
}

template<class T>
inline int BTree<T>::getTreeHeight()
{
	return 0;
}

template<class T>
inline void BTree<T>::PrintTree()
{
}
