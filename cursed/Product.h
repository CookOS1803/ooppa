#pragma once
#include <string>
#include "Identifiable.h"

namespace IMEX
{
	class Product : public Identifiable<int>
	{
		std::string name;
		std::string category;
		int amount = 0;
		int unitPrice = 0;

	public:

		Product();
		// Передача параметра по ссылке
		Product(const Product& other);

		auto GetName() const -> std::string_view;
		auto GetCategory() const -> std::string_view;
		auto GetAmount() const -> int;
		auto GetUnitPrice() const -> int;
		auto GetTotalPrice() const -> int;

		void SetName(std::string_view name);
		void SetCategory(std::string_view category);
		void SetAmount(int amount); // Передача параметра по значению
		void SetUnitPrice(int unitPrice);

		// Дружественная функция
		friend std::istream& operator>>(std::istream& in, Product& p);

	};

	// Перегрузка операторов ввода/вывода
	std::ostream& operator<<(std::ostream& out, const Product& p);
}

