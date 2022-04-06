#include "User.h"
#include <fstream>
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

void User::SaveToFile()
{
	std::fstream file;
	std::string readLogin;

	file.open(FILE_NAME, std::ios::in);

	while (file.good())
	{
		file >> readLogin;

		if (this->login == readLogin)
		{
			file.close();
			throw DuplicateLoginException();
		}

		file.ignore(99999, '\n');
		std::ignore = file.peek();
	}

	file.close();
	file.open(FILE_NAME, std::ios::app);

	file << login << " " << password << "\n";

	file.close();
}

void User::ReadFromFile(std::string_view login)
{
	std::ifstream in;

	in.open(FILE_NAME);

	while (in.good())
	{
		in >> this->login;
		in >> password;

		if (this->login == login)
		{
			in.close();
			return;
		}

		std::ignore = in.get();
		std::ignore = in.peek();
	}	

	in.close();
	throw WrongLoginException();
}

std::string User::MakePassword(const std::string& password)
{
	return std::to_string(std::hash<std::string>()(password));
}
