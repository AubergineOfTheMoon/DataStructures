#pragma once
#ifndef HEAP_H
#define HEAP_H
#include<vector>
#include<math.h>
using namespace std;

class Heap {
	// Maximum Heap
private:
	vector<int> heapArray;
	int getRightMostItemIndex(int);
	int findParentIndex(int);
	void reheapDown(int);
	void reheapUp(int);
public:
	Heap(int);
	void addItem(int);
	int removeMinItem();
	int getNodeHeight(int);
	int getTreeHeight();
	int getTreeSize();
};

Heap::Heap(int rootVal) {
	heapArray.push_back(rootVal);
}

void Heap::addItem(int val) {
	heapArray.push_back(val);
	reheapUp(getTreeSize() - 1);
}

int Heap::getRightMostItemIndex(int index) {
	// Last Item is should be used in first call
	double logVal = log(index + 2) / log(2);
	if (floor(logVal) == ceil(logVal)) {
		return index;
	}
	else {
		getRightMostItemIndex(--index);
	}
}

int Heap::removeMinItem() {
	if (getTreeSize() == 0) {
		return -1;
		//TODO: Throw error???
	}
	int rightmostItemIndex = getRightMostItemIndex(getTreeSize() - 1);
	int removedVal = heapArray[0];
	heapArray[0] = heapArray[rightmostItemIndex];
	heapArray.erase(heapArray.begin() + rightmostItemIndex);
	reheapDown(0);
	return removedVal;
}

int Heap::getTreeSize() {
	return heapArray.size();
}

int Heap::getNodeHeight(int index) {
	return ceil(log(index + 2) / log(2));
}

int Heap::getTreeHeight() {
	return log(getTreeSize() + 1) / log(2);
}

int Heap::findParentIndex(int valIndex) {
	return int(valIndex / 2) - 1;
}

void Heap::reheapUp(int index) {
	// Value passed in first time should be, newly added node
	int temp;
	int parentIndex = findParentIndex(index);

	// If there is no parent, stop reheap
	if (parentIndex < 0) {
		return;
	}
	// Minimum tree- smallest item is root
	// If child has smaller value than parent, interchange values
	if (heapArray[index] < heapArray[parentIndex]) {
		temp = heapArray[index];
		heapArray[index] = heapArray[parentIndex];
		heapArray[parentIndex] = temp;
	}
	// If child has greater value than parent, heap is in order, so stop reheap
	else {
		return;
	}
	// Reheap up again
	reheapUp(parentIndex);
}

void Heap::reheapDown(int index) {
	// Value passed in first time should be root index, 0
	int indexChild1 = 2 * (index + 1) - 1;
	int indexChild2 = 2 * (index + 1);
	int replaceIndex;
	// If child has no children, stop reheap
	if (indexChild1 > (getTreeSize() - 1)) {
		return;
	}
	else {
		replaceIndex = indexChild1;
	}
	// If there is a second child, and if the value at child 2 is less than the value at child 1, child2 is the new replace index 
	if ((indexChild2 < (getTreeSize() - 1)) && (heapArray[replaceIndex] > heapArray[indexChild2])) {
		replaceIndex = indexChild2;
	}
	// If the parent has a value less than a child, stop reheap
	if (heapArray[index] < heapArray[replaceIndex]) {
		return;
	}
	// If parent has a value more than the child, interchange
	int temp;
	temp = heapArray[index];
	heapArray[index] = heapArray[replaceIndex];
	heapArray[replaceIndex] = temp;
	// Reheap down again
	reheapDown(replaceIndex);
}
#endif