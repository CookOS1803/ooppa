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
            catch (const std::exception& e)
            {
                std::cout << e.what() << "\n";
                break;
            }

            std::cout << "������� ������: ";
            std::getline(std::cin, password);
            
            u.TryLogin(login, password);

            if (u.IsInitialized())
            {
                std::cout << "�������� ����\n";
                u.Logout();
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

            try
            {
                u.SaveToFile();
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << "\n";
                break;
            }

            std::cout << "�������� �����������\n";

            break;
        case 0:
            return;
        }
    }

    
}
