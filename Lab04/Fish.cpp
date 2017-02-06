#include <string>
#include <iostream>
#include "Animal.h"
#include "Fish.h"

using namespace std;

Fish::Fish() {}
Fish::Fish(string n, float a, bool f) {
	name = n;
	age = a;
	freshWater = f;
}

void Fish::eat() {
	cout << "Yummy fish food.";
}

void Fish::move() {
	cout << "Just keep swimming.";
}

bool Fish::getFreshWater() { return freshWater; }
void Fish::setFreshWater(bool f) { freshWater = f; }
