#include "User.h"
#include <fstream>
#include "WrongLoginException.h"

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

void User::TryLogin(std::string_view login, std::string_view password)
{
	if (login == this->login and password == this->password)
		isInitialized = true;
}

void User::SaveToFile()
{
	std::ofstream out;

	out.open(FILE_NAME, std::ios::app);

	out << login << " " << password << "\n";

	out.close();
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
