#pragma once
#include <string>

namespace IMEX // Использование пространства имён
{
	class User // Абстрактный класс
	{
	protected: // Инкапсуляция

		// Статические поля
		static inline const std::string INFO_FILE_EXT = ".txt";
		static inline const std::string CRED_FILE_EXT = ".dat";
		static inline const std::string OPER_FILE_EXT = ".txt";
		static inline const std::string PROD_FILE_EXT = ".txt";
		static inline const std::string INFO_FILE_NAME = "info" + INFO_FILE_EXT;
		static inline const std::string CRED_FILE_NAME = "credentials" + CRED_FILE_EXT;
		static inline const std::string OPER_FILE_NAME = "operations" + OPER_FILE_EXT;
		static inline const std::string PROD_FILE_NAME = "products" + PROD_FILE_EXT;
		static inline const std::string REQ_FILE_NAME = "requests" + PROD_FILE_EXT;
		static inline const std::string ADMINS_FOLDER = "admins\\";
		static inline const std::string CLIENTS_FOLDER = "clients\\";

		std::string login;
		std::string password;
		bool isInitialized = false;

	public:

		User();
		User(std::string_view login, const std::string& password);
		virtual ~User();

		auto GetLogin() const -> std::string_view;
		auto GetPassword() const -> std::string_view;

		// Полиморфизм
		virtual void SetLogin(std::string_view login); // Виртуальный метод
		void SetPassword(const std::string& password);

		bool IsInitialized() const;

		void TryLogin(std::string_view login, const std::string& password);
		void Logout();

		void SaveCredentialsToFile(bool newUser);
		void ReadPasswordFromFile(const std::string& login);

		virtual void UserMenu() = 0;

		// Статический метод
		static auto MakePassword(const std::string& password) -> std::string;

	protected:

		virtual auto GetFolderName() -> std::string = 0;
		virtual auto GetCredentialsFileName() -> std::string = 0;
	};
}

