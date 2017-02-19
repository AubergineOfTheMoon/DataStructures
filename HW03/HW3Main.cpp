#include<string>
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

#include "Deck.h"
#include "SidePile.h"
#include "Player.h"

int selectGameStyle();
int* shuffleCards();

int main() {
	srand(time(NULL));
	string n;
	int maxRounds;
	cout << "Welcome to the Game of WAR!" << endl;
	cout << "Brave player, please tell me your name. " << endl;
	getline(cin, n);
	Player userPlayer = Player(n);
	Player compPlayer = Player("Computer");
	userPlayer.sidepile = SidePile();
	compPlayer.sidepile = SidePile();
	userPlayer.deck = Deck();
	compPlayer.deck = Deck();

	Player players[] = { userPlayer, compPlayer };
	//Select Game Style Preference (to the death or by number of rounds to win)
	maxRounds = selectGameStyle();

	// Shuffle cards.
	int* cards =shuffleCards();
	
	// Deal cards.
	for (int j = 0; j < 52; j++) {
		// Add cards to sidepile of user
		if (j < 5) {
			userPlayer.sidepile.addCard(cards[j]);
		}

		// Add cards to sidepile of computer
		else if ((j < 10) && (j >= 5)) {
			compPlayer.sidepile.addCard(cards[j]);
		}

		// Add cards to user's deck 
		else if ((j < 31) && (j >= 10)) {
			userPlayer.deck.addCard(cards[j]);
		}

		// Add cards to computer's deck
		else if ((j < 52) && (j >= 31)) {
			compPlayer.deck.addCard(cards[j]);
		}
	}


	int userSideCard=0, userMainCard=0, playerNum=0, userCardTotal, compCardTotal;
	int userCardsPlayed[] = {0, 0}; // Stores the cards played by the user in a round
	int ans;
	int numRounds = 0;
	
	// Play Game
	while ((!userPlayer.outOfCards()) && (!compPlayer.outOfCards()) && (numRounds < maxRounds)) {
		cout << "***************************************" << endl;
		cout << endl;
		cout << "ROUND " << numRounds + 1;
		cout << endl;
		userCardTotal = 0;
		compCardTotal = 0;
		userCardsPlayed[0] = 0;
		userCardsPlayed[1] = 0;
		
		// User's Turn

		// If the user has no cards in their deck, play from the side pile.
		if (userPlayer.deck.isEmpty()) {
			cout << "You have no cards in your deck." << endl;
			cout << "Your card will come from your side pile." << endl;
			userCardsPlayed[0] = userPlayer.sidepile.playCard();
			userCardTotal = userCardsPlayed[0];
			cout << "Your card is " << userCardsPlayed[0] << endl;

			// If the side pile is not empty, play from the side pile.
			if (!userPlayer.sidepile.isEmpty()) {
				ans = 0;
				do {
					cout << "You have " << userPlayer.deck.getCardsLeft() << " cards in your deck and " << userPlayer.sidepile.getNumCards() << " cards in your side pile." << endl;
					cout << "You have the following moves. " << endl;
					cout << "1. You can play another card from your side pile." << endl;
					cout << "2. You can stick with playing the card you have." << endl;
					cout << "Please enter 1 or 2 to choose your move: ";
					cin >> ans;
					cout << endl;
					switch (ans) {
					case 1: userCardsPlayed[1] = userPlayer.sidepile.playCard();
						break;
					case 2: break;
					default: ans = 0;
						break;
					}
				} while (ans == 0);
			}
		}
		// If the deck is not empty, play from the deck.
		else {
			ans = 0;
			do {
				cout << "Your card is " << userPlayer.deck.Peek() << endl;
				cout << "You have " << userPlayer.deck.getCardsLeft() << " cards in your deck and " << userPlayer.sidepile.getNumCards() << " cards in your side pile." << endl;
				cout << "You have the following possible moves. " << endl;
				cout << "1. You can play your card." << endl;
				if (!userPlayer.sidepile.isEmpty()) { // If the side pile is not empty, the user has the option of playing a card from the side pile.
					cout << "2. You can play this card along with another card from your side pile" << endl;
				}
				if (!userPlayer.sidepile.isFull()) { // If the side pile is not full, the user can add a card to the side pile.
					cout << "3. You can add this card to your side pile." << endl;
				}
				cout << "Enter a number based on your choice: ";
				cin >> ans;
				cout << endl;
				// Execute user's choice.
				switch (ans) {
				case 1: userCardsPlayed[0] = userPlayer.deck.playCard();
					break;
				case 2:userCardsPlayed[0] = userPlayer.deck.playCard();
					userCardsPlayed[1] = userPlayer.sidepile.playCard();
					break;
				case 3:userPlayer.sidepile.addCard(userPlayer.deck.playCard());
					userCardsPlayed[0] = userPlayer.deck.playCard();
					cout << "The card has been placed in your sidepile. You have drawn the following card from your deck: " << userCardsPlayed[0] << endl;
					break;
				default:
					cout << "Please read the instructions on the screen and enter 1, 2 or 3." << endl;
					ans = 0;
				} //TODO: Add error handling for if user enters a number without having that option available.
			} while (ans == 0);
		}
		userCardTotal = userCardsPlayed[0] + userCardsPlayed[1];

		//Computer's turn
		if (!compPlayer.deck.isEmpty()) {
			compCardTotal = compPlayer.deck.playCard();
		}
		else {
			compCardTotal = compPlayer.sidepile.playCard();
		}

		// Display scores
		cout << "The total of your cards was " << userCardTotal << " and the total of the computer's cards was " << compCardTotal << endl;

		// Find the winner of the round.
		if (userCardTotal > compCardTotal) {
			cout << "Congratulations! You have won this round!" << endl;
			userPlayer.deck.getWinnings(userCardsPlayed[0], userCardsPlayed[1] ,compCardTotal, 0);
			userPlayer.roundsWon += 1;
		}
		else {
			cout << "I'm sorry, you have lost this round." << endl;
			compPlayer.deck.getWinnings(userCardsPlayed[0], userCardsPlayed[1], compCardTotal, 0);
			compPlayer.roundsWon += 1;
		}
		cout << "The computer has won " << compPlayer.roundsWon << " rounds and you have won " << userPlayer.roundsWon << " rounds." << endl;
		numRounds++;
	}

	// Print message for winning or losing.
	if (((maxRounds != 10000000)&&(userPlayer.roundsWon > compPlayer.roundsWon)) || (compPlayer.outOfCards())) {
		cout << "Congratulations, " << userPlayer.getPlayerName() << "! You have won the game." << endl;
	}
	else if ((maxRounds != 10000000) && (userPlayer.roundsWon == compPlayer.roundsWon)) {
		cout << "You and the computer have tied." << endl;
	}
	else {	
		cout << "The computer has won. The computer apocalypse is nearer. Be warned." << endl;
	}
	getchar();
	return 0;
}

int selectGameStyle() {
	// Select the Game Style by asking the User and returning the desired number of rounds.
	int choice = 0;
	int maxRounds;
	do {
		cout << "Which style would you like to play?" << endl;
		cout << "1. Until one player is out of cards" << endl;
		cout << "2. For a particular number of rounds of your choice." << endl;
		cout << "Enter 1 or 2 to indicate your choice: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			maxRounds = 10000000;
			break;
		case 2:
			cout << "How many rounds do you want to play maximum? (Please enter a number between 1 and 1000): ";
			cin >> maxRounds;
			if ((maxRounds > 1000) || (maxRounds < 1)) {
				cout << "Due to you lack of ability to follow instructions (I asked for a number between 1 and 1000), the number of rounds you will play is 10" << endl;
				maxRounds = 10;
			}
			break;
		default:
			cout << "Please follow instructions and enter 1 or 2." << endl;
			choice = 0;
		}
	} while (choice == 0);
	return maxRounds;
}

int* shuffleCards() {
	int cards[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13, 1,2,3,4,5,6,7,8,9,10,11,12,13, 1,2,3,4,5,6,7,8,9,10,11,12,13, 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int card1, card2, index, card;

	// Shuffle cards
	for (int i = 0; i < 52; i++) {
		index = rand() % 52;
		card1 = cards[i];
		card2 = cards[index];
		cards[i] = card2;
		cards[index] = card1;
	}
	return cards;
}