#include "Transport.h"

Transport::Transport()
{
	setSpeed(0);
	setPrice(0);
}

Transport::Transport(float speed, int price)
{
	setSpeed(speed);
	setPrice(price);
}

void Transport::setSpeed(float speed)
{
	this->speed = speed;
}

void Transport::setPrice(int price)
{
	this->price = price;
}

float Transport::getSpeed() const
{
	return speed;
}

int Transport::getPrice() const
{
	return price;
}

void Transport::calculateRoute(int path, float& time, int& totalPrice)
{
	time = path / speed;
	totalPrice = price;
}
