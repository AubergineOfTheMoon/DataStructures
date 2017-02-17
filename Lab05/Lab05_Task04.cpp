#include <iostream>
#include <string>
#include "AnimalCollection.h"
#include "Fish.h"
#include "Lab05_Task04.h"

using namespace std;

int main() {
	int action, m, age;
	string name;
	bool fresh;
	AnimalCollection<Fish> happyFarms = AnimalCollection<Fish>();
	Fish removedFish;
	do {
		cout << "Welcome to Happy Fish Farms" << endl;
		cout << "Press 1 to add a fish" << endl << "Press 2 to remove a fish" << endl;
		cout << "Press 3 to see how many fish are here" << endl << "Press 4 to quit" << endl;
		cin >> action;
		switch (action) {
		case 1:
			cout << "What is the name of this fish?" << endl;
			getline(cin.ignore(), name);
			cout << "Enter the age of the fish" << endl;
			cin >> age;
			cout << "Is the fish freshwater? Enter 1 for yes and 0 for no" << endl;
			cin >> m;
			fresh = bool(m);
			// TODO: Set fishname and age
			try {
				happyFarms.addAnimal(new Fish(name, age, fresh));
			}
			catch (AnimalCollection<Fish>::FullAnimalCollection e) {
				cout << "Error: " << e.getValue() << " is too many fish for the farm!" << endl;
			}
			break;
		case 2:
			try {
				removedFish = happyFarms.removeAnimal();
				cout << "I hate to see you go!\nRemoved fish: \nName- " + removedFish.getName() << endl;
				cout << "Age: " << removedFish.getAge() << endl;
				if (removedFish.getFreshWater()) {
					cout << "Goodbye Mini fish!" << endl;
				}
				else {
					cout << "Goodbye Big fish" << endl;
				}
			}
			catch (AnimalCollection<Fish>::EmptyAnimalCollection) {
				cout << "You can't take fish out of an empty farm!" << endl;
			}
			break;
		case 3:
			cout << "The current number of fish in the farm: " << happyFarms.getAnimalNum() << endl;
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