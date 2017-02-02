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
		case '+':
			cout << "Enter x value for added vector: ";
			cin >> x2;
			cout << "Enter y value for added vector: ";
			cin >> y2;
			v2.setX(x2);
			v2.setY(y2);
			v + v2;
			break;
		case '-':
			cout << "Enter x value for subtracted vector: ";
			cin >> x2;
			cout << "Enter y value for subtracted vector: ";
			cin >> y2;
			v2.setX(x2);
			v2.setY(y2);
			v - v2;
			break;
		case '*':
			cout << "Enter scalar: ";
			cin >> s;
			v * s;
			break;
		case '/':
			cout << "Enter scalar: ";
			cin >> s;
			v / s;
			break;
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
		case 'q':
			break;
		default:
			cout << op << " is not a valid operation" << endl;
		}
		v.print();
		cout << "Magnitude " << v.getMagnitude() << " angle " << v.getAngle() << endl;
	} while (op != 'q');

	// Testing remaining functions	
	double mag = 4.0;
	float angleTheta = 30.0;
	Vector vTest = Vector(mag, angleTheta);
	cout << "\nVector with polar coordinates magnitude " << mag << " units and " << angleTheta << " degrees are: ";
	cout << vTest.getX() << " and " << vTest.getY() << endl;

};