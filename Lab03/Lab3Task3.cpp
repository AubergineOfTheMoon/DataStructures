#include<iostream>
#include<cmath>
#include"Vector.h"
using namespace std;
int main()
{
	double x, y, s, x2, y2;
	bool isEqual;
	char op;
	cout << "Enter x value for vector: ";
	cin >> x;
	cout << "Enter y value for vector: ";
	cin >> y;
	Vector v = Vector(x, y); 
	Vector v2;
	do {
		cout << "\nWhat operation would you like to perform [+, -, *, /, =, q (to quit)]: ";
		cin >> op;
		cout << endl;
		switch (op) {
		
		// Input another vector and perform addition operation
		case '+':
			cout << "Enter x value for added vector: ";
			cin >> x2;
			cout << "Enter y value for added vector: ";
			cin >> y2;
			v2.setX(x2);
			v2.setY(y2);
			v + v2;
			break;

		// Input another vector and perform subtraction operation
		case '-':
			cout << "Enter x value for subtracted vector: ";
			cin >> x2;
			cout << "Enter y value for subtracted vector: ";
			cin >> y2;
			v2.setX(x2);
			v2.setY(y2);
			v - v2;
			break;

		// Input a scalar and perform multiplication operation
		case '*':
			cout << "Enter scalar: ";
			cin >> s;
			v * s;
			break;

		// Input a scalar and perform division operation
		case '/':
			cout << "Enter scalar: ";
			cin >> s;
			v / s;
			break;

		// Input another vector and compare both vectors
		case '=':
			cout << "Enter x value for comparison vector: ";
			cin >> x2;
			cout << "Enter y value for comparison vector: ";
			cin >> y2;
			v2.setX(x2);
			v2.setY(y2);
			isEqual = v == v2;
			if (isEqual)
				cout << "Vectors are equal" << endl;
			else
				cout << "Vectors are not equal" << endl;
			break;

		// User chooses to quit
		case 'q':
			break;

		// Default option: Operation is invalid
		default:
			cout << op << " is not a valid operation" << endl;
		}

		//Print vector information
		v.print();
		cout << "Magnitude " << v.getMagnitude() << " angle " << v.getAngle() << endl;

	} while (op != 'q'); //Performs operations until user chooses to quit by entering q

	// Testing remaining functions	
	double mag = 4.0;
	float angleTheta = 30.0;
	Vector vTest = Vector(mag, angleTheta); // Test magnitude and angle constructor
	cout << "\nVector with polar coordinates magnitude " << mag << " units and " << angleTheta << " degrees are: ";
	cout << vTest.getX() << " and " << vTest.getY() << endl; // Test getters for x and y coordinates vector

};