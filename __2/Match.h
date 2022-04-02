#pragma once
#include <string>
#include <string_view>
#include <ctime>

struct Score
{
	std::string name;
	int amount;

	Score();
	Score(std::string_view name, int amount);
	Score(const Score& other);
};

class Match
{
	std::string tournament;
	tm date;
	Score teamOne;
	Score teamTwo;

public:

	Match();
	Match(const Match& other);
	Match(std::string_view tournament, std::string_view date, const Score& teamOne, const Score& teamTwo);

	auto GetTournament() const -> std::string_view;
	auto GetDate() const -> std::string;
	auto GetTeamOneScore() const -> const Score&;
	auto GetTeamTwoScore() const -> const Score&;

	void SetTournament(std::string_view tournament);
	void SetDate(std::string_view date);
	void SetTeamOneScore(const Score& team);
	void SetTeamOneName(std::string_view name);
	void SetTeamOneScoreAmount(int amount);
	void SetTeamTwoScore(const Score& team);
	void SetTeamTwoName(std::string_view name);
	void SetTeamTwoScoreAmount(int amount);
};

