#pragma once
#include <string>

class Worker
{
	int id = 0;
	std::string name;
	std::string phoneNumber;
	int salary = 0;
	int experience = 0;

public:

	Worker();
	Worker(std::string_view name, std::string_view phoneNumber, int salary, int experience);
	Worker(const Worker& other);

	auto GetID() const -> int;
	auto GetName() const -> std::string_view;
	auto GetPhoneNumber() const -> std::string_view;
	auto GetSalary() const -> int;
	auto GetExperience() const -> int;

	void SetID(int newID);
	void SetName(std::string_view newName);
	void SetPhoneNumber(std::string_view newPhoneNumber);
	void SetSalary(int newSalary);
	void SetExperience(int newExperience);
};

