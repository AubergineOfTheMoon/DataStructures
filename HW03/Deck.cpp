#include <iostream>
#include <string>
#include "Deck.h"

using namespace std;

Deck::Deck() {

}

int Deck::getCardsLeft() {
	return deckSize;
}

int Deck::playCard() {
	int card = cardDeck[0];
	for (int i = 0; i < deckSize - 1; i++) {
		cardDeck[i] = cardDeck[i + 1];
	}
	deckSize--;
	return card;

}

void Deck::getWinnings(int you, int opp) {
	cardDeck[deckSize] = you;
	deckSize++;
	cardDeck[deckSize] = opp;
	deckSize++;


}

bool Deck::isEmpty() {
	return deckSize == 0;
}

void Deck::Peek() {
	cout << cardDeck[0] << endl;
}