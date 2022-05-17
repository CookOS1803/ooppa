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

bool IMEX::IndividualOperationList::DoesMatchFilters(const std::shared_ptr<Operation>& e) const
{
	return IDFilter(e->GetID()) and typeFilter((int)e->GetType()) and statusFilter((int)e->GetStatus())
		and productIDFilter(e->GetElementID()) and productAmountFilter(e->GetElementAmount()) and clientLoginFilter(e->GetClientLogin());
}

void IMEX::IndividualOperationList::SetIDFilterMin(int min)
{
	IDFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetIDFilterMax(int max)
{
	IDFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetTypeFilter(Operation::Type value)
{
	typeFilter.SetValue((int)value);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetStatusFilter(Operation::Status value)
{
	statusFilter.SetValue((int)value);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetProductIDFilterMin(int min)
{
	productIDFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetProductIDFilterMax(int max)
{
	productIDFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetProductAmountFilterMin(int min)
{
	productAmountFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetProductAmountFilterMax(int max)
{
	productAmountFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::IndividualOperationList::SetClientLoginFilter(std::string_view s)
{
	clientLoginFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::IndividualOperationList::ClearFilters()
{
	IDFilter.Clear();
	typeFilter.Clear();
	statusFilter.Clear();
	productIDFilter.Clear();
	productAmountFilter.Clear();
	clientLoginFilter.Clear();

	ApplyFilters();
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

