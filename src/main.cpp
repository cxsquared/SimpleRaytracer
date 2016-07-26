#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>

#include "vect.h"
#include "ray.h"
#include "camera.h"
#include "color.h"
#include "light.h"
#include "sphere.h"
#include "plane.h"

using namespace std;

struct RGBType
{
	double r;
	double g;
	double b;
};

void savebmp(const char *filename, int w, int h, int dpi, RGBType *data);
int winningObjectIndex(vector<double>);
Color getColorAt(const Vect, const Vect, vector<SceneObject*>, int, double, double, vector<Light*>);

int currentPixel;

int main(int argc, char *argv[])
{
	cout << "rendering ...\n";

	int dpi = 72;
	int width = 640;
	int height = 480;
	double aspectratio = (double)width/(double)height;
	double ambientlight = 0.2;
	double accuracy = 0.000001;

	int numPixels = width*height;

	RGBType *pixels = new RGBType[numPixels];

	Camera cam;

	Vect X(1,0,0);
	Vect Y(0,1,0);
	Vect Z(0,0,1);

	Vect campos(0, 1, -4);
	Vect look_at (0, 0, 0);
	Vect diff_btw  = campos - look_at;

	Vect camdir = diff_btw.negative().normalize();
	Vect camright = Y.crossProduct(camdir).normalize();
	Vect camdown = camright.crossProduct(camdir);

	Camera scene_cam (campos, camdir, camright, camdown);

	Color white_light (1, 1, 1, 0);
	Color pretty_green (0.5, 1.0, 0.5, 0.3);
	Color grey (0.5, 0.5, 0.5, 0);
	Color black (0, 0, 0, 0);
	Color maroon(0.75, 0.25, 0.25, 0);

	vector<Light*> lights;

	Vect light_position(-7, 10, 0);
	Light scene_light(light_position, white_light);
	lights.push_back(dynamic_cast<Light*>(&scene_light));

	Sphere scene_sphere(Vect(0,0,0), 1, pretty_green);
	Plane scene_plane(Y, -1, maroon);

	vector<SceneObject*> objects;
	objects.push_back(dynamic_cast<SceneObject*>(&scene_sphere));
	objects.push_back(dynamic_cast<SceneObject*>(&scene_plane));

	double xamnt, yamnt;

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			currentPixel = y*width+x;

			// start with no anti-aliasing
			if(width > height)
			{
				xamnt = ((x+0.5) / width) * aspectratio - (((width-height)/(double)height)/2);
				yamnt = ((height - y) + 0.5) / height; 
			}
			else if(height > width)
			{
				xamnt = (x + 0.5) / width;
				yamnt = (((height - y) + 0.5) / height)/aspectratio - (((height-width)/(double)width)/2);
			}
			else
			{
				xamnt = (x + 0.5) / width;
				yamnt = ((height - y) + 0.5)/height;
			}

			Vect camRayOrigin = scene_cam.getCameraPosition();
			Vect camRayDir = (camdir + (camright * (xamnt - 0.5)) + (camdown * (yamnt - 0.5))).normalize();

			Ray camRay (camRayOrigin, camRayDir);

			vector<double> intersections;

			for(int index = 0; index < objects.size(); ++index)
			{
				double intersect = objects.at(index)->findIntersection(camRay);
				intersections.push_back(intersect);
			}

			int indexWinningObject = winningObjectIndex(intersections);

			if (indexWinningObject >= 0) {
				double intersectDist = intersections.at(indexWinningObject);
				if(intersectDist > accuracy)
				{
					Vect interectPoint = camRayOrigin + (camRayDir * intersectDist);
					Vect intersectionDir = camRayDir;

					Color intersectColor = getColorAt(interectPoint, intersectionDir, objects, indexWinningObject, accuracy, ambientlight, lights);

					pixels[currentPixel].r = intersectColor.getRed();
					pixels[currentPixel].g = intersectColor.getGreen();
					pixels[currentPixel].b = intersectColor.getBlue();
				}
			} 
			else 
			{
				pixels[currentPixel].r = 0;
				pixels[currentPixel].g = 0;
				pixels[currentPixel].b = 0;
			}
		}
	}

	savebmp("scene.bmp", width, height, dpi, pixels);

	return 0;
}

void savebmp(const char *filename, int w, int h, int dpi, RGBType *data)
{
	FILE *f;
	const unsigned char bmpHeaderSize = 14;
	const unsigned char bmpInfoSize = 40;
	int numPixels = w * h;
	int size = 4 * numPixels;
	int filesize = bmpHeaderSize + bmpInfoSize + size;

	double factor = 39.375;
	int m = static_cast<int>(factor);

	int ppm = dpi * m;

	unsigned char bmpfileheader[bmpHeaderSize] = {'B','M', 0,0,0,0, 0,0,0,0, bmpHeaderSize+bmpInfoSize,0,0,0};
	unsigned char bmpinfoheader[bmpInfoSize] = {bmpInfoSize,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize>>8);
	bmpfileheader[4] = (unsigned char)(filesize>>16);
	bmpfileheader[5] = (unsigned char)(filesize>>24);

	bmpinfoheader[4] = (unsigned char)(w);
	bmpinfoheader[5] = (unsigned char)(w>>8);
	bmpinfoheader[6] = (unsigned char)(w>>16);
	bmpinfoheader[7] = (unsigned char)(w>>24);

	bmpinfoheader[8] = (unsigned char)(h);
	bmpinfoheader[9] = (unsigned char)(h>>8);
	bmpinfoheader[10] = (unsigned char)(h>>16);
	bmpinfoheader[11] = (unsigned char)(h>>24);

	bmpinfoheader[21] = (unsigned char)(size);
	bmpinfoheader[22] = (unsigned char)(size>>8);
	bmpinfoheader[23] = (unsigned char)(size>>16);
	bmpinfoheader[24] = (unsigned char)(size>>24);

	bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm>>8);
	bmpinfoheader[27] = (unsigned char)(ppm>>16);
	bmpinfoheader[28] = (unsigned char)(ppm>>24);

	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm>>8);
	bmpinfoheader[31] = (unsigned char)(ppm>>16);
	bmpinfoheader[32] = (unsigned char)(ppm>>24);

	f = fopen(filename, "wb");

	fwrite(bmpfileheader,1,bmpHeaderSize,f);
	fwrite(bmpinfoheader,1,bmpInfoSize,f);

	for (int i = 0; i < numPixels; ++i)
	{
		//RGBType rgb = data[i];

		double red = (data[i].r)*255;
		double green = (data[i].g)*255;
		double blue = (data[i].b)*255;

		unsigned char color[3] = {(int)floor(blue), (int)floor(green), (int)floor(red)};

		fwrite(color,1,3,f);
	}

	fclose(f);
}

int winningObjectIndex(vector<double> objectIntersections)
{
	int returnIndex = -1;

	if(objectIntersections.size() == 0)
	{
		return -1;
	}
	else if (objectIntersections.size() == 1 && objectIntersections.at(0) > 0)
	{
		return 0;
	}
	else
	{
		double min = DBL_MAX;
		for(int i = 0; i < objectIntersections.size(); ++i)
		{
			if (objectIntersections.at(i) > 0 && objectIntersections.at(i) < min)
			{
				min = objectIntersections.at(i);
				returnIndex = i;
			}
		}

		if (returnIndex >= 0)
		{
			return returnIndex;
		}
	}

	return -1; // Couldn't find an intersection
}

Color getColorAt(const Vect point, const Vect dir, vector<SceneObject*> objs, int objIndex, double acc, double amb, vector<Light*> lightSources)
{
	return Color();
}
