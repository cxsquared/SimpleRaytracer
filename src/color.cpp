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

double Color::brightness()
{
	return(red+green+blue)/3;
}

Color& Color::operator+=(const Color& rhs)
{
	red += rhs.getRed();
	green += rhs.getGreen();
	blue += rhs.getBlue();
	special += rhs.getSpecial();
	return *this;
}

const Color Color::operator+(const Color& rhs) const
{
	return Color(*this) += rhs;
}

Color& Color::operator-=(const Color& rhs)
{
	red -= rhs.getRed();
	green -= rhs.getGreen();
	blue -= rhs.getBlue();
	special -= rhs.getSpecial();
	return *this;
}

const Color Color::operator-(const Color& rhs) const
{
	return Color(*this) -= rhs;
}

Color& Color::operator*=(const double& rhs)
{
	red *= rhs;
	green *= rhs;
	blue *= rhs;
	special *= rhs;
	return *this;
}

const Color Color::operator*(const double& rhs) const
{
	return Color(*this) *= rhs;
}

Color& Color::operator*=(const Color& rhs)
{
	red *= rhs.getRed();
	green *= rhs.getGreen();
	blue *= rhs.getBlue();
	special *= rhs.getSpecial();
	return *this;
}

const Color Color::operator*(const Color& rhs) const
{
	return Color(*this) *= rhs;
}

Color& Color::average(const Color& color)
{
	red = (red * color.getRed())/2;
	green = (green * color.getGreen())/2;
	blue = (blue * color.getBlue())/2;
	special = (special * color.getSpecial())/2;
	return *this;
}





