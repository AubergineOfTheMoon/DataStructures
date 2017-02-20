#pragma once
#ifndef STABLE_H
#define STABLE_H
#include "Horse.h"

const int maxHorses = 10;

class Stable {
private:
	Horse horsesInStable[maxHorses];
	int currentHorseNum; // This number represents the number of horses in the stable 
	                     // and indicates the next open space in the stable.

public:
	Stable();
	void addHorse(Horse*);
	Horse removeHorse();
	int getHorseNum();

	// Exception classes for a full stable and an empty stable
	class FullStable;
	class EmptyStable;
	
	//FullStable Class Definition
	class FullStable {
	private:
		int index;
	public:
		FullStable(int i) { index = i; }
		int getValue() { return index; }
	};

	//EmptyStable Class Definition
	class EmptyStable {
	public:
		EmptyStable() { }
	};
};

#endif