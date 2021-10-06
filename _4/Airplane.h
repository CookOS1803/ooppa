#pragma once
#include "Transport.h"
class Airplane : public Transport
{
public:

	Airplane();
	Airplane(float speed, int price);

	void calculateRoute(int path, float& time, int& totalPrice);
};

