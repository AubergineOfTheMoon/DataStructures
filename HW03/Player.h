#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include "Deck.h"
#include "SidePile.h"

class Player {
private:
	string name;
public:
	Deck deck;
	SidePile sidepile;
	int roundsWon;

	Player(string n);

	// Class member functions
	string getPlayerName();
	void setPlayerName(string);
	bool outOfCards();
};


#endif