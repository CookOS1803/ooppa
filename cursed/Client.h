#pragma once
#include "User.h"
#include "ClientInfo.h"
#include "ISerializable.h"
#include "ProductList.h"

namespace IMEX
{
	class Client : public User
	{
		ClientInfo info;
		ProductList products;

	public:

		Client();
		Client(std::string_view login, const std::string& password);

		void SetLogin(std::string_view login) override;

		void RegistrationMenu();
		void UserMenu() override;

	protected:

		auto GetFolderName() -> std::string override;
		auto GetCredentialsFileName()->std::string override;
		auto GetInfoFileName() -> std::string;
		auto GetOperationsFileName() -> std::string;
		void InfoChangeMenu();
		void StorageMenu();
		void ShowStorageTask();
		void SortStorageMenu();
		void OperationsMenu();

	};
}

