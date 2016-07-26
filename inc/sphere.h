#ifndef _SPHERE_H
#define _SPHERE_H

#include <cmath>
#include "sceneObject.h"

class Sphere: public SceneObject
{
public:
	Sphere();
	Sphere(Vect, double, Color);

	Color color;

	double getRadius(){ return radius; }
	double findIntersection(Ray ray);
	Vect getNormalAt(Vect point);
private:
	double radius;
};

#endif