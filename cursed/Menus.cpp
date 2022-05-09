#include "Menus.h"
#include <fstream>
#include "UserInput.h"
#include "User.h"
#include "Admin.h"
#include "Client.h"

// ���������������� �������
void IMEX::MainMenu()
{
    int choice;
    User* user = nullptr;

    while (true)
    {
        INPUT
        (
            // ����������� �������
            system("cls");

            // ������������� �������
            std::cout
            << "1. ����� ��� �������������\n"
            << "2. ����� ��� ������\n"
            << "3. ������������������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            // ������������ ��������� ������
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

    login = StringInput("������� �����: ");

    // ��������� ������
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

    password = StringInput("������� ������: ");

    user->TryLogin(login, password);

    if (user->IsInitialized())
    {
        user->UserMenu();
        user->Logout();
    }
    else
    {
        std::cout << "������������ ������\n";
        std::cin.get();
    }
}

void IMEX::RegistrationMenu(Client* client)
{
    std::string login, password;

    login = StringInput("������� �����: ");
    password = StringInput("������� ������: ");

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

    std::cout << "�������� �����������\n";
    std::cin.get();
    system("cls");
    client->RegistrationMenu();
}
