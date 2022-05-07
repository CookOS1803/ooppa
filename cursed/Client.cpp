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
    operations.SetOperationsFileName(GetFolderName() + OPER_FILE_NAME);
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

            SaveCredentialsToFile(false);

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
            << "3. ��������� ������� ������\n"
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
        case 3:
            FilterStorageMenu();
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
            << "3. ����������� �� ������������������ ������\n"
            << "4. ����������� �� ���� �� �����\n"
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
                products.Sort(ProductList::ByIDAscendingly);
            else
                products.Sort(ProductList::ByIDDescendingly);

            break;
        case 4:
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

void Client::FilterStorageMenu()
{
    int choice;
    std::string s;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. ����������� �� �����\n"
            << "2. ����������� �� ���������\n"
            << "3. ����������� �� ������������������ ������\n"
            << "4. ����������� �� ���� �� �����\n"
            << "5. ������ �������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            std::cout << "������� ������-������: ";
            std::getline(std::cin, s);

            products.SetNameFilter(s);

            break;
        case 2:
            std::cout << "������� ������-������: ";
            std::getline(std::cin, s);

            products.SetCategoryFilter(s);

            break;
        case 3:
            INPUT_CONDITION
            (
                std::cout
                << "1. �������� �������\n"
                << "2. �������� ��������\n",
                choice,
                choice == 1 or choice == 2
            );

            if (choice == 1)
            {
                INPUT
                (
                    std::cout << "������� �������: ",
                    choice
                );

                products.SetIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "������� ��������: ",
                    choice
                );

                products.SetIDFilterMax(choice);
            }

            break;
        case 4:
            INPUT_CONDITION
            (
                std::cout
                << "1. �������� �������\n"
                << "2. �������� ��������\n",
                choice,
                choice == 1 or choice == 2
            );

            if (choice == 1)
            {
                INPUT
                (
                    std::cout << "������� �������: ",
                    choice
                );

                products.SetUnitPriceFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "������� ��������: ",
                    choice
                );

                products.SetUnitPriceFilterMax(choice);
            }

            break;
        case 5:
            products.ClearFilters();

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
            << "3. ��������� ������� ������\n"
            << "4. ���������� ������\n"
            << "5. ���������� �������\n"
            << "6. �������� ��������\n"
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
            FilterOperationsMenu();
            break;
        case 4:
            MakeOperationTask(Operation::Type::IMPORT);
            break;
        case 5:
            MakeOperationTask(Operation::Type::EXPORT);
            break;
        case 6:
            CanselOperationTask();
            break;
        case 0:
            return;
        }
    }
}

void Client::SortOperationsMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. ����������� �� ������������������ ������ ��������\n"
            << "2. ����������� �� ����\n"
            << "3. ����������� �� �������\n"
            << "4. ����������� �� ������������������ ������ ������\n"
            << "5. ����������� �� ���������� ������\n"
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
                operations.Sort(IndividualOperationList::ByIDAscendingly);
            else
                operations.Sort(IndividualOperationList::ByIDDescendingly);

            break;
        case 2:
            if (order == 1)
                operations.Sort(OperationList::ByTypeAscendingly);
            else
                operations.Sort(OperationList::ByTypeDescendingly);

            break;
        case 3:
            if (order == 1)
                operations.Sort(OperationList::ByStatusAscendingly);
            else
                operations.Sort(OperationList::ByStatusDescendingly);

            break;
        case 4:
            if (order == 1)
                operations.Sort(OperationList::ByProductIDAscendingly);
            else
                operations.Sort(OperationList::ByProductIDDescendingly);

            break;
        case 5:
            if (order == 1)
                operations.Sort(OperationList::ByProductAmountAscendingly);
            else
                operations.Sort(OperationList::ByProductAmountDescendingly);

            break;
        case 0:
            return;
        }
    }
    
}

void Client::FilterOperationsMenu()
{
    int choice, bound;
    std::string s;

    while (true)
    {
        INPUT_CONDITION
        (
            std::cout
            << "1. ����������� �� ����\n"
            << "2. ����������� �� �������\n"
            << "3. ����������� �� ������������������ ������ ��������\n"
            << "4. ����������� �� ������������������ ������ ������\n"
            << "5. ����������� �� ���������� ������\n"
            << "6. ������ ��� �������\n"
            << "0. �����\n",
            choice,
            choice >= 0 and choice <= 7
        );

        if (choice != 0 and choice >= 3 and choice <= 5)
        {
            INPUT_CONDITION
            (
                std::cout
                << "1. �������� �������\n"
                << "2. �������� ��������\n",
                bound,
                bound == 1 or bound == 2
            );
        }

        switch (choice)
        {
        case 1:
            INPUT_CONDITION
            (
                std::cout
                << "1. ������\n"
                << "2. �������\n",
                choice,
                choice == 1 or choice == 2
            );

            if (choice == 1)
                operations.SetTypeFilter(Operation::Type::IMPORT);
            else
                operations.SetTypeFilter(Operation::Type::EXPORT);

            break;
        case 2:
            INPUT_CONDITION
            (
                std::cout
                << "1. ���������������\n"
                << "2. ���������\n"
                << "3. ��������\n",
                choice,
                choice >= 1 and choice <= 3
            );

            switch (choice)
            {
            case 1:
                operations.SetStatusFilter(Operation::Status::PENDING);
                break;
            case 2:
                operations.SetStatusFilter(Operation::Status::REJECTED);
                break;
            case 3:
                operations.SetStatusFilter(Operation::Status::APPROVED);
                break;
            }

            break;
        case 3:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "������� �������: ",
                    choice
                );

                operations.SetIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "������� ��������: ",
                    choice
                );

                operations.SetIDFilterMax(choice);
            }

            break;
        case 4:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "������� �������: ",
                    choice
                );

                operations.SetProductIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "������� ��������: ",
                    choice
                );

                operations.SetProductIDFilterMax(choice);
            }

            break;
        case 5:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "������� �������: ",
                    choice
                );

                operations.SetProductAmountFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "������� ��������: ",
                    choice
                );

                operations.SetProductAmountFilterMax(choice);
            }

            break;
        case 6:
            products.ClearFilters();

            break;
        case 0:
            return;
        }
    }
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

    OperationList l;
    l.SetFolderName(CLIENTS_FOLDER);
    l.SetOperationsFileName(OPER_FILE_NAME);
    l.ReadFromFile();

    l.CalculateNewID(temp);

    operations.Add(temp);

    operations.SaveToFile();
}

void Client::CanselOperationTask()
{
    int choice;

    INPUT
    (
        std::cout << "������� ����������������� ����� ��������: ",
        choice
    );

    if (!operations.Contains(choice))
    {
        std::cout << "��� ����� ��������\n\n";
        return;
    }

    operations.Remove(choice);

    operations.SaveToFile();
}
