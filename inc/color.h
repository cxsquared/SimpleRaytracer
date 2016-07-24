#ifndef _COLOR_H
#define _COLOR_H

class Color
{
public:
	Color();
	Color(double, double, double, double);

	double getRed(){ return red; }
	double getGreen(){ return green; }
	double getBlue(){ return blue; }
	double getSpecial(){ return special; }

	void setRed(double);
	void setGreen(double);
	void setBlue(double);
	void setSpecial(double);
private:
	double red, green, blue, special;
};

#endif