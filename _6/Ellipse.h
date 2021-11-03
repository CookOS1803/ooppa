#pragma once
#include "Shape2D.h"
#include "Point.h"

class Ellipse : public Shape2D, private Point
{
protected:

	int radiusX, radiusY;

public: 

	Ellipse();
	Ellipse(Point point, int radiusX, int radiusY);

	virtual void printData(std::ostream& out) override;

	Point getCenterPoint() const { return Point(x, y); }
	void setCenterPoint(Point point);

	virtual int getRadiusX() const { return radiusX; }
	virtual int getRadiusY() const { return radiusY; }

	virtual void setRadiusX(int val) { radiusX = val; }
	virtual void setRadiusY(int val) { radiusY = val; }

	using Point::getX;
	using Point::getY;
	using Point::setX;
	using Point::setY;
};

