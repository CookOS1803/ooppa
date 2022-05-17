#pragma once
#include <memory>
#include <functional>
#include "ISerializable.h"
#include "Product.h"
#include "List.h"
#include "Filter.h"

namespace IMEX
{
	class ProductList : public List<Product, int>, public ISerializable
	{
		std::string fileName;

		IntFilter IDFilter;
		StringFilter nameFilter;
		StringFilter categoryFilter;
		IntFilter amountFilter;
		IntFilter unitPriceFilter;
		IntFilter totalPriceFilter;

	public:

		ProductList();

		void SetFileName(std::string_view fileName);

		void CalculateNewID(Product& e);

		bool DoesMatchFilters(const std::shared_ptr<Product>& e) const override;

		void SetIDFilterMin(int min);
		void SetIDFilterMax(int max);
		void SetNameFilter(std::string_view s);
		void SetCategoryFilter(std::string_view s);
		void SetAmountFilterMin(int min);
		void SetAmountFilterMax(int max);
		void SetUnitPriceFilterMin(int min);
		void SetUnitPriceFilterMax(int max);
		void SetTotalPriceFilterMin(int min);
		void SetTotalPriceFilterMax(int max);

		void ClearFilters();

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;

	};
}

