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
        << "���: " << name << std::endl
        << "������: " << country << std::endl
        << "�������: " << phone << std::endl
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
            << "1. �������� ������������ ����������\n"
            << "2. �������� ������������ ����������\n"
            << "3. �������� ������� ��������\n"
            << "4. �������� ��������\n"
            << "5. �������\n"
            << "6. ������\n"
            << "0. �����\n",
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