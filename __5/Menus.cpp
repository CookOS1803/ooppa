#include "Menus.h"
#include <iostream>
#include <fstream>
#include "WorkerList.h"
#include "UserInput.h"

void MainMenu(WorkerList& workers)
{
	int choice;

	while (true)
	{
		system("CLS");

		INPUT
		(
			std::cout
				<< "1. Показать сотрудников\n"
				<< "2. Показать конкретного сотрудника\n"
				<< "3. Отсортировать сотрудников\n"
				<< "4. Добавить сотрудника\n"
				<< "5. Удалить сотрудника\n"
				<< "6. Изменить сотрудника\n"
				<< "7. Найти сотрудников\n"
				<< "8. Сохранить сотрудников в файл\n"
				<< "0. Выход\n",
			choice
		);

		system("CLS");

		switch (choice)
		{
		case 1:
			ShowWorkersTask(workers);
			break;
		case 2:
			ShowOneWorkerTask(workers);
			break;
		case 3:
			SortWorkersTask(workers);
			break;
		case 4:
			AddWorkerTask(workers);
			break;
		case 5:
			RemoveWorkerTask(workers);
			break;
		case 6:
			ChangeWorkerTask(workers);
			break;
		case 7:
			FindWorkerTask(workers);
			break;
		case 8:
			SaveWorkersToFile(workers);
			break;
		case 0:
			return;
		}
	}
}

void ShowWorkersTask(const WorkerList& workers)
{
	for (const auto& w : workers)
	{
		std::cout << w->GetID() << ": " << w->GetName() << std::endl;
	}

	std::ignore = std::cin.get();
}

void ShowOneWorkerTask(const WorkerList& workers)
{
	int id;

	INPUT
	(
		std::cout << "Введите идентификационный номер сотрудника: ",
		id
	);

	system("cls");

	if (!workers.Contains(id))
	{
		std::cout << "Такого сотрудника нет\n";
	}
	else
	{
		ShowWorker(*workers[id]);
	}

	std::ignore = std::cin.get();
}

void ShowWorker(const Worker& worker)
{
	std::cout
		<< "Идентификационный номер: " << worker.GetID() << std::endl
		<< "Имя: " << worker.GetName() << std::endl
		<< "Телефон: " << worker.GetPhoneNumber() << std::endl
		<< "Зарплата: " << worker.GetSalary() << std::endl
		<< "Стаж (лет): " << worker.GetExperience() << std::endl;
}

void SortWorkersTask(WorkerList& workers)
{
	int choice, order;

	INPUT_CONDITION
	(
		system("cls");
		std::cout
		<< "1. По ИД\n"
		<< "2. По имени\n"
		<< "3. По номеру телефона\n"
		<< "4. По зарплате\n"
		<< "5. По стажу\n"
		<< "0. Назад\n",
		choice,
		choice >= 0 and choice <= 5
	);

	if (choice == 0)
		return;

	INPUT_CONDITION
	(
		std::cout
		<< "1. По возрастанию\n"
		<< "2. По убыванию\n",
		order,
		order == 1 or order == 2
	);

	switch (choice)
	{
	case 1:
		if (order == 1)
			workers.Sort(WorkerList::ByIDAscendingly);
		else
			workers.Sort(WorkerList::ByIDDescendingly);

		break;
	case 2:
		if (order == 1)
			workers.Sort(WorkerList::ByNameAscendingly);
		else
			workers.Sort(WorkerList::ByNameDescendingly);

		break;
	case 3:
		if (order == 1)
			workers.Sort(WorkerList::ByPhoneAscendingly);
		else
			workers.Sort(WorkerList::ByPhoneDescendingly);

		break;
	case 4:
		if (order == 1)
			workers.Sort(WorkerList::BySalaryAscendingly);
		else
			workers.Sort(WorkerList::BySalaryDescendingly);

		break;
	case 5:
		if (order == 1)
			workers.Sort(WorkerList::ByExpAscendingly);
		else
			workers.Sort(WorkerList::ByExpDescendingly);

		break;
	}
		
}

void AddWorkerTask(WorkerList& workers)
{
	std::string name, phone;
	int salary, exp;

	std::cout << "Введите имя: ";
	std::getline(std::cin, name);

	std::cout << "Введите номер телефона: ";
	std::getline(std::cin, phone);

	INPUT_CONDITION
	(
		std::cout << "Введите зарплату: ",
		salary,
		salary > 0
	);

	INPUT_CONDITION
	(
		std::cout << "Введите стаж: ",
		exp,
		exp >= 0
	);

	workers.Add(name, phone, salary, exp);
}

void RemoveWorkerTask(WorkerList& workers)
{
	int id;

	INPUT
	(
		std::cout << "Введите идентификационный номер сотрудника: ",
		id
	);

	std::cout << std::endl;

	if (!workers.Contains(id))
	{
		std::cout << "Такого сотрудника нет\n";
		std::ignore = std::cin.get();
	}
	else
		workers.Remove(id);
}

void ChangeWorkerTask(WorkerList& workers)
{
	int choice, id;
	std::string str;

	INPUT
	(
		std::cout << "Введите идентификационный номер сотрудника: ",
		id
	);

	std::cout << std::endl;

	if (!workers.Contains(id))
	{
		std::cout << "Такого сотрудника нет\n";
		std::ignore = std::cin.get();
		return;
	}

	while (true)
	{
		system("cls");

		ShowWorker(*workers[id]);
		std::cout << std::endl;

		INPUT
		(
			std::cout
			<< "1. Изменить имя\n"
			<< "2. Изменить номер телефона\n"
			<< "3. Изменить зарплату\n"
			<< "4. Изменить стаж\n"
			<< "0. Назад\n",
			choice
		);

		system("cls");

		ShowWorker(*workers[id]);
		std::cout << std::endl;

		switch (choice)
		{
		case 1:
			std::cout << "Введите имя: ";
			std::getline(std::cin, str);

			workers[id]->SetName(str);

			break;
		case 2:
			std::cout << "Введите номер телефона: ";
			std::getline(std::cin, str);

			workers[id]->SetPhoneNumber(str);

			break;
		case 3:
			INPUT_CONDITION
			(
				std::cout << "Введите зарплату: ",
				choice,
				choice > 0
			);

			workers[id]->SetSalary(choice);

			break;
		case 4:
			INPUT_CONDITION
			(
				std::cout << "Введите стаж: ",
				choice,
				choice >= 0
			);

			workers[id]->SetExperience(choice);

			break;
		case 0:
			return;
		}
	}
}

void FindWorkerTask(const WorkerList& workers)
{
	int choice;
	std::string str;
	std::vector<std::shared_ptr<Worker>> temp;

	INPUT_CONDITION
	(
		system("cls");
		std::cout
		<< "1. По имени\n"
		<< "2. По номеру телефона\n"
		<< "3. По зарплате\n"
		<< "4. По стажу\n",
		choice,
		choice >= 0 and choice <= 4
	);

	system("cls");

	switch (choice)
	{
	case 1:
		std::cout << "Введите имя: ";
		std::getline(std::cin, str);
		
		for (const auto& w : workers)
		{
			if (w->GetName() == str)
				temp.push_back(w);
		}
		
		break;
	case 2:
		std::cout << "Введите номер телефона: ";
		std::getline(std::cin, str);

		for (const auto& w : workers)
		{
			if (w->GetPhoneNumber() == str)
				temp.push_back(w);
		}

		break;
	case 3:
		INPUT_CONDITION
		(
			std::cout << "Введите зарплату: ",
			choice,
			choice > 0
		);

		for (const auto& w : workers)
		{
			if (w->GetSalary() == choice)
				temp.push_back(w);
		}

		break;
	case 4:
		INPUT_CONDITION
		(
			std::cout << "Введите стаж: ",
			choice,
			choice >= 0
		);

		for (const auto& w : workers)
		{
			if (w->GetExperience() == choice)
				temp.push_back(w);
		}

		break;
	}

	system("cls");

	if (temp.empty())
		std::cout << "Таких сотрудников нет\n";
	else
	{
		for (const auto& w : temp)
		{
			std::cout << w->GetID() << ": " << w->GetName() << std::endl;
		}
	}

	std::ignore = std::cin.get();
}

void SaveWorkersToFile(const WorkerList& workers)
{
	std::ofstream out;

	out.open("workers.txt");

	for (const auto& w : workers)
	{
		out
			<< w->GetID() << " " << w->GetName() << " " << w->GetPhoneNumber() << " "
			<< w->GetSalary() << " " << w->GetExperience() << std::endl;
	}

	out.close();

}