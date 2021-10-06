#include "Train.h"

void Train::calculateRoute(int path, float& time, int& totalPrice)
{
	Transport::calculateRoute(path, time, totalPrice);

	totalPrice += price * path * 0.003f;
}
