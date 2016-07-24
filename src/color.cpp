#include "color.h"

Color::Color()
{
	red = 0.5;
	green = 0.5;
	blue = 0.5;
	special = 0;
}

Color::Color(double red, double green, double blue, double special)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->special = special;
}

void Color::setRed(double red)
{
	this->red = red;
}

void Color::setGreen(double green)
{
	this->green = green;
}


void Color::setBlue(double blue)
{
	this->blue = blue;
}

void Color::setSpecial(double special)
{
	this->special = special;
}



