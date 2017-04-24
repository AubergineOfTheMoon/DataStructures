#include <iostream> #include <string> #include <cstdlib> #include <time.h> #include <stdio.h>
# include <stdlib.h>

using namespace std;

void printList(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
/*
class Node {
public:
int value;
int level;
Node* left;
Node* right;
Node(int, int);
};

Node::Node(int v, int l) {
value = v;
level = l;
left = nullptr;
right = nullptr;
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
nodeToAdd->right = new Node(v);
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
}
*/

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

	}

	else if (n == 2) {
		if (arr[start] > arr[end]) { // If left > right, swape them
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}// Else size is 1, and doesn't need to be sorted

}

void countingSort(int arr[], int n, int max) {
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

void radixSort(int arr[], int n, int max) {
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

void quickSort(int arr[], int n, int start = 0, int end = 0, int pivotIndex = 0) {
	if (end == 0) {
		end = n;
	}
	int pivot = arr[pivotIndex];
	//Partition
	int lastGoodIndex = pivotIndex;
	for (int i = start; i < end; i++) {

		if (arr[i] > arr[lastGoodIndex] && lastGoodIndex == -1) {
			lastGoodIndex = i;
		}
		else {
			int temp = arr[lastGoodIndex];
			arr[lastGoodIndex] = arr[i];
			arr[i] = temp;
			lastGoodIndex = i;
		}
		printList(arr, n);
	}
	int j = 0;
	while (arr[j] != pivot) {
		j++;
	}
	//Quick sort left partition


}

int main() {
	int n = 20;
	// size of list being tested

	// creates array of size n with random values
	int* test = new int[n];
	for (int i = 0; i < n; i++)
		test[i] = rand() % (n);
	for (int i = 0; i < n; i++) {
		cout << test[i] << " ";
	}

	cout << endl;
	// mergeSort(test, 20, 0, 0, 20);
	// countingSort(test, n, max);
	//countingSort(test, n, n);
	mergeSort(test, n);
	printList(test, n);
}