#pragma once
#include <string>

class Drug
{
	std::string name;
	std::string type;
	int amount = 0;

public:

	Drug();
	Drug(const Drug& other);

	auto GetName() const -> std::string_view;
	auto GetType() const -> std::string_view;
	auto GetAmount() const -> int;

	void SetName(std::string_view newName);
	void SetType(std::string_view newType);
	void SetAmount(int newAmount);
};
