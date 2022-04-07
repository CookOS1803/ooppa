#pragma once
#include "User.h"

namespace IMEX
{
	class Client : public User
	{
	public:
		Client();
		Client(std::string_view login, const std::string& password);

		void UserMenu() override;

	protected:

		auto GetFolderName() -> std::string override;
	};
}

