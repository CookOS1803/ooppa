#include "Drug.h"

Drug::Drug()
{
}

Drug::Drug(const Drug& other)
	: name(other.name), type(other.type), amount(other.amount)
{
}

auto Drug::GetName() const -> std::string_view
{
	return name;
}

auto Drug::GetType() const -> std::string_view
{
	return type;
}

auto Drug::GetAmount() const -> int
{
	return amount;
}

void Drug::SetName(std::string_view newName)
{
	name = newName;
}

void Drug::SetType(std::string_view newType)
{
	type = newType;
}

void Drug::SetAmount(int newAmount)
{
	amount = newAmount;
}
