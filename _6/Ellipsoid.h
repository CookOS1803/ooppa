#pragma once
#include "Ellipse.h"

class Ellipsoid : private Ellipse
{
protected:

	int radiusZ;
	int z;

public:

	Ellipsoid();
	Ellipsoid(::Point point, int radiusX, int radiusY, int radiusZ);

	int getRadiusZ() const { return radiusZ; }
	void setRadiusZ(int val) { radiusZ = val; }

	virtual void printData(std::ostream& out) override;

	using Ellipse::getX;
	using Ellipse::getY;
	int getZ() const { return z; }
	using Ellipse::setX;
	using Ellipse::setY;
	void setZ(int z) { this->z = z; };
	using Ellipse::getCenterPoint;
	using Ellipse::setCenterPoint;

	virtual void setRadiusX(int val) override { Ellipse::setRadiusX(val); }
	virtual void setRadiusY(int val) override { Ellipse::setRadiusY(val); }

	virtual int getRadiusX() const override { return Ellipse::getRadiusX(); }
	virtual int getRadiusY() const override { return Ellipse::getRadiusY(); }

};

