#pragma once
#include "Sportsman.h"


class Team
{
	std::string name;
	std::vector<Sportsman> members;

public:

	Team(std::string_view name);

	auto GetName() const -> std::string_view;

	void AddSportsman(std::string_view role, const PersonalInfo& info, const Results& results);
	void AddSportsman(const Sportsman& s);
	void AddMatchToSportsman(const std::string& name, std::weak_ptr<Match> match);

	auto GetSportsman(const std::string& name) const -> const Sportsman&; 

	auto begin() -> std::vector<Sportsman>::iterator;
	auto begin() const -> std::vector<Sportsman>::const_iterator;
	auto end() -> std::vector<Sportsman>::iterator;
	auto end() const -> std::vector<Sportsman>::const_iterator;
};

