#pragma once
#include <iostream>
#include <iomanip>
#include "Sportsman.h"

std::ostream& table(std::ostream& stream)
{
	stream << std::setw(15);
	return stream;
}

void ShowMatches(const std::vector<std::shared_ptr<Match>>& matches)
{
	std::cout << std::left;

	std::cout << "   " << table << "������" << table << "����" << std::right << std::setw(19) << "����\n" << std::left;

	for (int i = 0; i < matches.size(); i++)
	{
		std::cout
			<< i + 1 << ". "
			<< table << matches[i]->GetTournament()
			<< table << matches[i]->GetDate()
			<< std::right << std::setw(13) << matches[i]->GetTeamOneScore().name << " "
			<< matches[i]->GetTeamOneScore().amount << " : "
			<< std::left << matches[i]->GetTeamTwoScore().amount << " "
			<< matches[i]->GetTeamTwoScore().name
			<< "\n";
	}

	std::cout << std::right << "\n";
}

void ShowMatches(const std::vector<std::weak_ptr<Match>>& matches)
{
	std::cout << std::left;

	std::cout << "   " << table << "������" << table << "����" << std::right << std::setw(19) << "����\n" << std::left;

	for (int i = 0; i < matches.size(); i++)
	{
		auto m = matches[i].lock();

		std::cout
			<< i + 1 << ". "
			<< table << m->GetTournament()
			<< table << m->GetDate()
			<< std::right << std::setw(13) << m->GetTeamOneScore().name << " "
			<< m->GetTeamOneScore().amount << " : "
			<< std::left << m->GetTeamTwoScore().amount << " "
			<< m->GetTeamTwoScore().name
			<< "\n";
	}

	std::cout << std::right << "\n";
}

void ShowSportsman(const Sportsman& s)
{
	std::cout
		<< "\n������������ ����������:\n"
		<< "\t���: " << s.GetPersonalInfo().name << "\n"
		<< "\t�������: " << s.GetPersonalInfo().age << "\n"
		<< "\t����: " << s.GetPersonalInfo().height << "\n"
		<< "\t���: " << s.GetPersonalInfo().weight << "\n"
		<< "����: " << s.GetRole() << "\n"
		<< "����������:\n"
		<< "\t����: " << s.GetResults().goals << "\n"
		<< "\t������� ��������: " << s.GetResults().assists << "\n"
		<< "�����:\n";
	ShowMatches(s.GetPreviousMatches());
}