#pragma once
#include <functional>
#include "Sportsman.h"

class Team
{
	std::string name;
	std::vector<std::shared_ptr<Sportsman>> members;

public:

	static inline const std::string MAIN_TEAM_FILE = "team.txt";
	static inline const std::string CURRENT_TEAM_FILE = "current.txt";

	Team(std::string_view name);

	auto GetName() const -> std::string_view;

	void AddSportsman(std::string_view role, const PersonalInfo& info, const Results& results);
	void AddSportsman(const std::shared_ptr<Sportsman>& s);
	void DeleteSportsman(std::string_view name);
	void AddMatchToSportsman(const std::string& name, const std::shared_ptr<Match>& match);
	void RemoveMatch(const Match* matchAddress);
	void Clear();

	auto GetSportsman(const std::string& name) const -> const std::shared_ptr<Sportsman>&;
	auto GetSize() const -> int;

	auto begin() -> std::vector<std::shared_ptr<Sportsman>>::iterator;
	auto begin() const ->std::vector<std::shared_ptr<Sportsman>>::const_iterator;
	auto end() -> std::vector<std::shared_ptr<Sportsman>>::iterator;
	auto end() const -> std::vector<std::shared_ptr<Sportsman>>::const_iterator;

	void Sort(const std::function<bool(const std::shared_ptr<Sportsman>&,const std::shared_ptr<Sportsman>&)>& criteria);

	void SaveToFile(const std::string& fileName);
	void ReadFromFile(const std::vector<std::shared_ptr<Match>>& matches);
	void ReadFromFile(const Team& main);

	static bool ByNameAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByNameDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByRoleAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByRoleDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByAgeAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByAgeDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByHeightAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByHeightDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByWeightAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByWeightDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByGoalsAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByGoalsDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByAssistsAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByAssistsDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByLastMatchAscendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
	static bool ByLastMatchDescendingly(const std::shared_ptr<Sportsman>& s1, const std::shared_ptr<Sportsman>& s2);
};

