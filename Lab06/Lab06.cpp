#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

void displayTowers(Stack<int> l, Stack<int> m, Stack<int> r, int size) { //size is numDisks

	// adds first line
	string t = "\t|\t|\t|";
	string ls, ms, rs;

	// gets the appropriate values from the stack
	// if it is a nullptr or a 0 make it a | 
	for (int i = size-1; i >= 0; i--) {
		if (l.returnStackListItem(i) == nullptr || *l.returnStackListItem(i) == 0) {
			ls = "|";
		}
		else {
			ls = to_string(*l.returnStackListItem(i));
		}
		if (m.returnStackListItem(i) == nullptr || *m.returnStackListItem(i) == 0) {
			ms = "|";
		}
		else {
			ms = to_string(*m.returnStackListItem(i));
		}
		if (r.returnStackListItem(i) == nullptr || *r.returnStackListItem(i) == 0) {
			rs = "|";
		}
		else {
			rs = to_string(*r.returnStackListItem(i));
		}
		t += "\n\t" + ls +"\t" + ms + "\t" + rs;
	}
	// adds base plus options
	t += "\n    -------------------------";
	t += "\n    |  (1)     (2)     (3)  |";
	t += "\n    -------------------------\n";

	cout << t;
}

bool canMove(int val, int tower) {
	switch (val)
	return true;
}

int main() {
	cout << "Welcome to Towers of Hanoi!" << endl << endl;
	cout << "How many disks would you like to use?: ";
	int numDisks;
	cin >> numDisks;

	Stack<int> lTower = Stack<int>(6); //Should be num disks
	Stack<int> mTower = Stack<int>(6);
	Stack<int> rTower = Stack<int>(6);

	int disks[] = { 1,2,3,4,5,6 };

	lTower.push(&disks[5]);
	lTower.push(&disks[4]);
	lTower.push(&disks[3]);
	lTower.push(&disks[2]);
	lTower.push(&disks[1]);
	lTower.push(&disks[0]);

	bool stillPlaying = true;
	int tower;
	Stack<int>* fromTower;
	Stack<int>* toTower;
	int* disk;

	while (stillPlaying) {
		cout << endl;
		displayTowers(lTower, mTower, rTower, 6);
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
					break;
				}
			}
			catch (Stack<int>::StackUnderflow) {
				cout << "This tower is empty, there are no disks to pick up" << endl;
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
				break;
			}
			
			if (toTower == fromTower) {
				cout << "I wouldn't recommend that move" << endl;
			}
			else if (toTower->isEmpty()) {
				toTower->push(fromTower->pop());
			}
			else if (fromTower->top() > toTower->top()) {
				cout << "That's an illegal move" << endl;
			}else {
				toTower->push(fromTower->pop());
			}
			if (mTower.isFull() || rTower.isFull()) {
				cout << "A tower is full" << endl;
				stillPlaying = false;
			}
		} while (!(tower != 0 || tower != 2 || tower != 2) && toTower == fromTower);
	}
	cout << "Congratulations, you have won!" << endl;
}



