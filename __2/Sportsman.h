#pragma once
#include <vector>
#include <memory>
#include "Match.h"

struct PersonalInfo
{
	std::string name;
	int age;
	int height;
	int weight;

	PersonalInfo();
	PersonalInfo(std::string_view name, int age, int height, int weight);
	PersonalInfo(const PersonalInfo& other);
};

struct Results
{
	int goals;
	int assists;

	Results();
	Results(int goals, int assists);
	Results(const Results& other);
};

class Sportsman
{
	std::vector<std::weak_ptr<Match>> previousMatches;
	std::string role;
	PersonalInfo info;
	Results results;

public:

	Sportsman();
	Sportsman(std::string_view role, const PersonalInfo& info, const Results& results);
	Sportsman(const Sportsman& other);

	auto GetPreviousMatches() const -> const std::vector<std::weak_ptr<Match>>&;
	auto GetRole() const -> std::string_view;
	auto GetPersonalInfo() const -> const PersonalInfo&;
	auto GetResults() const -> const Results&;

	void AddMatch(const std::weak_ptr<Match>& match);
};