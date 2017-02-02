#include<iostream>
#include<cmath>
#include"Vector.h"
using namespace std;
int main()
{
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
	
	
	


	

	
	//task 4
}