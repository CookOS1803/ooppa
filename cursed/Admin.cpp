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


auto Admin::GetCredentialsFileName() -> std::string
{
    return GetFolderName() + login + CRED_FILE_EXT;
}

void Admin::UserMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Работа с клиентами\n"
            << "2. Работа с операциями\n"
            << "3. Работа с складом\n"
            << "4. Работа с администраторами\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 1:

        case 0:
            return;
        }
    }
}

void Admin::ClientsMenu()
{
    int choice;
    
    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Показать всех клиентов\n"
            << "2. Найти клиентов\n"
            << "3. Показать операции клиента\n"
            << "4. "
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
