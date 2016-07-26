#include "sphere.h"

Sphere::Sphere()
{
	position = Vect(0,0,0);
	radius = 1.0;
	color = Color(.5, .5, 1, 0);
}

Sphere::Sphere(Vect position, double radius, Color color)
{
	this->position = position;
	this->radius = radius;
	this->color = color;
}

double Sphere::findIntersection(Ray ray)
{
	Vect rayOrigin = ray.getOrigin();
	double rayOriginX = rayOrigin.getVectX();
	double rayOriginY = rayOrigin.getVectY();
	double rayOriginZ = rayOrigin.getVectZ();

	Vect rayDir = ray.getDirection();
	double rayDirX = rayDir.getVectX();
	double rayDirY = rayDir.getVectY();
	double rayDirZ = rayDir.getVectZ();

	Vect sphereCenter = position;
	double sphereCenterX = sphereCenter.getVectX();
	double sphereCenterY = sphereCenter.getVectY();
	double sphereCenterZ = sphereCenter.getVectZ();

	double a = 1; //normalized
	double b = (2 * (rayOriginX - sphereCenterX)*rayDirX)
				+ (2 * (rayOriginY - sphereCenterY)*rayDirY)
				+ (2 * (rayOriginZ - sphereCenterZ)*rayDirZ);
	double c = pow(rayOriginX - sphereCenterX, 2)
				+ pow(rayOriginY - sphereCenterY, 2)
				+ pow(rayOriginZ - sphereCenterZ, 2)
				- (radius*radius);

	double discriminat = (b*b)-(4*a*c);

	if(discriminat > 0)
	{
		// we go there at most two points on the sphere

		double root1 = ((-b - sqrt(discriminat))/2*a) - 0.0001; // helps fix acceracy errors

		if (root1 > 0)
		{
			// smallest root so closet
			return root1;
		}

		double root2 = ((b - sqrt(discriminat))/2*a) - 0.0001;

		if (root2 > 0)
		{
			return root2;
		}
	}

	// we missed sphere
	return -1;


}

Vect Sphere::getNormalAt(Vect point)
{
	Vect normal = (point - position).normalize();

	return normal;
}