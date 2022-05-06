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

void IndividualOperationList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "Идентификационный номер" << std::setw(30) << "Тип"
		<< std::setw(30) << "Статус" << std::setw(30) << "ИД товара"
		<< std::setw(30) << "Количество товара"
		<< std::endl;

	for (const auto& operation : copiedElements)
	{
		std::cout
			<< std::setw(30) << operation->GetID()
			<< std::setw(30) << Operation::TypeToString(operation->GetType())
			<< std::setw(30) << Operation::StatusToString(operation->GetStatus())
			<< std::setw(30) << operation->GetElementID() << std::setw(30) << operation->GetElementAmount()
			<< std::endl;
	}
}

void IndividualOperationList::SaveToFile()
{
	std::ofstream file;
	file.open(operationsFileName);

	for (const auto& product : originalElements)
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
		originalElements.emplace_back(std::make_shared<Operation>());

		file >> *originalElements.back();

		copiedElements.push_back(originalElements.back());

		file.peek();
	}

	file.close();
}

bool IndividualOperationList::ByIDAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetID() < o2->GetID();
}

bool IndividualOperationList::ByIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetID() > o2->GetID();
}

bool IndividualOperationList::ByTypeAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetType() < o2->GetType();
}

bool IndividualOperationList::ByTypeDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetType() > o2->GetType();
}

bool IndividualOperationList::ByStatusAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetStatus() < o2->GetStatus();
}

bool IndividualOperationList::ByStatusDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetStatus() > o2->GetStatus();
}

bool IndividualOperationList::ByProductIDAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementID() < o2->GetElementID();
}

bool IndividualOperationList::ByProductIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementID() > o2->GetElementID();
}

bool IndividualOperationList::ByProductAmountAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementAmount() < o2->GetElementAmount();
}

bool IndividualOperationList::ByProductAmountDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetElementAmount() > o2->GetElementAmount();
}

bool IndividualOperationList::ByClientLoginAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetClientLogin()[0] < o2->GetClientLogin()[0];
}

bool IndividualOperationList::ByClientLoginDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetClientLogin()[0] > o2->GetClientLogin()[0];
}
