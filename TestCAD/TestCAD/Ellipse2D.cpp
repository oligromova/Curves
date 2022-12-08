#include "Ellipse2D.h"

Ellipse2D::Ellipse2D(double radius1, double radius2)
{
	if (radius1 <= 0)
	{
		throw ("The radius(radius1) must be a positive number");
	}
	if (radius2 <= 0)
	{
		throw ("The radius(radius2) must be a positive number");
	}
	m_radius1 = radius1;
	m_radius2 = radius2;
}

Point Ellipse2D::getPoint(double t) const
{
	if (t < 0 || t > 2 * M_PI)
	{
		throw ("The value of the argument(t) must lie on the segment [0; 2PI]");
	}
	return Point{ m_radius1 * cos(t), m_radius2 * sin(t) };
}

Vector3D Ellipse2D::get3DVector(double t) const
{
	if (t < 0 || t > 2 * M_PI)
	{
		throw ("The value of the argument(t) must lie on the segment [0; 2PI]");
	}
	return Vector3D{ -1 * m_radius1 * sin(t), m_radius2 * cos(t), 0 };
}

CurveType Ellipse2D::curveType() const
{
	return CurveType::Ellipse2D;
}
