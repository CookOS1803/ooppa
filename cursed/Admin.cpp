#include "Admin.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "UserInput.h"

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
            std::cout
            << "1. ������ � ���������\n"
            << "2. ������ � ����������\n"
            << "3. ������ � �������\n"
            << "4. ������ � ����������������\n"
            << "0. �����\n",
            choice
        );

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
            std::cout
            << "1. �������� ���� ��������\n"
            << "2. �������� �������� �������\n"
            << "3. ������������� ������ ��������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            clients.ShowToConsole();
            break;
        case 2:
            ShowClientTask();
            break;
        case 3:
            SortClientsMenu();
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
        auto c = clients.GetClient(input);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n\n";
        return;
    }

    IndividualOperationList l;
    l.SetOperationsFileName(CLIENTS_FOLDER + input + "\\" + OPER_FILE_NAME);
    l.ReadFromFile();
    l.ShowToConsole();
}

void Admin::SortClientsMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. ����������� �� ������\n"
            << "2. ����������� �� �����\n"
            << "3. ����������� �� ������������ ����\n"
            << "4. ����������� �� ������\n"
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
                clients.Sort(ClientsList::ByLoginAscendingly);
            else
                clients.Sort(ClientsList::ByLoginDescendingly);

            break;
        case 2:
            if (order == 1)
                clients.Sort(ClientsList::ByNameAscendingly);
            else
                clients.Sort(ClientsList::ByNameDescendingly);

            break;
        case 3:
            if (order == 1)
                clients.Sort(ClientsList::ByLegalEntityAscendingly);
            else
                clients.Sort(ClientsList::ByLegalEntityDescendingly);

            break;
        case 4:
            if (order == 1)
                clients.Sort(ClientsList::ByCountryAscendingly);
            else
                clients.Sort(ClientsList::ByCountryDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Admin::OperationsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. �������� ��������\n"
            << "2. ������������� ������ ��������\n"
            << "3. ����������� ��������\n"
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
                operations.Sort(OperationList::ByIDAscendingly);
            else
                operations.Sort(OperationList::ByIDDescendingly);

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
        case 6:
            if (order == 1)
                operations.Sort(OperationList::ByClientLoginAscendingly);
            else
                operations.Sort(OperationList::ByClientLoginDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Admin::HandleOperationTask()
{
    int choice;

    INPUT
    (
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
        return;
    }

    if (o->GetStatus() != Operation::Status::PENDING)
    {
        std::cout << "��� �������� ��� �����������\n\n";
        return;
    }

    INPUT_CONDITION
    (
        std::cout
        << "1. ��������\n"
        << "2. ���������\n",
        choice,
        choice == 1 and choice == 2
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
            std::cout
            << "1. ����������� �����\n"
            << "2. �������� �������\n"
            << "3. ������������� ������ ���������\n"
            << "4. ������� �������\n"
            << "5. �������� �������\n"
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            products.ShowToConsole();
            break;
        case 2:
            AddProductTask();
            break;
        case 3:
            SortStorageMenu();
            break;
        case 4:
            DeleteProductTask();
            break;
        case 5:
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
                products.Sort(ProductList::ByIDAscendingly);
            else
                products.Sort(ProductList::ByIDDescendingly);

            break;
        case 2:
            if (order == 1)
                products.Sort(ProductList::ByNameAscendingly);
            else
                products.Sort(ProductList::ByNameDescendingly);

            break;
        case 3:
            if (order == 1)
                products.Sort(ProductList::ByCategoryAscendingly);
            else
                products.Sort(ProductList::ByCategoryDescendingly);

            break;
        case 4:
            if (order == 1)
                products.Sort(ProductList::ByAmountAscendingly);
            else
                products.Sort(ProductList::ByAmountDescendingly);

            break;
        case 5:
            if (order == 1)
                products.Sort(ProductList::ByUnitPriceAscendingly);
            else
                products.Sort(ProductList::ByUnitPriceDescendingly);

            break;
        case 6:
            if (order == 1)
                products.Sort(ProductList::ByTotalPriceAscendingly);
            else
                products.Sort(ProductList::ByTotalPriceDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Admin::DeleteProductTask()
{
    int ID;

    INPUT
    (
        std::cout << "������� ����������������� ����� ��������\n",
        ID
    );


    if (!products.Contains(ID))
    {
        std::cout << "������ �������� ���\n\n";
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
            std::cout
            << "1. �������� ��������\n"
            << "2. �������� ���������\n"
            << "3. �������� ����������\n"
            << "4. �������� ���� �� �����\n"
            << "0. �����\n",
            choice
        );

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
                std::cout << "������� ����������: ",
                choice,
                choice >= 0
            );

            product->SetAmount(choice);
            break;
        case 4:
            INPUT_CONDITION
            (
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
            std::cout
            << "1. �������� ��������������\n"
            << "2. ������� ��������������\n"
            << "0. �����\n",
            choice
        );

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
}
