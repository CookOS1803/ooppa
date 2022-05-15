#include "DrugList.h"
#include <iostream>
#include <iomanip>

DrugList::DrugList()
{
}

void DrugList::Add(std::string_view name, std::string_view type, int amount)
{
	auto ptr = std::make_shared<Drug>(name, type, amount);

	if (!sortedDrugs.empty())
		ptr->SetID(sortedDrugs.top()->GetID() + 1);

	drugs.push(ptr);
	sortedDrugs.push(ptr);
}

void DrugList::Remove(int id)
{
	Drugs temp;

	while (!sortedDrugs.empty())
	{
		sortedDrugs.pop();
	}

	while (!drugs.empty())
	{
		if (drugs.top()->GetID() == id)
		{
			drugs.pop();

			if (drugs.empty())
				break;
		}

		temp.push(drugs.top());
		drugs.pop();
	}

	while (!temp.empty())
	{
		drugs.push(temp.top());
		sortedDrugs.push(temp.top());
		temp.pop();
	}

	
	
}

auto DrugList::Get(int id) -> std::optional<std::shared_ptr<Drug>>
{
	Drugs temp;

	std::optional<std::shared_ptr<Drug>> result = {};

	while (!drugs.empty())
	{
		if (drugs.top()->GetID() == id)
		{
			result = drugs.top();
			break;
		}

		temp.push(drugs.top());
		drugs.pop();
	}

	while (!temp.empty())
	{
		drugs.push(temp.top());
		temp.pop();
	}

	return result;
}

void DrugList::ShowInConsole()
{
	const int width = 25;
	Drugs temp;

	std::cout << std::left;

	std::cout << std::setw(width) << "ИД" << std::setw(width) << "Название" << std::setw(width) << "Тип" << std::setw(width) << "Количество" << std::endl;

	while (!drugs.empty())
	{
		std::cout << std::setw(width) << drugs.top()->GetID() << std::setw(width) << drugs.top()->GetName() << std::setw(width) << drugs.top()->GetType() << std::setw(width) << drugs.top()->GetAmount() << std::endl;

		temp.push(drugs.top());
		drugs.pop();
	}

	while (!temp.empty())
	{
		drugs.push(temp.top());
		temp.pop();
	}
}
