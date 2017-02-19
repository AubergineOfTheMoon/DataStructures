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
	void addCard(int);
	void getWinnings(int, int, int, int );
	bool isEmpty();
	int Peek();

};

#endif 

