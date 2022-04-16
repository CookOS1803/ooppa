#pragma once
#include <string>
#include <string_view>
#include <ctime>
#include <memory>
#include <iostream>
#include <vector>

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
	auto GetDateRaw() const -> const tm&;
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

	bool operator==(const Match& other) const;
	
	static bool ByTournamentAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTournamentDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByDateAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByDateDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTeamOneScoreAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTeamOneScoreDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTeamTwoScoreAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTeamTwoScoreDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTeamTwoNameAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);
	static bool ByTeamTwoNameDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2);

	static inline const std::string FILE_NAME = "matches.txt";

	friend std::istream& operator>>(std::istream& in, Match& match);
};

std::ostream& operator<<(std::ostream& out, const std::vector<std::shared_ptr<Match>>& matches);
std::istream& operator>>(std::istream& in, std::vector<std::shared_ptr<Match>>& matches);
std::ostream& operator<<(std::ostream& out, const Match& match);