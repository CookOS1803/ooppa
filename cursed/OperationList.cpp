#include "OperationList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <filesystem>

using namespace IMEX;

OperationList::OperationList()
{
}

void OperationList::SetOperationsFileName(std::string_view operationsFileName)
{
	this->operationsFileName = operationsFileName;
}

void OperationList::SetFolderName(std::string_view folderName)
{
	this->folderName = folderName;
}

auto OperationList::begin() -> std::vector<std::shared_ptr<Operation>>::iterator
{
	return copiedOperations.begin();
}

auto OperationList::begin() const -> std::vector<std::shared_ptr<Operation>>::const_iterator
{
	return copiedOperations.begin();
}

auto OperationList::end() -> std::vector<std::shared_ptr<Operation>>::iterator
{
	return copiedOperations.end();
}

auto OperationList::end() const -> std::vector<std::shared_ptr<Operation>>::const_iterator
{
	return copiedOperations.end();
}

void OperationList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "Идентификационный номер" << std::setw(30) << "Тип"
		<< std::setw(30) << "Статус" << std::setw(30) << "ИД товара"
		<< std::setw(30) << "Количество товара"
		<< std::setw(30) << "Логин клиента" << std::endl;

	for (const auto& operation : copiedOperations)
	{
		std::cout
			<< std::setw(30) << operation->GetID()
			<< std::setw(30) << Operation::TypeToString(operation->GetType())
			<< std::setw(30) << Operation::StatusToString(operation->GetStatus())
			<< std::setw(30) << operation->GetProductID() << std::setw(30) << operation->GetProductAmount()
			<< std::setw(30) << operation->GetClientLogin() << std::endl;
	}
}

void OperationList::SaveToFile()
{
	std::ofstream file;

	for (const auto& product : originalOperations)
	{	
		std::string login = product->GetClientLogin().data();

		file.open(folderName + login + "\\" + operationsFileName);

		file << *product;

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

		while (file.good())
		{
			originalOperations.emplace_back(std::make_shared<Operation>());

			file >> *originalOperations.back();

			copiedOperations.push_back(originalOperations.back());

			file.peek();
		}

		file.close();
	}	

}
