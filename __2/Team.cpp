#include <algorithm>
#include "Team.h"
#include "WrongMemberNameException.h"
#include "DuplicateMatchException.h"
#include "DuplicateMemberException.h"

Team::Team(std::string_view name)
	: name(name)
{
}

auto Team::GetName() const -> std::string_view
{
	return name;
}

void Team::AddSportsman(std::string_view role, const PersonalInfo& info, const Results& results)
{
	members.emplace_back(new Sportsman(role, info, results));
}

void Team::AddSportsman(const std::shared_ptr<Sportsman>& s)
{
	for (const auto& m : members)
	{
		if (m->GetPersonalInfo().name == s->GetPersonalInfo().name)
		{
			throw DuplicateMemberException();
		}
	}

	members.push_back(s);
}

void Team::DeleteSportsman(std::string_view name)
{
	auto it = std::find_if(members.begin(), members.end(), 
		[name](const std::shared_ptr<Sportsman>& p) { return p->GetPersonalInfo().name == name; });

	if (it != members.end())
		members.erase(it);
}

void Team::AddMatchToSportsman(const std::string& name, const std::shared_ptr<Match>& match)
{
	for (auto& s : members)
	{
		if (s->GetPersonalInfo().name == name)
		{			
			s->AddMatch(match);
			return;
		}
	}

	throw WrongMemberNameException(name);
}

void Team::RemoveMatch(const Match* matchAddress)
{
	for (auto& sp : members)
	{
		sp->RemoveMatch(matchAddress);
	}
}

void Team::Clear()
{
	members.clear();
}

auto Team::GetSportsman(const std::string& name) const -> const std::shared_ptr<Sportsman>&
{
	for (const auto& s : members)
	{
		if (s->GetPersonalInfo().name == name)
		{
			return s;
		}
	}

	throw WrongMemberNameException(name);
}

auto Team::GetSize() const -> int
{
	return members.size();
}

auto Team::begin() -> std::vector<std::shared_ptr<Sportsman>>::iterator
{
	return members.begin();
}

auto Team::begin() const -> std::vector<std::shared_ptr<Sportsman>>::const_iterator
{
	return members.begin();
}

auto Team::end() -> std::vector<std::shared_ptr<Sportsman>>::iterator
{
	return members.end();
}

auto Team::end() const -> std::vector<std::shared_ptr<Sportsman>>::const_iterator
{
	return members.end();
}

void Team::Sort(const std::function<bool(const std::shared_ptr<Sportsman>&, const std::shared_ptr<Sportsman>&)>& criteria)
{
	std::sort(members.begin(), members.end(), criteria);
}

bool Team::ByNameAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().name[0] < s2->GetPersonalInfo().name[0];
}

bool Team::ByNameDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().name[0] > s2->GetPersonalInfo().name[0];
}

bool Team::ByRoleAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetRole()[0] > s2->GetRole()[0];
}

bool Team::ByRoleDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetRole()[0] < s2->GetRole()[0];
}

bool Team::ByAgeAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().age < s2->GetPersonalInfo().age;
}

bool Team::ByAgeDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().age > s2->GetPersonalInfo().age;
}

bool Team::ByHeightAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().height < s2->GetPersonalInfo().height;
}

bool Team::ByHeightDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().height > s2->GetPersonalInfo().height;
}

bool Team::ByWeightAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().weight < s2->GetPersonalInfo().weight;
}

bool Team::ByWeightDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetPersonalInfo().weight > s2->GetPersonalInfo().weight;
}

bool Team::ByGoalsAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetResults().goals < s2->GetResults().goals;
}

bool Team::ByGoalsDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetResults().goals > s2->GetResults().goals;
}

bool Team::ByAssistsAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetResults().assists < s2->GetResults().assists;
}

bool Team::ByAssistsDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	return s1->GetResults().assists > s2->GetResults().assists;
}

bool Team::ByLastMatchAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	auto m1 = s1->GetLastMatch();
	auto m2 = s2->GetLastMatch();

	bool result =
		m1->GetDateRaw().tm_year < m2->GetDateRaw().tm_year ? true :
		m1->GetDateRaw().tm_mon < m2->GetDateRaw().tm_mon ? true :
		m1->GetDateRaw().tm_mday < m2->GetDateRaw().tm_mday;

	return result;
}

bool Team::ByLastMatchDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2)
{
	auto m1 = s1->GetLastMatch();
	auto m2 = s2->GetLastMatch();

	bool result =
		m1->GetDateRaw().tm_year > m2->GetDateRaw().tm_year ? true :
		m1->GetDateRaw().tm_mon > m2->GetDateRaw().tm_mon ? true :
		m1->GetDateRaw().tm_mday > m2->GetDateRaw().tm_mday;

	return result;
}