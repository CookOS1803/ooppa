#pragma once
#include <string>
#include <iostream>

namespace IMEX
{
	class Product
	{
		std::string name;
		std::string category;
		int amount = 0;
		int unitPrice = 0;


	public:

		Product();
		Product(const Product& other);

		auto GetName() const -> std::string_view;
		auto GetCategory() const -> std::string_view;
		auto GetAmount() const -> int;
		auto GetUnitPrice() const -> int;
		auto GetTotalPrice() const -> int;

		void SetName(std::string_view name);
		void SetCategory(std::string_view category);
		void SetAmount(int amount);
		void SetUnitPrice(int unitPrice);

		friend std::istream& operator>>(std::istream& in, Product& p);

	};

	std::ostream& operator<<(std::ostream& out, const Product& p);
}

