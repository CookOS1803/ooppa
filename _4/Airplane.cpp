#include "Airplane.h"

void Airplane::calculateRoute(int path, float& time, int& totalPrice)
{
	Transport::calculateRoute(path, time, totalPrice);

	time *= 0.7f;
	totalPrice += price * path * 0.001f;
}