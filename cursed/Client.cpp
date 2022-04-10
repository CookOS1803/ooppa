#include "Client.h"
#include <iostream>
#include <fstream>
#include <iomanip>
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
    info.SetLogin(login);
    info.SetFileName(GetInfoFileName());
}

auto Client::GetFolderName() -> std::string
{
	return CLIENTS_FOLDER + login + "\\";
}


auto Client::GetCredentialsFileName() -> std::string
{
    return GetFolderName() + CRED_FILE_NAME;
}

auto Client::GetInfoFileName() -> std::string
{
    return GetFolderName() + INFO_FILE_NAME;
}

void Client::RegistrationMenu()
{
    std::string input;

    std::cout << "������� ���: ";
    std::getline(std::cin, input);
    info.SetName(input);

    std::cout << "������� ����������� ����: ";
    std::getline(std::cin, input);
    info.SetLegalEntity(input);

    std::cout << "������� ������: ";
    std::getline(std::cin, input);
    info.SetCountry(input);

    std::cout << "������� ����� ��������: ";
    std::getline(std::cin, input);
    info.SetPhone(input);

    info.SetLogin(login);

    info.SaveToFile();
}

void Client::UserMenu()
{
    info.ReadFromFile();
    products.SetFileName(PROD_FILE_NAME);
    products.ReadFromFile();
    operations.SetOperationsFileName(OPER_FILE_NAME);
    operations.SetFolderName(CLIENTS_FOLDER);
    operations.ReadFromFile();

    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. �������� ������������ ����������\n"
            << "2. �������� ������������ ����������\n"
            << "3. ������\n"
            << "4. ��������\n"
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
        case 3:
            StorageMenu();
            break;
        case 4:
            OperationsMenu();
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
            << "3. �������� ����������� ����\n"
            << "4. �������� ����� ��������\n"
            << "5. �������� ������\n"
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
            std::cout << "������� ����� ����������� ����: ";
            std::getline(std::cin, input);

            info.SetLegalEntity(input);

            break;
        case 4:
            std::cout << "������� ����� ����� ��������: ";
            std::getline(std::cin, input);

            info.SetPhone(input);

            break;
        case 5:
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

void Client::StorageMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. ����������� �����\n"
            << "2. ������������� ������ �������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            ShowStorageTask();
            break;
        case 2:
            SortStorageMenu();
            break;
        case 0:
            return;
        }
    }
}

void Client::ShowStorageTask()
{
    std::cout << std::left;

    std::cout
        << std::setw(30) << "����������������� �����" << std::setw(30) << "������������" << std::setw(30) << "���������"
        << std::setw(30) << "���� �� �����" << std::endl;

    for (const auto& product : products)
    {
        std::cout
            << std::setw(30) << product->GetID() << std::setw(30) << product->GetName() << std::setw(30) << product->GetCategory()
            << std::setw(30) << product->GetUnitPrice() << std::endl;
    }

}

void Client::SortStorageMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. ����������� �� �����\n"
            << "2. ����������� �� ���������\n"
            << "3. ����������� �� ���� �� �����\n"
            << "0. �����\n",
            choice
        );


        if (choice != 0)
        {
            INPUT_CONDITION
            (
                std::cout
                << "1. �� �����������\n"
                << "2. �� ��������\n",
                order,
                order == 1 or order == 2
            );
        }

        switch (choice)
        {
        case 1:
            if (order == 1)
                products.Sort(ProductList::ByNameAscendingly);
            else
                products.Sort(ProductList::ByNameDescendingly);

            break;
        case 2:
            if (order == 1)
                products.Sort(ProductList::ByCategoryAscendingly);
            else
                products.Sort(ProductList::ByCategoryDescendingly);

            break;
        case 3:
            if (order == 1)
                products.Sort(ProductList::ByUnitPriceAscendingly);
            else
                products.Sort(ProductList::ByUnitPriceDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Client::OperationsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. �������� ��������\n"
            << "2. ������������� ������ ��������\n"
            << "3. ���������� ������\n"
            << "4. ���������� �������\n"
            << "5. �������� ��������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            operations.ShowToConsole();
            break;
        case 2:
            SortOperationsMenu();
            break;
        case 3:
            MakeOperationTask(Operation::Type::IMPORT);
            break;
        case 4:
            MakeOperationTask(Operation::Type::EXPORT);
            break;
        case 5:
            CanselOperationTask();
            break;
        case 0:
            return;
        }
    }
}

void Client::SortOperationsMenu()
{
    
}

void Client::MakeOperationTask(Operation::Type type)
{
    Operation temp;
    int choice;

    INPUT
    (
        std::cout << "������� ����������������� ����� ������: ",
        choice
    );

    if (!products.Contains(choice))
    {
        std::cout << "��� ������ ������\n\n";
        return;
    }

    temp.SetProductID(choice);

    INPUT_CONDITION
    (
        std::cout << "������� ���������� ������: ",
        choice,
        choice > 0
    );

    temp.SetProductAmount(choice);

    temp.SetType(type);
    temp.SetStatus(Operation::Status::PENDING);
    temp.SetClientLogin(login);
    temp.CalculateNewID(operations);
}

void Client::CanselOperationTask()
{

}
