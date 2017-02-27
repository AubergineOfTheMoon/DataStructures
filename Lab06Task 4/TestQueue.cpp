#include<iostream>
#include"Queue.h"

int main() {
	Queue<int> trialQueue = Queue<int>();
	cout << "isEmpty(): " << trialQueue.isEmpty() << endl;
	for (int i = 0; i < 10; i++) {
		trialQueue.enqueue(i);
		cout << "Peek: " << trialQueue.peek() << endl;
	}
	cout << "isEmpty(): " << trialQueue.isEmpty() << endl;
	cout << "Length: " << trialQueue.length() << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Dequeue: " << trialQueue.dequeue() << endl;
	}
	trialQueue.makeEmpty();
	cout << "isEmpty(): " << trialQueue.isEmpty() << endl;

	return 0;
}