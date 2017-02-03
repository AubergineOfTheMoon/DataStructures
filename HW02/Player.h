#include "Die.h"
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
	private:
		float money;
		int rolledNum;
	public:
		
		Die playerDie;
		Player(float money);
		void setMoney(float m);
		void setWager(float w);
		void depositMoney(float w);
		float getBalance();
};
#endif