#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "Product.h"

namespace IMEX
{
	class ProductList : public ISerializable
	{
		std::vector<std::shared_ptr<Product>> originalProducts;
		std::vector<std::shared_ptr<Product>> copiedProducts;

	public:


		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

