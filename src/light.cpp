#include "light.h"

Light::Light()
{
	position = Vect(0, 0, 0);
	color = Color(1, 1, 1, 0);
}

Light::Light(Vect position, Color color)
{
	this->position = position;
	this->color = color;
}