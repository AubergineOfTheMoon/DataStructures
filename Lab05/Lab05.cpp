#include <iostream>
#include <string>
#include "Stable.h"
#include "Horse.h"

using namespace std;

int main() {
	int action;
	Horse removedHorse;
	do {
		cout << "Welcome to Happy Farms Horse Stable" << endl;
		cout << "Press 1 to add a horse" << endl << "Press 2 to add a horse" << endl;
		cout << "Press 3 to see how many horses are here" << endl << "Press 0 to quit" << endl;
		cin >> action;
		Stable happyFarms;
		switch (action) {
		case 1:
			cout << "What is the name of this horse?" << endl;
			// TODO: Set horsename and age
			happyFarms.addHorse(new Horse());
			break;
		case 2:
			removedHorse = happyFarms.removeHorse();
			cout << "I hate to see you go!\nRemoved Horse: \nName- " + removedHorse.getName() << endl;
			cout << "Age: " << removedHorse.getAge() << endl;
			if (removedHorse.getIsMini()) {
				cout << "Goodbye Mini Horse!" << endl;
			}
			else {
				cout << "Goodbye Big Horse" << endl;
			}
			break;
		case 3:
			cout << "The current number of horses in the stable: " << happyFarms.getHorseNum() << endl;
			break;
		case 0:
			cout << "Thanks for Visiting!!!" << endl;
			break;
		default:
			cout << "Well Partner, that doesn't seem to be an option! Please choose options 0-3." << endl;
		}
	} while (action != 0);
	return 0;
}
