#pragma once
#include <iostream>

#include "ExportDef.h"

class LIBRARY_API Point
{
	double m_x;
	double m_y;
	double m_z;
public:
	Point();
	Point(double, double);
	Point(double, double, double);

	LIBRARY_API friend std::ostream& operator<< (std::ostream&, const Point&);
};