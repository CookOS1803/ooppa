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

bool IndividualOperationList::Contains(int ID)
{
	for (const auto& product : originalOperations)
	{
		if (product->GetID() == ID)
			return true;
	}

	return false;
}

void IndividualOperationList::Remove(int ID)
{
	auto it = std::find_if(originalOperations.begin(), originalOperations.end(),
		[ID](const std::shared_ptr<Operation>& p) { return p->GetID() == ID; });

	const Operation* ptr = it->get();

	if (it != originalOperations.end())
		originalOperations.erase(it);

	it = std::find_if(copiedOperations.begin(), copiedOperations.end(),
		[ptr](const std::shared_ptr<Operation>& p) { return p.get() == ptr; });

	if (it != copiedOperations.end())
		copiedOperations.erase(it);
}

void IndividualOperationList::Sort(const std::function<bool(const std::shared_ptr<Operation>&, const std::shared_ptr<Operation>&)>& criteria)
{
	std::sort(copiedOperations.begin(), copiedOperations.end(), criteria);
}

auto IndividualOperationList::GetOperation(int ID) -> std::shared_ptr<Operation>
{
	for (const auto& o : originalOperations)
	{
		if (o->GetID() == ID)
			return o;
	}

	throw std::exception("Такой операции нет");
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
	return o1->GetProductID() < o2->GetProductID();
}

bool IndividualOperationList::ByProductIDDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetProductID() > o2->GetProductID();
}

bool IndividualOperationList::ByProductAmountAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetProductAmount() < o2->GetProductAmount();
}

bool IndividualOperationList::ByProductAmountDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetProductAmount() > o2->GetProductAmount();
}

bool IndividualOperationList::ByClientLoginAscendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetClientLogin()[0] < o2->GetClientLogin()[0];
}

bool IndividualOperationList::ByClientLoginDescendingly(const std::shared_ptr<Operation>& o1, const std::shared_ptr<Operation>& o2)
{
	return o1->GetClientLogin()[0] > o2->GetClientLogin()[0];
}
