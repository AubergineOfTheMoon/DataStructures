#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Die.h"
#include "Player.h"
using namespace std;

void setSidesBonusMode(Die&, int, float, int&);
int main() 
{
	srand(time(NULL));
	float balance;
	char hard;
	float wager;
	int sides;
	cout << "Welcome to the game of dice rolling" << endl;
	cout << "Play hard mode [y/n]?: ";
	cin >> hard;
	cout << "How much money do you have? : ";
	cin >> balance;

	Player you = Player(balance);

	cout << "Enter the number of sides you want to roll (between 6 and 20): ";
	cin >> sides;
	cout << endl;

	float winnings = -1;
	int losses = 0;
	
	while (sides < 6 || sides > 20)
	{
		cout << "The number of sides must be between 6 and 20. Enter another number: ";
		cin >> sides;
		cout << endl;
	}
	Die houseDie = Die(sides);
	you.playerDie.setSides(sides);

	do
	{
		cout << "You have $" << you.getBalance() << endl;
		if (hard == 'y') {
			setSidesBonusMode(houseDie, you.playerDie.getSides(), winnings, losses);
		}
		
		cout << "How much money would you like to wager?(Type 0 to quit) ";

		cin >> wager;
		if (wager != 0)
		{
			while (wager > you.getBalance())
			{
				cout << "You can't bet more than you have" << endl;
				cout << "You have $" << you.getBalance() << endl;
				cout << "How much money would you like to wager?(Type 0 to quit) ";
				cin >> wager;
			}
			you.setWager(wager);
			winnings = playGame(you.playerDie, houseDie, wager);
			you.depositMoney(winnings);
			cout << endl;
		}
		if (you.getBalance() == 0)
		{
			cout << "You have to pay to play! See ya!" << endl;
		}
	} while (you.getBalance() > 0 && wager > 0);
}

float playGame(Die diePlayer, Die dieHouse, float w) 
{
	float wager = w;
	int pRoll = diePlayer.roll();
	int hRoll = dieHouse.roll();
	cout << "You rolled a " << pRoll << " The house rolled a " << hRoll << endl;
	if (pRoll > hRoll) 
	{ 
		cout << "You Win!" << endl;
		return wager * 2; 
	}
	else
	{
		cout << "You Lose haha!" << endl;
		return 0; 
	}
	

}

void setSidesBonusMode(Die &houseDie, int playerSides, float winnings, int &losses) {
	if (winnings > 0) {
		houseDie.setSides(houseDie.getSides() + 1);
		losses = 0;
	}
	else {
		losses++;
		if (losses > 1) {
			if (houseDie.getSides() > playerSides)
			{
				houseDie.setSides(houseDie.getSides() - 1);
			}
			losses = 0;
		}
	}
	cout << "Your die has " << playerSides << " The house die has " << houseDie.getSides() << endl;
}