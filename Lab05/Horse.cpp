#include <string>
#include <iostream>
#include "Animal.h"
#include "Horse.h"

using namespace std;

Horse::Horse() {
	// Default constructor for Horse
	name = "";
	age = 0.0;
	isMini = false;
}
Horse::Horse(string n, float a, bool m) {
	// Constructor for Horse
	name = n;
	age = a;
	isMini = m;
}

// Eat and Move functions
void Horse::eat() { cout << "Yummy grass." << endl; }
void Horse::move() { cout << "Walk, Trot, Canter, Gallop." << endl; }

// Getter and Setter functions
bool Horse::getIsMini() { return isMini; }
void Horse::setIsMini(bool m) { isMini = m; }
