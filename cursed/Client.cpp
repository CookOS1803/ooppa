#include "Client.h"
#include <iostream>
#include <fstream>
#include "UserInput.h"

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

void Client::ShowToConsole()
{
    std::cout
        << "Имя: " << name << std::endl
        << "Страна: " << country << std::endl
        << "Телефон: " << phone << std::endl
        << std::endl;
}

void Client::SaveToFile()
{
    std::ofstream out;

    out.open(GetDatFile());

    out << login << " " << password << "\n";
    out.write(name.c_str(), name.size());
    out << "\n";
    out.write(country.c_str(), country.size());
    out << "\n";
    out.write(phone.c_str(), phone.size());
    out << "\n";

    out.close();
}

void Client::ReadFromFile()
{
    std::ifstream in;

    in.open(GetDatFile());

    in.ignore(99999, '\n');
    std::getline(in, name);
    std::getline(in, country);
    std::getline(in, phone);

    in.close();
}

void Client::SaveCredentialsToFile()
{
    User::SaveCredentialsToFile();
    SaveToFile();
}

void Client::UserMenu()
{
    ReadFromFile();

    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Показать персональную информацию\n"
            << "2. Изменить персональную информацию\n"
            << "3. Показать текущие операции\n"
            << "4. Отменить операцию\n"
            << "5. Экспорт\n"
            << "6. Импорт\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 1:
            ShowToConsole();
            break;
        case 2:
            InfoChangeMenu();
            break;
        case 0:
            return;
        }
    }
}

void Client::InfoChangeMenu()
{
    int choice;
    std::string input;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Изменить имя\n"
            << "2. Изменить страну\n"
            << "3. Изменить номер телефона\n"
            << "4. Изменить пароль\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            std::cout << "Введите новое имя: ";
            std::getline(std::cin, input);

            name = input;

            break;
        case 2:
            std::cout << "Введите новую страну: ";
            std::getline(std::cin, input);

            country = input;

            break;
        case 3:
            std::cout << "Введите новый номер телефона: ";
            std::getline(std::cin, input);

            phone = input;

            break;
        case 4:
            std::cout << "Введите старый пароль: ";
            std::getline(std::cin, input);

            if (MakePassword(input) != password)
            {
                std::cout << "Введён неправильный пароль\n\n";
                break;
            }

            std::cout << "Введите новый пароль: ";
            std::getline(std::cin, input);

            password = MakePassword(input);

            break;
        case 0:
            return;
        }

        SaveToFile();
    }
}
