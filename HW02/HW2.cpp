#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Die.h"
#include "Player.h"
using namespace std;

void setSidesBonusMode(Die&, int, float, int&);
float playGame(Player&, Die, float);
int main() 
{
	srand(time(NULL)); 
	float balance;
	char hard;
	float wager;
	int sides;
	cout << "Welcome to the game of dice rolling" << endl;

	// Ask if the user wants to play the hard mode
	cout << "Play hard mode [y/n]?: ";
	cin >> hard;

	//Ask the user for their money
	cout << "How much money do user have? : ";
	cin >> balance;

	Player user = Player(balance);
	float userWinnings = 0; // Set the amount of money the user won to -1
							// userWinnings is initialized because it is referenced before it is set after playing a game
	int userLosses = 0;//keeps track of the number of times user has lost in a row, for the hard mode
	
	// Get the number of sides on the player's and house's dice
	cout << "Enter the number of sides user want to roll (between 6 and 20): ";
	cin >> sides;
	cout << endl;
	while (sides < 6 || sides > 20) // makes sure the number of sides of the dice is within limits
	{
		cout << "The number of sides must be between 6 and 20. Enter another number: ";
		cin >> sides;
		cout << endl;
	}
	//Initializes the player and house dice
	Die houseDie = Die(sides);
	user.playerDie.setSides(sides);

	do
	{
		cout << "You have $" << user.getBalance() << endl;
		if (hard == 'y') {
			// Makes changes to the house die if necessary while playing the hard mode
			setSidesBonusMode(houseDie, user.playerDie.getSides(), userWinnings, userLosses);
		}
		
		// Asks for player's initial wager
		cout << "How much money would user like to wager?(Type 0 to quit) ";
		cin >> wager;
		if (wager != 0) // Skips if user entered 0 as not betting means they're leaving
		{
			while (wager > user.getBalance()) // Checks if the user has bet more money than they possess
			{
				cout << "You can't bet more money than you has" << endl;
				cout << "You have $" << user.getBalance() << endl;
				cout << "How much money would you like to wager?(Type 0 to quit) ";
				cin >> wager;
			}
			userWinnings = playGame(user, houseDie, wager); // Calls the playGame function and returns any possible winnings
			user.depositMoney(userWinnings); // Deposits the winnings of the user into their account
			cout << endl;
		}
		if (user.getBalance() == 0) // Checks if user has money to play because user has to pay to play
		{
			cout << "You have to pay to play! See ya!" << endl;
		}
	} while (user.getBalance() > 0 && wager > 0); // Checks if the user has money and still wants to play
	if (user.getBalance() > 0) {
		cout << endl <<"You left with $" << user.getBalance() << ". Thanks for playing!" << endl;
	}
}

// Parameter Die playerDie was changed to Player p with the permission of Prof. Zimmer
// This allows the function to access the player balance to check if they have enough money to double down
// It is passed as a reference so that the balance can be manipulated (for doubling down)
float playGame(Player &p, Die dieHouse, float w) 
{
	float wager = w;
	char doubleDown;
	p.setWager(wager); // Takes the money for the wager out of the user's account
	int pRoll = p.playerDie.roll();
	int hRoll = dieHouse.roll();
	cout << "You rolled a " << pRoll << ". Would you like to double down (y/n): ";
	cin >> doubleDown;
	if (doubleDown == 'y' && wager <= p.getBalance()) {// see if the player has enough to double down (placing the same wager)
		p.setWager(w); // Since the player has already placed a wager, the same ammount needs to be re-bet
		wager *= 2; //the wager is doubled so if they win *4 is won
	}
	else if (wager > p.getBalance()) { // see if the player has enough to double down (placing the same wager)
		cout << "You don't have enough money to double down" << endl;
	}
	cout << "The house rolled a " << hRoll << endl;
	if (pRoll > hRoll) //if the house rolled better than the user
	{ 
		cout << "You Win!" << endl;
		return wager * 2; //win the wager and then some
	}
	else
	{
		cout << "You Lose haha!" << endl;
		return 0; //win nothing
	}
	

 }
				// houseDie is passed by reference so that the houseDie can be manipulated
				// Same with userLosses
void setSidesBonusMode(Die &houseDie, int playerSides, float userWinnings, int &userLosses) {
	if (userWinnings > 0) {//If the user won any money
		houseDie.setSides(houseDie.getSides() + 1); //Increase the number of sides on the house die
		userLosses = 0;
	}
	else {
		userLosses++;
		if (userLosses > 1) { // If the user won twice in a row
			if (houseDie.getSides() > playerSides) //Check if the house die will be within the minimum
			{
				houseDie.setSides(houseDie.getSides() - 1); // Decreases the number of sides
			}
			userLosses = 0; // Set it back to zero so
		}
	}
	//Display how many sides each die has
	cout << "Your die has " << playerSides << " sides. The house die has " << houseDie.getSides() << " sides" << endl;
}