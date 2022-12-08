#pragma once
#include <iostream>

#include "Curve.h"

class LIBRARY_API Ellipse2D : public Curve
{
	double m_radius1;
	double m_radius2;
public:
	Ellipse2D(double radius1, double radius2);
	~Ellipse2D() override = default;

	Point getPoint(double t) const override;
	Vector3D get3DVector(double t) const override;
	CurveType curveType() const override;
};