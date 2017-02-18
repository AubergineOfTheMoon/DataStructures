#pragma once
#ifndef SIDEPILE_H
#define SIDEPILE_H
#include "Deck.h"

using namespace std;

class SidePile {
private:
	int sidePile[5];
	int cardsInSidePile;
public:
	SidePile();
	void Push(int c);
	int Pop();
	int numCards();
};


#endif

