#pragma once
#include "Transport.h"
class Train : public Transport
{
public:

	Train();
	Train(float speed, int price);

	void calculateRoute(int path, float& time, int& totalPrice);
};

