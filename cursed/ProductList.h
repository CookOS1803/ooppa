#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "ISerializable.h"
#include "Product.h"

namespace IMEX
{
	class ProductList : public ISerializable
	{
		std::vector<std::shared_ptr<Product>> originalProducts;
		std::vector<std::shared_ptr<Product>> copiedProducts;

		std::string fileName;

	public:

		ProductList();

		void SetFileName(std::string_view fileName);

		bool Contains(int ID);
		void Add(const Product& product);
		void Remove(int ID);
		auto GetProduct(int ID) -> std::shared_ptr<Product>;
		void Sort(const std::function<bool(const std::shared_ptr<Product>&, const std::shared_ptr<Product>&)>& criteria);

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;

		auto begin() -> std::vector<std::shared_ptr<Product>>::iterator;
		auto begin() const -> std::vector<std::shared_ptr<Product>>::const_iterator;
		auto end() -> std::vector<std::shared_ptr<Product>>::iterator;
		auto end() const -> std::vector<std::shared_ptr<Product>>::const_iterator;

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

