#include "ray.h"

Ray::Ray()
{
	origin = Vect(0, 0, 0);
	direction = Vect(1, 0, 0);
}

Ray::Ray(Vect origin, Vect direction)
{
	this->origin = origin;
	this->direction = direction;
}