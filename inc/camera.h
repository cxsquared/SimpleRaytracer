#ifndef _CAMERA_H
#define _CAMERA_H
#include "vect.h"

class Camera
{
public:
	Camera();
	Camera(Vect, Vect, Vect, Vect);

	Vect getCameraPosition(){ return camPos; }
	Vect getCameraDirection(){ return camDir; }
	Vect getCameraRight(){ return camRight; }
	Vect getCameraDown(){ return camDown; }
private:
	Vect camPos, camDir, camRight, camDown;
};

#endif