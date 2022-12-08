#pragma once
#include <iostream>

#include "Curve.h"

class LIBRARY_API Helix3D : public Curve
{
	double m_radius;
	double m_step;

public:
	Helix3D(double radius, double step);
	~Helix3D() override = default;

	Point getPoint(double t) const override;
	Vector3D get3DVector(double t) const override;
	CurveType curveType() const override;
};