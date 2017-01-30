#include<iostream>
#include<cmath>
#include"Vector.h"

#define PI 3.14159265
using namespace std;

Vector::Vector()
{
	xVal = 0.00;
	yVal = 0.00;
	magnitude = 0.00;
	angle = 0.00;
}
Vector::Vector(double x, double y)
{
	xVal = x;
	yVal = y;
	magnitude = sqrt(x*x+y*y);
	angle = float(atan(y/x));
	
}
Vector::Vector(double r, float th)
{
	magnitude = r;
	angle = th;
	xVal = cos(th)*r;
	yVal = sin(th)*r;	
}

double Vector::getX() { return xVal; }
void Vector::setX(double x) { xVal = x; }
void Vector::printX() { cout << xVal; }

double Vector::getY() { return yVal; }
void Vector::setY(double y) { yVal=y; }
void Vector::printY() { cout << yVal; }

double Vector::getMagnitude() { return magnitude; }
void Vector::setMagnitude(double r) { magnitude = r; }
void Vector::printMagnitude() { cout << magnitude; }

float Vector::getAngle() { return angle; }
void Vector::setAngle(float th) {	angle = th;}
void Vector::printAngle() { cout << angle; }

