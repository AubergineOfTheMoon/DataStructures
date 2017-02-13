#pragma once
#ifndef STABLE_H
#define STABLE_H
#include "Horse.h"

const int maxHorses = 10;

class Stable {
private:
	Horse horsesInStable[maxHorses];
	int currentHorseNum;
public:
	Stable();
	void addHorse(Horse);
	Horse removeHorse();
	int getHorseNum();
};

#endif