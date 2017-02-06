#pragma once
#ifndef HORSE_H
#define HORSE_H
#include "Animal.h"

class Horse : public Animal
{
private:
	bool isMini; // True is freshwater false is saltwater
public:
	Horse();
	Horse(string, float, bool);

	bool getIsMini();
	void setIsMini(bool);

	void eat();
	void move();
};

#endif // !FISH_H
