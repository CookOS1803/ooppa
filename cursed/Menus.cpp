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
            << "1. Войти как администратор\n"
            << "2. Войти как клиент\n"
            << "3. Зарегистрироваться\n"
            << "0. Выход\n",
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

            RegistrationMenu(dynamic_cast<Client*>(user));

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

    std::cout << "Введите логин: ";
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

    user->SetLogin(login);

    std::cout << "Введите пароль: ";
    std::getline(std::cin, password);

    user->TryLogin(login, password);

    if (user->IsInitialized())
    {
        user->UserMenu();
        user->Logout();
    }
    else
        std::cout << "Неправильный пароль\n";
}

void IMEX::RegistrationMenu(Client* client)
{
    std::string login, password;

    std::cout << "Введите логин: ";
    std::getline(std::cin, login);

    std::cout << "Введите пароль: ";
    std::getline(std::cin, password);

    client->SetLogin(login);
    client->SetPassword(password);

    try
    {
        client->SaveCredentialsToFile(true);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
        return;
    }

    std::cout << "Успешная регистрация\n";
    client->RegistrationMenu();
}
