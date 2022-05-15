#include "Menus.h"
#include "DrugList.h"
#include "UserInput.h"

void MainMenu()
{
	DrugList drugs;
	int choice;

	drugs.Add("��� ����", "�������������� ��������", 2);
	drugs.Add("�������", "����������", 5);

	while (true)
	{
		INPUT
		(
			system("cls");
			std::cout
			<< "1. �������� ���������\n"
			<< "2. �������� ���������\n"
			<< "3. ������� ���������\n"
			<< "4. �������� ���������\n"
			<< "0. �����\n",
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

	std::cout << "������� ��������: ";
	std::getline(std::cin, name);

	std::cout << "������� ���: ";
	std::getline(std::cin, type);

	INPUT_CONDITION
	(
		std::cout << "������� ����������: ",
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
		std::cout << "������� �� ���������: ",
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
		std::cout << "������� �� ���������: ",
		choice
	);

	auto drug = drugs.Get(choice);

	if (!drug.has_value())
	{
		std::cout << "������ ��������� ���\n";
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
			<< "1. �������� ��������\n"
			<< "2. �������� ���\n"
			<< "3. �������� ����������\n"
			<< "0. �����\n",
			choice
		);

		system("cls");

		switch (choice)
		{
		case 1:
			std::cout << "������� ��������: ";
			std::getline(std::cin, temp);

			drug.value()->SetName(temp);

			break;
		case 2:
			std::cout << "������� ���: ";
			std::getline(std::cin, temp);

			drug.value()->SetType(temp);

			break;
		case 3:
			INPUT_CONDITION
			(
				system("cls");
				std::cout << "������� ����������: ",
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
		<< "��: " << drug.GetID() << std::endl
		<< "��������: " << drug.GetName() << std::endl
		<< "���: " << drug.GetType() << std::endl
		<< "����������: " << drug.GetType() << std::endl << std::endl;
}