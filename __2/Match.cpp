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
		throw WrongDateFormatException();


	const char* day = date.substr(0, 2).data();
	this->date.tm_mday = atoi(day);

	if (this->date.tm_mday < 1 or this->date.tm_mday > 31)
		throw WrongDateFormatException();


	const char* month = date.substr(3, 2).data();
	this->date.tm_mon = atoi(month) - 1;

	if (this->date.tm_mon < 0 or this->date.tm_mon > 11)
		throw WrongDateFormatException();


	const char* year = date.substr(6, 4).data();
	this->date.tm_year = atoi(year) - 1900;

	if (this->date.tm_year < 0)
		throw WrongDateFormatException();
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

auto Match::GetDateRaw() const -> const tm&
{
	return date;
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

void Match::SetTeamOneName(std::string_view name)
{
	teamOne.name = name;
}

void Match::SetTeamOneScoreAmount(int amount)
{
	teamOne.amount = amount;
}

void Match::SetTeamTwoScore(const Score& team)
{
	teamTwo = team;
}

void Match::SetTeamTwoName(std::string_view name)
{
	teamTwo.name = name;
}

void Match::SetTeamTwoScoreAmount(int amount)
{
	teamTwo.amount = amount;
}

bool Match::operator==(const Match& other) const
{
	return tournament == other.tournament and GetDate() == other.GetDate();
}

bool Match::ByTournamentAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTournament()[0] < m2->GetTournament()[0];
}

bool Match::ByTournamentDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTournament()[0] > m2->GetTournament()[0];
}

bool Match::ByDateAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	bool result =
		m1->GetDateRaw().tm_year < m2->GetDateRaw().tm_year ? true :
		m1->GetDateRaw().tm_mon < m2->GetDateRaw().tm_mon ? true :
		m1->GetDateRaw().tm_mday < m2->GetDateRaw().tm_mday;

	return result;
}

bool Match::ByDateDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	bool result =
		m1->GetDateRaw().tm_year > m2->GetDateRaw().tm_year ? true :
		m1->GetDateRaw().tm_mon > m2->GetDateRaw().tm_mon ? true :
		m1->GetDateRaw().tm_mday > m2->GetDateRaw().tm_mday;

	return result;
}

bool Match::ByTeamOneScoreAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTeamOneScore().amount < m2->GetTeamOneScore().amount;
}

bool Match::ByTeamOneScoreDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTeamOneScore().amount > m2->GetTeamOneScore().amount;
}

bool Match::ByTeamTwoScoreAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTeamTwoScore().amount < m2->GetTeamTwoScore().amount;
}

bool Match::ByTeamTwoScoreDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTeamTwoScore().amount > m2->GetTeamTwoScore().amount;
}

bool Match::ByTeamTwoNameAscendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTeamTwoScore().name[0] < m2->GetTeamTwoScore().name[0];
}

bool Match::ByTeamTwoNameDescendingly(const std::shared_ptr<Match>& m1, const std::shared_ptr<Match>& m2)
{
	return m1->GetTeamTwoScore().name[0] > m2->GetTeamTwoScore().name[0];
}

std::istream& operator>>(std::istream& in, Match& match)
{
	in >> match.tournament;

	std::string d;
	in >> d;
	match.SetDate(d);

	in >> match.teamOne.name >> match.teamOne.amount >> match.teamTwo.name >> match.teamTwo.amount;

	return in;
}

std::ostream& operator<<(std::ostream& out, const std::vector<std::shared_ptr<Match>>& matches)
{
	for (const auto& m : matches)
	{
		out << *m;
	}

	out << "&\n";

	return out;
}

std::istream& operator>>(std::istream& in, std::vector<std::shared_ptr<Match>>& matches)
{
	matches.clear();

	while (in.peek() != '&')
	{
		matches.emplace_back(std::make_shared<Match>());
		in >> *matches.back();
		
		std::ignore = in.get();
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Match& match)
{
	out << match.GetTournament() << ' ' << match.GetDate() << ' '
		<< match.GetTeamOneScore().name << ' ' << match.GetTeamOneScore().amount << ' '
		<< match.GetTeamTwoScore().name << ' ' << match.GetTeamTwoScore().amount << "\n";

	return out;
}
