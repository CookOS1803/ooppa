#include "Operation.h"
#include "OperationList.h"
#include <iostream>

using namespace IMEX;

Operation::Operation()
{
}

Operation::Operation(const Operation& other)
	: ID(other.ID), type(other.type), status(other.status), productID(other.productID), productAmount(other.productAmount), clientLogin(other.clientLogin)
{
}

auto Operation::GetID() const -> int
{
	return ID;
}

auto Operation::GetType() const -> Operation::Type
{
	return type;
}

auto Operation::GetStatus() const -> Operation::Status
{
	return status;
}

auto Operation::GetProductID() const -> int
{
	return productID;
}

auto Operation::GetProductAmount() const -> int
{
	return productAmount;
}

auto Operation::GetClientLogin() const -> std::string_view
{
	return clientLogin;
}

void Operation::SetID(int newID)
{
	this->ID = ID;
}

void Operation::SetType(Type type)
{
	this->type = type;
}

void Operation::SetStatus(Status status)
{
	this->status = status;
}

void Operation::SetProductID(int productID)
{
	this->productID = productID;
}

std::string Operation::TypeToString(Type type)
{
	switch (type)
	{
	case Type::IMPORT:
		return "Импорт";
	case Type::EXPORT:
		return "Экспорт";
	}
}

void Operation::CalculateNewID(const OperationList& produts)
{
	ID = 0;

	for (const auto& p : produts)
	{
		if (ID <= p->GetID())
			ID = p->GetID();
	}

	ID++;
}


std::string Operation::StatusToString(Status status)
{
	switch (status)
	{
	case Status::PENDING:
		return "Рассматривается";
	case Status::REJECTED:
		return "Отклонена";
	case Status::APPROVED:
		return "Одобрена";
	default:
		break;
	}
}

void Operation::SetProductAmount(int productAmount)
{
	this->productAmount = productAmount;
}

void Operation::SetClientLogin(std::string_view clientLogin)
{
	this->clientLogin = clientLogin;
}

std::istream& IMEX::operator>>(std::istream& in, Operation& p)
{
	in >> p.ID;
	std::ignore = in.get();
	in >> (int&)p.type;
	std::ignore = in.get();
	in >> (int&)p.status;
	std::ignore = in.get();
	in >> p.productID;
	std::ignore = in.get();
	in >> p.productAmount;
	std::ignore = in.get();
	std::getline(in, p.clientLogin);

	return in;
}

std::ostream& IMEX::operator<<(std::ostream& out, const Operation& p)
{
	out << p.GetID() << "_" << (int)p.GetType() << "_" << (int)p.GetStatus() << "_"
		<< p.GetProductID() << "_" << p.GetProductAmount() << "_";

	out.write(p.GetClientLogin().data(), p.GetClientLogin().size());
	out << "\n";

	return out;
}