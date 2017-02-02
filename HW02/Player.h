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
		Player();
		Player(float money);
		void setMoney(float m);
		
};
#endif