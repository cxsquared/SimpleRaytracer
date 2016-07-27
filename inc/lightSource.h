#ifndef _LIGH_SOURCE_H
#define _LIGH_SOURCE_H

#include "Vect.h"
#include "Color.h"

class LightSource
{
public:

	Vect getPosition(){ return position; }
	Color getColor(){ return color; }
protected:
	Vect position;
	Color color;
};
#endif