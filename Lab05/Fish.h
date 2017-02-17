#pragma once
#ifndef FISH_H
#define FISH_H
#include "Animal.h"

class Fish : public Animal
{
private:
	bool freshWater; // True is freshwater false is saltwater
public:
	Fish();
	Fish(string, float, bool);

	bool getFreshWater();
	void setFreshWater(bool);

	void eat();
	void move();
};

#endif // !FISH_H
