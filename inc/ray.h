#ifndef _RAY_H
#define _RAY_H 

#include "vect.h"

class Ray
{
public:
	Ray();
	Ray(Vect, Vect);

	Vect getOrigin(){ return origin; }
	Vect getDirection(){ return direction; }
private:
	Vect origin, direction;
};

#endif