#include "camera.h"

Camera::Camera()
{
	camPos = Vect(0, 0, 0);
	camDir = Vect(0, 0, 1);
	camRight = Vect(0, 0, 0);
	camDown = Vect(0, 0, 0);
}

Camera::Camera(Vect position, Vect direciton, Vect right, Vect down)
{
	camPos = position;
	camDir = direciton;
	camRight = right;
	camDown = down;
}