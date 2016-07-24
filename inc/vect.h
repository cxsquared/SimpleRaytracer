#ifndef _VECT_H
#define _VECT_H

#include <cmath>

class Vect
{
public:
	Vect();
	Vect(double, double, double);

	double getVectX() { return x; }
	double getVectY() { return y; }
	double getVectZ() { return z; }

	Vect normalize();
	double magnitude();
	Vect negative();

	double dotProduct (Vect v);
	Vect crossProduct(Vect v);
	Vect add(Vect v);
	Vect multiply(double);
	Vect subtract(Vect v);
private:
	double x, y, z; 
};

#endif