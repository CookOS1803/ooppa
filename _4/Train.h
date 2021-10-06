#pragma once
#include "Transport.h"
class Train : public Transport
{
public:
	void calculateRoute(int path, float& time, int& totalPrice);
};

