#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
	name = "";
	age = 0.0;
}
Animal::Animal(string n, float a) {
	name = n;
	age = a;
}

void Animal::eat() { cout << "Yummy" << endl; }
void Animal::move() { cout << "Move" << endl; }

string Animal::getName() { return name; }
float Animal::getAge() { return age; }
void Animal::setName(string n) { name = n; }
void Animal::setAge(float a) { age = a; }