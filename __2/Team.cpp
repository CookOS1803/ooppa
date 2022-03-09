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
	members.emplace_back(role, info, results);
}

void Team::AddSportsman(const Sportsman& s)
{
	for (const auto& m : members)
	{
		if (m.GetPersonalInfo().name == s.GetPersonalInfo().name)
		{
			throw new DuplicateMemberException;
		}
	}

	members.push_back(s);
}

void Team::AddMatchToSportsman(const std::string& name, std::weak_ptr<Match> match)
{
	for (Sportsman& s : members)
	{
		if (s.GetPersonalInfo().name == name)
		{
			for (const auto& m : s.GetPreviousMatches())
			{
				if (m.lock().get() == match.lock().get())
				{
					throw new DuplicateMatchException;
				}
			}

			s.AddMatch(match);
			return;
		}
	}

	throw new WrongMemberNameException(name);
}

auto Team::GetSportsman(const std::string& name) const -> const Sportsman&
{
	for (const Sportsman& s : members)
	{
		if (s.GetPersonalInfo().name == name)
		{
			return s;
		}
	}

	throw new WrongMemberNameException(name);
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
