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

auto Sportsman::GetPreviousMatches() const -> const std::vector<std::weak_ptr<Match>>&
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

void Sportsman::AddMatch(const std::weak_ptr<Match>& match)
{
	previousMatches.push_back(match);
}
