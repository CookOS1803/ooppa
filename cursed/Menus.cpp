#include "Menus.h"
#include <fstream>
#include "UserInput.h"
#include "User.h"

void IMEX::MainMenu()
{
    int choice;
    User u;
    std::string login, password;

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
            catch (const std::exception& e)
            {
                std::cout << e.what() << "\n";
                break;
            }

            std::cout << "Введите пароль: ";
            std::getline(std::cin, password);
            
            u.TryLogin(login, password);

            if (u.IsInitialized())
            {
                std::cout << "Успешный вход\n";
                u.Logout();
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

            try
            {
                u.SaveToFile();
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << "\n";
                break;
            }

            std::cout << "Успешная регистрация\n";

            break;
        case 0:
            return;
        }
    }

    
}
