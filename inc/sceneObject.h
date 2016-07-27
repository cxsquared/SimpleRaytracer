#ifndef _SCENE_OBJECT_H
#define _SCENE_OBJECT_H

#include "vect.h"
#include "ray.h"
#include "color.h"

class SceneObject
{
public:
	Color color;

	virtual double findIntersection(Ray ray) = 0;
	virtual Vect getNormalAt(Vect point) = 0;

	Vect getPosition(){ return position; }
protected:
	Vect position;
};
#endif