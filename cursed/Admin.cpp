#include "Admin.h"
#include <iostream>
#include <filesystem>
#include "UserInput.h"

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
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Работа с пользователями\n"
            << "2. Работа с операциями\n"
            << "3. Работа с складом\n"
            << "4. Работа с администраторами\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 0:
            return;
        }
    }
}
