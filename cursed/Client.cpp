#include "Client.h"
#include <iostream>

using namespace IMEX;

Client::Client() : User()
{
}

Client::Client(std::string_view login, const std::string& password)
	: User(login, password)
{
}

auto Client::GetFolderName() -> std::string
{
	return "clients\\";
}

void Client::UserMenu()
{
	std::cout << "Успешный вход\n";
}