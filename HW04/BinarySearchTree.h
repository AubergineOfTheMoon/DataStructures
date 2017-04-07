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
	int frequency; // Number of times this word has appeared in the text
	string word; // The word
public:
	Node(string); // constructor
	bool operator<(Node); // Operator overloads
	bool operator>(Node);
	bool operator==(Node);
	int getFrequency(); // Get number of unique words (number of not nullptr nodes)
	Node* left; // Left child node
	Node* right; // Right child node
	string getWord(); // Get the word of this node
	void incrementFrequency(); // Increase size counter
};

Node::Node(string w) {
	word = w;
	frequency = 1;
	left = nullptr;;
	right = nullptr;
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

int Node::getFrequency()
{
	return frequency;
}

string Node::getWord()
{
	return word;
}

void Node::incrementFrequency(){
	frequency++;
}


/*******************************************************
BinarySearchTree Class
********************************************************/

template<class T> class BinarySearchTree {
private:
	int getBalance(Node *); // Gets the height differnce, if it is greater than 1, it is unbalanced
	int nodeHeight(T*);
	int printPos = 0; // Variable counter for creating sorted array	
	int treeSize;
	T* findLargest(T*);
	T* findParent(T*, T*);
	T* findUnBalNode(T *); // Finds the root of the subtree which needs to be rebalanced
	void balanceTree(); // self explanitory
	void getAscending(T*); // Private helper function for getAllAscending()
	void getDescending(T*); // Private helper function for getAllDescending()
	void rotateLeft(T*, T*); // Rotates a subtree with given pivot and parent
	void rotateRight(T*, T*);	
	void subInsert(T* in, T*); // "Nested" function inside of insert
	vector<T*> sortedVA; // Holds the sorted values
	vector<T*> sortedVD; // Holds the sorted values
public:
	BinarySearchTree(T* in = nullptr); // Constructor
	int getTreeSize(); // Returns number of nodes
	T* find(T* in, T*); // Returns the node if it finds it in the tree
	T* remove(T*); // Returns and removes a node
	T* root; // The top level node
	vector<T*> getAllAscending(); // Returns a vector with the elements sorted in ascending order
	vector<T*> getAllDescending(); // Returns a vector with the elements sorted in descending order
	void emptyTree(); 
	void insert(T* in, T*);
	class ItemAlreadyInTree {
	public: ItemAlreadyInTree() {}
	};
	class ItemNotFound {
	public: ItemNotFound() {}
	};
};

#endif

template<class T>
inline BinarySearchTree<T>::BinarySearchTree(T* in = nullptr) {
	treeSize = 0;
	root = in;
}

template<class T>
inline int BinarySearchTree<T>::getBalance(Node * n)
{
	// Gets the difference in heights to check balance recursively
	int right = nodeHeight(n->right);
	int left = nodeHeight(n->left);
	return right - left;
}

template<class T>
inline int BinarySearchTree<T>::nodeHeight(T* temp)
{
	// Gets the max of each node height and returns it
	if (temp == nullptr) {
		return 0;
	}
	if ((temp->left == nullptr) && (temp->right == nullptr)) {
		return 1;
	}
	int left = nodeHeight(temp->left);
	int right = nodeHeight(temp->right);
	return 1 + max(left, right);
}

// Returns the number of elements in the tree
template<class T>
inline int BinarySearchTree<T>::getTreeSize()
{
	return treeSize;
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

// Finds the largest node in the section of the binary tree passed in
template<class T>
inline T* BinarySearchTree<T>::findLargest(T* subTree = root)
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

// Finds the parent of the entered node
template<class T>
inline T* BinarySearchTree<T>::findParent(T* itemToFind, T* subtree) {
	T * parent = subtree;
	if (*subtree == *itemToFind) {
		return nullptr;
	}
	else if ((subtree->right != nullptr) && (*subtree->right == *itemToFind)) {
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

template<class T>
inline T * BinarySearchTree<T>::findUnBalNode(T * n)
{
	if (getBalance(n) > 0) {
		return findUnBalNode(n->right);
	}
	else if (getBalance(n) < 0) {
		return findUnBalNode(n->left);
	}
	return n;
}

// Removes a certain item from the tree
template<class T>
inline T* BinarySearchTree<T>::remove(T* nodeToRemove) {
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

	// Check to rebalance
	if (abs(getBalance(root)) > 1) {
		balanceTree();
	}

	return nodeToRemove;
}

// Returns an array of nodes - smallest to largest - based on sorting value
template<class T>
inline vector<T*> BinarySearchTree<T>::getAllAscending() {
	getAscending(root);
	return sortedVA;
}

// Returns an array of nodes - largest to smallest - based on sorting value
template<class T>
inline vector<T*> BinarySearchTree<T>::getAllDescending() {
	getDescending(root);
	return sortedVD;
}

template<class T>
inline void BinarySearchTree<T>::balanceTree()
{
	T* unBal; // = findUnBalNode(root);
	T* p; // = findParent(unBal, root);
	T* gp;
	T* temp;
	unBal = root;  //findUnBalNode(root);
	p = nullptr;// findParent(unBal, root);

	

	while (abs(getBalance(root)) > 1) {

		int right = nodeHeight(unBal->right);
		int left = nodeHeight(unBal->left);

		while (abs(right - left) > 1) {
			if (getBalance(unBal) > 0) {
				temp = unBal;
				unBal = unBal->right;
				p = unBal;
			}
			else {
				temp = unBal;
				unBal = unBal->left;
				p = unBal;
			}
			right = nodeHeight(unBal->right);
			left = nodeHeight(unBal->left);
		}
		p = unBal;
		if (getBalance(p) > 0) {
			unBal = p->right;
		}
		else {
			unBal = p->left;
		}
		gp = findParent(p, root);

		if (getBalance(gp) > 0 && p->left == unBal) {
			rotateRight(unBal, p);
			rotateLeft(unBal, findParent(unBal, root));
		}
		else if (getBalance(gp) < 0 && p->right == unBal) {
			rotateLeft(unBal, p);
			rotateRight(unBal, findParent(unBal,root));
		}
		else if (getBalance(p) > 0) {
			rotateLeft(unBal, p);
		}
		else if(getBalance(p) < 0) {
			rotateRight(unBal, p);
		}
		else {
			// Error, this should never happen
		}
	}
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
	
	// Rebalance if needed
	if (abs(getBalance(root)) > 1) {
		balanceTree();
	}
}

template<class T>
inline void BinarySearchTree<T>::getAscending(T* in) {
	if (in != nullptr) {
		getAscending(in->left);
		sortedVA.push_back(in);
		getAscending(in->right);
	}
}


template<class T>
inline void BinarySearchTree<T>::getDescending(T* in) {
	if (in != nullptr) {
		getDescending(in->right);
		sortedVD.push_back(in);
		getDescending(in->left);
	}
}

template<class T>
inline void BinarySearchTree<T>::rotateLeft(T* pivot, T* parent) {
	
	// There are two cases
	// The pivot is above the parent
	// The pivot is not above the parent
	T* temp = findUnBalNode(root);

	parent->right = pivot->left;
	pivot->left = parent;

	if (parent == root) {
		root = pivot;
	}
	else {
		T* gp = findParent(parent, root);
		if (gp->left == parent) {
			gp->left = pivot;
		}
		else {
			gp->right = pivot;
		}
			
	}

}


template<class T>
inline void BinarySearchTree<T>::rotateRight(T* pivot, T* parent) {

		parent->left = pivot->right;
		pivot->right = parent;

		if (parent == root) {
			root = pivot;
		}
		else {
			T* gp = findParent(parent, root);
			if (gp->right == parent) {
				gp->right = pivot;
			}
			else {
				gp->left = pivot;
			}
			//gp->left = pivot;
		}
}


