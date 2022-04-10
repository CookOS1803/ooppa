#include "OperationList.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace IMEX;

OperationList::OperationList()
{
}

void OperationList::SetFileName(std::string_view fileName)
{
	this->fileName = fileName;
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
	file.open(fileName);

	for (const auto& product : originalOperations)
	{
		file << *product;
	}

	file.close();
}

void OperationList::ReadFromFile()
{
	std::ifstream file;
	file.open(fileName);

	while (file.good())
	{
		originalOperations.emplace_back(std::make_shared<Operation>());

		file >> *originalOperations.back();

		copiedOperations.push_back(originalOperations.back());

		file.peek();
	}

	file.close();
}
