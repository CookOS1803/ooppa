#include "IndividualOperationList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <filesystem>

using namespace IMEX;

IndividualOperationList::IndividualOperationList()
{
}

IndividualOperationList::~IndividualOperationList()
{
}

void IndividualOperationList::SetOperationsFileName(std::string_view operationsFileName)
{
	this->operationsFileName = operationsFileName;
}

void IndividualOperationList::Add(const Operation& op)
{
	auto ptr = std::make_shared<Operation>(op);

	originalOperations.push_back(ptr);
	copiedOperations.push_back(ptr);
}

auto IndividualOperationList::begin() -> std::vector<std::shared_ptr<Operation>>::iterator
{
	return copiedOperations.begin();
}

auto IndividualOperationList::begin() const -> std::vector<std::shared_ptr<Operation>>::const_iterator
{
	return copiedOperations.begin();
}

auto IndividualOperationList::end() -> std::vector<std::shared_ptr<Operation>>::iterator
{
	return copiedOperations.end();
}

auto IndividualOperationList::end() const -> std::vector<std::shared_ptr<Operation>>::const_iterator
{
	return copiedOperations.end();
}

void IndividualOperationList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "Идентификационный номер" << std::setw(30) << "Тип"
		<< std::setw(30) << "Статус" << std::setw(30) << "ИД товара"
		<< std::setw(30) << "Количество товара"
		<< std::endl;

	for (const auto& operation : copiedOperations)
	{
		std::cout
			<< std::setw(30) << operation->GetID()
			<< std::setw(30) << Operation::TypeToString(operation->GetType())
			<< std::setw(30) << Operation::StatusToString(operation->GetStatus())
			<< std::setw(30) << operation->GetProductID() << std::setw(30) << operation->GetProductAmount()
			<< std::endl;
	}
}

void IndividualOperationList::SaveToFile()
{
	std::ofstream file;
	file.open(operationsFileName);

	for (const auto& product : originalOperations)
	{
		file << *product;
	}

	file.close();
}

void IndividualOperationList::ReadFromFile()
{
	std::ifstream file;
	file.open(operationsFileName);

	while (file.good())
	{
		originalOperations.emplace_back(std::make_shared<Operation>());

		file >> *originalOperations.back();

		copiedOperations.push_back(originalOperations.back());

		file.peek();
	}

	file.close();
}

