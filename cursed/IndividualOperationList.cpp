#include "IndividualOperationList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include "SortHelper.h"

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

void IMEX::IndividualOperationList::CalculateNewID(Operation& e)
{
	if (originalElements.empty())
		return;

	auto it = originalElements.end();
	--it;

	e.SetID(it->first + 1);
}

void IndividualOperationList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "����������������� �����" << std::setw(30) << "���"
		<< std::setw(30) << "������" << std::setw(30) << "�� ������"
		<< std::setw(30) << "���������� ������"
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
		file << *product.second;
	}

	file.close();
}

void IndividualOperationList::ReadFromFile()
{
	std::ifstream file;
	file.open(operationsFileName);

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
	return SortHelper::CompareStrings(o1->GetClientLogin(), o2->GetClientLogin());
}

bool IndividualOperationList::ByClientLoginDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return !ByClientLoginAscendingly(o1, o2);
}
