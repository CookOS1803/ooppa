#include "Ellipsoid.h"

using namespace std;

Ellipsoid::Ellipsoid() : Ellipse(), radiusZ(0) {}

Ellipsoid::Ellipsoid(::Point point, int radiusX, int radiusY, int radiusZ) : Ellipse(point, radiusX, radiusY), radiusZ(radiusZ) {}

void Ellipsoid::printData(ostream& out)
{
	Ellipse::printData(out);
	out << "Radius Z: " << radiusZ << endl;
}