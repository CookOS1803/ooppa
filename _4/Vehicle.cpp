#include "Vehicle.h"

Vehicle::Vehicle() : Transport()
{
}

Vehicle::Vehicle(float speed, int price) : Transport(speed, price)
{
}

void Vehicle::calculateRoute(int path, float& time, int& totalPrice)
{
	Transport::calculateRoute(path, time, totalPrice);

	time *= 1.2f;
	totalPrice += price * path * 0.006f;
}
