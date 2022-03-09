#pragma once
#include "UserInput.h"
#include "Util.h"
#include "Team.h"

void CreateMatches_Task(std::vector<std::shared_ptr<Match>>& matches)
{
	matches.emplace_back
	(
		new Match
		(
			"turik",
			"22.01.2022",
			{ "komanda", 1 },
			{ "team", 2 }
		)
	);
	matches.emplace_back
	(
		new Match
		(
			"turik",
			"24.01.2022",
			{ "komanda", 3 },
			{ "ktoto", 0 }
		)
	);
}

void CreateTeam_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches)
{
	team.AddSportsman
	(
		"napadayuschiy",
		{
			"nikita",
			18,
			180,
			80
		},
		{
			4,
			3
		}
	);
	team.AddSportsman
	(
		"zashitnik",
		{
			"andryuha",
			20,
			170,
			75
		},
		{
			1,
			2
		}
	);

	try
	{
		team.AddMatchToSportsman("nikita", matches[0]);
		team.AddMatchToSportsman("nikita", matches[1]);
		team.AddMatchToSportsman("andryuha", matches[1]);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n";
		delete e;
	}
}

void ShowSportsmen_Task(const Team& team)
{
	for (const Sportsman& s : team)
	{
		std::cout << s.GetPersonalInfo().name << ", " << s.GetRole() << "\n";
	}
}

void ShowOneSportsman_Task(const Team& team)
{
	std::string name;

	std::cout << "¬ведите им€: ";
	std::getline(std::cin, name);

	try
	{
		const Sportsman& s = team.GetSportsman(name);
		ShowSportsman(s);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n\n";
		delete e;
	}

}

void AddSportsman_Task(Team& team)
{
	std::string role;
	PersonalInfo info;
	Results results;

	std::cout << "¬ведите им€: ";
	std::getline(std::cin, info.name);

	INPUT_CONDITION
	(
		std::cout << "¬ведите возраст: ",
		info.age,
		info.age > 0
	);

	INPUT_CONDITION
	(
		std::cout << "¬ведите рост: ",
		info.height,
		info.height > 0
	);

	INPUT_CONDITION
	(
		std::cout << "¬ведите вес: ",
		info.weight,
		info.weight > 0
	);

	std::cout << "¬ведите роль: ";
	std::getline(std::cin, role);

	INPUT_CONDITION
	(
		std::cout << "¬ведите количество голов: ",
		results.goals,
		results.goals > 0
	);

	INPUT_CONDITION
	(
		std::cout << "¬ведите количество голевых передач: ",
		results.assists,
		results.assists > 0
	);

	team.AddSportsman(role, info, results);
}

void AddMatch_Task(const Team& team, std::vector<std::shared_ptr<Match>>& matches)
{
	std::string tournament;
	std::string date;
	int choice;

	std::cout << "¬ведите название турнира: ";
	std::getline(std::cin, tournament);

	std::cout << "¬ведите дату: ";
	std::getline(std::cin, date);

	try
	{
		matches.emplace_back
		(
			new Match
			(
				tournament,
				date,
				{ team.GetName(), -1 },
				{ "", 2 }
			)
		);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n";
		delete e;
		return;
	}

	INPUT_CONDITION
	(
		std::cout << "¬ведите счЄт вашей команды: ",
		choice,
		choice > 0
	);
	
	Score s1 = matches.back()->GetTeamOneScore();
	s1.amount = choice;
	matches.back()->SetTeamOneScore(s1);

	std::cout << "¬ведите название другой команды: ";
	std::getline(std::cin, tournament);

	INPUT_CONDITION
	(
		std::cout << "¬ведите счЄт другой команды: ",
		choice,
		choice > 0
	);

	Score s2 = matches.back()->GetTeamTwoScore();
	s2.name = tournament;
	s2.amount = choice;
	matches.back()->SetTeamOneScore(s2);
}

void AddMatchToSportsman_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches)
{
	ShowMatches(matches);
	
	std::string name;
	int choice;

	std::cout << "¬ведите им€ спортсмена: ";
	std::getline(std::cin, name);

	try
	{
		std::ignore = team.GetSportsman(name);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n";
		delete e;
		return;
	}

	INPUT_CONDITION
	(
		std::cout << "¬ведите номер матча: ",
		choice,
		choice >= 1 and choice <= matches.size()
	);

	try
	{
		team.AddMatchToSportsman(name, matches[choice - 1]);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n";
		delete e;
	}
}

void AddToCurrent(const Team& team, Team& current)
{
	std::string name;

	std::cout << "¬ведите им€: ";
	std::getline(std::cin, name);


	try
	{
		const Sportsman& s = team.GetSportsman(name);
		current.AddSportsman(s);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n";
		delete e;
	}
}