#include "Helix3D.h"

Helix3D::Helix3D(double radius, double step)
{
	if (radius <= 0)
	{
		throw ("The radius must be a positive number");
	}
	if (step < 0 || step > 2 * M_PI)
	{
		throw ("The value of the argument(step) must lie on the segment [0; 2PI]");
	}
	m_radius = radius;
	m_step = step;
}

Point Helix3D::getPoint(double t) const
{
	if (t < 0 || t > 2 * M_PI)
	{
		throw ("The value of the argument(t) must lie on the segment [0; 2PI]");
	}
	return Point{ m_radius * cos(t), m_radius * sin(t), m_step * t / (2 * M_PI) };
}

Vector3D Helix3D::get3DVector(double t) const
{
	if (t < 0 || t > 2 * M_PI)
	{
		throw ("The value of the argument(t) must lie on the segment [0; 2PI]");
	}
	return Vector3D{ -1 * m_radius * sin(t), m_radius * cos(t), 0 };
}

CurveType Helix3D::curveType() const
{
	return CurveType::Helix3D;
}