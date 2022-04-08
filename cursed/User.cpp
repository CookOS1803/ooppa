#include "User.h"
#include <fstream>
#include <filesystem>
#include "WrongLoginException.h"
#include "DuplicateLoginException.h"

using namespace IMEX;

User::User()
{
}

User::User(std::string_view login, const std::string& password)
	: login(login)
{
	SetPassword(password);
}

User::~User()
{
}

auto User::GetLogin() const -> std::string_view
{
	return login;
}

auto User::GetPassword() const -> std::string_view
{
	return password;
}

void User::SetLogin(std::string_view login)
{
	this->login = login;
}

void User::SetPassword(const std::string& password)
{
	this->password = MakePassword(password);
}

bool User::IsInitialized() const
{
	return isInitialized;
}

void User::TryLogin(std::string_view login, const std::string& password)
{
	if (login == this->login and MakePassword(password) == this->password)
		isInitialized = true;
}

void User::Logout()
{
	isInitialized = false;
}

void User::SaveCredentialsToFile()
{
	std::fstream file;

	if (std::filesystem::exists(GetFolderName()))
	{
		file.open(GetDatFile());

		if (file.good())
		{
			file.close();
			throw DuplicateLoginException();
		}

		file.close();
	}
	else
		std::filesystem::create_directory(GetFolderName());

	file.open(GetDatFile(), std::ios::app);

	file << login << " " << password << "\n";

	file.close();
}


void User::ReadPasswordFromFile(const std::string& login)
{
	if (!std::filesystem::exists(GetFolderName()))
		throw WrongLoginException();

	std::ifstream in;

	this->login = login;

	in.open(GetDatFile());

	if (!in.good())
	{
		in.close();
		throw WrongLoginException();
	}

	in >> this->login;
	in >> password;

	in.close();
	
}

auto User::MakePassword(const std::string& password) -> std::string
{
	return std::to_string(std::hash<std::string>()(password));
}

auto User::GetDatFile() -> std::string
{
	return GetFolderName() + login + FILE_EXT;
}
