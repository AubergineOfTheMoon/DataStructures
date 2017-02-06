#include <string>
#include <iostream>
#include "Animal.h"
#include "Fish.h"

using namespace std;

Fish::Fish() {
	name = "";
	age = 0.0;
	freshWater = false;
}
Fish::Fish(string n, float a, bool f) {
	name = n;
	age = a;
	freshWater = f;
}

void Fish::eat() { cout << "Yummy fish food." << endl; }

void Fish::move() { cout << "Just keep swimming." << endl; }

bool Fish::getFreshWater() { return freshWater; }
void Fish::setFreshWater(bool f) { freshWater = f; }
