#include "Sphere.h"

using namespace std;

Sphere::Sphere() : Ellipsoid() {}

Sphere::Sphere(::Point point, int radius) : Ellipsoid(point, radius, radius, radius) {}

void Sphere::printData(ostream& out)
{
	out << "Center point: "
		<< "(" << getX() << ", " << getY() << ", " << z << ")\n"
		<< "Radius: " << radiusZ << endl;
}