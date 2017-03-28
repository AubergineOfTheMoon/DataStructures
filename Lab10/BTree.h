#pragma once
#ifndef BTREE_H
#define BTREE_H

/*******************************************************
					Node Class
********************************************************/

template<class T> class Node {
private:
	int keyList[];
	Node* children[];
	int max;
	int pos;
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
	pos = 0;
}

template<class T>
inline void Node<T>::addKey(int *k)
{
	if (isFull()) {
		// TODO Throw Error for splitting
	}
	else {
		int counter = 0;
		while ((counter < pos) && (*k > *keyList[counter])) {
			counter++;
		}
		for (int i = pos; i > counter; i--) {
			keyList[i] = keyList[i - 1];
		}
		keyList[counter] = k;
		pos++;
	}
}

template<class T>
inline int* Node<T>::removeKey(int *k)
{
	int* retItem = nullptr;
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
	return retItem;

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
	return pos == max;
}

template<class T>
inline bool Node<T>::isEmpty()
{
	return pos == 0;
}

/*******************************************************
					BTree Class
********************************************************/

template<class T> class BTree {
private:
	int treeSize;
	

public:
	BTree();
	void insertItem();
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
inline void BTree<T>::insertItem()
{
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
