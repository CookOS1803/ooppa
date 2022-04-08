#pragma once
#include <string>

namespace IMEX
{
	class User
	{
	protected:
		static inline const std::string INFO_FILE_EXT = ".inf";
		static inline const std::string CRED_FILE_EXT = ".txt";

		std::string login;
		std::string password;
		bool isInitialized = false;

	public:

		User();
		User(std::string_view login, const std::string& password);
		virtual ~User();

		auto GetLogin() const -> std::string_view;
		auto GetPassword() const -> std::string_view;

		void SetLogin(std::string_view login);
		void SetPassword(const std::string& password);

		bool IsInitialized() const;

		void TryLogin(std::string_view login, const std::string& password);
		void Logout();

		virtual void SaveCredentialsToFile();
		void ReadPasswordFromFile(const std::string& login);

		virtual void UserMenu() = 0;

		static auto MakePassword(const std::string& password) -> std::string;

	protected:

		virtual auto GetFolderName() -> std::string = 0;
		auto GetDatFile() -> std::string;
	};
}

