#include <iostream>
#include <string>
#include "SidePile.h"
#include "Deck.h"

using namespace std;

SidePile::SidePile() {
	int SidePile[5] = {};
	int cardsInSidePile = 0;
}

void SidePile::Push(int c) {
	sidePile[cardsInSidePile] = c;
	cardsInSidePile++;
}

int SidePile::Pop() {
	int retCard = sidePile[cardsInSidePile];
	cardsInSidePile--;
	return retCard;
}

int SidePile::numCards() {
	return cardsInSidePile;
}

