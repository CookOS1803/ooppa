#pragma once
#include <string>

namespace IMEX
{
	class Operation
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

		int ID = 0;
		Type type = Type::IMPORT;
		Status status = Status::PENDING;
		int productID = 0;
		int productAmount = 0;
		std::string clientLogin;

	public:

		Operation();
		Operation(const Operation& other);

		auto GetID() const -> int;
		auto GetType() const -> Type;
		auto GetStatus() const -> Status;
		auto GetProductID() const -> int;
		auto GetProductAmount() const -> int; 
		auto GetClientLogin() const -> std::string_view;

		void SetID(int newID);
		void SetType(Type type);
		void SetStatus(Status status);
		void SetProductID(int productID);
		void SetProductAmount(int productAmount);
		void SetClientLogin(std::string_view clientLogin);
		
		void CalculateNewID(const class IndividualOperationList& produts);

		static std::string TypeToString(Type type);
		static std::string StatusToString(Status status);

		friend std::istream& operator>>(std::istream& in, Operation& p);
	};

	std::ostream& operator<<(std::ostream& out, const Operation& p);
}

