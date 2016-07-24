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

#include "vect.h"
#include "ray.h"
#include "camera.h"
#include "color.h"

using namespace std;

struct RGBType
{
	double r;
	double g;
	double b;
};

void savebmp(const char *filename, int w, int h, int dpi, RGBType *data);

int currentPixel;

int main(int argc, char *argv[])
{
	cout << "rendering ...\n";

	int dpi = 72;
	int width = 640;
	int height = 480;

	int numPixels = width*height;

	RGBType *pixels = new RGBType[numPixels];

	Camera cam();

	Vect X(1,0,0);
	Vect Y(0,1,0);
	Vect Z(0,0,1);

	Vect campos(0, 1.5, -10);
	Vect look_at (0, 0, 0);
	Vect diff_btw  = campos.subtract(look_at);

	Vect camdir = diff_btw.negative().normalize();
	Vect camright = Y.crossProduct(camdir).normalize();
	Vect camdown = camright.crossProduct(camdir);

	Camera scene_cam (campos, camdir, camright, camdown);

	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			currentPixel = y*width+x;

			if (x > width/4 && x < width*.75 && y > height/4 && y < height*.75)
			{
				pixels[currentPixel].r = .5;
				pixels[currentPixel].g = .75;
				pixels[currentPixel].b = .1;
			} else
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
	unsigned char bmpHeaderSize = 14;
	unsigned char bmpInfoSize = 40;
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