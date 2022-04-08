#include "Menus.h"
#include <fstream>
#include "UserInput.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"

void IMEX::MainMenu()
{
    int choice;
    User* user = nullptr;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. ����� ��� �������������\n"
            << "2. ����� ��� ������\n"
            << "3. ������������������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            user = new Admin();

            LoginMenu(user);

            delete user;
            user = nullptr;
            break;
        case 2:
            user = new Client();

            LoginMenu(user);

            delete user;
            user = nullptr;
            break;
        case 3:
            user = new Client();

            RegistrationMenu(user);

            delete user;
            user = nullptr;
            break;
        case 0:
            delete user;
            return;
        }
    }    
}

void IMEX::LoginMenu(User* user)
{
    std::string login, password;

    std::cout << "������� �����: ";
    std::getline(std::cin, login);

    try
    {
        user->ReadPasswordFromFile(login);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return;
    }

    std::cout << "������� ������: ";
    std::getline(std::cin, password);

    user->TryLogin(login, password);

    if (user->IsInitialized())
    {
        user->UserMenu();
        user->Logout();
    }
    else
        std::cout << "������������ ������\n";
}

void IMEX::RegistrationMenu(User* user)
{
    std::string login, password;

    std::cout << "������� �����: ";
    std::getline(std::cin, login);

    std::cout << "������� ������: ";
    std::getline(std::cin, password);

    user->SetLogin(login);
    user->SetPassword(password);

    try
    {
        user->SaveCredentialsToFile();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return;
    }

    std::cout << "�������� �����������\n";
}
