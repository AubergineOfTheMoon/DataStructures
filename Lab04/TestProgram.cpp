#include <iostream>
#include <string>
#include "Animal.h"
#include "Fish.h"
#include "Horse.h"

using namespace std;

void callClassFunc(Animal *animal2)
{
	animal2->eat();
	animal2->move();
}

int main()
{
	int exit = 1; // flag for continuing loop
	while(exit>0)
	{
		int choice;
		// Enter the user's choice for the animal
		cout << "Which animal would you like to talk about?" << endl;
		cout << "Press 1 for an instance of animal." << endl;
		cout << "Press 2 for an instance of fish." << endl;
		cout << "Press 3 for an instance of horse." << endl;
		cout << "Press 4 for an instance of fish declared as an animal." << endl;
		cout << "Press 5 for an instance of horse declared as an animal." << endl;
		cin >> choice;
		string n="";
		float a=0.0;
		Animal animal1;
		Fish fish1;
		Horse horse1;
		bool mini = false;
		bool fresh = false;
		int f = 0, m=0;
		switch (choice)
		{
		case 1:
			cout << "Enter the name of the animal: ";
			cin >> n;
			cout << endl;
			cout << "Enter the age of the animal: ";
			cin >> a;
			animal1 = Animal(n, a);
			animal1.move();
			animal1.eat();
			callClassFunc(&animal1);
			break;
		case 2:
			cout << "Enter the name of the fish: ";
			cin >> n;
			cout << endl;
			cout << "Enter the age of the fish: ";
			cin >> a;
			cout << endl;
			cout << "Enter 1 if the fish is freshwater. Enter 0 if it is not: ";
			cin >> f;
			fresh = (bool)f;
			fish1 = Fish(n, a, fresh);
			fish1.move();
			fish1.eat();
			callClassFunc(&fish1);
			break;
		case 3:
			cout << "Enter the name of the horse: ";
			cin >> n;
			cout << endl;
			cout << "Enter the age of the horse: ";
			cin >> a;
			cout << endl;
			cout << "Enter 1 if the horse is miniature. Enter 0 if it is not: ";
			cin >> m;
			mini = (bool)m;
			horse1 = Horse(n, a, mini);
			horse1.move();
			horse1.eat();
			callClassFunc(&horse1);
			break;
		case 4:
			cout << "Enter the name of the fishde declared as an animal: ";
			cin >> n;
			cout << endl;
			cout << "Enter the age of the fish declared as an animal: ";
			cin >> a;
			cout << endl;
			cout << "Enter 1 if the fish declared as an animal is freshwater. Enter 0 if it is not: ";
			cin >> f;
			fresh = (bool)f;
			fish1 = Fish(n, a, fresh);
			fish1.move();
			fish1.eat();
			callClassFunc(&fish1);
			break;
		case 5:
			cout << "Enter the name of the horse: ";
			cin >> n;
			cout << endl;
			cout << "Enter the age of the horse: ";
			cin >> a;
			cout << endl;
			cout << "Enter 1 if the horse is miniature. Enter 0 if it is not: ";
			cin >> m;
			mini = (bool)m;
			horse1 = Horse(n, a, mini);
			horse1.move();
			horse1.eat();
			callClassFunc(&horse1);
			break;
		default: cout << "Invalid input. Please enter 1, 2, 3, 4 or 5 to select a choice." << endl;
			break;
		}
		cout << "Do you wish to continue?(Enter 1 if you wish to continue. Enter 0 if you wish to quit.)" << endl;
		cin >> exit;
	}
}
