#pragma once
#include <iomanip>
#include <iostream>

template <class T>
void ShowWorkersTask(const T& workers)
{
	std::cout << std::left;

	std::cout << std::setw(20) << "ИД" << std::setw(20) << "Имя" << std::setw(20)
		<< "Номер телефона" << std::setw(20) << "Зарплата" << std::setw(20)
		<< "Стаж" << std::endl;

	for (const auto& w : workers)
	{
		std::cout << std::setw(20) << w->GetID() << std::setw(20) << w->GetName()
			<< std::setw(20) << w->GetPhoneNumber() << std::setw(20) << w->GetSalary()
			<< std::setw(20) << w->GetExperience() << std::endl;
	}

	std::ignore = std::cin.get();
}

void MainMenu(class WorkerList& workers);

void ShowOneWorkerTask(const WorkerList& workers);

void ShowWorker(const class Worker& worker);

void SortWorkersTask(WorkerList& workers);

void AddWorkerTask(WorkerList& workers);

void RemoveWorkerTask(WorkerList& workers);

void ChangeWorkerTask(WorkerList& workers);

void FindWorkerTask(const WorkerList& workers);

void SaveWorkersToFile(const WorkerList& workers);
