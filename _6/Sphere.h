#pragma once
#include "Ellipsoid.h"

class Sphere : public Ellipsoid
{
public:

	Sphere();
	Sphere(::Point point, int radius);

	virtual void printData(std::ostream& out) override;

	virtual void setRadiusX(int val) override { setRadiusZ(val); }
	virtual void setRadiusY(int val) override { setRadiusZ(val); }
	
	virtual int getRadiusX() const override { return getRadiusZ(); }
	virtual int getRadiusY() const override { return getRadiusZ(); }

};

