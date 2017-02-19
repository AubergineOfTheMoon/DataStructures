#include<string>
#include "Player.h"

Player::Player(string n) {
	name = n;
	roundsWon = 0;
}
string Player::getPlayerName() {
	return name;
}

void Player::setPlayerName(string n) {
	name = n;
}

bool Player::outOfCards() {
	if ((sidepile.getNumCards() + deck.getCardsLeft()) == 0) { return true; }
	else { return false; }
}
