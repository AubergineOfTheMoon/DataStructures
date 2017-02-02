#include <iostream>
#include "Player.h"
#include "Die.h"

using namespace std;

Player::Player() 
{
	money = 0.00;
	playerDie = Die();
}

Player::Player(float m) 
{
	money = m;
	playerDie = Die();
}


void Player::setMoney(float m) { money = m; };