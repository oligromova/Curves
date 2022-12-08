#pragma once
#include <iostream>

#include "Curve.h"

class LIBRARY_API Circle2D : public Curve
{
	double m_radius;

public:
	Circle2D(double radius);
	~Circle2D() override = default;

	Point getPoint(double t) const override;
	Vector3D get3DVector(double t) const override;
	CurveType curveType() const override;

	double getRadius() const;
};