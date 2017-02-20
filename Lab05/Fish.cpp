#include <string>
#include <iostream>
#include "Animal.h"
#include "Fish.h"

using namespace std;

Fish::Fish() {
	// Default constructor for Fish
	name = "";
	age = 0.0;
	freshWater = false;
}
Fish::Fish(string n, float a, bool f) {
	// Constructor for Fish
	name = n;
	age = a;
	freshWater = f;
}

// Eat and Move functions
void Fish::eat() { cout << "Yummy fish food." << endl; }
void Fish::move() { cout << "Just keep swimming." << endl; }

// Getter and setter functions
bool Fish::getFreshWater() { return freshWater; }
void Fish::setFreshWater(bool f) { freshWater = f; }
