#include <algorithm>
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
			MenuForCurrent(team, current, matches);
			break;
		case 3:
			MenuForMatches(team, matches);
			break;
		case 0:
			exit = true;
		}
	}
}

void MenuForTeam(Team& team, Team& current, const std::vector<std::shared_ptr<Match>>& matches)
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
			<< "3. ����� ����������� �� �����\n"
			<< "4. �������������\n"
			<< "5. �������� ����������\n"
			<< "6. ������� ����������\n"
			<< "7. �������� ����������\n"
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
			MenuForSportsmenFind(team, matches);
			break;
		case 4:
			MenuForSportsmenSort(team);
			break;
		case 5:
			AddSportsman_Task(team);
			break;
		case 6:
			DeleteSportsman_Task(team, current, matches);
			break;
		case 7:
			ChangeSportsman_Task(team, matches);
			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void MenuForSportsmenFind(const Team& team, const std::vector<std::shared_ptr<Match>>& matches)
{
	int choice;
	bool exit = false;
	std::string role;
	Team temp("temp");

	while (true)
	{
		INPUT
		(
			std::cout
			<< "1. ����� �� ����\n"
			<< "2. ����� �� ��������\n"
			<< "3. ����� �� �����\n"
			<< "4. ����� �� ����\n"
			<< "5. ����� �� ���������� �����\n"
			<< "6. ����� �� ���������� ������� �������\n"
			<< "7. ����� �� ������� � �����\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			std::cout << "������� ����: ";
			std::getline(std::cin, role);

			for (const auto& sp : team)
			{
				if (sp->GetRole() == role)
					temp.AddSportsman(sp);
			}

			break;
		case 2:
			INPUT_CONDITION
			(
				std::cout << "������� �������: ",
				choice,
				choice >= 0
			);

			for (const auto& sp : team)
			{
				if (sp->GetPersonalInfo().age == choice)
					temp.AddSportsman(sp);
			}

			break;
		case 3:
			INPUT_CONDITION
			(
				std::cout << "������� ����: ",
				choice,
				choice >= 0
			);

			for (const auto& sp : team)
			{
				if (sp->GetPersonalInfo().height == choice)
					temp.AddSportsman(sp);
			}

			break;
		case 4:
			INPUT_CONDITION
			(
				std::cout << "������� ���: ",
				choice,
				choice >= 0
			);

			for (const auto& sp : team)
			{
				if (sp->GetPersonalInfo().weight == choice)
					temp.AddSportsman(sp);
			}

			break;
		case 5:
			INPUT_CONDITION
			(
				std::cout << "������� ���������� �����: ",
				choice,
				choice >= 0
			);

			for (const auto& sp : team)
			{
				if (sp->GetResults().goals == choice)
					temp.AddSportsman(sp);
			}

			break;
		case 6:
			INPUT_CONDITION
			(
				std::cout << "������� ���������� ������� �������: ",
				choice,
				choice >= 0
			);

			for (const auto& sp : team)
			{
				if (sp->GetResults().assists == choice)
					temp.AddSportsman(sp);
			}

			break;
		case 7:
			ShowMatches(matches);
			INPUT_CONDITION
			(
				std::cout << "������� ����� �����: ",
				choice,
				choice > 0 and choice <= matches.size()
			);

			for (const auto& sp : team)
			{
				if (sp->HasMatch(matches[choice - 1].get()))
					temp.AddSportsman(sp);
			}

			break;
		case 0:
			exit = true;
			break;
		}

		if (exit)
			break;

		if (temp.GetSize() == 0)
			std::cout << "����� ����������� ���\n\n";
		else
		{
			ShowSportsmen_Task(temp);
			temp.Clear();
		}
	}
}

void MenuForSportsmenSort(Team& team)
{
	int choice, order;
	bool exit = false;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. ����������� �� �����\n"
			<< "2. ����������� �� ����\n"
			<< "3. ����������� �� ��������\n"
			<< "4. ����������� �� �����\n"
			<< "5. ����������� �� ����\n"
			<< "6. ����������� �� ���������� �����\n"
			<< "7. ����������� �� ���������� ������� �������\n"
			<< "8. ����������� �� ���� ���������� �����\n"
			<< "0. �����\n",
			choice
		);

		if (choice != 0)
			order = GetBinaryChoice();

		switch (choice)
		{
		case 1:
			if (order == 1)
				team.Sort(Team::ByNameAscendingly);
			else
				team.Sort(Team::ByNameDescendingly);

			break;
		case 2:
			if (order == 1)
				team.Sort(Team::ByRoleAscendingly);
			else
				team.Sort(Team::ByRoleDescendingly);

			break;
		case 3:
			if (order == 1)
				team.Sort(Team::ByAgeAscendingly);
			else
				team.Sort(Team::ByAgeDescendingly);
			
			break;
		case 4:
			if (order == 1)
				team.Sort(Team::ByHeightAscendingly);
			else
				team.Sort(Team::ByHeightDescendingly);

			break;
		case 5:
			if (order == 1)
				team.Sort(Team::ByWeightAscendingly);
			else
				team.Sort(Team::ByWeightDescendingly);

			break;
		case 6:
			if (order == 1)
				team.Sort(Team::ByGoalsAscendingly);
			else
				team.Sort(Team::ByGoalsDescendingly);

			break;
		case 7:
			if (order == 1)
				team.Sort(Team::ByAssistsAscendingly);
			else
				team.Sort(Team::ByAssistsDescendingly);

			break;
		case 8:
			if (order == 1)
				team.Sort(Team::ByLastMatchAscendingly);
			else
				team.Sort(Team::ByLastMatchDescendingly);

			break;
		case 0:
			exit = true;
			break;
		}
	}
}

int GetBinaryChoice()
{
	int choice;

	INPUT_CONDITION
	(
		std::cout
		<< "1. �� �����������\n"
		<< "2. �� ��������\n",
		choice,
		choice == 1 or choice == 2
	);

	return choice;
}

void ChangeSportsman_Task(Team& team, const std::vector<std::shared_ptr<Match>>& matches)
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

void MenuForSportsmanChange(std::shared_ptr<Sportsman>& sportsman, const std::vector<std::shared_ptr<Match>>& matches)
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
				choice >= 0
			);
			sportsman->SetAge(choice);

			break;
		case 4:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ����: ",
				choice,
				choice >= 0
			);
			sportsman->SetHeight(choice);

			break;
		case 5:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���: ",
				choice,
				choice >= 0
			);
			sportsman->SetWeight(choice);

			break;
		case 6:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���������� �����: ",
				choice,
				choice >= 0
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

void MenuForCurrent(Team& team, Team& current, const std::vector<std::shared_ptr<Match>>& matches)
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
			<< "3. ����� ����������� �� �����\n"
			<< "4. �������������\n"
			<< "5. �������� ���������� � ������\n"
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
			MenuForSportsmenFind(current, matches);
			break;
		case 4:
			MenuForSportsmenSort(current);
			break;
		case 5:
			AddToCurrent_Task(team, current);
			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void MenuForMatches(Team& team, std::vector<std::shared_ptr<Match>>& matches)
{
	int choice;
	bool exit = false;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. �������� �����\n"
			<< "2. ����� ����� �� �����\n"
			<< "3. �������������\n"
			<< "4. �������� ����\n"
			<< "5. ������� ����\n"
			<< "6. �������� ����\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			ShowMatches(matches);
			break;
		case 2:
			MenuForMatchesFind(matches);
			break;
		case 3:
			MenuForMatchesSort(matches);
			break;
		case 4:
			AddMatch_Task(team, matches);
			break;
		case 5:
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
		case 6:
			ShowMatches(matches);
			INPUT_CONDITION
			(
				std::cout << "������� ����� �����: ",
				choice,
				choice > 0 and choice <= matches.size(),
			);

			MenuForMatchChange(matches[choice - 1]);

			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void MenuForMatchesFind(const std::vector<std::shared_ptr<Match>>& matches)
{
	int choice;
	bool exit = false;
	std::string tempStr;
	std::vector<std::shared_ptr<Match>> tempMatches;

	while (true)
	{
		INPUT
		(
			std::cout
			<< "1. ����� �� �������� �������\n"
			<< "2. ����� �� ���� ����������\n"
			<< "3. ����� �� ����� ����� �������\n"
			<< "4. ����� �� ����� ������ �������\n"
			<< "5. ����� �� �������� ������ �������\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			std::cout << "������� �������� �������: ";
			std::getline(std::cin, tempStr);

			for (const auto& m : matches)
			{
				if (m->GetTournament() == tempStr)
					tempMatches.push_back(m);
			}

			break;
		case 2:
			std::cout << "������� ����: ";
			std::getline(std::cin, tempStr);

			try
			{
				Match match;
				match.SetDate(tempStr);
				tempStr = match.GetDate();
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << "\n";
				break;
			}

			for (const auto& m : matches)
			{
				if (m->GetDate() == tempStr)
					tempMatches.push_back(m);
			}

			break;
		case 3:
			INPUT_CONDITION
			(
				std::cout << "������� ����: ",
				choice,
				choice >= 0,
			);

			for (const auto& m : matches)
			{
				if (m->GetTeamOneScore().amount == choice)
					tempMatches.push_back(m);
			}

			break;
		case 4:
			INPUT_CONDITION
			(
				std::cout << "������� ����: ",
				choice,
				choice >= 0,
			);

			for (const auto& m : matches)
			{
				if (m->GetTeamTwoScore().amount == choice)
					tempMatches.push_back(m);
			}

			break;
		case 5:
			std::cout << "������� �������� ������ �������: ";
			std::getline(std::cin, tempStr);

			for (const auto& m : matches)
			{
				if (m->GetTeamTwoScore().name == tempStr)
					tempMatches.push_back(m);
			}

			break;
		case 0:
			exit = true;
			break;
		}

		if (exit)
			break;

		if (tempMatches.size() == 0)
			std::cout << "����� ������ ���\n\n";
		else
		{
			ShowMatches(tempMatches);
			tempMatches.clear();
		}
	}
}

void MenuForMatchesSort(std::vector<std::shared_ptr<Match>>& matches)
{
	int choice, order;
	bool exit = false;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. ����������� �� �������� �������\n"
			<< "2. ����������� �� ����\n"
			<< "3. ����������� �� ����� ����� �������\n"
			<< "4. ����������� �� ����� ������ �������\n"
			<< "5. ����������� �� �������� ������ �������\n"
			<< "0. �����\n",
			choice
		);

		if (choice != 0)
			order = GetBinaryChoice();

		switch (choice)
		{
		case 1:
			if (order == 1)
				std::sort(matches.begin(), matches.end(), Match::ByTournamentAscendingly);
			else
				std::sort(matches.begin(), matches.end(), Match::ByTournamentDescendingly);

			break;
		case 2:
			if (order == 1)
				std::sort(matches.begin(), matches.end(), Match::ByDateAscendingly);
			else
				std::sort(matches.begin(), matches.end(), Match::ByDateDescendingly);

			break;
		case 3:
			if (order == 1)
				std::sort(matches.begin(), matches.end(), Match::ByTeamOneScoreAscendingly);
			else
				std::sort(matches.begin(), matches.end(), Match::ByTeamOneScoreDescendingly);

			break;
		case 4:
			if (order == 1)
				std::sort(matches.begin(), matches.end(), Match::ByTeamTwoScoreAscendingly);
			else
				std::sort(matches.begin(), matches.end(), Match::ByTeamTwoScoreDescendingly);

			break;
		case 5:
			if (order == 1)
				std::sort(matches.begin(), matches.end(), Match::ByTeamTwoNameAscendingly);
			else
				std::sort(matches.begin(), matches.end(), Match::ByTeamTwoNameDescendingly);

			break;
		case 0:
			exit = true;
			break;
		}
	}
}

void MenuForMatchChange(std::shared_ptr<Match>& match)
{
	int choice;
	bool exit = false;
	std::string temp;

	while (!exit)
	{
		INPUT
		(
			std::cout
			<< "1. �������� �������� �������\n"
			<< "2. �������� ����\n"
			<< "3. �������� ���� ����� �������\n"
			<< "4. �������� ���� ������ �������\n"
			<< "5. �������� �������� ������ �������\n"
			<< "0. �����\n",
			choice
		);

		switch (choice)
		{
		case 1:
			std::cout << "������� ����� �������� �������: ";
			std::getline(std::cin, temp);

			match->SetTournament(temp);

			break;
		case 2:
			std::cout << "������� ����� ����: ";
			std::getline(std::cin, temp);

			try
			{
				match->SetDate(temp);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << "\n";
			}

			break;
		case 3:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���� ����� �������: ",
				choice,
				choice >= 0
			);

			match->SetTeamOneScoreAmount(choice);

			break;
		case 4:
			INPUT_CONDITION
			(
				std::cout << "������� ����� ���� ������ �������: ",
				choice,
				choice >= 0
			);

			match->SetTeamTwoScoreAmount(choice);

			break;
		case 5:
			std::cout << "������� ����� �������� ������ �������: ";
			std::getline(std::cin, temp);

			match->SetTeamTwoName(temp);

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

	std::cout << std::endl;
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

void DeleteSportsman_Task(Team& team, Team& current, const std::vector<std::shared_ptr<Match>>& matches)
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
