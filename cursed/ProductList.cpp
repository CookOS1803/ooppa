#include "ProductList.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include "SortHelper.h"

using namespace IMEX;

ProductList::ProductList()
{
}

void ProductList::SetFileName(std::string_view fileName)
{
	this->fileName = fileName;
}

void IMEX::ProductList::CalculateNewID(Product& e)
{
	if (originalElements.empty())
		return;

	auto it = originalElements.end();
	--it;

	e.SetID(it->first + 1);
}


bool IMEX::ProductList::DoesMatchFilters(const std::shared_ptr<Product>& e) const
{
	return amountFilter(e->GetAmount()) and unitPriceFilter(e->GetUnitPrice()) and totalPriceFilter(e->GetTotalPrice())
		and nameFilter(e->GetName()) and categoryFilter(e->GetCategory()) and IDFilter(e->GetID());
}

void IMEX::ProductList::SetIDFilterMin(int min)
{
	IDFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::ProductList::SetIDFilterMax(int max)
{
	IDFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::ProductList::SetNameFilter(std::string_view s)
{
	nameFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ProductList::SetCategoryFilter(std::string_view s)
{
	categoryFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ProductList::SetAmountFilterMin(int min)
{
	amountFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::ProductList::SetAmountFilterMax(int max)
{
	amountFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::ProductList::SetUnitPriceFilterMin(int min)
{
	unitPriceFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::ProductList::SetUnitPriceFilterMax(int max)
{
	unitPriceFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::ProductList::SetTotalPriceFilterMin(int min)
{
	totalPriceFilter.SetMin(min);
	ApplyFilters();
}

void IMEX::ProductList::SetTotalPriceFilterMax(int max)
{
	totalPriceFilter.SetMax(max);
	ApplyFilters();
}

void IMEX::ProductList::ClearFilters()
{
	IDFilter.Clear();
	nameFilter.Clear();
	categoryFilter.Clear();
	amountFilter.Clear();
	unitPriceFilter.Clear();
	totalPriceFilter.Clear();
	ApplyFilters();
}

void ProductList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "Идентификационный номер" << std::setw(30) << "Наименование" << std::setw(30) << "Категория"
		<< std::setw(30) << "Количество" << std::setw(30) << "Цена за штуку"
		<< std::setw(30) << "Стоимость" << std::endl;

	for (const auto& product : copiedElements)
	{
		std::cout
			<< std::setw(30) << product->GetID() << std::setw(30) <<  product->GetName() << std::setw(30) << product->GetCategory()
			<< std::setw(30) << product->GetAmount() << std::setw(30) << product->GetUnitPrice()
			<< std::setw(30) << product->GetTotalPrice() << std::endl;
	}

}

void ProductList::SaveToFile()
{
	std::ofstream file;
	file.open(fileName);

	for (const auto& product : originalElements)
	{
		file << *product.second;
	}

	file.close();
}

void ProductList::ReadFromFile()
{
	std::ifstream file;
	file.open(fileName);

	while (file.good())
	{
		auto newElement = std::make_shared<Product>();
		
		file >> *newElement;

		originalElements[newElement->GetID()] = newElement;
		copiedElements.push_back(newElement);

		file.peek();
	}

	file.close();
}

bool ProductList::ByIDAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetID() < p2->GetID();
}

bool ProductList::ByIDDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetID() > p2->GetID();
}

bool ProductList::ByNameAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return SortHelper::CompareStrings(p1->GetName(), p2->GetName());
}

bool ProductList::ByNameDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return !ByNameAscendingly(p1, p2);
}

bool ProductList::ByCategoryAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return SortHelper::CompareStrings(p1->GetCategory(), p2->GetCategory());
}

bool ProductList::ByCategoryDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return !ByCategoryAscendingly(p1, p2);
}

bool ProductList::ByAmountAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetAmount() < p2->GetAmount();
}

bool ProductList::ByAmountDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetAmount() > p2->GetAmount();
}

bool ProductList::ByUnitPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetUnitPrice() < p2->GetUnitPrice();
}

bool ProductList::ByUnitPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetUnitPrice() > p2->GetUnitPrice();
}

bool ProductList::ByTotalPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetTotalPrice() < p2->GetTotalPrice();
}

bool ProductList::ByTotalPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetTotalPrice() > p2->GetTotalPrice();
}

