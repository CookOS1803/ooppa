#pragma once
#include <string>

class Drug
{
	int id = 0;
	std::string name;
	std::string type;
	int amount = 0;

public:

	Drug();
	Drug(std::string_view name, std::string_view type, int amount);
	Drug(const Drug& other);

	auto GetID() const -> int;
	auto GetName() const -> std::string_view;
	auto GetType() const -> std::string_view;
	auto GetAmount() const -> int;

	void SetID(int newID);
	void SetName(std::string_view newName);
	void SetType(std::string_view newType);
	void SetAmount(int newAmount);
};
