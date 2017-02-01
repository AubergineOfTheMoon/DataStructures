#include<iostream>
#include<cmath>
#include<string>
#include"Vector.h"

#define PI 3.14159265
using namespace std;

Vector::Vector()
{
	xVal = 0.00;
	yVal = 0.00;
}
Vector::Vector(double x, double y)
{
	xVal = x;
	yVal = y;	
}
Vector::Vector(double r, float th)
{	
	//for degrees
	xVal = cos(th /180*PI)*r;
	yVal = sin(th /180*PI)*r;	
}

double Vector::getX() { return xVal; }
void Vector::setX(double x) { xVal = x; }

double Vector::getY() { return yVal; }
void Vector::setY(double y) { yVal=y; }

double Vector::getMagnitude() { return sqrt(xVal*xVal + yVal*yVal); }
float Vector::getAngle() { return float(atan(yVal / xVal));}
void Vector::print() { cout << "Rectangular coordinates: (" + to_string(xVal) + "," + to_string(yVal) + ")" << endl; }

//Task 3
bool Vector::operator==(Vector v) 
{ 
	float diffX = xVal - v.getX();
	float diffY = yVal - v.getY();
	float p = .005; //precision bc floats  
	return abs(diffX) < p && abs(diffY) < p;
}

// Multiplication Vector Operator
void Vector::operator*(double s) 
{
	setX(xVal*s);
	setY(yVal*s);
}