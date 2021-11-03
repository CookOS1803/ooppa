#include "Ellipse.h"

using namespace std;

Ellipse::Ellipse() : Shape2D(), Point(), radiusX(0), radiusY(0) {}

Ellipse::Ellipse(Point point, int radiusX, int radiusY) : Shape2D(), Point(point), radiusX(radiusX), radiusY(radiusY) {}

void Ellipse::printData(ostream& out)
{
	out << "Center point: ";
	printPoint(out);
	out << "Radius X: " << radiusX << endl
	    << "Radius Y: " << radiusY << endl;
}

void Ellipse::setCenterPoint(Point point)
{
	x = point.getX();
	y = point.getY();
}
