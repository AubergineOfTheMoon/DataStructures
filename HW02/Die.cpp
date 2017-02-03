#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Die.h"

using namespace std;

Die::Die() 
{
	sides = 6;
}

Die::Die(int s) 
{
	sides = s;
}


void Die::setSides(int s) { sides = s; };
int Die::roll() { return rand() % sides + 1; };
int Die::getSides() { return sides; };

