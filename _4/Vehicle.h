#pragma once
#include "Transport.h"
class Vehicle : public Transport
{
public:

	Vehicle();
	Vehicle(float speed, int price);

	void calculateRoute(int path, float& time, int& totalPrice);
};

