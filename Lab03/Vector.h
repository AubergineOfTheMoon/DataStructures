#ifndef VECTOR_H
#define VECTOR_H
#pragma once
// This code was written by Kyle, Smit, Saylee and Evan in collaboration.

class Vector 
{
	private:
		// Class attributes, Task 1
		double xVal;
		double yVal;
	public:
		// Constructors, Task 1
		Vector();
		Vector(double x, double y);
		Vector(double r, float Theta);
		
		// Getter and Setter functions, Task 1
		double getX();
		void setX(double x);

		double getY();
		void setY(double y);

		double getMagnitude();
		float getAngle();

		// Print function
		void print();

		// Operator Overloading functions, Task 3  
		bool operator==(Vector v);
		void operator+(Vector v);
		void operator-(Vector v);
		void operator*(double s);
		void operator/(double s);
	
};
#endif
