#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

void displayTowers(Stack<int> &l, Stack<int> &m, Stack<int> &r, int size) { //size is numDisks

	// adds first line
	string t = "\t|\t|\t|";
	string ls, ms, rs;

	// gets the appropriate values from the stack
	// if it is a nullptr make it a | 
	for (int i = size-1; i >= 0; i--) {
		if (getItem(l, i) == nullptr) { // || getItem(l, i) == 0
			ls = "|";
		}
		else {
			ls = to_string(*getItem(l, i));
		}
		if (getItem(m, i) == nullptr) {
			ms = "|";
		}
		else {
			ms = to_string(*getItem(m, i));
		}
		if (getItem(r, i) == nullptr) {
			rs = "|";
		}
		else {
			rs = to_string(*getItem(r, i));
		}
		t += "\n\t" + ls +"\t" + ms + "\t" + rs;
	}
	// adds base plus options
	t += "\n    -------------------------";
	t += "\n    |  (1)     (2)     (3)  |";
	t += "\n    -------------------------\n";

	// print the board
	cout << t;
}

int main() {
	cout << "Welcome to Towers of Hanoi!" << endl << endl;
	int numDisks;
	
	// get valid int
	do { 
		cout << "How many disks would you like to use?: ";
		cin >> numDisks;
		if (numDisks < 1) {
			cout << "Please choose a positive number of disks" << endl;
		}
	} while (numDisks < 1);

	// make 3 stacks, one for each tower
	Stack<int> lTower = Stack<int>(numDisks); 
	Stack<int> mTower = Stack<int>(numDisks);
	Stack<int> rTower = Stack<int>(numDisks);

	// makes a pointer array of disks, and pushes it to the left tower
	int *disks = new int[numDisks];
	for (int i = numDisks; i > 0; i--) {
		disks[i] = i; // fill the disk array
		lTower.push(&disks[i]); // push the disk to the left tower
	}

	bool stillPlaying = true;
	int tower;
	Stack<int>* fromTower; // the tower the disk comes from
	Stack<int>* toTower; // the tower the disk goes

	while (stillPlaying) {
		cout << endl;
		displayTowers(lTower, mTower, rTower, numDisks); 
		do {
			// Pick up the disk
			cout << "Choose the tower you would like to pick from: ";
			cin >> tower;
			try {
				switch (tower) {
				case 1:
					fromTower = &lTower;
					break;
				case 2:
					fromTower = &mTower;
					break;
				case 3:
					fromTower = &rTower;
					break;
				default:
					cout << "Choose a valid tower" << endl;
					continue; // restart the loop
					break;
				}
				fromTower->top();
			}
			catch (Stack<int>::StackUnderflow) { // if the tower is empty, tell the user
				cout << "This tower is empty, there are no disks to pick up" << endl;
				continue;
			}

			// Put down the disk
			cout << "Choose the tower you would like to place the disk: ";
			cin >> tower;
			switch (tower) {
			case 1:
				toTower = &lTower;
				break;
			case 2:
				toTower = &mTower;
				break;
			case 3:
				toTower = &rTower;
				break;
			default:
				cout << "Choose a valid tower" << endl;
				continue;
				break;
			}
			

			if (toTower == fromTower) { // if you put the disk on the same tower it was picked up from
				cout << "It's not really a move to pick up the disk and put it down in the same spot" << endl;
			}
			else if (toTower->isEmpty()) { // if toTower is empty, put the disk there
				toTower->push(fromTower->pop());
				// TODO Task 4: log move
			}
			else if (fromTower->top() > toTower->top()) {
				cout << "That's an illegal move" << endl;
			}else { // the last scenario is when you take a disk from a tower and put it on a non empty tower
				toTower->push(fromTower->pop());
				// TODO Task 4: log move
			}
			if (mTower.isFull() || rTower.isFull()) {
				cout << "A tower is full" << endl;
				stillPlaying = false;
			}
		} while (!(tower != 0 || tower != 2 || tower != 2) && toTower == fromTower);
	}
	cout << "Congratulations, you have won!" << endl;
	displayTowers(lTower, mTower, rTower, numDisks);
}