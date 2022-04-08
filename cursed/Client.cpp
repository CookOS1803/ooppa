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
        << "���: " << name << std::endl
        << "������: " << country << std::endl
        << "�������: " << phone << std::endl
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

            name = input;

            break;
        case 2:
            std::cout << "������� ����� ������: ";
            std::getline(std::cin, input);

            country = input;

            break;
        case 3:
            std::cout << "������� ����� ����� ��������: ";
            std::getline(std::cin, input);

            phone = input;

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

            break;
        case 0:
            return;
        }

        SaveToFile();
    }
}
