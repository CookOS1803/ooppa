#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "ISerializable.h"
#include "Product.h"
#include "List.h"

namespace IMEX
{
	class ProductList : public List<Product>, public ISerializable
	{
		std::string fileName;

	public:

		ProductList();

		void SetFileName(std::string_view fileName);

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

