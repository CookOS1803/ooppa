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

		static bool ByIDAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByIDDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByNameAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByNameDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByCategoryAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByCategoryDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByAmountAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByAmountDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByUnitPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByUnitPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByTotalPriceAscendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);
		static bool ByTotalPriceDescendingly(const std::shared_ptr<Product>& p1, const std::shared_ptr<Product>& p2);

	};
}

