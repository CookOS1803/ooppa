#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

void Point::printPoint(std::ostream& out)
{
	out << "(" << x << ", " << y << ")\n";
}
