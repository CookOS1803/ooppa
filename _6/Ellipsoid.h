#pragma once
#include "Ellipse.h"

class Ellipsoid : private Ellipse
{
protected:

	int radiusZ;

public:

	Ellipsoid();
	Ellipsoid(::Point point, int radiusX, int radiusY, int radiusZ);

	int getRadiusZ() const { return radiusZ; }
	void setRadiusZ(int val) { radiusZ = val; }

	virtual void printData(std::ostream& out) override;

	using Ellipse::getX;
	using Ellipse::getY;
	using Ellipse::setX;
	using Ellipse::setY;
	using Ellipse::getCenterPoint;
	using Ellipse::setCenterPoint;

	virtual void setRadiusX(int val) override { Ellipse::setRadiusX(val); }
	virtual void setRadiusY(int val) override { Ellipse::setRadiusY(val); }

	virtual int getRadiusX() const override { return Ellipse::getRadiusX(); }
	virtual int getRadiusY() const override { return Ellipse::getRadiusY(); }

};

