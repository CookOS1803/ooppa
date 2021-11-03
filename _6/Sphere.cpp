#include "Sphere.h"

using namespace std;

Sphere::Sphere() : Ellipsoid() {}

Sphere::Sphere(::Point point, int radius) : Ellipsoid(point, radius, radius, radius) {}

void Sphere::printData(ostream& out)
{
	out << "Center point: ";
	getCenterPoint().printPoint(out);
	out << "Radius: " << radiusZ << endl;
}