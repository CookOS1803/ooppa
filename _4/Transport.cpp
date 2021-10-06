#include "Transport.h"

Transport::Transport()
{
	setName("");
	setSpeed(0);
	setPrice(0);
}

Transport::Transport(string name, float speed, int price)
{
	setName(name);
	setSpeed(speed);
	setPrice(price);
}

void Transport::setName(string name)
{
	this->name = name;
}

void Transport::setSpeed(float speed)
{
	this->speed = speed;
}

void Transport::setPrice(int price)
{
	this->price = price;
}

string Transport::getName() const
{
	return name;
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
