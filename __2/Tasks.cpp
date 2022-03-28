#include "Tasks.h"
#include "Util.h"

void Menu(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches)
{
	int choice;
	bool exit = false;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. �������� ���� �����������\n"
			<< "2. �������� ����������� ����������\n"
			<< "3. �������� �����\n"
			<< "4. �������� ����������\n"
			<< "5. �������� ����\n"
			<< "6. �������� ���� ����������\n"
			<< "7. �������� ������ ��� ���������� �����\n"
			<< "8. �������� ���������� � ������ ��� ���������� �����\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			ShowSportsmen_Task(team);
			break;
		case 2:
			ShowOneSportsman_Task(team);
			break;
		case 3:
			ShowMatches(matches);
			break;
		case 4:
			AddSportsman_Task(team);
			break;
		case 5:
			AddMatch_Task(team, matches);
			break;
		case 6:
			AddMatchToSportsman_Task(team, matches);
			break;
		case 7:
			ShowSportsmen_Task(current);
			break;
		case 8:
			AddToCurrent_Task(team, current);
			break;
		case 0:
			exit = true;
		}
	}
}

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
	for (const auto& s : team)
	{
		std::cout << s->GetPersonalInfo().name << ", " << s->GetRole() << "\n";
	}
}

void ShowOneSportsman_Task(const Team& team)
{
	std::string name;

	std::cout << "������� ���: ";
	std::getline(std::cin, name);

	try
	{
		const auto& s = team.GetSportsman(name);
		ShowSportsman(*s);
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

	std::cout << "������� ���: ";
	std::getline(std::cin, info.name);

	INPUT_CONDITION
	(
		std::cout << "������� �������: ",
		info.age,
		info.age > 0
	);

	INPUT_CONDITION
	(
		std::cout << "������� ����: ",
		info.height,
		info.height > 0
	);

	INPUT_CONDITION
	(
		std::cout << "������� ���: ",
		info.weight,
		info.weight > 0
	);

	std::cout << "������� ����: ";
	std::getline(std::cin, role);

	INPUT_CONDITION
	(
		std::cout << "������� ���������� �����: ",
		results.goals,
		results.goals > 0
	);

	INPUT_CONDITION
	(
		std::cout << "������� ���������� ������� �������: ",
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

	std::cout << "������� �������� �������: ";
	std::getline(std::cin, tournament);

	std::cout << "������� ����: ";
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
		std::cout << "������� ���� ����� �������: ",
		choice,
		choice > 0
	);

	Score s1 = matches.back()->GetTeamOneScore();
	s1.amount = choice;
	matches.back()->SetTeamOneScore(s1);

	std::cout << "������� �������� ������ �������: ";
	std::getline(std::cin, tournament);

	INPUT_CONDITION
	(
		std::cout << "������� ���� ������ �������: ",
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

	std::cout << "������� ��� ����������: ";
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
		std::cout << "������� ����� �����: ",
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

void AddToCurrent_Task(const Team& team, Team& current)
{
	std::string name;

	std::cout << "������� ���: ";
	std::getline(std::cin, name);


	try
	{
		const auto& s = team.GetSportsman(name);
		current.AddSportsman(s);
	}
	catch (std::exception* e)
	{
		std::cout << e->what() << "\n";
		delete e;
	}
}
