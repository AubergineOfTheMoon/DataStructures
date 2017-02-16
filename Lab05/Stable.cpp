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
	if (currentHorseNum < maxHorses) {
		horsesInStable[currentHorseNum] = *h;
		currentHorseNum++;
	}
	else {
		throw FullStable(currentHorseNum + 1);
	}

}

Horse Stable::removeHorse() {
	if (currentHorseNum > 0) {
		currentHorseNum--;
		return horsesInStable[currentHorseNum];
	}
	else {
		throw EmptyStable();
	}

}

int Stable::getHorseNum() {
	return currentHorseNum;
}
