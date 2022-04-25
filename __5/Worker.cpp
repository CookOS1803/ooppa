#include "Worker.h"

Worker::Worker()
{
}

Worker::Worker(std::string_view name, std::string_view phoneNumber, int salary, int experience)
	: name(name), phoneNumber(phoneNumber), salary(salary), experience(experience)
{
}

Worker::Worker(const Worker& other)
	: id(other.id), name(other.name), phoneNumber(other.phoneNumber), salary(other.salary), experience(other.experience)
{
}

auto Worker::GetID() const -> int
{
	return id;
}

auto Worker::GetName() const -> std::string_view
{
	return name;
}

auto Worker::GetPhoneNumber() const -> std::string_view
{
	return phoneNumber;
}

auto Worker::GetSalary() const -> int
{
	return salary;
}

auto Worker::GetExperience() const -> int
{
	return experience;
}

void Worker::SetID(int newID)
{
	id = newID;
}

void Worker::SetName(std::string_view newName)
{
	name = newName;
}

void Worker::SetPhoneNumber(std::string_view newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

void Worker::SetSalary(int newSalary)
{
	salary = newSalary;
}

void Worker::SetExperience(int newExperience)
{
	experience = newExperience;
}
