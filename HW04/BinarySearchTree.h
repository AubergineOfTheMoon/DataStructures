#pragma once
#ifndef BST_H
#define BST_H
#include<string>
#include<algorithm> 
#include<cmath>
#include<vector>
using namespace std;
/*******************************************************
Node Class
********************************************************/

class Node {
private:
	string word;
	int frequency;
public:
	Node(string);
	Node* left;
	Node* right;
	string getWord();
	int getFrequency();
	void incrementFrequency();
	bool operator<(Node);
	bool operator>(Node);
	bool operator==(Node);
};

Node::Node(string w) {
	word = w;
	frequency = 1;
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

void Node::incrementFrequency(){
	frequency++;
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
	int printPos = 0; // Variable counter for creating sorted array
	T** sortedArray; // Variable for storing sorted array for get Ascending and descending
	vector<T*> sortedV;
	// bool isUnbalanced();
	// void rotateRight();
	// void rotateLeft();
	int nodeHeight(T*);
	T* findParent(T*, T*);
	T* findLargest(T*);
	void getAscending(T*); // Private helper function for getAllAscending()
	void getDescending(T*); // Private helper function for getAllDescending()

	void subInsert(T* in, T*);
	void balanceTree();
	void rotateLeft(T*, T*);
	void rotateRight(T*, T*);
	T* findUnBalNode(T *);

	int getHeight(Node);
	int getMin(Node *);
	int getMax(Node *);
	int getBalance(Node *);
	//int subMin(int);
	//int subMax(int);

	//const int heightDif = 2;

public:
	T* root;
	BinarySearchTree(T* in = nullptr);
	void insert(T* in, T*);
	T* find(T* in, T*);
	int size();
	vector<T*> getAllAscending();
	vector<T*> getAllDescending();
	void emptyTree();
	T* remove(T*);
	int getTreeSize();

	class ItemAlreadyInTree {
	public: ItemAlreadyInTree() {}
	};
	class ItemNotFound {
	public: ItemNotFound() {}
	};
};

#endif



template<class T>
inline T * BinarySearchTree<T>::findUnBalNode(T * n)
{
	if (getBalance(n) > 1) {
		return findUnBalNode(n->right);
	}
	else if (getBalance(n) < -1) {
		return findUnBalNode(n->left);
	}
	// This should be the node that is unbalanced
	return n; // findParent(n, root);
}

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(T* in = nullptr) {
	treeSize = 0;
	root = in;
}


// Insterts an item into the tree where it should be ( ordered)
template<class T>
inline void BinarySearchTree<T>::insert(T* in, T* subtree) {
	//cout << in->getWord() << endl;
	subInsert(in, subtree);
	treeSize++;
}

template<class T>
inline void BinarySearchTree<T>::subInsert(T* in, T* subtree) {
	if (subtree == nullptr) {
		root = in;
	}
	else if ((subtree->left != nullptr) && (*in < *subtree)) {
		subInsert(in, subtree->left);
	}
	else if ((subtree->right != nullptr) && (*in > *subtree)) {
		subInsert(in, subtree->right);
	}
	else if (*in < *subtree) {
		subtree->left = in;
	}
	else if (*in > *subtree) {
		subtree->right = in;
	}
	else {
		throw ItemAlreadyInTree();
	}
	
	if (abs(getBalance(root)) > 1) {
		balanceTree();
	}
}

template<class T>
inline void BinarySearchTree<T>::balanceTree()
{
	T* unBal = findUnBalNode(root);
	T* p = findParent(unBal, root);
	if (root == p) {
		if (getBalance(root) > 0) {
			rotateLeft(unBal, p);
		}
		else {
			rotateRight(unBal, p);
		}
	}
	else {
		T* gp = findParent(p, root);
		if (unBal->left == nullptr && p->left == unBal) {
			rotateLeft(unBal, unBal->right);
			rotateRight(p->left, p);
		}
		if (unBal->right == nullptr && p->right == unBal) {
			rotateRight(unBal, unBal->left);
			rotateLeft(p->right, p);
		}
	}
}

template<class T>
inline void BinarySearchTree<T>::rotateLeft(T* pivot, T* parent) {
	
	if (parent->right == pivot) {
		T* t = pivot->left;
		pivot->left = parent;
		parent->right = t;

		if (parent == root) {
			root = pivot;
		}
		else {
			T* gp = findParent(parent, root);
			gp->right = pivot;
		}
	}
	else {
		if (pivot->right == parent) {
			parent->left = pivot;
			pivot->right = nullptr;
		}
		else {
			parent->right = pivot;
			pivot->left = nullptr;
		}
		findParent(pivot, root)->left = parent;

	}



}


template<class T>
inline void BinarySearchTree<T>::rotateRight(T* pivot, T* parent) {

	if (parent->left == pivot) {
		T* t = pivot->right;
		pivot->right = parent;
		parent->left = t;

		if (parent == root) {
			root = pivot;
		}
		else {
			T* gp = findParent(parent, root);
			gp->left = pivot;
		}
	}
	else {
		if (pivot->left == parent) {
			parent->right = pivot;
			pivot->left = nullptr;
		}
		else {
			parent->left = pivot;
			pivot->right = nullptr;
		}
		findParent(pivot, root)->right = parent;
	}

}



// Returns the number of elements in the tree
template<class T>
inline int BinarySearchTree<T>::size() {
	return treeSize;
}

// Removes a certain item from the tree
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
	
	if (abs(getBalance(root)) > 1) {
		balanceTree();
	}

	return nodeToRemove;
}


// Finds the node and returns a pointer to that node
template<class T>
inline T* BinarySearchTree<T>::find(T* itemToFind, T* subtree) {
	if (root == nullptr) {
		return nullptr;
	}
	if (*subtree == *itemToFind) {
		return subtree;
	}
	if ((*subtree > *itemToFind) && (subtree->left != nullptr)) {
		return find(itemToFind, subtree->left);
	}
	else if ((*subtree < *itemToFind) && (subtree->right != nullptr)) {
		return find(itemToFind, subtree->right);
	}
	else {
		return nullptr;
	}
}

template<class T>
inline int BinarySearchTree<T>::nodeHeight(T* temp)
{
	if (temp == nullptr) {
		return 0;
	}
	return 1 + max(nodeHeight(temp->left), nodeHeight(temp->right));
}

template<class T>
inline T* BinarySearchTree<T>::findParent(T* itemToFind, T* subtree) {
	T * parent = subtree;
	if (*subtree == *itemToFind) {
		return nullptr;
	}
	else if ((subtree->right!=nullptr)&&(*subtree->right == *itemToFind)) {
		return parent;
	}
	else if ((subtree->left != nullptr) && (*subtree->left == *itemToFind)) {
		return parent;
	}
	else if ((subtree->right == nullptr) && (subtree->left == nullptr)) {
		throw ItemNotFound();
	}
	else {
		if (*itemToFind < *subtree) {
			return findParent(itemToFind, subtree->left);
		}
		else {
			return findParent(itemToFind, subtree->right);
		}
	}
}

// Finds the largest node in the section of the binary tree passed in
template<class T>
inline T* BinarySearchTree<T>::findLargest(T* subTree=root)
{
	if (subTree == nullptr) {
		return nullptr; 
	}
	// Change to return ["" , 0 ]
	T* maxNode = subTree;
	while (maxNode->right != nullptr) {
		maxNode = maxNode->right;
	}
	return maxNode;
}

// Returns an array of nodes - smallest to largest - based on sorting value
template<class T>
inline vector<T*> BinarySearchTree<T>::getAllAscending() {
	//sortedArray = new T*[treeSize];
	//printPos = 0;
	//vector<T*> sortedV(treeSize, nullptr);
	getAscending(root);
	return sortedV;
}

template<class T>
inline void BinarySearchTree<T>::getAscending(T* in) {
	if (in != nullptr) {
		getAscending(in->left);
		//sortedArray[printPos]= in;
		//printPos++;
		sortedV.push_back(in);
		getAscending(in->right);
	}
}

// Returns an array of nodes - largest to smallest - based on sorting value
template<class T>
inline vector<T*> BinarySearchTree<T>::getAllDescending() {
	//sortedArray = new T*[treeSize];
	//printPos = 0;
	//vector<T*> sortedV (treeSize, nullptr);
	getDescending(root);
	return sortedV;
}

template<class T>
inline void BinarySearchTree<T>::getDescending(T* in) {
	if (in != nullptr) {
		getDescending(in->right);
		//sortedArray[printPos] = in;
		//printPos++;
		sortedV.push_back(in);
		getDescending(in->left);
	}
}

template<class T>
inline int BinarySearchTree<T>::getTreeSize()
{
	return treeSize;
}

template<class T>
inline void BinarySearchTree<T>::emptyTree()
{
	if (root != nullptr)
	{
		delete_tree(root->left);
		delete_tree(root->right);
		delete(root);
		if (root->left != nullptr)
			root->left = nullptr;
		if (root->right != nullptr)
			root->right = nullptr;
		root = nullptr;
		}
}

// Balancin code 
template<class T>
inline int BinarySearchTree<T>::getHeight(Node)
{
	return 0;
}

template<class T>
inline int BinarySearchTree<T>::getMin(Node * n)
{
	if (n->left == nullptr && n->right == nullptr) {
		return 0;
	}
	if (n->left == nullptr) {
		return 1 + getMin(n->right);
	}
	if (n->right == nullptr) {
		return 1 + getMin(n->left);
	}
	return 1 + min(getMin(n->right), getMin(n->left));
}

template<class T>
inline int BinarySearchTree<T>::getMax(Node * n)
{
	if (n->left == nullptr && n->right == nullptr) {
		return 0;
	}
	if (n->left == nullptr) {
		return 1 + getMax(n->right);
	}
	if (n->right == nullptr) {
		return 1 + getMax(n->left);
	}
	return 1 + max(getMax(n->right), getMax(n->left));
}

template<class T>
inline int BinarySearchTree<T>::getBalance(Node * n)
{
	return nodeHeight(n->right) - nodeHeight(n->left);
	/*
	if (nodeHeight(n->left) - nodeHeight(n->right) == 1) {
		// Left heavy
	}
	else (nodeHeight(n->left) - nodeHeight(n->right) == -1) {
		// Right heavy
	}else {
		// Balanced

	}
	//return getMax(n) - getMin(n);
	*/
}

