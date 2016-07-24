#ifndef _LIGHT_H
#define _LIGHT_H

#include "Vect.h"
#include "Color.h"

class Light
{
public:
	Light();
	Light(Vect, Color);

	Vect getPosition(){ return position; }
	Color getColor(){ return color; }
private:
	Vect position;
	Color color;
};

#endif