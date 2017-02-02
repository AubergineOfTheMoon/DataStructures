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
			v2 = Vector(x2, y2);
			v + v2;
			break;
		case '-':
			cout << "Enter x value for subtracted vector: ";
			cin >> x2;
			cout << "Enter y value for subtracted vector: ";
			cin >> y2;
			v2 = Vector(x2, y2);
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
			v2 = Vector(x2, y2);
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
		/*
		double x = 1.732, y = 1.00, mag = 2.00;
		float th = 30;
		Vector vec1 = Vector();
		Vector vec2 = Vector(x, y);
		Vector vec3 = Vector(mag, th);
		vec1.print();
		vec2.print();
		vec3.print();

		cout << "V1 v V2: " << boolalpha << (vec1 == vec2) <<endl;
		cout << "V2 v V3: " << boolalpha << (vec2 == vec3) <<endl;

		 vec2 + vec3;
		 vec2.print();


		vec2 * 5;
		vec2.print();
		vec3 * 2;
		vec3.print();

		*/






		//task 4
};