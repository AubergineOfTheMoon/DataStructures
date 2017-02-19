#include <iostream>
#include <string>
#include "SidePile.h"
#include "Deck.h"

using namespace std;

SidePile::SidePile() {
	// Constructor for Side Pile
	for (int i = 0; i < 5; i++) {
		sidePile[i] = 0;
	}
	numCards = 0;
}

void SidePile::addCard(int c) {
	// Add cards to Side Pile.
	sidePile[numCards] = c;
	numCards++;
}

int SidePile::playCard() {
	// Remove and return the first card in the Side Pile.
	int retCard = sidePile[numCards];
	numCards--;
	return retCard;
}

int SidePile::getNumCards() {
	// Return the number of cards in the side pile.
	return numCards;
}

bool SidePile::isEmpty() {
	return numCards == 0;
}

bool SidePile::isFull() {
	return numCards == 5;
}