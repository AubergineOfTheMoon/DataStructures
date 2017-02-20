#include <iostream>
#include <string>
#include "Stable.h"
#include "Horse.h"

using namespace std;

int main() {
	int action, m;
	double age;
	string name;
	bool mini;
	Stable happyFarms;
	Horse removedHorse;
	do {
		// Get the user's choice for adding or removing horses or displaying the number of horses in the stable
		cout << "Welcome to Happy Farms Horse Stable" << endl;
		cout << "Press 1 to add a horse" << endl << "Press 2 to remove a horse" << endl;
		cout << "Press 3 to see how many horses are here" << endl << "Press 4 to quit" << endl;
		cin >> action;
		switch (action) {

		case 1:
			// Add horse to stable if the stable is not full
			cout << "What is the name of this horse?" << endl;
			getline(cin.ignore(), name);
			cout << "Enter the age of the horse" << endl;
			cin >> age;
			cout << "Is the horse miniature? Enter 1 for yes and 0 for no" << endl;
			cin >> m;
			mini = bool(m);
			try {
				happyFarms.addHorse(new Horse(name, age, mini));
			}
			catch (Stable::FullStable e) {
				cout << "Error: " << e.getValue() << " is too many horses for the stable!" << endl;
			}
			break;

		case 2:
			// Remove horse from the stable if there is a horse in stable
			try{
				removedHorse = happyFarms.removeHorse();
				cout << "I hate to see you go!\nRemoved Horse: \nName- " + removedHorse.getName() << endl;
				cout << "Age: " << removedHorse.getAge() << endl;
				if (removedHorse.getIsMini()) {
					cout << "Goodbye Mini Horse!" << endl;
				}
				else {
					cout << "Goodbye Big Horse" << endl;
				}
			}
			catch (Stable::EmptyStable e) {
				cout << "You can't take horses out of an empty stable!" << endl;
			}
			break;

		case 3:
			// Print the current number of horses in the stable
			cout << "The current number of horses in the stable: " << happyFarms.getHorseNum() << endl;
			break;

		case 4:
			//  The user wishes to exit the loop. Bid them farewell.
			cout << "Thanks for Visiting!!!" << endl;
			break;

		default:
			// The user enters an invalid input. Display error message and ask them to select another option.
			cout << "Well Partner, that doesn't seem to be an option! Please choose options 1-4." << endl;
		}
	} while (action != 4);
	return 0;
}
