#include<iostream>
#include<cmath>
#include<string>
#include"Vector.h"

#define PI 3.14159265
using namespace std;
 
// Default Constructor 
Vector::Vector()
{
	xVal = 0.00;
	yVal = 0.00;
}

// Overloaded Constructor that takes in rectangular coordinates 
Vector::Vector(double x, double y)
{
	xVal = x;
	yVal = y;	
}

// Overloaded Constructor that takes in magnitude and angle
Vector::Vector(double r, float th)
{	
	//for degrees
	xVal = cos(th /180*PI)*r;
	yVal = sin(th /180*PI)*r;	
}

// Getter and Setter Functions
double Vector::getX() { return xVal; }
void Vector::setX(double x) { xVal = x; }

double Vector::getY() { return yVal; }
void Vector::setY(double y) { yVal=y; }

double Vector::getMagnitude() { return sqrt(xVal*xVal + yVal*yVal); }
float Vector::getAngle() { return float(atan(yVal / xVal) * 180/PI);}

// Print function
void Vector::print() { cout << "Rectangular coordinates: (" + to_string(xVal) + "," + to_string(yVal) + ")" << endl; }

// Overloaded Operator ==, Evan
bool Vector::operator==(Vector v) 
{ 
	float diffX = xVal - v.getX();
	float diffY = yVal - v.getY();
	float p = .005; //precision bc floats  
	return abs(diffX) < p && abs(diffY) < p;
}

// Overloaded Operator *, Kyle
void Vector::operator*(double s) 
{
	xVal *= s;
	yVal *= s;
}

// Overloaded Operator /, Saylee
void Vector::operator/(double s) 
{
	xVal /= s;
	yVal /= s;
}

// Overloaded Operator +, adds 2 vectors, Smit
void Vector::operator+(Vector v)
{
	xVal += v.getX();
	yVal += v.getY();
}

// Overloaded Operator -, subtracts 2 vectors, Smit
void Vector::operator-(Vector v)
{
	xVal -= v.getX();
	yVal -= v.getY();
}

