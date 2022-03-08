#include "Team.h"

Team::Team(std::string_view name)
	: name(name)
{
}

auto Team::GetName() const -> std::string_view
{
	return name;
}

auto Team::begin() -> std::vector<Sportsman>::iterator
{
	return members.begin();
}

auto Team::begin() const -> std::vector<Sportsman>::const_iterator
{
	return members.begin();
}

auto Team::end() -> std::vector<Sportsman>::iterator
{
	return members.end();
}

auto Team::end() const -> std::vector<Sportsman>::const_iterator
{
	return members.end();
}
