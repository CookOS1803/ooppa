#include "Sportsman.h"

PersonalInfo::PersonalInfo()
{
}

PersonalInfo::PersonalInfo(std::string_view name, int age, int height, int weight)
	: name(name), age(age), height(height), weight(weight)
{
}

PersonalInfo::PersonalInfo(const PersonalInfo& other)
	: name(other.name), age(other.age), height(other.height), weight(other.weight)
{
}

Results::Results()
{
}

Results::Results(int goals, int assists)
	: goals(goals), assists(assists)
{
}

Results::Results(const Results& other)
	: goals(other.goals), assists(other.assists)
{
}

Sportsman::Sportsman()
{
}

Sportsman::Sportsman(std::string_view role, const PersonalInfo& info, const Results& results)
	: role(role), info(info), results(results)
{
}

Sportsman::Sportsman(const Sportsman& other)
	: role(other.role), info(other.info), results(other.results)
{
}

auto Sportsman::GetPreviousMatches() const -> const std::vector<std::shared_ptr<Match>>&
{
	return previousMatches;
}

auto Sportsman::GetRole() const -> std::string_view
{
	return role;
}

auto Sportsman::GetPersonalInfo() const -> const PersonalInfo&
{
	return info;
}

auto Sportsman::GetResults() const -> const Results&
{
	return results;
}

void Sportsman::SetName(std::string_view name)
{
	info.name = name;
}

void Sportsman::SetAge(int age)
{
	info.age = age;
}

void Sportsman::SetHeight(int height)
{
	info.height = height;
}

void Sportsman::SetWeight(int weight)
{
	info.weight = weight;
}

void Sportsman::SetGoals(int goals)
{
	results.goals = goals;
}

void Sportsman::SetAssists(int assists)
{
	results.assists = assists;
}

void Sportsman::SetRole(std::string_view role)
{
	this->role = role;
}

void Sportsman::AddMatch(const std::shared_ptr<Match>& match)
{
	previousMatches.push_back(match);
}
