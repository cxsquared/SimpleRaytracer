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

Vect Vect::normalize() const
{
	double mag = magnitude();

	return Vect(x/mag, y/mag, z/mag);
}

double Vect::magnitude() const
{
	return sqrt((x*x) + (y*y) + (z*z));
}

Vect Vect::negative() const
{
	return Vect(-x, -y, -z);
}

double Vect::dotProduct (Vect v)
{
	return x * v.getVectX() + y * v.getVectY();
}

Vect& Vect::operator+=(const Vect& rhs)
{
	x += rhs.getVectX();
	y += rhs.getVectY();
	z += rhs.getVectZ();
	return *this;
}

const Vect Vect::operator+(const Vect& rhs) const
{
	return Vect(*this) += rhs;
}

Vect& Vect::operator-=(const Vect& rhs)
{
	x -= rhs.getVectX();
	y -= rhs.getVectY();
	z -= rhs.getVectZ();
	return *this;
}

const Vect Vect::operator-(const Vect& rhs) const
{
	return Vect(*this) -= rhs;
}

Vect& Vect::operator*=(const double& rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

const Vect Vect::operator*(const double& rhs) const
{
	return Vect(*this) *= rhs;
}

Vect Vect::crossProduct(Vect v)
{
	return Vect(y * v.getVectZ() - z * v.getVectY(),
				z * v.getVectX() - x * v.getVectZ(),
				x * v.getVectY() - y * v.getVectX());
}