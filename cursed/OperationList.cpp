#include "OperationList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>

using namespace IMEX;

OperationList::OperationList() : IndividualOperationList()
{
}

void OperationList::SetFolderName(std::string_view folderName)
{
	this->folderName = folderName;
}

void OperationList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "����������������� �����" << std::setw(30) << "���"
		<< std::setw(30) << "������" << std::setw(30) << "�� ������"
		<< std::setw(30) << "���������� ������"
		<< std::setw(30) << "����� �������" << std::endl;

	for (const auto& operation : originalElements)
	{
		std::cout
			<< std::setw(30) << operation->GetID()
			<< std::setw(30) << Operation::TypeToString(operation->GetType())
			<< std::setw(30) << Operation::StatusToString(operation->GetStatus())
			<< std::setw(30) << operation->GetElementID() << std::setw(30) << operation->GetElementAmount()
			<< std::setw(30) << operation->GetClientLogin() << std::endl;
	}
}

void OperationList::SaveToFile()
{
	std::filesystem::path path{ folderName };
	std::ofstream file;

	for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
	{
		std::string login = dir_entry.path().stem().string();
		file.open(folderName + login + "\\" + operationsFileName);
		file.close();
	}

	for (const auto& operation : originalElements)
	{
		std::string login = operation->GetClientLogin().data();

		file.open(folderName + login + "\\" + operationsFileName, std::ios::app);

		file << *operation;

		file.close();
	}

}

void OperationList::ReadFromFile()
{
	std::filesystem::path path{ folderName };
	std::ifstream file;

	for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
	{
		std::string login = dir_entry.path().stem().string();

		file.open(folderName + login + "\\" + operationsFileName);
		std::ignore = file.peek();

		while (file.good())
		{
			originalElements.emplace_back(std::make_shared<Operation>());

			file >> *originalElements.back();

			copiedElements.push_back(originalElements.back());

			file.peek();
		}

		file.close();
	}

}