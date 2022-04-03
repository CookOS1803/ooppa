#include <algorithm>
#include "Sportsman.h"
#include "DuplicateMatchException.h"

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

auto Sportsman::GetLastMatch() const -> const std::shared_ptr<Match>&
{
	std::shared_ptr<Match> result(new Match);
	result->SetDate("12.12.9999");

	for (const auto& m : previousMatches)
	{
		if (m->GetDateRaw().tm_year < result->GetDateRaw().tm_year)
			result = m;
		else if (m->GetDateRaw().tm_mon < result->GetDateRaw().tm_mon)
			result = m;
		else if (m->GetDateRaw().tm_mday < result->GetDateRaw().tm_mday)
			result = m;
	}

	return result;
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

bool Sportsman::HasMatch(const Match* matchAddress)
{
	auto it = find_if(previousMatches.begin(), previousMatches.end(),
		[matchAddress](const std::shared_ptr<Match>& m) { return m.get() == matchAddress; });

	return it != previousMatches.end();
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
	for (const auto& m : previousMatches)
	{
		if (m.get() == match.get())
		{
			throw DuplicateMatchException();
		}
	}

	previousMatches.push_back(match);
}

void Sportsman::RemoveMatch(const Match* matchAddress)
{
	auto it = find_if(previousMatches.begin(), previousMatches.end(),
		[matchAddress](const std::shared_ptr<Match>& m) { return m.get() == matchAddress; });

	if (it != previousMatches.end())
		previousMatches.erase(it);
}
