#include "Point.h"

Point::Point()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Point::Point(double x, double y)
{
	m_x = x;
	m_y = y;
	m_z = 0;
}

Point::Point(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

std::ostream& operator<< (std::ostream& out, const Point& point)
{
	return out << point.m_x << ",  " << point.m_y << ",  " << point.m_z;
}
