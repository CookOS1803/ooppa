#pragma once
#include "Sportsman.h"


class Team
{
	std::string name;
	std::vector<std::shared_ptr<Sportsman>> members;

public:

	Team(std::string_view name);

	auto GetName() const -> std::string_view;

	void AddSportsman(std::string_view role, const PersonalInfo& info, const Results& results);
	void AddSportsman(const std::shared_ptr<Sportsman>& s);
	void DeleteSportsman(std::string_view name);
	void AddMatchToSportsman(const std::string& name, const std::shared_ptr<Match>& match);
	void RemoveMatch(const Match* matchAddress);

	auto GetSportsman(const std::string& name) const -> const std::shared_ptr<Sportsman>&;

	auto begin() -> std::vector<std::shared_ptr<Sportsman>>::iterator;
	auto begin() const ->std::vector<std::shared_ptr<Sportsman>>::const_iterator;
	auto end() -> std::vector<std::shared_ptr<Sportsman>>::iterator;
	auto end() const -> std::vector<std::shared_ptr<Sportsman>>::const_iterator;
};

