#pragma once
#include <string>

namespace IMEX
{
	class User
	{
		static inline const std::string FILE_NAME = "users.txt";

		std::string login;
		std::string password;
		bool isInitialized = false;

	public:

		User();
		User(std::string_view login, const std::string& password);

		auto GetLogin() const -> std::string_view;
		auto GetPassword() const -> std::string_view;

		void SetLogin(std::string_view login);
		void SetPassword(const std::string& password);

		bool IsInitialized() const;

		void TryLogin(std::string_view login, std::string_view password);

		void SaveToFile();
		void ReadFromFile(std::string_view login);

		static std::string MakePassword(const std::string& password);
	};
}

