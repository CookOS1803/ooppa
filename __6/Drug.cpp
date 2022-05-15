#include "Drug.h"

Drug::Drug()
{
}

Drug::Drug(std::string_view name, std::string_view type, int amount)
	: id(0), name(name), type(type), amount(amount)
{
}

Drug::Drug(const Drug& other)
	: id(other.id), name(other.name), type(other.type), amount(other.amount)
{
}

auto Drug::GetID() const -> int
{
	return id;
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

void Drug::SetID(int newID)
{
	id = newID;
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
