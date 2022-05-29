#pragma once
#include "User.h"
#include "ClientInfo.h"
#include "ISerializable.h"
#include "ProductList.h"
#include "OperationList.h"

namespace IMEX
{
	class Client : public User // Наследование
	{
		ClientInfo info;
		ProductList products;
		ProductList requests;
		IndividualOperationList operations;

	public:

		Client();
		Client(std::string_view login, const std::string& password);

		void SetLogin(std::string_view login) override;

		void RegistrationMenu();
		void UserMenu() override; // Переопределение

	protected:

		auto GetFolderName() -> std::string override;
		auto GetCredentialsFileName()->std::string override;
		auto GetInfoFileName() -> std::string;
		void InfoChangeMenu();
		void StorageMenu(ProductList& curr);
		void ShowStorageTask(ProductList& curr);
		void SortStorageMenu(ProductList& curr);
		void FilterStorageMenu(ProductList& curr);
		void OperationsMenu();
		void SortOperationsMenu();
		void FilterOperationsMenu();
		void MakeOperationTask(Operation::Type type, ProductList& curr);
		void CanselOperationTask();

	};
}

