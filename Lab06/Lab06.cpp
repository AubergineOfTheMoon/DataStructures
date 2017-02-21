#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
	Stack<int> ptrStack = Stack<int>(4);
	int a = 3;
	int b = 2;
	int c = 1;
	int d = 4;
	cout << "Push: " << endl;
	ptrStack.push(&a);
	cout << "Top: \n"<< *ptrStack.top() << endl;
	cout << "Pop: \n" << ptrStack.pop() << endl;
	ptrStack.push(&a);
	ptrStack.push(&b);
	ptrStack.push(&c);
	ptrStack.push(&d);
	cout << ptrStack.returnStackString() << endl;
	cout << "Length: "<< ptrStack.length() << endl;
	ptrStack.empty();
	cout << ptrStack.length() << endl;
}