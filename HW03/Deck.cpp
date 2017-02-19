#include <string>
#include "Deck.h"

using namespace std;

Deck::Deck() {
	for (int i = 0; i < 52; i++) {
		cardDeck[i] = 0;
	}
	deckSize = 0;
}

int Deck::getCardsLeft() {
	// Return the number of cards left in the deck.
	return deckSize;
}

int Deck::playCard() {
	// Removes amd returns the card at the top of the deck.
	int card = cardDeck[0];
	for (int i = 0; i < deckSize - 1; i++) {
		cardDeck[i] = cardDeck[i + 1];
	}
	deckSize--;
	return card;

}

void Deck::addCard(int c) {
	cardDeck[deckSize] = c;
	deckSize++;

}

void Deck::getWinnings(int cardMain1, int cardSide1, int cardMain2, int cardSide2) {
	// Add cards won to the deck.
	if (cardMain1 != 0) {
		cardDeck[deckSize] = cardMain1;
		deckSize++;
	}
	if (cardMain2 != 0) {
		cardDeck[deckSize] = cardMain2;
		deckSize++;
	}
	if (cardSide1 != 0) {
		cardDeck[deckSize] = cardSide1;
		deckSize++;
	}
	if (cardSide2 != 0) {
		cardDeck[deckSize] = cardSide2;
		deckSize++;
	}
}

bool Deck::isEmpty() {
	// Returns whether deck is empty or not.
	return deckSize == 0;
}

int Deck::Peek() {
	// Allows user to view card at top of deck. Returns card at top of deck without removing it.
	return cardDeck[0];
}