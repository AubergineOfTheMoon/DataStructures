#include <iostream>
#include <string>
#include "Stable.h"
#include "Horse.h"

using namespace std;

int main() {
	int action, m, age;
	string name;
	bool mini;
	Stable happyFarms;
	Horse removedHorse;
	do {
		cout << "Welcome to Happy Farms Horse Stable" << endl;
		cout << "Press 1 to add a horse" << endl << "Press 2 to remove a horse" << endl;
		cout << "Press 3 to see how many horses are here" << endl << "Press 4 to quit" << endl;
		cin >> action;
		switch (action) {
		case 1:
			cout << "What is the name of this horse?" << endl;
			getline(cin.ignore(), name);
			cout << "Enter the age of the horse" << endl;
			cin >> age;
			cout << "Is the horse miniature? Enter 1 for yes and 0 for no" << endl;
			cin >> m;
			mini = bool(m);
			// TODO: Set horsename and age
			try {
				happyFarms.addHorse(new Horse(name, age, mini));
			}
			catch (Stable::FullStable e) {
				cout << "Error: " << e.getValue() << " is too many horses for the stable!" << endl;
			}
			break;
		case 2:
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
			cout << "The current number of horses in the stable: " << happyFarms.getHorseNum() << endl;
			break;
		case 4:
			cout << "Thanks for Visiting!!!" << endl;
			break;
		default:
			cout << "Well Partner, that doesn't seem to be an option! Please choose options 0-3." << endl;
		}
	} while (action != 4);
	return 0;
}
