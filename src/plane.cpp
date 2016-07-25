#include "plane.h"

Plane::Plane()
{
	normal = Vect(1,0,0);
	distance = 0.0;
	color = Color(0.5, 0.5, 0.5, 0);
}

Plane::Plane(Vect normal, double distance, Color color)
{
	this->normal = normal;
	this->distance = distance;
	this->color = color;
}

double Plane::findIntersection(Ray ray)
{
	Vect ray_direction = ray.getDirection();

	double a = ray_direction.dotProduct(normal);

	if (a == 0)
	{
		// ray is parallel to the plane
		return -1;
	}

	double b = normal.dotProduct(ray.getOrigin().add(normal.multiply(distance).negative()));

	return -1*b/a;
}

Vect Plane::getNormalAt(Vect point)
{
	return normal;
}
