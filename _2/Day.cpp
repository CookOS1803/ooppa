#include "Day.h"

Day::Day()
{
	setName("");
	setSchedule(nullptr, 0);
}

Day::Day(string name, int n)
{
	setName(name);
	setSchedule(new string[n], n);
}

Day::Day(string name, string* schedule, int n)
{
	setName(name);
	setSchedule(schedule, n);
}

Day::~Day()
{
	delete[] schedule;
}

int Day::getAmount() const
{
	return n;
}

const string& Day::getCourse(int i) const
{
	return schedule[i];
}

const string& Day::getName() const
{
	return name;
}

void Day::setSchedule(string* schedule, int n)
{
	this->schedule = schedule;
	this->n = n;
}

void Day::setCourse(int i, string course)
{
	schedule[i] = course;
}

void Day::setName(string name)
{
	this->name = name;
}
