#include "Circle2D.h"
#include "Vector3D.h"

Circle2D::Circle2D(double radius)
{
	if (radius <= 0)
	{
		throw ("The radius must be a positive number");
	}
	m_radius = radius;
}

Point Circle2D::getPoint(double t) const
{
	if (t < 0 || t > 2 * M_PI)
	{
		throw ("The value of the argument(t) must lie on the segment [0; 2PI]");
	}
	return Point{ m_radius * cos(t), m_radius * sin(t) };
}

Vector3D Circle2D::get3DVector(double t) const
{
	if (t < 0 || t > 2 * M_PI)
	{
		throw ("The value of the argument(t) must lie on the segment [0; 2PI]");
	}
	return Vector3D{-1 * m_radius * sin(t), m_radius * cos(t), 0 };
}

double Circle2D::getRadius() const
{
	return m_radius;
}

CurveType Circle2D::curveType() const
{
	return CurveType::Circle2D;
}
