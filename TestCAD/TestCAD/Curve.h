#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <stdexcept>

#include "ExportDef.h"
#include "Point.h"
#include "Vector3D.h"

enum class CurveType
{
	Circle2D,
	Ellipse2D,
	Helix3D,
	COUNT
};

class LIBRARY_API Curve {
public:
	virtual Point getPoint(double) const = 0;
	virtual Vector3D get3DVector(double) const = 0;
	virtual CurveType curveType() const = 0;

	virtual ~Curve() = default;
};