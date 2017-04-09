#include<iostream>
#include"BTree.h"
using namespace std;

int main() {

	int order;
	do {
		cout << "What would you like the order of your BTree to be?(Enter a number from 3-5): ";
		cin >> order;
	} while ((order > 5) || (order < 3));

	BTree<int> myTree(order);
	int choice = 0;
	int numToAdd, numToFind;
	int* tempNum;
	int* removedNum;
	// bool flag;
	do {
		cout << "***************************************" << endl;
		cout << "Please select the the action you would like to complete" << endl;
		cout << "1. Add an item to the tree" << endl;
		cout << "2. Remove an item from the tree" << endl;
		cout << "3. Find an item in the tree" << endl;
		cout << "4. Get the size of the tree" << endl;
		cout << "5. Get the height of the tree." << endl;
		cout << "6. Print the current tree" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter the number of the choice you wish to select: ";
		cin >> choice;
		if (cin.fail()) {
			choice = 10;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (choice) {
		case 1: cout << "You have chosen to add a item to the tree. " << endl;
			cout << "Enter the number you would like to add ";
			cin >> numToAdd;
			// cout << endl;
			tempNum = new int();
			*tempNum = numToAdd;
			myTree.insertItem(tempNum, myTree.rootNode);
			break;
		case 2: cout << "Cannot remove " << endl;
			break;
		case 3: cout << "Enter the number you would like to find: ";
			cin >> numToFind;
			tempNum = new int();
			*tempNum = numToFind;
			removedNum = myTree.findItem(tempNum, myTree.rootNode);
			if (removedNum == nullptr) {
				cout << "Number is not in the tree" << endl;
			}
			else {
				cout << "Found number: " << *removedNum << endl;
			}
			break;
		case 4: cout << "Tree size: " << myTree.getTreeSize() << endl;			
			break;
		case 5: cout << "The height of the tree is: " << myTree.getTreeHeight() << endl;
			break;
		case 6: myTree.PrintTree(nullptr, myTree.rootNode);
			cout << endl;
			break;
		case 0: cout << "You have chosen to exit." << endl;
			break;
		default: cout << "You have entered an invalid choice." << endl;
			break;
		}
	} while (choice != 0);
	return 0;
}