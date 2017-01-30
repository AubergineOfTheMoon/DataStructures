#ifndef VECTOR_H
#define VECTOR_H
#pragma once

class Vector {
	private:
		double xVal;
		double yVal;
		double magnitude;
		float angle;
	public:
		Vector();
		Vector(double x, double y);
		Vector(double r, float Theta);
		
		double getX();
		void setX(double x);
		void printX();

		double getY();
		void setY(double y);
		void printY();

		double getMagnitude();
		void setMagnitude(double r);
		void printMagnitude();

		float getAngle();
		void setAngle(float th);
		void printAngle();
};
#endif
