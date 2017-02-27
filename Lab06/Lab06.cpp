#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
using namespace std;

struct Move {
	int from;
	int to;
	int diskMoved;
	string description;
};

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
	Queue<Move> movesQueue = Queue<Move>();
	// makes a pointer array of disks, and pushes it to the left tower
	int *disks = new int[numDisks];
	for (int i = numDisks; i > 0; i--) {
		disks[i] = i; // fill the disk array
		lTower.push(&disks[i]); // push the disk to the left tower
	}

	bool stillPlaying = true;
	int tower;
	int toTowerNum = 0;
	int fromTowerNum = 0;
	Move movePlayed;
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
					fromTowerNum = 1;
					break;
				case 2:
					fromTower = &mTower;
					fromTowerNum = 2;
					break;
				case 3:
					fromTower = &rTower;
					fromTowerNum = 3;
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
				toTowerNum = 1;
				break;
			case 2:
				toTower = &mTower;
				toTowerNum = 2;
				break;
			case 3:
				toTower = &rTower;
				toTowerNum = 3;
				break;
			default:
				cout << "Choose a valid tower" << endl;
				continue;
				break;
			}
			

			if (toTower == fromTower) { // if you put the disk on the same tower it was picked up from
				cout << "It's not really a move to pick up the disk and put it down in the same spot" << endl;
				movePlayed = {fromTowerNum, toTowerNum, *(fromTower->top()), "Disk cannot be moved to same spot. Invalid move not allowed."};
				movesQueue.enqueue(movePlayed);
			}
			else if (toTower->isEmpty()) { // if toTower is empty, put the disk there
				toTower->push(fromTower->pop());
				movePlayed = { fromTowerNum, toTowerNum, *(toTower->top()), "" };
				movesQueue.enqueue(movePlayed);
			}
			else if (fromTower->top() > toTower->top()) {
				cout << "That's an illegal move" << endl;
				movePlayed = { fromTowerNum, toTowerNum, *(fromTower->top()), "Illegal move. Invalid move not allowed." };
				movesQueue.enqueue(movePlayed);
			}
			else { // the last scenario is when you take a disk from a tower and put it on a non empty tower
				toTower->push(fromTower->pop());
				movePlayed = { fromTowerNum, toTowerNum, *(toTower->top()), "" };
				movesQueue.enqueue(movePlayed);
			}
			if (mTower.isFull() || rTower.isFull()) {
				cout << "A tower is full" << endl;
				stillPlaying = false;
			}
		} while (!(tower != 0 || tower != 2 || tower != 2) && toTower == fromTower);
	}
	cout << "Congratulations, you have won!" << endl;
	displayTowers(lTower, mTower, rTower, numDisks);
	cout << "The moves that led to victory were: " << endl;
	int numMoves = movesQueue.length();
	for (int i = 0; i < numMoves; i++) {
		Move movePlayed = movesQueue.dequeue();
		cout << "Moved disk " << movePlayed.diskMoved << " from tower " << movePlayed.from << " to tower " << movePlayed.to << " " << movePlayed.description << endl;
	}

	return 0;
}