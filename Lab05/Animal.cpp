#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
	// Default constructor for animal
	name = "";
	age = 0.0;
}
Animal::Animal(string n, float a) {
	// Constructor for animal
	name = n;
	age = a;
}

// Eat and Move functions
void Animal::eat() { cout << "Yummy" << endl; }
void Animal::move() { cout << "Move" << endl; }

// Getter and setter functions
string Animal::getName() { return name; }
float Animal::getAge() { return age; }
void Animal::setName(string n) { name = n; }
void Animal::setAge(float a) { age = a; }