#pragma once

#include <string>

using namespace std;

class Transport
{
protected:

	string name;
	float speed;
	int price;

public:

	Transport();
	Transport(string name, float speed, int price);

	void setName(string name);
	void setSpeed(float speed);
	void setPrice(int price);

	string getName() const;
	float getSpeed() const;
	int getPrice() const;

	void calculateRoute(int path, float& time, int& totalPrice);
};

