#include "Admin.h"
#include <iostream>
#include <filesystem>
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
        case 3:
            StorageMenu();

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
            << "2. ����� ��������\n"
            << "3. �������� �������� �������\n"
            << "4. "
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 1:
            clients.ShowToConsole();

            break;
        case 2:
            FindClientsMenu();

            break;
        case 0:
            return;
        }
    }
}

void Admin::FindClientsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "0. �����\n",
            choice
        );

        switch (choice)
        {
        case 0:
            return;
        }
    }
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
    std::string pName, pCategory;
    int choice;

    std::cout << "������� �������� ��������: ";
    std::getline(std::cin, pName);

    std::cout << "������� ��������� ��������: ";
    std::getline(std::cin, pCategory);

    if (products.Contains(pName, pCategory))
    {
        std::cout << "����� ������� ��� ����\n\n";
        return;
    }

    tempProduct.SetName(pName);
    tempProduct.SetCategory(pCategory);

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
            << "1. ����������� �� �����\n"
            << "2. ����������� �� ���������\n"
            << "3. ����������� �� ����������\n"
            << "4. ����������� �� ���� �� �����\n"
            << "5. ����������� �� ���������\n"
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
                products.Sort(ProductList::ByAmountAscendingly);
            else
                products.Sort(ProductList::ByAmountDescendingly);

            break;
        case 4:
            if (order == 1)
                products.Sort(ProductList::ByUnitPriceAscendingly);
            else
                products.Sort(ProductList::ByUnitPriceDescendingly);

            break;
        case 5:
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
    Product tempProduct;
    std::string pName, pCategory;

    std::cout << "������� �������� ��������: ";
    std::getline(std::cin, pName);

    std::cout << "������� ��������� ��������: ";
    std::getline(std::cin, pCategory);

    if (!products.Contains(pName, pCategory))
    {
        std::cout << "������ �������� ���\n\n";
        return;
    }

    products.Remove(pName, pCategory);

    products.SaveToFile();
}

void Admin::ChangeProductTask()
{
    std::string pName, pCategory;

    std::cout << "������� �������� ��������: ";
    std::getline(std::cin, pName);

    std::cout << "������� ��������� ��������: ";
    std::getline(std::cin, pCategory);


    try
    {
        auto tempProduct = products.GetProduct(pName, pCategory);
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
            std::cout << "������� ����� �������� ��������: ";
            std::getline(std::cin, input);

            if (products.Contains(input, product->GetCategory()))
            {
                std::cout << "����� ������� ��� ����\n\n";
                break;
            }

            product->SetName(input);
            break;
        case 2:
            std::cout << "������� ����� ��������� ��������: ";
            std::getline(std::cin, input);

            if (products.Contains(product->GetName(), input))
            {
                std::cout << "����� ������� ��� ����\n\n";
                break;
            }

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