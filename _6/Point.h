#pragma once
#include <ostream>

class Point
{
protected:

	int x, y;

public:
	
	Point();
	Point(int x, int y);

	int getX() const { return x; }
	int getY() const { return y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void printPoint(std::ostream& out);
};

