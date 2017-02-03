#include <iostream>
#include "Player.h"
#include "Die.h"

using namespace std;

Player::Player(float m) 
{
	money = m;
	playerDie = Die();
}

void Player::setWager(float w) { money -= w; }
void Player::depositMoney(float w) { money += w; }

void Player::setMoney(float m) { money = m; };

float Player::getBalance() { return money; };


