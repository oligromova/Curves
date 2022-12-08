#pragma once
#include <iostream>

class Vector3D {
	double m_x;
	double m_y;
	double m_z;

public:
	Vector3D(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	friend std::ostream& operator<< (std::ostream& out, const Vector3D& vector)
	{
		return out << vector.m_x << ",  " << vector.m_y << ",  " << vector.m_z;
	}
};