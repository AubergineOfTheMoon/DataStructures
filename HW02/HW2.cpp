#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main() 
{
	srand(time(NULL));
	int sides;
	cout << "Welcome to the game of dice rolling" << endl;
	do
	{
		char play;
		int sides;
		cout << "Enter the number of sides you want to roll: ";
		cin >> sides;
		if (sides < 6 || sides > 20)
		{
			cout << "Must be between 6 and 20";
		}
	} while (sides < 6 || sides > 20);
}