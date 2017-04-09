#pragma once
#ifndef BTREE_H
#define BTREE_H
#include<iostream>
#include<math.h>
#include"OrderedList.h"
using namespace std;

/*******************************************************
					Node Class
********************************************************/

template<class T> class Node {
private:
	OrderedList<T> keyList;
	OrderedList<Node<T>> children;
	int max;
	//int posChildren;
public:
	Node(int m = 3);
	void addKey(T*);
	T* removeKey(T*);
	T* peekKey(int);
	void addChild(Node*);
	Node* getChild(int);
	Node* removeChild(Node<T>*);
	int getNumChildren();
	bool isFull();
	bool isLeaf();
	bool isEmpty();
	int getNumKeys();
	bool operator<(Node<T>);
	bool operator>(Node<T>);
	bool operator==(Node<T>);
	bool operator!=(Node<T>);
	class IndexOutOfRange {
	public: IndexOutOfRange() {}
	};
};

template<class T>
inline Node<T>::Node(int m = 3) {
	max = m;
	// posChildren = 0;
	keyList = OrderedList<T>(max);
	children = OrderedList<Node<T>>(max+1);
}

template<class T>
inline void Node<T>::addKey(T* k)
{
	/*	try{
	*/	
	keyList.AddItem(k);
	// TODO: Catch error
	/*catch (OrderedListOverflow) {
		cout << "Your program sucks right now. This means you aren't even splitting the nodes properly" << endl;
	}*/
}

template<class T>
inline T* Node<T>::removeKey(T* k)
{
	//try {
		T* retItem = keyList.RemoveItem(k);
		return retItem;
	/*}
	catch (OrderedListItemNotFound) {
		cout << "Add checking for item before trying to remove it." << endl;
	}
	catch (OrderedListUnderflow) {
		cout << "Your program should not get tot this point, but if it has :( here is something to catch it." << endl;
	}*/
	//TODO: Add error catching
	// return retItem;
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
inline T* Node<T>::peekKey(int peekPos) {
	//TODO: Add code for errors	
	//try {
	int* retItem = keyList.peekItem(peekPos);
	return retItem;
	/*}
	catch (OrderedListOutOfRangeIndex) {
		cout << "Not a valid peek.";
	}*/
}

template<class T>
inline void Node<T>::addChild(Node* child) {
	//TODO: Add code for adding child	
	children.AddItem(child);
	// posChildren++;
}

template<class T>
inline Node<T>* Node<T>::removeChild(Node<T>* childToRemove) {
	///TODO Add code for removing child
	return children.RemoveItem(childToRemove);
}

template<class T>
inline Node<T>* Node<T>::getChild(int removePos) {
	///TODO Add code for removing child
	Node* nodeToReturn = children.peekItem(removePos);
	return nodeToReturn;
	
}

template<class T>
inline int Node<T>::getNumChildren() {
	///TODO Add code for removing child
	return children.length();
}

template<class T>
inline bool Node<T>::isFull()
{
	return keyList.isFull();
}

template<class T>
inline bool Node<T>::isLeaf()
{
	return children.length() == 0;
}

template<class T>
inline bool Node<T>::isEmpty()
{
	return keyList.isEmpty();
}

template<class T>
inline int Node<T>::getNumKeys()
{
	return keyList.length();
}

template<class T>
bool Node<T>::operator<(Node<T> comp) {
	return *keyList.peekItem(0) < *comp.peekKey(0);

}

template<class T>
bool Node<T>::operator>(Node<T> comp) {
	return *keyList.peekItem(0) > *comp.peekKey(0);

}

template<class T>
bool Node<T>::operator==(Node<T> comp) {
	bool flag = true;
	if (keyList.length() != comp.getNumKeys()) {
		return false;
	}
	for (int i = 0; i < comp.getNumKeys(); i++) {
		if (*keyList.peekItem(i) != *comp.peekKey(i)) {
			flag = false;
		}
	}
	return flag;
}

template<class T>
bool Node<T>::operator!=(Node<T> comp) {
	return !(this->operator==(comp));
}

/*******************************************************
					BTree Class
********************************************************/

template<class T> class BTree {
private:
	int treeSize;
	// Node<T>* rootNode;
	Node<T>* findParent(Node<T>* findNode, Node<T>* nodeToCheck);
	int order;
public:
	Node<T>* rootNode;
	BTree(int);
	void insertItem(T*, Node<T>* parent);
	void splitChild(Node<T>* nodeToSplit, int, Node<T>* child);
	void removeItem();
	T* findItem(T*, Node<T>* nodeToCheck);
	int getTreeSize();
	int getTreeHeight();
	void PrintTree(Node<T>* parent, Node<T>* nodeToPrint);

};

#endif

template<class T> 
inline BTree<T>::BTree(int o) {
	treeSize = 0;
	order = o;
	rootNode = new Node<T>(order);
}

template<class T>
inline void BTree<T>::insertItem(T* key, Node<T>* parent) {
	// Parent is leaf and not full, node is never full as node is split when it is full
	if ((parent->getNumKeys() < order) && (parent->isLeaf())) {
		parent->addKey(key);
		treeSize++;
		if (parent->getNumKeys() == order) {
			//split Node
			// split node into at least two if it is a root
			// else split node into at least ceil(order/2)
			splitChild(parent, 0, nullptr);
		}
	}
	else {
		// Find out which child the key fits in 
		Node<T>* newParent;
		T* keyComp;
		int insertNodeIndex = 0;
		for (int i = 0; i < parent->getNumKeys(); i++) {
			keyComp = parent->peekKey(i);
			if (*key > *keyComp) {
				insertNodeIndex = i + 1;
			}
		}
		newParent = parent->getChild(insertNodeIndex);
		if (newParent->getNumKeys() == order) {
			// split child
			splitChild(parent, insertNodeIndex, newParent);
		}
		insertItem(key, newParent);
	}
}

template<class T>
inline void BTree<T>::removeItem() {
	// Empty function
}

template<class T>
inline T* BTree<T>::findItem(T* findkey, Node<T>* nodeToCheck) {
	for (int i = 0; i < nodeToCheck->getNumKeys(); i++) {
		if (*nodeToCheck->peekKey(i) == *findkey) {
			return nodeToCheck->peekKey(i);
		}
	}
	if (nodeToCheck->isLeaf()) {
		return nullptr;
	}
	else {
		T* keyComp;
		int compNodeIndex = 0;
		for (int i = 0; i < nodeToCheck->getNumKeys(); i++) {
			keyComp = nodeToCheck->peekKey(i);
			if (*findkey > *keyComp) {
				compNodeIndex = i+1;
			}
		}
		return findItem(findkey, nodeToCheck->getChild(compNodeIndex));
	}
}

template<class T>
inline Node<T>* BTree<T>::findParent(Node<T>* findNode, Node<T>* nodeToCheck) {
	if ((*findNode == *nodeToCheck) && (*nodeToCheck == *rootNode)) {
		return nullptr;
	}
	else if (nodeToCheck->isLeaf()) {
		return nullptr;
		//TODO: Throw item not found error
	}
	else {
		for (int i = 0; i < nodeToCheck->getNumChildren(); i++) {
			if (*nodeToCheck->getChild(i) == *findNode) {
				return nodeToCheck;
			}
		}
		int checkNodeIndex = 0;
		T* key = findNode->peekKey(0);
		for (int i = 0; i < nodeToCheck->getNumKeys(); i++) {
			T* keyComp = nodeToCheck->peekKey(i);
			if (*key > *keyComp) {
				checkNodeIndex = i + 1;
			}
		}
		findParent(findNode, nodeToCheck->getChild(checkNodeIndex));

	}
}


template<class T>
inline int BTree<T>::getTreeSize() {
	return treeSize;
}

template<class T>
inline int BTree<T>::getTreeHeight()
{
	Node<T>* node = rootNode;
	int level = 1;
	if ((node == nullptr)||(node->getNumKeys()==0)) {
		return 0;
	}
	while (!node->isLeaf()) {
		node = node->getChild(0);
		level++;
	}
	return level;
}

template<class T>
inline void BTree<T>::PrintTree(Node<T>* parent, Node<T>* nodeToPrint) {
	// Print node type
	cout << "***Node***" << endl;
	cout << "Node Type: ";
	if (parent == nullptr) {
		cout << "Root";
		// Node to print is root
		if (nodeToPrint->isLeaf()) {
			cout << ", Leaf";
		}
		cout << endl;
	}
	else {
		if (nodeToPrint->isLeaf()) {
			cout << "Leaf" << endl;
		}
		else {
			cout << "Intermediate" << endl;
		}
		
	}
	
	cout << "Node's keys: ";
	// Print current node's keys
	for (int i = 0; i < nodeToPrint->getNumKeys(); i++) {
		cout << *nodeToPrint->peekKey(i)<<" ";
	}

	// Print parent's keys
	if (parent != nullptr) {
		cout << "Parent's keys: ";
		for (int i = 0; i < parent->getNumKeys(); i++) {
			cout << *parent->peekKey(i) << " ";
		}
	}
	cout << endl;
	int numchild = nodeToPrint->getNumChildren();
	for (int i = 0; i < numchild; i++) {
		PrintTree(nodeToPrint, nodeToPrint->getChild(i));
	}
}

template<class T>
inline void BTree<T>::splitChild(Node<T>* nodeToSplit, int childIndex, Node<T>* child) {
	// Node<T>*nodeToSplit;
	
	// Normal split
	/*if (child != nullptr) {
		Node<T>* newNode = new Node<T>(order);
		int t = ceil(order / 2);
		for (int i = 0; i < t - 1; i++) {
			newNode->addKey(child->peekKey(i));
		}
		if (!child->isLeaf()) {
			for (int i = 0; i < t; i++) {
				newNode->addChild(child->getChild(i));
			}
		}
		// nodeToSplit->addKey(child->removeKey(t));
		nodeToSplit->addChild(newNode); // adjust index by making it 
	}*/
	// else {
	if (nodeToSplit == rootNode) {
		// The root node must have at least 2 children
		Node<T>* newNode1 = new Node<T>(order);
		Node<T>* newNode2 = new Node<T>(order);
		int t = ceil((float)order / 2);
		for (int i = 0; i < t-1; i++) {
			newNode1->addKey(nodeToSplit->removeKey(nodeToSplit->peekKey(0)));
		}
		for (int i = t; i < order; i++) {
			newNode2->addKey(nodeToSplit->removeKey(nodeToSplit->peekKey(nodeToSplit->getNumKeys()-1)));
		}
		if ((!nodeToSplit->isLeaf()) && (nodeToSplit->getNumChildren() == order + 1)) {
			// A parent node which is full must have order + 1 children
			// Divides children of parent node among the 2 new nodes
			for (int i = 0; i < t; i++) {
				newNode1->addChild(nodeToSplit->removeChild(nodeToSplit->getChild(0)));
			}
			for (int i = t; i < order + 1; i++) {
				newNode2->addChild(nodeToSplit->removeChild(nodeToSplit->getChild(0)));
			}
		}
		nodeToSplit->addChild(newNode1);
		nodeToSplit->addChild(newNode2);
	}
	else {
		Node<T>* parent = findParent(nodeToSplit, rootNode);
		// parents should not have order+1 children anyway, but this has just been put in as a check
		if (parent->getNumChildren() <= order) {
			// Creates new node, adds keys to the left of the middle term in the node to split, adds the middle term to the parent, and adds the new node as a child to the parent 
			Node<T>* newNode = new Node<T>(order);
			int t = ceil((float)order / 2);
			int middleTerm = t - 1;
			for (int i = 0; i < middleTerm; i++) {
				newNode->addKey(nodeToSplit->removeKey(nodeToSplit->peekKey(i)));
			}
			// If the parent has another child that is not a leaf, I'm assuming it has just split one of those children and that split child has extra children
			// This portion of the code is to move those children to the new node
			if (!parent->isLeaf()) {
				if (!(parent->getChild(0)->isLeaf())) {
					Node<T>* nodeWithExtraChildren;
					// Find child with extra children
					for (int i = 0; i < parent->getNumChildren(); i++) {
						if ((parent->getChild(i)->getNumChildren()) == (order + 1)) {
							nodeWithExtraChildren = parent->getChild(i);
						}
					}
					// Find nodes to move from nodeWithExtraChildren to newNode
					if (*newNode < *nodeWithExtraChildren) {
						// Add children before midpoint to newNode
						for (int i = 0; i < t ; i++) {
							newNode->addChild(nodeWithExtraChildren->removeChild(nodeWithExtraChildren->getChild(0)));
						}
					}
					else {
						// Add children after midpoint to newNode
						for (int i = 0; i < t ; i++) {
							newNode->addChild(nodeWithExtraChildren->removeChild(nodeWithExtraChildren->getChild(nodeWithExtraChildren->getNumChildren()-1)));
						}
					}
				}
			}
			// Adds middle key to the parent
			parent->addKey(nodeToSplit->removeKey(nodeToSplit->peekKey(0))); // since all terms to the left have been added to the new node, the middleterm is now the first term
			// Adds new node to the parent
			parent->addChild(newNode);
			// If the parent has more than the permitted number of children (meaning that the parent is also full), the parent is split
			if (parent->getNumChildren() == order+1) {
				splitChild(parent, 0, nullptr);
			}
		}
		//TODO: Add else for if parent has max number of children, maybe
	}
}

/*template<class T>
inline void BTree<T>::splitChild(Node<T>* nodeToSplit, int childIndex, Node<T>* child) {
	Node<T>*nodeToSplit;
	// int i1;
	// Node<T>*y;
	Node<T>* newNode = new Node<T>(order);
	int t = ceil(order / 2);
	// newNode is a leaf if whatever y is is a leaf
	for (int i = 0; i < t - 1; i++) {
		newNode->addKey(child->peekKey(i));
	}
	if (!child->isLeaf()) {
		for (int i = 0; i < t; i++) {
			newNode->addChild(child->getChild(i));
		}
	}
	// nodeToSplit->addKey(child->removeKey(t));
	nodeToSplit->addChild(newNode); // adjust index by making it 
}*/