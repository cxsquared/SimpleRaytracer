#include "vect.h"

Vect::Vect()
{
	x = 0;
	y = 0;
	z = 0;
}

Vect::Vect (double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vect Vect::normalize()
{
	double mag = magnitude();

	return Vect(x/mag, y/mag, z/mag);
}

double Vect::magnitude()
{
	return sqrt((x*x) + (y*y) + (z*z));
}

Vect Vect::negative()
{
	return Vect(-x, -y, -z);
}

double Vect::dotProduct (Vect v)
{
	return x * v.getVectX() + y * v.getVectY();
}

Vect Vect::add(Vect v)
{
	return Vect(x + v.getVectX(), y + v.getVectY(), z + v.getVectZ());
}

Vect Vect::subtract(Vect v)
{
	return Vect(x - v.getVectX(), y - v.getVectY(), z - v.getVectZ());
}

Vect Vect::crossProduct(Vect v)
{
	return Vect(y * v.getVectZ() - z * v.getVectY(),
				z * v.getVectX() - x * v.getVectZ(),
				x * v.getVectY() - y * v.getVectX());
}

Vect Vect::multiply(double scalar)
{
	return Vect(x*scalar, y*scalar, z*scalar);
}