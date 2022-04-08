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

auto Client::GetInfoFileName() -> std::string
{
    return GetFolderName() + login + INFO_FILE_EXT;
}


void Client::SaveCredentialsToFile()
{
    User::SaveCredentialsToFile();
    info.SaveToFile(GetInfoFileName());
}

void Client::UserMenu()
{
    info.ReadFromFile(GetInfoFileName());

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
            info.ShowToConsole();
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
            << "1. �������� ���\n"
            << "2. �������� ������\n"
            << "3. �������� ����� ��������\n"
            << "4. �������� ������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            std::cout << "������� ����� ���: ";
            std::getline(std::cin, input);

            info.SetName(input);

            break;
        case 2:
            std::cout << "������� ����� ������: ";
            std::getline(std::cin, input);

            info.SetCountry(input);

            break;
        case 3:
            std::cout << "������� ����� ����� ��������: ";
            std::getline(std::cin, input);

            info.SetPhone(input);

            break;
        case 4:
            std::cout << "������� ������ ������: ";
            std::getline(std::cin, input);

            if (MakePassword(input) != password)
            {
                std::cout << "����� ������������ ������\n\n";
                break;
            }

            std::cout << "������� ����� ������: ";
            std::getline(std::cin, input);

            password = MakePassword(input);

            SaveCredentialsToFile();

            break;
        case 0:
            return;
        }

        info.SaveToFile(GetInfoFileName());
    }
}
