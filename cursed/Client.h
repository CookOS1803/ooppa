#pragma once
#include "User.h"
#include "ClientInfo.h"
#include "ISerializable.h"

namespace IMEX
{
	class Client : public User
	{
		ClientInfo info;

	public:

		Client();
		Client(std::string_view login, const std::string& password);

		void SaveCredentialsToFile() override;
		void UserMenu() override;
		

	protected:

		auto GetFolderName() -> std::string override;
		auto GetInfoFileName() -> std::string;
		void InfoChangeMenu();
	};
}

