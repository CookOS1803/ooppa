#include <functional>
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
			<< "1. �������\n"
			<< "2. ������ ��� ���������� �����\n"
			<< "3. �����\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			MenuForTeam(team, current, matches);
			break;
		case 2:
			MenuForCurrent(team, current);
			break;
		case 3:
			MenuForMatches(team, current, matches);
			break;
		case 0:
			exit = true;
		}
	}
}

void MenuForTeam(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches)
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
			<< "3. �������� ����������\n"
			<< "4. ������� ����������\n"
			<< "5. �������� ����������\n"
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
			AddSportsman_Task(team);
			break;
		case 4:
			DeleteSportsman_Task(team, current, matches);
			break;
		case 5:
			ChangeSportsman_Task(team, matches);
			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void ChangeSportsman_Task(Team& team, std::vector<std::shared_ptr<Match>>& matches)
{
	std::string name;

	std::cout << "������� ���: ";
	std::getline(std::cin, name);

	try
	{
		auto s = team.GetSportsman(name);
		MenuForSportsmanChange(s, matches);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n\n";
	}
}

void MenuForSportsmanChange(std::shared_ptr<Sportsman>& sportsman, std::vector<std::shared_ptr<Match>>& matches)
{
	int choice;
	bool exit = false;
	std::string temp;

	while (!exit)
	{
		ShowSportsman(*sportsman);

		INPUT
		(
			std::cout
			<< "1. �������� ���\n"
			<< "2. �������� ����\n"
			<< "3. �������� �������\n"
			<< "4. �������� ����\n"
			<< "5. �������� ���\n"
			<< "6. �������� ���������� �����\n"
			<< "7. �������� ���������� ������� �������\n"
			<< "8. �������� ����\n"
			<< "9. ������� ����\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			std::cout << "������� ����� ���: ";
			std::getline(std::cin, temp);
			sportsman->SetName(temp);

			break;
		case 2:
			std::cout << "������� ����� ����: ";
			std::getline(std::cin, temp);
			sportsman->SetRole(temp);

			break;
		case 3:
			INPUT_CONDITION
			(
				std::cout << "������� ����� �������: ",
				choice,
				choice >= 0,
			);
			sportsman->SetAge(choice);

			break;
		case 4:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ����: ",
				choice,
				choice >= 0,
			);
			sportsman->SetHeight(choice);

			break;
		case 5:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���: ",
				choice,
				choice >= 0,
			);
			sportsman->SetWeight(choice);

			break;
		case 6:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���������� �����: ",
				choice,
				choice >= 0,
			);
			sportsman->SetGoals(choice);

			break;
		case 7:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���������� ������� �������: ",
				choice,
				choice >= 0,
			);
			sportsman->SetAssists(choice);

			break;
		case 8:
			ShowMatches(matches);
			INPUT_CONDITION
			(
				std::cout << "������� ����� �����: ",
				choice,
				choice > 0 and choice <= matches.size(),
			);

			try
			{
				sportsman->AddMatch(matches[choice - 1]);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << "\n";
			}
			break;
		case 9:
		{
			const auto& sm = sportsman->GetPreviousMatches();

			ShowMatches(matches);
			INPUT_CONDITION
			(
				std::cout << "������� ����� �����: ",
				choice,
				choice > 0 and choice <= sm.size(),
			);

			sportsman->RemoveMatch(sm[choice - 1].get());
		}
			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void MenuForCurrent(Team& team, Team& current)
{
	int choice;
	bool exit = false;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. �������� ������\n"
			<< "2. �������� ����������� ����������\n"
			<< "3. �������� ���������� � ������\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			ShowSportsmen_Task(current);
			break;
		case 2:
			ShowOneSportsman_Task(current);
			break;
		case 3:
			AddToCurrent_Task(team, current);
			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void MenuForMatches(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches)
{
	int choice;
	bool exit = false;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. �������� �����\n"
			<< "2. �������� ����\n"
			<< "3. ������� ����\n"
			<< "4. �������� ����\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			ShowMatches(matches);
			break;
		case 2:
			AddMatch_Task(team, matches);
			break;
		case 3:
			ShowMatches(matches);
			INPUT_CONDITION
			(
				std::cout << "������� ����� �����: ",
				choice,
				choice > 0 and choice <= matches.size(),
			);

			team.RemoveMatch(matches[choice - 1].get());

			matches.erase(matches.begin() + choice - 1);

			break;
		case 0:
			exit = true;
			break;
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
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
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
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n\n";
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
		info.age >= 0
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
		results.goals >= 0
	);

	INPUT_CONDITION
	(
		std::cout << "������� ���������� ������� �������: ",
		results.assists,
		results.assists >= 0
	);

	team.AddSportsman(role, info, results);
}

void DeleteSportsman_Task(Team& team, Team& current, std::vector<std::shared_ptr<Match>>& matches)
{
	std::string name;

	std::cout << "������� ���: ";
	std::getline(std::cin, name);

	try
	{
		std::ignore = team.GetSportsman(name);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return;
	}

	team.DeleteSportsman(name);
	current.DeleteSportsman(name);
}

void AddMatch_Task(const Team& team, std::vector<std::shared_ptr<Match>>& matches)
{
	std::shared_ptr<Match> temp(new Match());
	std::string str;
	int choice;

	std::cout << "������� �������� �������: ";
	std::getline(std::cin, str);

	temp->SetTournament(str);

	std::cout << "������� ����: ";
	std::getline(std::cin, str);

	try
	{
		temp->SetDate(str);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return;
	}

	Score s;
	s.name = team.GetName();

	INPUT_CONDITION
	(
		std::cout << "������� ���� ����� �������: ",
		choice,
		choice >= 0
	);

	s.amount = choice;

	temp->SetTeamOneScore(s);

	std::cout << "������� �������� ������ �������: ";
	std::getline(std::cin, str);

	s.name = str;

	INPUT_CONDITION
	(
		std::cout << "������� ���� ������ �������: ",
		choice,
		choice >= 0
	);

	s.amount = choice;

	temp->SetTeamTwoScore(s);

	matches.push_back(temp);
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
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
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
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
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
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}
