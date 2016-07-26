#ifndef _VECT_H
#define _VECT_H

#include <cmath>

class Vect
{
public:
	Vect();
	Vect(double, double, double);

	double getVectX() const { return x; }
	double getVectY() const { return y; }
	double getVectZ() const { return z; }

	Vect normalize() const;
	double magnitude() const;
	Vect negative() const;

	double dotProduct (Vect v);
	Vect crossProduct(Vect v);
	Vect& operator+=(const Vect& rhs);
	const Vect operator+(const Vect& rhs) const;
	Vect& operator-=(const Vect& rhs);
	const Vect operator-(const Vect& rhs) const;
	Vect& operator*=(const double& rhs);
	const Vect operator*(const double& rhs) const;

private:
	double x, y, z; 
};

#endif