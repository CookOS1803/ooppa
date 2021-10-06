#pragma once

#include <string>

using namespace std;

class Transport
{
protected:

	float speed;
	int price;

public:

	Transport();
	Transport(float speed, int price);

	void setSpeed(float speed);
	void setPrice(int price);

	float getSpeed() const;
	int getPrice() const;

	void calculateRoute(int path, float& time, int& totalPrice);
};

