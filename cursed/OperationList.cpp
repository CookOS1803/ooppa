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
		<< std::setw(30) << "Идентификационный номер" << std::setw(30) << "Тип"
		<< std::setw(30) << "Статус" << std::setw(30) << "ИД товара"
		<< std::setw(30) << "Количество товара"
		<< std::setw(30) << "Логин клиента" << std::endl;

	for (const auto& operation : copiedElements)
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
		std::string login = operation.second->GetClientLogin().data();

		file.open(folderName + login + "\\" + operationsFileName, std::ios::app);

		file << *operation.second;

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
			auto newElement = std::make_shared<Operation>();

			file >> *newElement;

			originalElements[newElement->GetID()] = newElement;
			copiedElements.push_back(newElement);

			file.peek();
		}

		file.close();
	}

}