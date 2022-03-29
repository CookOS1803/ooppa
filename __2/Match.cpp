#include "Match.h"
#include "WrongDateFormatException.h"

Score::Score()
	: name(""), amount(0)
{
}

Score::Score(std::string_view name, int amount)
	: name(name), amount(amount)
{
}

Score::Score(const Score& other)
	: name(other.name), amount(other.amount)
{
}

Match::Match()
{
}

Match::Match(const Match& other)
	: tournament(other.tournament), teamOne(other.teamOne), teamTwo(other.teamTwo), date(other.date)
{
}

Match::Match(std::string_view tournament, std::string_view date, const Score& teamOne, const Score& teamTwo)
	: tournament(tournament), teamOne(teamOne), teamTwo(teamTwo)
{
	SetDate(date);
}

void Match::SetDate(std::string_view date)
{
	if (date.size() != 10)
		throw new WrongDateFormatException;


	const char* day = date.substr(0, 2).data();
	this->date.tm_mday = atoi(day);

	if (this->date.tm_mday < 1 or this->date.tm_mday > 31)
		throw new WrongDateFormatException;


	const char* month = date.substr(3, 2).data();
	this->date.tm_mon = atoi(month) - 1;

	if (this->date.tm_mon < 0 or this->date.tm_mon > 11)
		throw new WrongDateFormatException;


	const char* year = date.substr(6, 4).data();
	this->date.tm_year = atoi(year) - 1900;

	if (this->date.tm_year < 0)
		throw new WrongDateFormatException;
}

auto Match::GetTournament() const -> std::string_view
{
	return tournament;
}

auto Match::GetDate() const -> std::string
{
	char buffer[11];
	strftime(buffer, 11, "%d.%m.%Y", &date);

	return buffer;
}

auto Match::GetTeamOneScore() const -> const Score&
{
	return teamOne;
}

auto Match::GetTeamTwoScore() const -> const Score&
{
	return teamTwo;
}

void Match::SetTournament(std::string_view tournament)
{
	this->tournament = tournament;
}

void Match::SetTeamOneScore(const Score& team)
{
	teamOne = team;
}

void Match::SetTeamTwoScore(const Score& team)
{
	teamTwo = team;
}
