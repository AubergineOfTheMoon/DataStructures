#pragma once
#ifndef DECK_H
#define DECK_H

class Deck {
private:
	int cardDeck[52];
	int deckSize;
public:
	Deck();
	int getCardsLeft();
	int playCard();
	void getWinnings(int y, int o);
	bool isEmpty();
	void Peek();

};

#endif 

