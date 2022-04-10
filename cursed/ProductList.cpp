#include "ProductList.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "WrongProductException.h"

using namespace IMEX;

ProductList::ProductList()
{
}

void ProductList::SetFileName(std::string_view fileName)
{
	this->fileName = fileName;
}

bool ProductList::Contains(std::string_view name, std::string_view category)
{
	for (const auto& product : originalProducts)
	{
		if (product->GetName() == name and product->GetCategory() == category)
			return true;
	}

	return false;
}

void ProductList::Add(const Product& product)
{
	std::shared_ptr<Product> ptr = std::make_unique<Product>(product);

	originalProducts.push_back(ptr);
	copiedProducts.push_back(ptr);
}

void ProductList::Remove(std::string_view name, std::string_view category)
{
	auto it = std::find_if(originalProducts.begin(), originalProducts.end(),
		[name, category](const std::shared_ptr<Product>& p) { return p->GetName() == name and p->GetCategory() == category; });

	const Product* ptr = it->get();

	if (it != originalProducts.end())
		originalProducts.erase(it);

	it = std::find_if(copiedProducts.begin(), copiedProducts.end(),
		[ptr](const std::shared_ptr<Product>& p) { return p.get() == ptr; });

	if (it != copiedProducts.end())
		copiedProducts.erase(it);
}

auto ProductList::GetProduct(std::string_view name, std::string_view category) -> std::shared_ptr<Product>
{
	for (const auto& product : originalProducts)
	{
		if (product->GetName() == name and product->GetCategory() == category)
			return product;
	}

	throw WrongProductException();
}

void ProductList::Sort(const std::function<bool(const std::shared_ptr<Product>&, const std::shared_ptr<Product>&)>& criteria)
{
	std::sort(copiedProducts.begin(), copiedProducts.end(), criteria);
}

void ProductList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "Наименование" << std::setw(30) << "Категория"
		<< std::setw(30) << "Количество" << std::setw(30) << "Цена за штуку"
		<< std::setw(30) << "Стоимость" << std::endl;

	for (const auto& product : copiedProducts)
	{
		std::cout
			<< std::setw(30) << product->GetName() << std::setw(30) << product->GetCategory()
			<< std::setw(30) << product->GetAmount() << std::setw(30) << product->GetUnitPrice()
			<< std::setw(30) << product->GetTotalPrice() << std::endl;
	}

}

void ProductList::SaveToFile()
{
	std::ofstream file;
	file.open(fileName);

	for (const auto& product : originalProducts)
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
		originalProducts.emplace_back(std::make_shared<Product>());
		
		file >> *originalProducts.back();

		copiedProducts.push_back(originalProducts.back());

		file.peek();
	}

	file.close();
}

auto ProductList::begin() -> std::vector<std::shared_ptr<Product>>::iterator
{
	return copiedProducts.begin();
}

auto ProductList::begin() const -> std::vector<std::shared_ptr<Product>>::const_iterator
{
	return copiedProducts.begin();
}

auto ProductList::end() -> std::vector<std::shared_ptr<Product>>::iterator
{
	return copiedProducts.end();
}

auto ProductList::end() const -> std::vector<std::shared_ptr<Product>>::const_iterator
{
	return copiedProducts.end();
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
