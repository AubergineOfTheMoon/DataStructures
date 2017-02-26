#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

struct Disk {
	int diskNum;
	string color;
};
void displayTowers(Stack<Disk> &l, Stack<Disk> &m, Stack<Disk> &r, int size) { //size is numDisks

																			   // adds first line
	string t = "\t|\t|\t|";
	string ls, ms, rs;

	// gets the appropriate values from the stack
	// if it is a nullptr make it a | 
	for (int i = size - 1; i >= 0; i--) {
		if (getItem(l, i) == nullptr) { // || getItem(l, i) == 0
			ls = "|";
		}
		else {
			ls = to_string((*getItem(l, i)).diskNum) + " " + (*getItem(l, i)).color;
		}
		if (getItem(m, i) == nullptr) {
			ms = "|";
		}
		else {
			ms = to_string((*getItem(m, i)).diskNum) + " " + (*getItem(m, i)).color;
		}
		if (getItem(r, i) == nullptr) {
			rs = "|";
		}
		else {
			rs = to_string((*getItem(r, i)).diskNum) + " " + (*getItem(r, i)).color;
		}
		t += "\n\t" + ls + "\t" + ms + "\t" + rs;
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
	int twoPlayer = 1;
	// Two Player Mode
	do {
		cout << "Would you like to Play 1 player or 2 player? [1/2]" << endl;
		cin >> twoPlayer;
	} while ((twoPlayer != 1) && (twoPlayer != 2));
	// get valid int
	do {
		cout << "How many disks would you like to use?: ";
		cin >> numDisks;
		if (numDisks < 1) {
			cout << "Please choose a positive number of disks" << endl;
		}
	} while (numDisks < 1);
	cout << "Hi" << endl;
	// make 3 stacks, one for each tower
	Stack<Disk> lTower = Stack<Disk>(numDisks);
	Stack<Disk> mTower = Stack<Disk>(numDisks);
	Stack<Disk> rTower = Stack<Disk>(numDisks);

	// makes a pointer array of disks, and pushes it to the left tower
	Disk *disks = new Disk[numDisks];
	Disk *disks2 = new Disk[numDisks];
	for (int i = numDisks; i > 0; i--) {
		disks[i - 1].diskNum = i; // fill the disk array
		disks[i - 1].color = "Blue";
		lTower.push(&disks[i - 1]); // push the disk to the left tower
	}
	if (twoPlayer == 2) {
		for (int i = numDisks; i > 0; i--) {
			disks2[i - 1].diskNum = i;
			disks2[i - 1].color = "Red ";
			rTower.push(&disks2[i - 1]);
		}
	}

	bool stillPlaying = true;
	int tower;
	Stack<Disk>* fromTower; // the tower the disk comes from
	Stack<Disk>* toTower; // the tower the disk goes

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
			}
			else { // the last scenario is when you take a disk from a tower and put it on a non empty tower
				toTower->push(fromTower->pop());
				// TODO Task 4: log move
			}
			if (lTower.isFull() || rTower.isFull()) {
				if ((lTower.top()->color.length() == 3) || (rTower.top()->color.length() == 4)) {
					cout << "A tower is full" << endl;
					stillPlaying = false;
				}
			}
		} while (!(tower != 0 || tower != 2 || tower != 2) && toTower == fromTower);
	}
	string winner;
	if (lTower.isFull()) {
		winner = "Red";
	}
	else if (rTower.isFull()) {
		winner = "Blue";
	}
	cout << "Congratulations " << winner << " has won!" << endl;
	displayTowers(lTower, mTower, rTower, numDisks);
}