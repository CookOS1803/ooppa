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

void Team::AddMatchToSportsman(const std::string& name, const std::shared_ptr<Match>& match)
{
	for (auto& s : members)
	{
		if (s->GetPersonalInfo().name == name)
		{
			for (const auto& m : s->GetPreviousMatches())
			{
				if (m.get() == match.get())
				{
					throw DuplicateMatchException();
				}
			}

			s->AddMatch(match);
			return;
		}
	}

	throw WrongMemberNameException(name);
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
