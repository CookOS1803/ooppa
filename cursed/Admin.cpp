#include "Admin.h"
#include <iostream>

using namespace IMEX;

Admin::Admin() : User()
{
}

Admin::Admin(std::string_view login, const std::string& password)
    : User(login, password)
{
}

auto Admin::GetFolderName() -> std::string
{
    return "admins\\";
}

void Admin::UserMenu()
{
    std::cout << "Успешный вход\n";
}
