#include "Menus.h"
#include <fstream>
#include "UserInput.h"
#include "User.h"

void IMEX::MainMenu()
{
    int choice;
    User u;
    std::string login, password;
    std::fstream file;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Войти как администратор\n"
            << "2. Войти как пользователь\n"
            << "3. Зарегистрироваться\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 1:
            std::cout << "Введите логин: ";
            std::getline(std::cin, login);

            try
            {
                u.ReadFromFile(login);
            }
            catch (std::exception& ex)
            {
                std::cout << ex.what() << "\n";
                break;
            }

            std::cout << "Введите пароль: ";
            std::getline(std::cin, password);
            password = User::MakePassword(password);

            u.TryLogin(login, password);

            if (u.IsInitialized())
            {
                std::cout << "Успешный вход\n";
                return;
            }
            else
                std::cout << "Неправильный пароль\n";


            break;
        case 2:
            break;
        case 3:
            std::cout << "Введите логин: ";
            std::getline(std::cin, login);

            std::cout << "Введите пароль: ";
            std::getline(std::cin, password);

            u.SetLogin(login);
            u.SetPassword(password);

            u.SaveToFile();

            break;
        case 0:
            return;
        }
    }

    
}
