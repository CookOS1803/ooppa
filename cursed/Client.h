#pragma once
#include "User.h"
#include "IShowable.h"

namespace IMEX
{
	class Client : public User, public IShowable
	{
		std::string name;
		std::string country;
		std::string phone;

	public:

		Client();
		Client(std::string_view login, const std::string& password);

		void UserMenu() override;
		void ShowToConsole() override;

	protected:

		auto GetFolderName() -> std::string override;

		void InfoChangeMenu();
	};
}

