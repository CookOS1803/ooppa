#include "Menus.h"
#include <fstream>
#include "UserInput.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"

// Пользовательская функция
void IMEX::MainMenu()
{
    int choice;
    User* user = nullptr;

    while (true)
    {
        INPUT
        (
            // Стандартная функция
            system("cls");

            // Использование потоков
            std::cout
            << "1. Войти как администратор\n"
            << "2. Войти как клиент\n"
            << "3. Зарегистрироваться\n"
            << "0. Выход\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            // Динамическое выделение памяти
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

    login = StringInput("Введите логин: ", " ");

    // Обработка ошибок
    try
    {
        user->ReadPasswordFromFile(login);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
        std::cin.get();

        return;
    }

    user->SetLogin(login);

    password = StringInput("Введите пароль: ");

    user->TryLogin(login, password);

    if (user->IsInitialized())
    {
        user->UserMenu();
        user->Logout();
    }
    else
    {
        std::cout << "Неправильный пароль\n";
        std::cin.get();
    }
}

void IMEX::RegistrationMenu(Client* client)
{
    std::string login, password;

    login = StringInput("Введите логин: ", " ");
    password = StringInput("Введите пароль: ");

    client->SetLogin(login);
    client->SetPassword(password);

    try
    {
        client->SaveCredentialsToFile(true);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
        std::cin.get();

        return;
    }

    std::cout << "Успешная регистрация\n";
    std::cin.get();
    system("cls");
    client->RegistrationMenu();
}
