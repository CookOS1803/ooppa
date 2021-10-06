#include "Train.h"

Train::Train() : Transport()
{
}

Train::Train(float speed, int price) : Transport(speed, price)
{
}

void Train::calculateRoute(int path, float& time, int& totalPrice)
{
	Transport::calculateRoute(path, time, totalPrice);

	totalPrice += price * path * 0.003f;
}
