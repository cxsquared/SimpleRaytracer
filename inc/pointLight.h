#ifndef _POINT_LIGHT_H
#define _POINT_LIGHT_H

#include "lightsource.h"

class PointLight : public LightSource
{
public:
	PointLight();
	PointLight(Vect, Color);
};

#endif