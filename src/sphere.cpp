#include "sphere.h"

Sphere::Sphere()
{
	position = Vect(0,0,0);
	radius = 1.0;
	color = Color(.5, .5, 1, 0);
}

Sphere::Sphere(Vect position, double radius, Color color)
{
	this->position = position;
	this->radius = radius;
	this->color = color;
}

double Sphere::findIntersection(Ray ray)
{
	return 0;
}