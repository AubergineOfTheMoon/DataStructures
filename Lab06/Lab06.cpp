#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main() {
	Stack<string> ptrStack = Stack<string>(4);// This is currently overriden 
	string a = "20", b = "big", c = "blue", d = "30, 000";
	cout << "Push: " << a << endl;
	ptrStack.push(&a);
	cout << "Top: " << *ptrStack.top() << endl;
	cout << "Pop: " << ptrStack.pop() << endl;
	ptrStack.push(&a);
	ptrStack.push(&b);
	ptrStack.push(&c);
	ptrStack.push(&d);
	try {
		ptrStack.push(&d);
		ptrStack.push(&d);
		ptrStack.push(&d);
	}
	catch (Stack<string>::StackOverflow e) {
		cout << "ERROR: Cannot have " << e.getValue() << " items in the stack" << endl;
	}
	cout << ptrStack.returnStackString() << endl;
	cout << "Length: " << ptrStack.length() << endl;
	ptrStack.empty();
	cout << ptrStack.length() << endl;

	cout << endl;

	Stack<int> ptrStackint = Stack<int>(4);// This is currently overriden 
	int a1 = 20, b1 = 0, c1 = 4001, d1 = 1234321;
	cout << "Push: " << endl;
	ptrStackint.push(&a1);
	cout << "Top: \n" << *ptrStackint.top() << endl;
	cout << "Pop: \n" << ptrStackint.pop() << endl;
	ptrStackint.push(&a1);
	ptrStackint.push(&b1);
	ptrStackint.push(&c1);
	ptrStackint.push(&d1);
	cout << ptrStackint.returnStackString() << endl;
	cout << "Length: " << ptrStackint.length() << endl;
	ptrStackint.empty();
	cout << ptrStackint.length() << endl;
	try {
		ptrStackint.pop();
	}
	catch (Stack<int>::StackUnderflow){
		cout << "ERROR: StackUnderflow, stack is empty" << endl;
	}
}