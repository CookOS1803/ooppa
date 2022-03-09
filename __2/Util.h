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

	std::cout << "   " << table << "Турнир" << table << "Дата" << std::right << std::setw(19) << "Счёт\n" << std::left;

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

	std::cout << "   " << table << "Турнир" << table << "Дата" << std::right << std::setw(19) << "Счёт\n" << std::left;

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
		<< "\nПерсональная информация:\n"
		<< "\tИмя: " << s.GetPersonalInfo().name << "\n"
		<< "\tВозраст: " << s.GetPersonalInfo().age << "\n"
		<< "\tРост: " << s.GetPersonalInfo().height << "\n"
		<< "\tВес: " << s.GetPersonalInfo().weight << "\n"
		<< "Роль: " << s.GetRole() << "\n"
		<< "Результаты:\n"
		<< "\tГолы: " << s.GetResults().goals << "\n"
		<< "\tГолевые передачи: " << s.GetResults().assists << "\n"
		<< "Матчи:\n";
	ShowMatches(s.GetPreviousMatches());
}