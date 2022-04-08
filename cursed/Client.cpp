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

void Client::SetLogin(std::string_view login)
{
    User::SetLogin(login);
    info.SetFileName(GetInfoFileName());
}

auto Client::GetFolderName() -> std::string
{
	return "clients\\";
}

auto Client::GetInfoFileName() -> std::string
{
    return GetFolderName() + login + INFO_FILE_EXT;
}

void Client::RegistrationMenu()
{
    std::string input;

    std::cout << "������� ���: ";
    std::getline(std::cin, input);
    info.SetName(input);

    std::cout << "������� ������: ";
    std::getline(std::cin, input);
    info.SetCountry(input);

    std::cout << "������� ����� ��������: ";
    std::getline(std::cin, input);
    info.SetPhone(input);

    info.SaveToFile();
}

void Client::UserMenu()
{
    info.ReadFromFile();

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

        info.SaveToFile();
    }
}
