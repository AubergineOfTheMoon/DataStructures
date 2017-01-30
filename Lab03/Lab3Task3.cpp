#include<iostream>
#include<cmath>
#include"Vector.h"
using namespace std;
int main()
{
	double x = 1.732, y = 1.00, mag = 2.00;
	float th = .523599;
	Vector vec1 = Vector();
	Vector vec2 = Vector(x, y);
	Vector vec3 = Vector(mag, th);
	cout << "hi";
	cout << endl;
	vec1.printAngle();
	cout << endl;
	vec2.printMagnitude();
	cout << endl;
	vec3.printY();
	cout << endl;
	cout << "Done";
}