#pragma once
#ifndef BST_H
#define BST_H
#include<string>
using namespace std;
/*******************************************************
Node Class
********************************************************/

class Node {
private:
	string word;
	int frequency;
public:
	Node(string , int);
	Node* left;
	Node* right;
	string getWord();
	int getFrequency();
	bool operator<(Node);
	bool operator>(Node);
	bool operator==(Node);
};

Node::Node(string w, int f) {
	word = w;
	frequency = f;
	left = nullptr;;
	right = nullptr;
}

string Node::getWord()
{
	return word;
}

int Node::getFrequency()
{
	return frequency;
}

bool Node::operator<(Node n) {
	if (word.compare(n.getWord()) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Node::operator>(Node n) {
	if (word.compare(n.getWord()) > 0) {
		return true;
	}
	else {
		return false;
	}
}
bool Node::operator==(Node n) {
	if (word.compare(n.getWord()) == 0) {
		return true;
	}
	else {
		return false;
	}
}

/*******************************************************
BinarySearchTree Class
********************************************************/

template<class T> class BinarySearchTree {
private:
	int treeSize;
	bool isUnbalanced();
	void rotateRight();
	void rotateLeft();
	int nodeHeight();
	T* findParent(T*, T*);
	T* findLargest(T*);
public:
	T* root;
	BinarySearchTree();
	void insert(T* in, T* subtree=root);
	T* find(T*, T* subtree = root);
	void size();
	int getAllAscending();
	int getAllDescending();
	void emptyTree();
	T* remove(T*);
	int getTreeSize();
	class ItemAlreadyInTree {
		ItemAlreadyInTree() {}
	};
	class ItemNotFound {
		ItemNotFound() {}
	};
};

#endif

template<class T>
inline BinarySearchTree<T>::BinarySearchTree() {
	treeSize = 0;
	root = in;
}

template<class T>
inline void BinarySearchTree<T>::insert(T* in, T* subtree = root){

	if (subtree == nullptr) {
		root = in;
	}
	else if ((subtree->left != nullptr) && (*in < *subtree)) {
		insert(in, subtree->left);
	}
	else if ((subtree->right != nullptr) && (*in > *subtree)) {
		insert(in, subtree->right);
	}
	else if (*in < *subtree) {
		subtree->left = in;
	}
	else if (*in > *subtree) {
		subtree->right = in;
	}
	else {
		// Handle error.
		throw ItemAlreadyInTree();
	}
	treeSize++;
	if (isUnbalanced()) {
		// Rotate right or rotate left as needed.
	}
}


template<class T>
inline T* BinarySearchTree<T>::remove(T* nodeToRemove){
	T* parent = findParent(nodeToRemove); //pass in parameters
	bool onLeft = nodeToRemove->left != nullptr;
	bool onRight = nodeToRemove->right != nullptr;
	if ((nodeToRemove->left == nullptr) && (nodeToRemove->right == nullptr)) {
		if (onLeft) {
			parent->left = nullptr;
		}
		else {
			parent->right = nullptr;
		}
	}
	else if ((nodeToRemove->left == nullptr) || (nodeToRemove->right == nullptr)) {
		if (onLeft) {
			parent->left = nodeToRemove->left;
		}
		else {
			parent->right = nodeToRemove->right;
		}
	}
	else {
		T* newVal = findLargest(nodeToRemove->left); //create function
		T* newNode = remove(newVal);
		newNode->left = nodeToRemove->left;
		newNode->right = nodeToRemove->right;
		if (onLeft) {
			parent_left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
	if (isUnbalanced()) {
		// Rotate right or rotate left as needed.
	}
	return nodeToRemove;
}

template<class T>
inline T* BinarySearchTree<T>::find(T* itemToFind, T* subtree = root) {
	if (*subtree == *itemToFind) {
		return subtree;
	}
	if ((*subtree < *itemToFind) && (*subtree->left != nullptr)) {
		return find(itemToFind, subtree->left);
	}
	else if ((*subtree > *itemToFind) && (*subtree->right != nullptr)) {
		return find(itemToFind, subtree->right);
	}
	else {
		return nullptr;
	}
}

template<class T>
inline T* BinarySearchTree<T>::findParent(T* itemToFind, T* subtree = root) {
	if (*subtree == *itemToFind) {
		return subtree;
	}
	if ((*subtree < *itemToFind) && (*subtree->left!=nullptr)) {
		return find(itemToFind, subtree->left);
	}
	else if ((*subtree > *itemToFind) && (*subtree->right != nullptr)) {
		return find(itemToFind, subtree->right);
	}
	else {
		return nullptr;
	}
}

template<class T>
inline T* BinarySearchTree<T>::findLargest(T*)
{
	return //
}

template<class T>
inline int BinarySearchTree<T>::getTreeSize()
{
	return treeSize;
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
