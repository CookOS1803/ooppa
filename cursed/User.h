#pragma once
#include <string>

namespace IMEX
{
	class User
	{
	protected:
		static inline const std::string FILE_EXT = ".txt";

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

		void TryLogin(std::string_view login, const std::string& password);
		void Logout();

		void SaveToFile();
		void ReadFromFile(const std::string& login);

		// TODO: ABSTRACT
		virtual std::string GetFolderName();

		static std::string MakePassword(const std::string& password);
	};
}

