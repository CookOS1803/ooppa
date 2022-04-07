#include "Client.h"
#include <iostream>
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

void Client::UserMenu()
{
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
}