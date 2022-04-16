#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Match.h"

struct PersonalInfo
{
	std::string name = "";
	int age = 18;
	int height = 180;
	int weight = 80;

	PersonalInfo();
	PersonalInfo(std::string_view name, int age, int height, int weight);
	PersonalInfo(const PersonalInfo& other);
};

struct Results
{
	int goals = 0;
	int assists = 0;

	Results();
	Results(int goals, int assists);
	Results(const Results& other);
};

class Sportsman
{
	std::vector<std::shared_ptr<Match>> previousMatches;
	std::string role;
	PersonalInfo info;
	Results results;

public:

	Sportsman();
	Sportsman(std::string_view role, const PersonalInfo& info, const Results& results);
	Sportsman(const Sportsman& other);

	auto GetPreviousMatches() const -> const std::vector<std::shared_ptr<Match>>&;
	auto GetLastMatch() const -> const std::shared_ptr<Match>&;
	auto GetRole() const -> std::string_view;
	auto GetPersonalInfo() const -> const PersonalInfo&;
	auto GetResults() const -> const Results&;
	
	bool HasMatch(const Match* matchAddress);

	void SetName(std::string_view name);
	void SetAge(int age);
	void SetHeight(int height);
	void SetWeight(int weight);

	void SetGoals(int goals);
	void SetAssists(int assists);

	void SetRole(std::string_view role);

	void AddMatch(const std::shared_ptr<Match>& match);
	void RemoveMatch(const Match* matchAddress);

	friend std::istream& operator>>(std::istream& in, Sportsman& sportsman);
};

std::ostream& operator<<(std::ostream& out, const Sportsman& sportsman);