#pragma once
#ifndef SIDEPILE_H
#define SIDEPILE_H
#include "Deck.h"

using namespace std;

class SidePile {
private:
	int sidePile[5];
	int numCards;
public:
	SidePile();
	void addCard(int c);
	int playCard();
	int getNumCards();
	bool isEmpty();
	bool isFull();
};


#endif

