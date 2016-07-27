#include "pointLight.h"

PointLight::PointLight()
{
	position = Vect(0, 0, 0);
	color = Color(1, 1, 1, 0);
}

PointLight::PointLight(Vect position, Color color)
{
	this->position = position;
	this->color = color;
}