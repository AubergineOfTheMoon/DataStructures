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
		vector<Node*> sortedWords = vector<Node*>(numWords, nullptr);
		
		do {
			cout << "***************************************" << endl;
			cout << "Please select the the action you would like to complete" << endl;
			cout << "1. Search for a word." << endl;
			cout << "2. View list of words in alphabetical order." << endl;
			cout << "3. View list of words in reverse alphabetical order." << endl;
			cout << "0. Exit" << endl;
			cout << "Enter the number of the choice you wish to select: ";
			cin >> choice;
			if (cin.fail()) {
				choice = 10;
				cin.clear();
				cin.ignore(10000, '\n');
			}
			switch (choice) {
			// Search for word
			case 1: cout << "Enter the word you want to search for: ";
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
			// Print word count ascending
			case 2: cout << "The sorted words are: " << endl;
				sortedWords = BSTWords.getAllAscending();
				for (int i = 0; i < numWords; i++) {
					cout << sortedWords[i]->getWord() << ": " << sortedWords[i]->getFrequency() << endl; // Error here with peterpan.txt and mobydick.txt
				}
				break;
			// Print word count descending
			case 3: cout << "The sorted words are: " << endl;
				sortedWords = BSTWords.getAllDescending();
				for (int i = 0; i < numWords; i++) {
					cout << sortedWords[i]->getWord() << ": " << sortedWords[i]->getFrequency() << endl;
				}
				break;
			case 0: cout << "You have chosen to exit." << endl;
				break;
			default: cout << "You have entered an invalid choice." << endl;
				break;
			}
		} while (choice != 0);
		return 0;
	
	}
}
