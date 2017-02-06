#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {}
Animal::Animal(string n, float a) {
	name = n;
	age = a;
}

void Animal::eat() {
	cout << "Yummy";
}

string Animal::getName() { return name; }
float Animal::getAge() { return age; }
void Animal::setName(string n) { name = n; }
void Animal::setAge(float a) { age = a; }