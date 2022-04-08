#pragma once
#include "User.h"
#include "IShowable.h"
#include "ISerializable.h"

namespace IMEX
{
	class Client : public User, public IShowable, public ISerializable
	{
		std::string name = "*";
		std::string country = "*";
		std::string phone = "*";

	public:

		Client();
		Client(std::string_view login, const std::string& password);

		void SaveCredentialsToFile() override;
		void UserMenu() override;
		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;

	protected:

		auto GetFolderName() -> std::string override;

		void InfoChangeMenu();
	};
}

