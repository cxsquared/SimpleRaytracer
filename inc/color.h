#ifndef _COLOR_H
#define _COLOR_H

class Color
{
public:
	Color();
	Color(double, double, double, double);

	double getRed() const { return red; }
	double getGreen() const { return green; }
	double getBlue() const { return blue; }
	double getSpecial() const { return special; }

	void setRed(double);
	void setGreen(double);
	void setBlue(double);
	void setSpecial(double);

	double brightness();

	Color& operator+=(const Color& rhs);
	const Color operator+(const Color& rhs) const;
	Color& operator-=(const Color& rhs);
	const Color operator-(const Color& rhs) const;
	Color& operator*=(const double& rhs);
	const Color operator*(const double& rhs) const;
	Color& operator*=(const Color& rhs);
	const Color operator*(const Color& rhs) const;

	Color& average(const Color& color);
private:
	double red, green, blue, special;
};

#endif