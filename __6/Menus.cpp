#include "Menus.h"
#include "DrugList.h"
#include "UserInput.h"

void MainMenu()
{
	DrugList drugs;
	int choice;

	drugs.Add("АЦЦ Лонг", "Муколитическое средство", 2);
	drugs.Add("Анзибел", "Антисептик", 5);

	while (true)
	{
		INPUT
		(
			system("cls");
			std::cout
			<< "1. Показать лекарства\n"
			<< "2. Добавить лекарство\n"
			<< "3. Удалить лекарство\n"
			<< "4. Изменить лекарство\n"
			<< "0. Выход\n",
			choice
		);

		system("cls");

		switch (choice)
		{
		case 1:
			drugs.ShowInConsole();
			std::cin.get();
			break;
		case 2:
			AddDrugTask(drugs);
			break;
		case 3:
			RemoveDrugTask(drugs);
			break;
		case 4:
			ChangeDrugTask(drugs);
			break;
		case 0:
			return;
		}
	}

}

void AddDrugTask(DrugList& drugs)
{
	std::string name, type;
	int amount;

	std::cout << "Введите название: ";
	std::getline(std::cin, name);

	std::cout << "Введите тип: ";
	std::getline(std::cin, type);

	INPUT_CONDITION
	(
		std::cout << "Введите количество: ",
		amount,
		amount >= 0
	);

	drugs.Add(name, type, amount);
}

void RemoveDrugTask(DrugList& drugs)
{
	int id;

	INPUT
	(
		system("cls");
		std::cout << "Введите ИД лекарства: ",
		id
	);

	drugs.Remove(id);
}

void ChangeDrugTask(DrugList& drugs)
{
	int choice;

	INPUT
	(
		system("cls");
		std::cout << "Введите ИД лекарства: ",
		choice
	);

	auto drug = drugs.Get(choice);

	if (!drug.has_value())
	{
		std::cout << "Такого лекарства нет\n";
		std::cin.get();
		return;
	}
	else while (true)
	{
		std::string temp;

		INPUT
		(
			system("cls");
			ShowDrug(*drug.value());
			std::cout
			<< "1. Изменить название\n"
			<< "2. Изменить тип\n"
			<< "3. Изменить количество\n"
			<< "0. Выход\n",
			choice
		);

		system("cls");

		switch (choice)
		{
		case 1:
			std::cout << "Введите название: ";
			std::getline(std::cin, temp);

			drug.value()->SetName(temp);

			break;
		case 2:
			std::cout << "Введите тип: ";
			std::getline(std::cin, temp);

			drug.value()->SetType(temp);

			break;
		case 3:
			INPUT_CONDITION
			(
				system("cls");
				std::cout << "Введите количество: ",
				choice,
				choice >= 0
			);

			drug.value()->SetAmount(choice);

			break;
		case 0:
			return;
		}
	}
}

void ShowDrug(const Drug& drug)
{
	std::cout
		<< "ИД: " << drug.GetID() << std::endl
		<< "Название: " << drug.GetName() << std::endl
		<< "Тип: " << drug.GetType() << std::endl
		<< "Количество: " << drug.GetType() << std::endl << std::endl;
}