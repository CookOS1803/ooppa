#pragma once
#include "Sportsman.h"

class Team
{
	std::string name;
	std::vector<Sportsman> members;

public:

	Team(std::string_view name);

	auto GetName() const -> std::string_view;

	auto begin() -> std::vector<Sportsman>::iterator;
	auto begin() const -> std::vector<Sportsman>::const_iterator;
	auto end() -> std::vector<Sportsman>::iterator;
	auto end() const -> std::vector<Sportsman>::const_iterator;
};

