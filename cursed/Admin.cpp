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
            << "1. ������ � ��������������\n"
            << "2. ������ � ����������\n"
            << "3. ������ � �������\n"
            << "4. ������ � ����������������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 0:
            return;
        }
    }
}
