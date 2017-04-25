#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include "LinkedList.h"
#include"Heap.h"
using namespace std;
typedef std::chrono::high_resolution_clock Clock;
void printList(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


/*class Node {
public:
	int value;
	int level;
	Node* left;
	Node* right;
	bool isFull();
	Node(int, int);
};

Node::Node(int v, int l) {
	value = v;
	level = l;
	left = nullptr;
	right = nullptr;
}

bool Node::isFull() {
	if ((left != nullptr) && (right != nullptr)) {
		return true;
	}
	return false;
}

class Heap {
private:
	Node* root;
	Node* findNodeToAdd();
	
public:
	Heap();
	void addValue(int);
	Node* removeValue();
	void reheapDown(Node*);
};

Heap::Heap() {
	root = nullptr;
}

Node* Heap::findNodeToAdd() {
	return nullptr;
}

void Heap::addValue(int v) {
	if (root == nullptr) {
		Node* newNode = new Node(v, 0);
		root = newNode;
	}
	else {
		Node* nodeToAdd = findNodeToAdd();
		if (nodeToAdd->left == nullptr) {
			nodeToAdd->left = new Node(v, 0);
			reheapDown(root);
		}
		else {
			nodeToAdd->right = new Node(v, 0);
			reheapDown(root);
		}
	}
}

void Heap::reheapDown(Node* nodeToCheck) {
	if ((nodeToCheck->left != nullptr) && (nodeToCheck->value < nodeToCheck->left->value)) {
		int tempVal = nodeToCheck->value;
		nodeToCheck->value = nodeToCheck->left->value;
		nodeToCheck->left->value = tempVal;
	}
	else if ((nodeToCheck->right != nullptr) && (nodeToCheck->value < nodeToCheck->right->value)) {
		int tempVal = nodeToCheck->value;
		nodeToCheck->value = nodeToCheck->right->value;
		nodeToCheck->right->value = tempVal;
	}
	if (nodeToCheck->left == nullptr) {}
}*/



void heapSort(int arr[], int n) {
	if (n > 0) {
		Heap myHeap = Heap(arr[0]);
		for (int i = 1; i < n; i++) {
			myHeap.addItem(arr[i]);
		}
		// int* newSortedArray = new int[n];
		for (int j = 0; j < n; j++) {
			arr[j] = myHeap.removeMinItem();
		}
	}
	else {
		cout << "Cannot sort array with no items" << endl;
	}
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - i - 1; k++) {
			if (arr[k] > arr[k + 1]) {
				int temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
}

void insertionSort(int arr[], int n) {
	int k;
	int temp;
	for (int i = 0; i < n; i++) {
		k = i;
		while (k > 0 && arr[k] < arr[k - 1]) {
			temp = arr[k];
			arr[k] = arr[k - 1];
			arr[k - 1] = temp;
			k--;
		}
	}
}

void mergeSort(int arr[], int n, int start=0, int end=0, int size=0) {
	if (end == 0) {
		end = n - 1;
		size = n;
	}

	// Only this should be done recursively 
	if (n > 2) {
		mergeSort(arr, n / 2, start, start + n / 2 - 1, size); // Left merge sort
		int rUp = end - (start + n / 2) + 1;
		mergeSort(arr, rUp, start + n / 2, end, size); // Right merge sort

		int* tempArr = new int[size]; // Make a temp array
		copy(arr, arr + size, tempArr);

		int pos1 = start;
		int pos2 = n / 2 + start;
		int startRight = pos2;

		for (int i = start; i <= end; i++) {
			if (pos2 > end || (tempArr[pos1] < tempArr[pos2] && pos1 < startRight)) {
				arr[i] = tempArr[pos1];
				pos1++;
			}
			else {
				arr[i] = tempArr[pos2];
				pos2++;
			}
		}
		delete[size] tempArr;
	}

	else if (n == 2) {
		if (arr[start] > arr[end]) { // If left > right, swape them
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}// Else size is 1, and doesn't need to be sorted

}

void countingSort(int arr[], int n, int max = 0) {
	if (max == 0) {
		max = n;
	}
	// n is the size of the array

	// Initialize array of all possible numbers from 0 to max
	int* count = new int[max];
	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}

	// Count number of occurrences of each number
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	// Make array of occurrences cumulative
	for (int i = 1; i < max; i++) {
		count[i] += count[i - 1];
	}

	// Create new array using count to find indices
	int* outputArray = new int[n];
	for (int i = n - 1; i >= 0; i--) {
		outputArray[--count[arr[i]]] = arr[i];
	}

	// Set array equal to output array
	for (int i = 0; i <n; i++) {
		arr[i] = outputArray[i];
	}
	delete outputArray;
	delete count;
}

void radixSort(int arr[], int n, int max = 0) {
	if (max == 0) {
		// max is the maximum value in the array
		/*for (int i = 0; i < n; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}*/
	}

	// Find the maximum number of significant digits in the array
	int m = max;
	int numSigDig = 0;
	while (m != 0) {
		m = int(m / 10);
		numSigDig++;
	}

	// Initialize array of all possible digits 0-9
	int* count = new int[10];
	for (int i = 0; i < 10; i++) {
		count[i] = 0;
	}
	int sigDig; // variable to store significant digit of number
	int* outputArray = new int[n]; // output array

								   // Iterate through counting sort algorithm for every significant digit
	for (int j = 0; j < numSigDig; j++) {

		// Increment value in significant digit array for value of significant digit
		for (int i = 0; i < n; i++) {
			sigDig = (int(arr[i] / pow(10, j))) % 10;
			count[sigDig]++;
		}

		// Make significant digit array cumulative
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		// Create output array based on indices from significant digit array
		for (int i = n - 1; i >= 0; i--) {
			sigDig = (int(arr[i] / pow(10, j))) % 10;
			outputArray[--count[sigDig]] = arr[i];
		}

		// Assign values from output array to array
		for (int i = 0; i < n; i++) {
			arr[i] = outputArray[i];
		}
		// Reset Count array
		for (int i = 0; i < 10; i++) {
			count[i] = 0;
		}
		// Reset OutputArray
		for (int i = 0; i < n; i++) {
			outputArray[i] = 0;
		}
	}
	delete outputArray;
	delete count;
}

void quickSort(int arr[], int n, int start = 0, int end = 0) {
	if (end == 0) {
		end = n-1;
	}

	int pIndex = end - n / 2;
	int pivot = arr[pIndex];
	int tStart = start;
	int tEnd = end;
	//Partition
	while (tStart < tEnd) {
		if (arr[tStart] >= pivot && pivot >= arr[tEnd]) {
			// Swap them 
			int temp = arr[tStart];
			arr[tStart] = arr[tEnd];
			arr[tEnd] = temp;
			tStart++;
			tEnd--;
		}
		else {
			if (arr[tStart] <= pivot) {
				tStart++;
			}
			if (arr[tEnd] >= pivot) {
				tEnd--;
			}
		}
		// Debug
		//printList(arr, 20);
	}
	

	//Quick sort left partition
	if (n > 1) {
		quickSort(arr, n / 2, start, pIndex);
		quickSort(arr, n / 2, pIndex-1, end);
		
	}
}

// Student sorting

static const char alphanum[] =
"abcdefghijklmnopqrstuvwxyz";

char genRandom()  // Random string generator function.
{

	return alphanum[rand() % 26];
}

int main() {
	int c, n;
	cout << "How big should the array be [0:10, 1:100, 2:500, 3:5000, 4:25000]: ";
	cin >> c;

	switch (c) { // Because I like typing 1 character vs 3
	case 0:
		n = 10;
		break;
	case 1:
		n = 100;
		break;
	case 2:
		n = 500;
		break;
	case 3:
		n = 5000;
		break;
	case 4:
		n = 25000;
		break;
	default:
		n = c;
		break;
	}
	// size of list being tested
	// int aTest[10] = { 8,9,4,5,0,4,0,9,9,2 };
	// creates array of size n with random values
	int* a1 = new int[n];
	int* a2 = new int[n];
	int* a3 = new int[n];
	int* a4 = new int[n];
	int* a5 = new int[n];
	int* a6 = new int[n];
	int* a7 = new int[n];
	// int* a8 = new int[n];

	int times[] = { 0,0,0,0,0,0,0 };

	// Seed random number
	srand(time(NULL));

	// Insert random numbers
	int num;
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < n; i++) {
			num = rand() % (n);
			a1[i] = num;
			a2[i] = num;
			a3[i] = num;
			a4[i] = num;
			a5[i] = num;
			a6[i] = num;
			a7[i] = num;
			// a8[i] = num;
		}
		
		//printList(a1, n);
		//cout << "Start" << endl;

		// Sort numbers
		// Record the times

		auto t1 = Clock::now();
		bubbleSort(a1, n);
		auto t2 = Clock::now();
		//printList(a1, n);
		times[0] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		t1 = Clock::now();
		insertionSort(a2, n);
		t2 = Clock::now();
		//printList(a2, n);
		times[1] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		t1 = Clock::now();
		mergeSort(a3, n);
		t2 = Clock::now();
		//printList(a3, n);
		times[2] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		
		t1 = Clock::now();
		countingSort(a4, n);
		t2 = Clock::now();
		//printList(a4, n);
		times[3] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
		

		t1 = Clock::now();
		quickSort(a5, n);
		t2 = Clock::now();
		//printList(a5, n);
		times[4] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		t1 = Clock::now();
		radixSort(a6, n);
		t2 = Clock::now();
		//printList(a6, n);
		times[5] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

		
		t1 = Clock::now();
		heapSort(a7, n);
		t2 = Clock::now();
		//printList(a7, n);
		//printList(a1, n);
		// printList(a8, n);
		//cout << endl;
		times[6] += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
		
	}
	// Print out results
	cout << "Bubble sort \t" << times[0] / 10 << "\t nano seconds" << endl;
	cout << "Insertion sort \t" << times[1] / 10 << "\t nano seconds" << endl;
	cout << "Merge sort \t" << times[2] / 10 << "\t nano seconds" << endl;
	cout << "Counting sort \t" << times[3] / 10 << "\t nano seconds" << endl;
	cout << "Quick sort \t" << times[4] / 10 << "\t nano seconds" << endl;
	cout << "Radix sort \t" << times[5] / 10 << "\t nano seconds" << endl;
	cout << "Heap sort \t" << times[6] / 10 << "\t nano seconds" << endl;

	LinkedList<Student> s(nullptr);
	string first = "";
	string last = "";
	int numa;
	srand(time(NULL));
	for (int i = 0; i < 50; i++) {
		first = "";
		last = "";
		for (int j = 0; j < 6; j++) {
			
			first += alphanum[rand() % 26];
			last += alphanum[rand() % 26];
		}
		numa = rand() % 10000;
		//cout << first << last << num << endl;
		Student* t = new Student(first, last, numa);
		s.AddItem(t);
		
	}
	if ("yxuppk" > "zpfnoy") {
		cout << "?";
	}
	s.DisplayAll();
	s.BubbleSort(true);
	cout << endl << endl;

	s.DisplayAll();
	s.BubbleSort(false);
	cout << endl << endl;

	s.DisplayAll();
}