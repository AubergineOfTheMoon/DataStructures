#include <iostream>
#include <string>
#include "Stable.h"
#include "Horse.h"

using namespace std;

// maxHorses = 10;

Stable::Stable() {
	// horsesInStable[0] = Horse();
	currentHorseNum = 0;
}

void Stable::addHorse(Horse* h) {
	horsesInStable[currentHorseNum] = *h;
	currentHorseNum++;
}

Horse Stable::removeHorse() {
	currentHorseNum--;
	return horsesInStable[currentHorseNum];
}

int Stable::getHorseNum() {
	return currentHorseNum;
}
