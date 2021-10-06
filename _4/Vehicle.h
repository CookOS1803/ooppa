#pragma once
#include "Transport.h"
class Vehicle : public Transport
{
public:
	void calculateRoute(int path, float& time, int& totalPrice);
};

