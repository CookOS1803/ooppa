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
            << "1. ����� ��� �������������\n"
            << "2. ����� ��� ������������\n"
            << "3. ������������������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            std::cout << "������� �����: ";
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

            std::cout << "������� ������: ";
            std::getline(std::cin, password);
            password = User::MakePassword(password);

            u.TryLogin(login, password);

            if (u.IsInitialized())
            {
                std::cout << "�������� ����\n";
                return;
            }
            else
                std::cout << "������������ ������\n";


            break;
        case 2:
            break;
        case 3:
            std::cout << "������� �����: ";
            std::getline(std::cin, login);

            std::cout << "������� ������: ";
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
