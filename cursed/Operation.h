#pragma once
#include <string>
#include "Identifiable.h"

namespace IMEX
{
	class Operation : public Identifiable<int>
	{		
	public:

		enum class Type : int
		{
			IMPORT,
			EXPORT
		};

		enum class Status : int
		{
			PENDING,
			REJECTED,
			APPROVED
		};

	private:

		Type type = Type::IMPORT;
		Status status = Status::PENDING;
		int productID = 0;
		int productAmount = 0;
		std::string clientLogin;

	public:

		Operation();
		Operation(const Operation& other);

		auto GetType() const -> Type;
		auto GetStatus() const -> Status;
		auto GetElementID() const -> int;
		auto GetElementAmount() const -> int; 
		auto GetClientLogin() const -> std::string_view;

		void SetType(Type type);
		void SetStatus(Status status);
		void SetProductID(int productID);
		void SetProductAmount(int productAmount);
		void SetClientLogin(std::string_view clientLogin);
		
		static std::string TypeToString(Type type);
		static std::string StatusToString(Status status);

		friend std::istream& operator>>(std::istream& in, Operation& p);

	};

	std::ostream& operator<<(std::ostream& out, const Operation& p);
}

