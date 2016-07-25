#ifndef _PLANE_H
#define _PLANE_H

#include "sceneObject.h"
#include <cmath>

class Plane: public SceneObject
{
public:
	Plane();
	Plane(Vect, double, Color);

	double findIntersection(Ray r);
	Vect getPlaneNormal() { return normal; }
	double getPlaneDistance() { return distance; }
	Vect getNormalAt(Vect point);
private:
	Vect normal;
	double distance;
};
#endif