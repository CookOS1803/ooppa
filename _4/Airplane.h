#pragma once
#include "Transport.h"
class Airplane : public Transport
{
public:
	void calculateRoute(int path, float& time, int& totalPrice);
};

