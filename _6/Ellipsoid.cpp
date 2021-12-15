#include "Ellipsoid.h"

using namespace std;

Ellipsoid::Ellipsoid() : Ellipse(), radiusZ(0), z(0) {}

Ellipsoid::Ellipsoid(::Point point, int radiusX, int radiusY, int radiusZ) : Ellipse(point, radiusX, radiusY), radiusZ(radiusZ), z(0) {}

void Ellipsoid::printData(ostream& out)
{
	out << "Center point: "
		<< "(" << getX() << ", " << getY() << ", " << z << ")\n"
	    << "Radius X: " << radiusX << endl
		<< "Radius Y: " << radiusY << endl
		<< "Radius Z: " << radiusZ << endl;
}