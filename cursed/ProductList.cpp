#include "ProductList.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include "WrongProductException.h"

using namespace IMEX;

ProductList::ProductList()
{
}

void ProductList::SetFileName(std::string_view fileName)
{
	this->fileName = fileName;
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
		file << *product;
	}

	file.close();
}

void ProductList::ReadFromFile()
{
	std::ifstream file;
	file.open(fileName);

	while (file.good())
	{
		originalElements.emplace_back(std::make_shared<Product>());
		
		file >> *originalElements.back();

		copiedElements.push_back(originalElements.back());

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
	return p1->GetName()[0] < p2->GetName()[0];
}

bool ProductList::ByNameDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetName()[0] > p2->GetName()[0];
}

bool ProductList::ByCategoryAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetCategory()[0] < p2->GetCategory()[0];
}

bool ProductList::ByCategoryDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2)
{
	return p1->GetCategory()[0] > p2->GetCategory()[0];
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
