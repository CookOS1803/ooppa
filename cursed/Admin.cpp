#include "Admin.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "UserInput.h"
#include "SortHelper.h"

using namespace IMEX;

Admin::Admin() : User()
{
}

Admin::Admin(std::string_view login, const std::string& password)
    : User(login, password)
{
}

auto Admin::GetFolderName() -> std::string
{
    return ADMINS_FOLDER;
}


auto Admin::GetCredentialsFileName() -> std::string
{
    return GetFolderName() + login + CRED_FILE_EXT;
}

void Admin::UserMenu()
{
    products.SetFileName(PROD_FILE_NAME);
    products.ReadFromFile();
    clients.SetFolderName(CLIENTS_FOLDER);
    clients.SetInfoFileName(INFO_FILE_NAME);
    clients.ReadFromFile();
    operations.SetFolderName(CLIENTS_FOLDER);
    operations.SetOperationsFileName(OPER_FILE_NAME);
    operations.ReadFromFile();

    int choice;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. ������ � ���������\n"
            << "2. ������ � ����������\n"
            << "3. ������ � �������\n"
            << "4. ������ � ����������������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            ClientsMenu();
            break;
        case 2:
            OperationsMenu();
            break;
        case 3:
            StorageMenu();
            break;
        case 4:
            AdminsMenu();
            break;
        case 0:
            return;
        }
    }
}

void Admin::ClientsMenu()
{
    int choice;
    
    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. �������� ���� ��������\n"
            << "2. �������� �������� �������\n"
            << "3. ������������� ������ ��������\n"
            << "4. ��������� ������� ������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            clients.ShowToConsole();
            std::cin.get();
            break;
        case 2:
            ShowClientTask();
            break;
        case 3:
            SortClientsMenu();
            break;
        case 4:
            FilterClientsMenu();
            break;
        case 0:
            return;
        }
    }
}

void Admin::ShowClientTask()
{
    std::string input;

    input = StringInput("������� ����� �������: ");

    try
    {
        auto c = clients.GetElement(input);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n\n";
        std::cin.get();
        return;
    }

    IndividualOperationList l;
    l.SetOperationsFileName(CLIENTS_FOLDER + input + "\\" + OPER_FILE_NAME);
    l.ReadFromFile();
    l.ShowToConsole();
    std::cin.get();
}

void Admin::SortClientsMenu()
{
    int choice, order;

    while (true)
    {
        INPUT_CONDITION
        (
            system("cls");
            std::cout
            << "1. ����������� �� ������\n"
            << "2. ����������� �� �����\n"
            << "3. ����������� �� ������������ ����\n"
            << "4. ����������� �� ������\n"
            << "5. ����������� �� ��������\n"
            << "0. �����\n",
            choice,
            choice >= 0 and choice <= 5
        );

        if (choice != 0)
        {
            INPUT_CONDITION
            (
                system("cls");
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
                clients.Sort(ClientSort::ByLoginAscendingly);
            else
                clients.Sort(ClientSort::ByLoginDescendingly);

            break;
        case 2:
            if (order == 1)
                clients.Sort(ClientSort::ByNameAscendingly);
            else
                clients.Sort(ClientSort::ByNameDescendingly);

            break;
        case 3:
            if (order == 1)
                clients.Sort(ClientSort::ByLegalEntityAscendingly);
            else
                clients.Sort(ClientSort::ByLegalEntityDescendingly);

            break;
        case 4:
            if (order == 1)
                clients.Sort(ClientSort::ByCountryAscendingly);
            else
                clients.Sort(ClientSort::ByCountryDescendingly);

            break;
        case 5:
            if (order == 1)
                clients.Sort(ClientSort::ByPhoneAscendingly);
            else
                clients.Sort(ClientSort::ByPhoneDescendingly);

            break;
        case 0:
            return;
        }

        system("cls");
        clients.ShowToConsole();
        std::cin.get();
    }
}

void Admin::FilterClientsMenu()
{
    int choice;
    std::string s;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. ����������� �� ������\n"
            << "2. ����������� �� �����\n"
            << "3. ����������� �� ������������ ����\n"
            << "4. ����������� �� ������\n"
            << "5. ����������� �� ��������\n"
            << "6. ������ �������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        if (choice != 0 and choice != 6)
        {
            s = StringInput("������� ������ ������: ");
        }

        switch (choice)
        {
        case 1:
            clients.SetLoginFilter(s);

            break;
        case 2:
            clients.SetNameFilter(s);

            break;
        case 3:
            clients.SetLegalEntityFilter(s);

            break;
        case 4:
            clients.SetCountryFilter(s);

            break;
        case 5:
            clients.SetPhoneFilter(s);

            break;
        case 6:
            clients.ClearFilters();

            break;
        case 0:
            return;
        }

        system("cls");
        clients.ShowToConsole();
        std::cin.get();
    }
}

void Admin::OperationsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. �������� ��������\n"
            << "2. ������������� ������ ��������\n"
            << "3. ��������� ������� ������\n"
            << "4. ����������� ��������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            operations.ShowToConsole();
            std::cin.get();
            break;
        case 2:
            SortOperationsMenu();
            break;
        case 3:
            FilterOperationsMenu();
            break;
        case 4:
            HandleOperationTask();
            break;
        case 0:
            return;
        }
    }
}

void Admin::SortOperationsMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. ����������� �� ������������������ ������ ��������\n"
            << "2. ����������� �� ����\n"
            << "3. ����������� �� �������\n"
            << "4. ����������� �� ������������������ ������ ������\n"
            << "5. ����������� �� ���������� ������\n"
            << "6. ����������� �� ������ �������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        if (choice != 0)
        {
            INPUT_CONDITION
            (
                system("cls");
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
                operations.Sort(OperationSort::ByIDAscendingly);
            else
                operations.Sort(OperationSort::ByIDDescendingly);

            break;
        case 2:
            if (order == 1)
                operations.Sort(OperationSort::ByTypeAscendingly);
            else
                operations.Sort(OperationSort::ByTypeDescendingly);

            break;
        case 3:
            if (order == 1)
                operations.Sort(OperationSort::ByStatusAscendingly);
            else
                operations.Sort(OperationSort::ByStatusDescendingly);

            break;
        case 4:
            if (order == 1)
                operations.Sort(OperationSort::ByProductIDAscendingly);
            else
                operations.Sort(OperationSort::ByProductIDDescendingly);

            break;
        case 5:
            if (order == 1)
                operations.Sort(OperationSort::ByProductAmountAscendingly);
            else
                operations.Sort(OperationSort::ByProductAmountDescendingly);

            break;
        case 6:
            if (order == 1)
                operations.Sort(OperationSort::ByClientLoginAscendingly);
            else
                operations.Sort(OperationSort::ByClientLoginDescendingly);

            break;
        case 0:
            return;
        }

        system("cls");
        operations.ShowToConsole();
        std::cin.get();
    }
}

void Admin::FilterOperationsMenu()
{
    int choice, bound;
    std::string s;

    while (true)
    {
        INPUT_CONDITION
        (
            system("cls");
            std::cout
            << "1. ����������� �� ����\n"
            << "2. ����������� �� �������\n"
            << "3. ����������� �� ������������������ ������ ��������\n"
            << "4. ����������� �� ������������������ ������ ������\n"
            << "5. ����������� �� ���������� ������\n"
            << "6. ����������� �� ������ �������\n"
            << "7. ������ ��� �������\n"
            << "0. �����\n",
            choice,
            choice >= 0 and choice <= 7
        );

        system("cls");

        if (choice != 0 and choice >= 3 and choice <= 5)
        {
            INPUT_CONDITION
            (
                system("cls");
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
                system("cls");
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
                system("cls");
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
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                operations.SetIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
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
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                operations.SetProductIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
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
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                operations.SetProductAmountFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� ��������: ",
                    choice
                );

                operations.SetProductAmountFilterMax(choice);
            }

            break;
        case 6:
            s = StringInput("������� ������-������: ");

            operations.SetClientLoginFilter(s);

            break;
        case 7:
            operations.ClearFilters();

            break;
        case 0:
            return;
        }

        system("cls");
        operations.ShowToConsole();
        std::cin.get();
    }
}

void Admin::HandleOperationTask()
{
    int choice;

    INPUT
    (
        system("cls");
        std::cout << "������� ����������������� ����� ��������\n",
        choice
    );

    std::shared_ptr<Operation> o;

    try
    {
        o = operations.GetElement(choice);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n\n";
        std::cin.get();
        return;
    }

    if (o->GetStatus() != Operation::Status::PENDING)
    {
        std::cout << "��� �������� ��� �����������\n\n";
        std::cin.get();
        return;
    }

    INPUT_CONDITION
    (
        system("cls");
        std::cout
        << "1. ��������\n"
        << "2. ���������\n",
        choice,
        choice == 1 or choice == 2
    );

    if (choice == 1)
        o->SetStatus(Operation::Status::APPROVED);
    else
        o->SetStatus(Operation::Status::REJECTED);

    operations.SaveToFile();        
}

void Admin::StorageMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. ����������� �����\n"
            << "2. �������� �������\n"
            << "3. ������������� ������ ���������\n"
            << "4. ��������� ������� ������\n"
            << "5. ������� �������\n"
            << "6. �������� �������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            products.ShowToConsole();
            std::cin.get();
            break;
        case 2:
            AddProductTask();
            break;
        case 3:
            SortStorageMenu();
            break;
        case 4:
            FilterStorageMenu();
            break;
        case 5:
            DeleteProductTask();
            break;
        case 6:
            ChangeProductTask();
            break;
        case 0:
            return;
        }
    }
}

void Admin::AddProductTask()
{
    Product tempProduct;
    std::string input;
    int choice;

    input = StringInput("������� �������� ��������: ");
    tempProduct.SetName(input);

    input = StringInput("������� ��������� ��������: ");
    tempProduct.SetCategory(input);

    INPUT_CONDITION
    (
        std::cout << "������� ����������: ",
        choice,
        choice >= 0
    );

    tempProduct.SetAmount(choice);

    INPUT_CONDITION
    (
        std::cout << "������� ���� �� �����: ",
        choice,
        choice >= 0
    );

    tempProduct.SetUnitPrice(choice);

    products.CalculateNewID(tempProduct);

    products.Add(tempProduct);

    products.SaveToFile();
}

void Admin::SortStorageMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. ����������� �� ������������������ ������\n"
            << "2. ����������� �� �����\n"
            << "3. ����������� �� ���������\n"
            << "4. ����������� �� ����������\n"
            << "5. ����������� �� ���� �� �����\n"
            << "6. ����������� �� ���������\n"
            << "0. �����\n",
            choice
        );

        if (choice != 0)
        {
            INPUT_CONDITION
            (
                system("cls");
                std::cout
                << "1. �� �����������\n"
                << "2. �� ��������\n",
                order,
                order == 1 or order == 2
            );
        }

        system("cls");

        switch (choice)
        {
        case 1:
            if (order == 1)
                products.Sort(ProductSort::ByIDAscendingly);
            else
                products.Sort(ProductSort::ByIDDescendingly);

            break;
        case 2:
            if (order == 1)
                products.Sort(ProductSort::ByNameAscendingly);
            else
                products.Sort(ProductSort::ByNameDescendingly);

            break;
        case 3:
            if (order == 1)
                products.Sort(ProductSort::ByCategoryAscendingly);
            else
                products.Sort(ProductSort::ByCategoryDescendingly);

            break;
        case 4:
            if (order == 1)
                products.Sort(ProductSort::ByAmountAscendingly);
            else
                products.Sort(ProductSort::ByAmountDescendingly);

            break;
        case 5:
            if (order == 1)
                products.Sort(ProductSort::ByUnitPriceAscendingly);
            else
                products.Sort(ProductSort::ByUnitPriceDescendingly);

            break;
        case 6:
            if (order == 1)
                products.Sort(ProductSort::ByTotalPriceAscendingly);
            else
                products.Sort(ProductSort::ByTotalPriceDescendingly);

            break;
        case 0:
            return;
        }

        system("cls");
        products.ShowToConsole();
        std::cin.get();
    }
}

void Admin::FilterStorageMenu()
{
    int choice, bound;
    std::string s;

    while (true)
    {
        INPUT_CONDITION
        (
            system("cls");
            std::cout
            << "1. ����������� �� �����\n"
            << "2. ����������� �� ���������\n"
            << "3. ����������� �� ������������������ ������\n"
            << "4. ����������� �� ����������\n"
            << "5. ����������� �� ���� �� �����\n"
            << "6. ����������� �� ���������\n"
            << "7. ������ ��� �������\n"
            << "0. �����\n",
            choice,
            choice >= 0 and choice <= 7
        );

        system("cls");

        if (choice != 0)
        {
            if (choice >= 3 and choice <= 6)
            {
                INPUT_CONDITION
                (
                    system("cls");
                    std::cout
                    << "1. �������� �������\n"
                    << "2. �������� ��������\n",
                    bound,
                    bound == 1 or bound == 2
                );
            }
            else if (choice != 7)
            {
                s = StringInput("������� ������-������: ");
            }
        }

        system("cls");

        switch (choice)
        {
        case 1:
            products.SetNameFilter(s);

            break;
        case 2:
            products.SetCategoryFilter(s);

            break;
        case 3:
            if (bound == 1)
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                products.SetIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� ��������: ",
                    choice
                );

                products.SetIDFilterMax(choice);
            }

            break;

        case 4:
            if (bound == 1)
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                products.SetAmountFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� ��������: ",
                    choice
                );

                products.SetAmountFilterMax(choice);
            }

            break;
        case 5:
            if (bound == 1)
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                products.SetUnitPriceFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� ��������: ",
                    choice
                );

                products.SetUnitPriceFilterMax(choice);
            }

            break;
        case 6:
            if (bound == 1)
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� �������: ",
                    choice
                );

                products.SetTotalPriceFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    system("cls");
                    std::cout << "������� ��������: ",
                    choice
                );

                products.SetTotalPriceFilterMax(choice);
            }

            break;
        case 7:
            products.ClearFilters();

            break;
        case 0:
            return;
        }

        system("cls");
        products.ShowToConsole();
        std::cin.get();
    }
}

void Admin::DeleteProductTask()
{
    int ID;

    INPUT
    (
        system("cls");
        std::cout << "������� ����������������� ����� ��������\n",
        ID
    );


    if (!products.Contains(ID))
    {
        std::cout << "������ �������� ���\n\n";
        std::cin.get();
        return;
    }

    products.Remove(ID);

    products.SaveToFile();
}

void Admin::ChangeProductTask()
{
    int ID;

    INPUT
    (
        system("cls");
        std::cout << "������� ����������������� ����� ��������\n",
        ID
    );

    try
    {
        auto tempProduct = products.GetElement(ID);
        ChangeProductMenu(tempProduct);
        products.SaveToFile();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl << std::endl;
        std::cin.get();
    }
}

void Admin::ChangeProductMenu(std::shared_ptr<Product> product)
{
    int choice;
    std::string input;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. �������� ��������\n"
            << "2. �������� ���������\n"
            << "3. �������� ����������\n"
            << "4. �������� ���� �� �����\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            input = StringInput("������� ����� �������� ��������: ");

            product->SetName(input);
            break;
        case 2:
            input = StringInput("������� ����� ��������� ��������: ");

            product->SetCategory(input);
            break;
        case 3:
            INPUT_CONDITION
            (
                system("cls");
                std::cout << "������� ����������: ",
                choice,
                choice >= 0
            );

            product->SetAmount(choice);
            break;
        case 4:
            INPUT_CONDITION
            (
                system("cls");
                std::cout << "������� ����� ���� �� �����: ",
                choice,
                choice >= 0
            );

            product->SetUnitPrice(choice);
            break;
        case 0:
            return;
        }
    }
}

void Admin::AdminsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            system("cls");
            std::cout
            << "1. �������� ��������������\n"
            << "2. ������� ��������������\n"
            << "0. �����\n",
            choice
        );

        system("cls");

        switch (choice)
        {
        case 1:
            AddAdminTask();
            break;
        case 2:
            RemoveAdminTask();
            break;
        case 0:
            return;
        }
    }
}

void Admin::AddAdminTask()
{
    std::string newLogin, newPassword;
    std::filesystem::path path{ ADMINS_FOLDER };
    
    newLogin = StringInput("������� �����: ");

    for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
    {
        if (newLogin == dir_entry.path().stem().string())
        {
            std::cout << "����� �����";
            std::cin.get();
            return;
        }
    }

    newPassword = MakePassword(StringInput("������� ������: "));

    std::ofstream file;
    file.open(ADMINS_FOLDER + newLogin + CRED_FILE_EXT);

    file << newLogin << " " << newPassword << "\n";

    file.close();
}

void Admin::RemoveAdminTask()
{
    std::string newLogin;
    std::filesystem::path path{ ADMINS_FOLDER };

    newLogin = StringInput("������� �����: ");

    for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
    {
        if (newLogin == dir_entry.path().stem().string())
        {
            std::filesystem::remove(dir_entry.path());
            return;
        }
    }

    std::cout << "������ �������������� ���\n\n";
    std::cin.get();
}
