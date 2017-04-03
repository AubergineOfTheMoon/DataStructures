#include <iostream>
#include <fstream>
#include <string>
#include"BinarySearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree<Node> BSTWords;
	bool failedInput = false;

	string filename;
	cout << "Enter a file name to be processed: ";
	cin >> filename;

	fstream fin;
	fin.open(filename, ios::in);

	string output;
	if (fin.fail()) {
		cout << "Error with finding the file" << endl;
	}
	else {
		string word;
		Node* tempWord;
		Node* foundWord;
		// Add words from the input file to the binary search tree
		while (!fin.eof()) {
			fin >> word;
			for (int i = 0; i < word.length(); i++) {
				word[i] = tolower(word[i]);
			}
			tempWord = new Node(word);
			foundWord = BSTWords.find(tempWord, BSTWords.root);
			if (foundWord == nullptr) {
				BSTWords.insert(tempWord, BSTWords.root);
			}
			else {
				foundWord->incrementFrequency();
				delete tempWord;
			}
			tempWord = nullptr;
		}
	}
	if (!failedInput) {
		string word;
		Node* tempWord;
		Node* removedWord;
		int choice;
		int numWords = BSTWords.getTreeSize();
		Node** sortedWords = new Node*[numWords];
		do {
			cout << "***************************************" << endl;
			cout << "Please select the the action you would like to complete" << endl;
			cout << "1. Search for a word." << endl;
			cout << "2. View list of words in alphabetical order." << endl;
			cout << "3. View list of words in reverse alphabetical order." << endl;
			// cout << "4. Check if directory is empty" << endl;
			// cout << "5. Get the number of students in the directory." << endl;
			// cout << "6. See the next student in the directory" << endl;
			// cout << "7. See a student at a location in the directory" << endl;
			// cout << "8. Reset the location. " << endl;
			// cout << "9. Print ASCII art of all students. " << endl;
			cout << "0. Exit" << endl;
			cout << "Enter the number of the choice you wish to select: ";
			cin >> choice;
			if (cin.fail()) {
				choice = 10;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			switch (choice) {
			case 1: cout << "Enter the word you want to search for." << endl;
				cin >> word;
				for (int i = 0; i < word.length(); i++) {
					word[i] = tolower(word[i]);
				}
				tempWord = new Node(word);
				removedWord = BSTWords.find(tempWord, BSTWords.root);
				if (removedWord == nullptr) {
					cout << "The word is not in the tree." << endl;
				}
				else {
					cout << "The frequency of the word is " << removedWord->getFrequency() << endl;
				}
				delete tempWord;
				tempWord = nullptr;
				removedWord = nullptr;
				break;
			case 2: cout << "The sorted words are: " << endl;
				sortedWords = BSTWords.getAllAscending();
				for (int i = 0; i < numWords; i++) {
					cout << sortedWords[i]->getWord() << ": " << sortedWords[i]->getFrequency() << endl;
				}
				break;
			case 3: cout << "The sorted words are: " << endl;
				sortedWords = BSTWords.getAllDescending();
				for (int i = 0; i < numWords; i++) {
					cout << sortedWords[i]->getWord() << ": " << sortedWords[i]->getFrequency() << endl;
				}
				break;
			/*case 4: cout << "Is the directory empty?: ";
				if (StudentDirectory.IsEmpty()) {
					cout << "Yes" << endl;
				}
				else {
					cout << "No" << endl;
				}
				break;
			case 5: cout << "The number of students in the directory: " << StudentDirectory.Size() << endl;
				break;
			case 6:
				try {
					tempStudent = StudentDirectory.SeeNext();
				}
				catch (exception EmptyList) {
					cout << "You cannot see the next item in an empty list." << endl;
				}
				if (tempStudent == nullptr) {
					cout << "There is no next student. You either have an empty directory or have reached the end of the directory. Please check whether the directory is empty and/or reset the starting location. " << endl;
				}
				else {
					cout << "Here are details of the next student: " << endl;
					cout << "Student Name: " << tempStudent->getName() << endl;
					cout << "Student M Number: " << tempStudent->getMNumber() << endl;
					cout << "Student Birthday: " << tempStudent->getBirthday() << endl;
					cout << "Student Age: " << tempStudent->getAge() << endl;
				}
				// delete tempStudent;
				break;
			case 7: int index;
				cout << "Enter the index of the student you would like to view (a number between 0 and " << StudentDirectory.Size() - 1 << "): ";
				cin >> index;
				try {
					tempStudent = StudentDirectory.SeeAt(index);
					if (tempStudent != nullptr) {
						cout << "Here are details of the student at that location: " << endl;
						cout << "Student Name: " << tempStudent->getName() << endl;
						cout << "Student M Number: " << tempStudent->getMNumber() << endl;
						cout << "Student Birthday: " << tempStudent->getBirthday() << endl;
						cout << "Student Age: " << tempStudent->getAge() << endl;
						// delete tempStudent;
					}
					else {
						cout << "That index is not in the directory." << endl;
					}
				}
				catch (exception ItemNotFound) {
					cout << "That index is not in the directory." << endl;
				}
				break;
			case 8: cout << "The positions in the list have been reset." << endl;
				StudentDirectory.Reset();
				break;*/
			case 0: cout << "You have chosen to exit." << endl;
				break;
			default: cout << "You have entered an invalid choice." << endl;
				break;
			}
		} while (choice != 0);
		return 0;
	
	}
}
