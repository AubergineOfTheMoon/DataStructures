#pragma once
#include <string>
#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal 
{
protected:
	string name;
	float age;
public:
	Animal();
	Animal(string, float);

	string getName();
	float getAge();
	void setName(string n);
	void setAge(float a);

	virtual void move();
	void eat();
};

#endif // !ANIMALS_H

