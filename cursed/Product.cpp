#include "Product.h"
#include <iostream>

using namespace IMEX;

Product::Product() : Identifiable()
{
}

Product::Product(const Product& other)
	: Identifiable(other), name(other.name), category(other.category), amount(other.amount), unitPrice(other.unitPrice)
{
}

auto Product::GetName() const -> std::string_view
{
	return name;
}

auto Product::GetCategory() const -> std::string_view
{
	return category;
}

auto Product::GetAmount() const -> int
{
	return amount;
}

auto Product::GetUnitPrice() const -> int
{
	return unitPrice;
}

auto Product::GetTotalPrice() const -> int
{
	return amount * unitPrice;
}

void Product::SetName(std::string_view name)
{
	this->name = name;
}

void Product::SetCategory(std::string_view category)
{
	this->category = category;
}

void Product::SetAmount(int amount)
{
	this->amount = amount;
}

void Product::SetUnitPrice(int unitPrice)
{
	this->unitPrice = unitPrice;
}

std::istream& IMEX::operator>>(std::istream& in, Product& p)
{
	in >> p.ID;
	std::ignore = in.get();
	std::getline(in, p.name, '_');
	std::getline(in, p.category, '_');
	in >> p.amount;
	std::ignore = in.get();
	in >> p.unitPrice;
	std::ignore = in.get();

	return in;
}

std::ostream& IMEX::operator<<(std::ostream& out, const Product& p)
{
	out << p.GetID() << "_";
	out.write(p.GetName().data(), p.GetName().size());
	out << "_";
	out.write(p.GetCategory().data(), p.GetCategory().size());
	out << "_";
	out << p.GetAmount() << "_" << p.GetUnitPrice() << "\n";

	return out;
}
