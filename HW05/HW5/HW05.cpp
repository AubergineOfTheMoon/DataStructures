#include <iostream> #include <string> #include <cstdlib> #include <time.h> #include <stdio.h>
# include <stdlib.h>

using namespace std;

void printList(int arr[], int n) {
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
		end = n-1;
		size = n;
	}


	// Only this should be done recursively 
	if (n > 2) {
		mergeSort(arr, n / 2, start, start + n / 2 - 1, size); // Left merge sort
		int rUp = end-(start + n / 2)+1;
		mergeSort(arr, rUp, start+n/2, end, size); // Right merge sort

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

void quickSort(int arr[], int n, int start = 0, int end = 0, int pivotIndex = 0) {
	if (end == 0) {
		end = n;
	}
	int pivot = arr[pivotIndex];
	//Partition
	int lastGoodIndex=pivotIndex;
	for (int i = start; i < end; i++) {

		if (arr[i] > arr[lastGoodIndex] && lastGoodIndex == -1) {
			lastGoodIndex = i;
		}else{
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
	int* test = new int[20];
	for (int i = 0; i < 20; i++)
		test[i] = rand()%(20);
	for (int i = 0; i < 20; i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	quickSort(test, 20);
	for (int i = 0; i < 20; i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	cout << "done " << endl;
}